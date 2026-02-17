//  Copyright (c) 2016-2025, Smart Engines Service LLC
//  All rights reserved.

package com.module.lib;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.ImageDecoder;
import android.net.Uri;
import android.os.Build;
import android.provider.MediaStore;

import androidx.annotation.NonNull;
import androidx.camera.core.ImageProxy;

import java.nio.ByteBuffer;

import com.smartengines.common.ImagePixelFormat;
import com.smartengines.common.YUVDimensions;
import com.smartengines.common.YUVType;

/**
 * Image helper class.
 * - Base64
 * - URIs
 * - Byte arrays
 * - Android Bitmaps
 * - CameraX ImageProxy
 */

public class Image {

    // Image from base64 string
    public static com.smartengines.common.Image createFromBase64(String imageObject) {
        try {
            return com.smartengines.common.Image.FromBase64Buffer(imageObject);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    // Image from Uri
    public static com.smartengines.common.Image createFromUri(String imageObject, Context context) {
        try {
            Bitmap file;
            if (Build.VERSION.SDK_INT >=29 ) {
                file = ImageDecoder.decodeBitmap(ImageDecoder.createSource(context.getContentResolver(), Uri.parse(imageObject)), (imageDecoder, imageInfo, source1) -> imageDecoder.setMutableRequired(true));
            } else {
                file = MediaStore.Images.Media.getBitmap(context.getContentResolver(), Uri.parse(imageObject));
            }
            return createFromBitmap(file);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    // image from Bytes. Common Flutter case
    public static com.smartengines.common.Image createFromByteArray(@NonNull byte[] bytes) {
        try {
            return com.smartengines.common.Image.FromFileBuffer(bytes);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

    }

    // Image from Android Bitmap
    public static com.smartengines.common.Image createFromBitmap(Bitmap bitmap) {
        try {
            int width = bitmap.getWidth();
            int height = bitmap.getHeight();
            // stride is a bytes per line. Can we replace it with imageData.getRowBytes();?
            int stride = width * 4; // ARGB_8888 format (4 bytes per pixel - 32 bit color depth)

            byte[] byteArray = new byte[stride * height];

            ByteBuffer byteBuffer = ByteBuffer.wrap(byteArray);
            bitmap.copyPixelsToBuffer(byteBuffer);
            // data, width, height, stride, PixelFormat, bytesPerChannel
            return com.smartengines.common.Image.FromBufferExtended(byteArray, width, height, stride, ImagePixelFormat.IPF_RGBA, 1);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    // Image from CameraX
    public static com.smartengines.common.Image createFromImageProxy(ImageProxy imageObject) {
        try {
            int width = imageObject.getWidth(); // ~1280
            int height = imageObject.getHeight(); // ~960

            // YUV_420_888
            if(imageObject.getFormat() == 35) {

                // Example for YUV_FORMAT_420_888
                // According to our tests RGBA_8888 has ~45ms overhead per frame (tested on Helio G90T)
                // https://developer.android.com/reference/android/graphics/ImageFormat#YUV_420_888

                ImageProxy.PlaneProxy planeY = imageObject.getPlanes()[0];
                ImageProxy.PlaneProxy planeU = imageObject.getPlanes()[1];
                ImageProxy.PlaneProxy planeV = imageObject.getPlanes()[2];

                YUVDimensions yuvDimensions = new YUVDimensions(
                        planeY.getPixelStride(), planeY.getRowStride(),
                        planeU.getPixelStride(), planeU.getRowStride(),
                        planeV.getPixelStride(), planeV.getRowStride(),
                        width, height, YUVType.YUVTYPE_420_888);

                return com.smartengines.common.Image.FromYUV(
                        getByteArrayFromByteBuffer(planeY.getBuffer(), planeY.getRowStride(), height),
                        getByteArrayFromByteBuffer(planeU.getBuffer(), planeU.getRowStride(), height),
                        getByteArrayFromByteBuffer(planeV.getBuffer(), planeV.getRowStride(), height),
                        yuvDimensions);
            }

            // JPG
            if(imageObject.getFormat() == 256) {

                // In case if image.getFormat() return 256 ()
                // Compressed data. Row and pixel strides are 0.
                // https://developer.android.com/reference/android/graphics/ImageFormat#JPEG

                ByteBuffer buffer = imageObject.getPlanes()[0].getBuffer(); // jpg
                byte[] frame_bytes = new byte[buffer.remaining()];
                buffer.get(frame_bytes);
                com.smartengines.common.Image frame = com.smartengines.common.Image.FromFileBuffer(frame_bytes);
                //String base64_after = frame.GetBase64String().GetCStr();
                return frame;
            }

        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        return null;
    }

    // ImageProxy to Android Bitmap
    public static Bitmap imageProxyToBitmap(ImageProxy image) {
        ImageProxy.PlaneProxy planeProxy = image.getPlanes()[0];
        ByteBuffer buffer = planeProxy.getBuffer();
        byte[] bytes = new byte[buffer.remaining()];
        buffer.get(bytes);
        return BitmapFactory.decodeByteArray(bytes, 0, bytes.length);
    }

    private static byte[] getByteArrayFromByteBuffer(ByteBuffer byteBuffer, int rowStride, int height) {

        /** getBuffer() - The stride after the last row may not be mapped into the buffer.
         *  This is why we always calculate the byteBuffer offset.
         *  https://developer.android.com/reference/android/media/Image.Plane#getBuffer()
         */

        int bufferSize = byteBuffer.remaining();
        // The byte array size is stride * height (the leftover spaces will be filled with 0 bytes)
        byte[] bytesArray = new byte[height * rowStride];
        byteBuffer.get(bytesArray, 0, bufferSize);
        return bytesArray;
    }

    private static byte[] bitmapToByteArray(Bitmap bitmap) {
        ByteBuffer byteBuffer = ByteBuffer.allocate(bitmap.getByteCount());
        bitmap.copyPixelsToBuffer(byteBuffer);
        byteBuffer.rewind();
        return byteBuffer.array();
    }

}
