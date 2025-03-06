//  Copyright (c) 2016-2024, Smart Engines Service LLC
//  All rights reserved.

package com.smartengines;

import android.content.Context;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Rect;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.camera.core.ImageProxy;

import com.smartengines.common.Image;
import com.smartengines.common.ImagePixelFormat;
import com.smartengines.common.Rectangle;
import com.smartengines.common.StringsSetIterator;
import com.smartengines.common.StringsVectorIterator;
import com.smartengines.common.YUVDimensions;
import com.smartengines.common.YUVType;
import com.smartengines.doc.DocProcessingSettings;
import com.smartengines.doc.DocResult;
import com.smartengines.doc.DocSession;
import com.smartengines.doc.DocSessionSettings;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class DocEngine {

    private static com.smartengines.doc.DocEngine instance;

    public static com.smartengines.doc.DocEngine getInstance(Context context) {
        if (instance == null) {
            try {
                byte[] bundleData = prepareBundle(context);
                // load library
                System.loadLibrary("jnidocengine");

                instance = com.smartengines.doc.DocEngine.Create(bundleData, true);
            } catch (Exception e) {
                Handler handler = new Handler(Looper.getMainLooper());
                handler.post(() -> {
                    Toast t = Toast.makeText(context, e.getMessage(), Toast.LENGTH_LONG);
                    t.show();
                });
                Log.e("SMARTENGINES", e.getMessage());
            }
        }
        return instance;
    }

    private static byte[] prepareBundle(Context context) {
        AssetManager assetManager = context.getAssets();
        String bundle_name = "";
        String[] file_list;
        ByteArrayOutputStream os = new ByteArrayOutputStream();

        try {
            file_list = assetManager.list("data");

            for (String file : file_list) {
                if (file.endsWith(".se")) {
                    bundle_name = file;
                    break;
                }
            }

            if (bundle_name.isEmpty()) {
                throw new IOException("No configuration bundle found!");
            }

            final String bundle_path = "data" + File.separator + bundle_name;

            InputStream is = assetManager.open(bundle_path);

            byte[] buffer = new byte[0xFFFF];
            for (int len = is.read(buffer); len != -1; len = is.read(buffer)) {
                os.write(buffer, 0, len);
            }
            os.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return os.toByteArray();
    }

    public static String[] getDocumentsList(Context context) {
        List<String> documents = new ArrayList<>();

        com.smartengines.doc.DocEngine engine = getInstance(context);

        DocSessionSettings sessionSettings = engine.CreateSessionSettings();

        for (StringsVectorIterator mt = sessionSettings.SupportedModesBegin(); !mt
                .Equals(sessionSettings.SupportedModesEnd()); mt.Advance()) {

            sessionSettings.SetCurrentMode(mt.GetValue());

            for (StringsSetIterator dt = sessionSettings.PermissiblePrefixDocMasksBegin(); !dt
                    .Equals(sessionSettings.PermissiblePrefixDocMasksEnd()); dt.Advance()) {
                documents.add(mt.GetValue() + ':' + dt.GetValue());
            }
        }

        String[] array = new String[documents.size()];
        documents.toArray(array);

        return array;
    }

    public String getVersion(Context context) {
        com.smartengines.doc.DocEngine engine = getInstance(context);
        return engine.GetVersion();
    }

    public static DocResult recognizeImage(final Image image, Context context) throws Exception {

        String docMode = SettingsStore.currentMode;
        //Label.getInstance().message.set("Wait...");
        // 1. Get engine instance
        com.smartengines.doc.DocEngine engine = DocEngine.getInstance(context);
        // 2. Create new session settings object
        DocSessionSettings docSettings = engine.CreateSessionSettings();
        docSettings.SetCurrentMode(docMode);

        // 2.1 Set document mask
        ArrayList<String> docArray = SettingsStore.currentMask;
        for (String name : docArray) {
            // System.out.println(name);
            docSettings.AddEnabledDocumentTypes(name);
        }
        // 2.2 Set custom options
        Map<String, String> map = SettingsStore.options;
        for (Map.Entry<String, String> entry : map.entrySet()) {
            String key = entry.getKey();
            String value = entry.getValue();
            docSettings.SetOption(key, value);
        }
        // 3. Spawn recognition session
        DocSession session = engine.SpawnSession(docSettings, SettingsStore.signature);

        // Create processing settings
        DocProcessingSettings ps = session.CreateProcessingSettings();
        // Register image
        int image_id = session.RegisterImage(image);
        // Set image as source
        ps.SetCurrentSourceID(image_id);
        // Process image
        session.Process(ps);
        //session.Reset();
        // Get result
        return session.GetCurrentResult();
    }


    /*
     * =====================================================================
     * ======================== Image Utils ================================
     * =====================================================================
     */

    public static Image SEImageFromYUV(@NonNull ImageProxy image) {
        // Get sensor orientation
        int imageRotationDegrees = image.getImageInfo().getRotationDegrees();
        // Calculate rotation image counts
        int rotationTimes = imageRotationDegrees / 90;

        int width = image.getWidth(); // ~1280
        int height = image.getHeight(); // ~960

        // image.getFormat();
        // Get rectangle for crop
        Rect crop = image.getCropRect();

        ImageProxy.PlaneProxy planeY = image.getPlanes()[0];
        ImageProxy.PlaneProxy planeU = image.getPlanes()[1];
        ImageProxy.PlaneProxy planeV = image.getPlanes()[2];

        YUVDimensions yuvDimensions = new YUVDimensions(
                planeY.getPixelStride(), planeY.getRowStride(),
                planeU.getPixelStride(), planeU.getRowStride(),
                planeV.getPixelStride(), planeV.getRowStride(),
                width, height, YUVType.YUVTYPE_420_888);

        Image frame = Image.FromYUV(
                getByteArrayFromByteBuffer(planeY.getBuffer(), planeY.getRowStride(), height),
                getByteArrayFromByteBuffer(planeU.getBuffer(), planeU.getRowStride(), height),
                getByteArrayFromByteBuffer(planeV.getBuffer(), planeV.getRowStride(), height),
                yuvDimensions);

        Rectangle crop_rect;
        //  Rectangle
        //  int x, X-coordinate of the top-left corner
        //  int y, Y-coordinate of the top-left corner
        //  int width, Width of the rectangle
        //  int height, Height of the rectangle

        // Rotate crop rectangle if needed
        if (imageRotationDegrees == 0 || imageRotationDegrees == 180) {
            crop_rect = new Rectangle(crop.left, crop.top, crop.right - crop.left, crop.bottom);
        } else {
            crop_rect = new Rectangle(crop.top, crop.left, crop.bottom - crop.top, crop.right);
        }

        // Copy out RGB bits to our shared buffer
        //ByteBuffer buffer = image.getPlanes()[0].getBuffer();// jpg default format
        //byte[] frame_bytes = getByteArrayFromByteBuffer(buffer);
        // String base64_before = frame.GetBase64String().GetCStr();
        frame.Rotate90(rotationTimes);
        //String base64_after = frame.GetBase64String().GetCStr();
        frame.Crop(crop_rect);
        // Recognize image
        image.close();

        return frame;
    }

    public static Image SEImageFromJPG(@NonNull ImageProxy image) {

        // image.getFormat();
        // Jpeg format. Compressed data. Row and pixel strides are 0.
        // https://developer.android.com/reference/android/media/Image#getFormat()

        ByteBuffer buffer = image.getPlanes()[0].getBuffer(); // jpg
        byte[] frame_bytes = new byte[buffer.remaining()];
        buffer.get(frame_bytes);
        Image frame = Image.FromFileBuffer(frame_bytes);
        //String base64_after = frame.GetBase64String().GetCStr();

        image.close();
        return frame;
    }

    public static Image SEImageFromBitmap(@NonNull Bitmap bitmap) {

        ByteBuffer byteBuffer = ByteBuffer.allocate(bitmap.getByteCount());
        bitmap.copyPixelsToBuffer(byteBuffer);
        byteBuffer.rewind();

        // Prepare for FromBufferExtended()
        byte[] bytes = byteBuffer.array();
        int stride = bitmap.getRowBytes();
        int height = bitmap.getHeight();
        int width = bitmap.getWidth();

        // Bitmap.getConfig() return ARGB_8888 pixel format. The channel order of ARGB_8888 is RGBA!
        Image frame = Image.FromBufferExtended(bytes, width, height, stride, ImagePixelFormat.IPF_RGBA, 1);
        //String base64_after = frame.GetBase64String().GetCStr();
        return frame;
    }

    public static Image SEImageFromByteArray(@NonNull byte[] bytes) {
        return Image.FromFileBuffer(bytes);
    }

    private static byte[] getByteArrayFromByteBuffer(ByteBuffer byteBuffer, int rowStride, int height) {

        /**
         *  For raw formats, each plane is only guaranteed to contain data up to the last pixel
         *  in the last row. The stride after the last row may not be mapped into the buffer.
         *  This is a necessary requirement for any interleaved format.
         *  https://developer.android.com/reference/android/media/Image.Plane#getBuffer()
         */

        int bufferSize = byteBuffer.remaining();
        // The byte array size is stride * height (the leftover spaces will be filled with 0 bytes)
        byte[] bytesArray = new byte[height * rowStride];
        byteBuffer.get(bytesArray, 0, bufferSize);
        return bytesArray;
    }



    private Bitmap imageProxyToBitmap(ImageProxy image) {
        ImageProxy.PlaneProxy planeProxy = image.getPlanes()[0];
        ByteBuffer buffer = planeProxy.getBuffer();
        byte[] bytes = new byte[buffer.remaining()];
        buffer.get(bytes);

        return BitmapFactory.decodeByteArray(bytes, 0, bytes.length);
    }

}

