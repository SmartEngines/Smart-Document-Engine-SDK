//  Copyright (c) 2016-2025, Smart Engines Service LLC
//  All rights reserved.

package com.docengine_example;

import android.app.Activity;
import android.content.Context;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.util.Log;
import android.util.Rational;
import android.util.Size;
import android.view.View;
import android.view.ViewTreeObserver;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.camera.core.CameraSelector;
import androidx.camera.core.ImageCapture;
import androidx.camera.core.ImageCaptureException;
import androidx.camera.core.ImageProxy;
import androidx.camera.core.Preview;
import androidx.camera.core.UseCaseGroup;
import androidx.camera.core.ViewPort;
import androidx.camera.core.resolutionselector.ResolutionSelector;
import androidx.camera.core.resolutionselector.ResolutionStrategy;
import androidx.camera.lifecycle.ProcessCameraProvider;
import androidx.camera.view.PreviewView;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import com.google.common.util.concurrent.ListenableFuture;
import com.module.ResultStore;
import com.module.lib.Session;
import com.smartengines.R;
import com.smartengines.common.Image;
import com.smartengines.doc.DocProcessingSettings;


import java.util.concurrent.ExecutionException;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;

public class ExampleCameraActivity extends AppCompatActivity {
    private Executor executor;
    private final int REQUEST_CODE_PERMISSIONS = 1001;
    private final String[] REQUIRED_PERMISSIONS = new String[]{"android.permission.CAMERA"};
    PreviewView cameraView;
    View captureButton;
    Context context;
    View overlay;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_camera);
        executor = Executors.newSingleThreadExecutor();

        context = getBaseContext();
        cameraView = findViewById(R.id.viewFinder);
        captureButton = findViewById(R.id.captureButton);
        overlay = findViewById(R.id.overlay);
        overlay.setVisibility(View.INVISIBLE);


        if (allPermissionsGranted()) {

            /**
             * * For native Android projects you can call initCamera() without ViewTreeObserver().
             * * We use TreeObserver because of an issue with flutter! After the first call of this activity in flutter
             * * we get cameraView.getHeight() equal to 0 in all subsequent calls.
             * ** We must wait for the rendering of the cameraView to be completed.
             */
            cameraView.getViewTreeObserver().addOnGlobalLayoutListener(new ViewTreeObserver.OnGlobalLayoutListener() {
                @Override
                public void onGlobalLayout() {
                    cameraView.getViewTreeObserver().removeOnGlobalLayoutListener(this);
                    initCamera();
                }
            });
        } else {
            ActivityCompat.requestPermissions(this, REQUIRED_PERMISSIONS, REQUEST_CODE_PERMISSIONS);
        }
    }

    private void initCamera() {
        final ListenableFuture<ProcessCameraProvider> cameraProviderFuture = ProcessCameraProvider.getInstance(this);
        cameraProviderFuture.addListener(() -> {
            try {
                ProcessCameraProvider cameraProvider = cameraProviderFuture.get();
                bindPreview(cameraProvider);
            } catch (ExecutionException | InterruptedException e) {
                // No errors need to be handled for this Future.
                // This should never be reached.
            }
        }, ContextCompat.getMainExecutor(this));
    }

    void bindPreview(@NonNull ProcessCameraProvider cameraProvider) {

        int rotation = this.getWindowManager().getDefaultDisplay().getRotation();
        // Preview
        Preview preview = new Preview.Builder().build();
        // Attach the preview to UI
        preview.setSurfaceProvider(cameraView.getSurfaceProvider());
        // Camera
        CameraSelector cameraSelector = new CameraSelector.Builder()
                .requireLensFacing(CameraSelector.LENS_FACING_BACK)
                .build();

        // Create image capture
        ImageCapture imageCapture = new ImageCapture.Builder()
                .setCaptureMode(ImageCapture.CAPTURE_MODE_MAXIMIZE_QUALITY)
                .setResolutionSelector(
                        new ResolutionSelector.Builder()
                                .setResolutionStrategy(
                                        new ResolutionStrategy(new Size(2500, 2500),
                                                ResolutionStrategy.FALLBACK_RULE_CLOSEST_HIGHER_THEN_LOWER)
                                ).build())
                .setTargetRotation(rotation)
                .build();

        // ViewPort
        Rational aspectRatio = new Rational(cameraView.getWidth(), cameraView.getHeight());
        ViewPort viewPort = new ViewPort.Builder(aspectRatio, rotation).build();

        // Use case
        UseCaseGroup useCaseGroup = new UseCaseGroup.Builder()
                .addUseCase(preview)
                .addUseCase(imageCapture)
                .setViewPort(viewPort)
                .build();

        cameraProvider.unbindAll();
        cameraProvider.bindToLifecycle(this, cameraSelector, useCaseGroup);

        captureButton.setOnClickListener(v -> {
            // freeze last frame
            cameraProvider.unbind(preview);

            captureButton.setVisibility(View.INVISIBLE);
            overlay.setVisibility(View.VISIBLE);
            imageCapture.takePicture(executor, new ImageCapture.OnImageCapturedCallback() {
                @Override
                public void onCaptureSuccess(@NonNull ImageProxy image) {
                    Log.i("SMARTENGINES", "== onCaptureSuccess ==");
                    try {
                        Image frame = com.module.lib.Image.createFromImageProxy(image);

                        Session.createImageSession();
                        // Create processing settings
                        DocProcessingSettings ps = Session.session.CreateProcessingSettings();
                        // Process image
                        Session.session.ProcessImage(frame,ps);
                        // Get result
                        ResultStore.instance.addResult(Session.session.GetCurrentResult());

                        setResult(Activity.RESULT_OK);
                        finish();

                    } catch (Exception e) {
                        //error(e.getMessage());
                        Log.e("SMARTENGINES", "processing error", e);
                        setResult(Activity.RESULT_OK);
                        finish();
                    }
                }

                @Override
                public void onError(@NonNull ImageCaptureException exception) {
                    //super.onError(exception);
                    finish();
                }
            });
        });

    }

    private boolean allPermissionsGranted() {

        for (String permission : REQUIRED_PERMISSIONS) {
            if (ContextCompat.checkSelfPermission(this, permission) != PackageManager.PERMISSION_GRANTED)  return false;
        }
        return true;
    }

    @Override
    // Open the camera on for the first time after confirmation
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if (requestCode == REQUEST_CODE_PERMISSIONS) {
            if (allPermissionsGranted()) {
                initCamera();
            } else {
                Toast.makeText(this, "Permissions not granted by the user.", Toast.LENGTH_SHORT).show();
                //this.finish();
            }
        }
    }
}