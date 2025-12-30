//  Copyright (c) 2016-2025, Smart Engines Service LLC
//  All rights reserved.

package com.docengine_example;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.LinearLayout;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import com.module.ResultStore;
import com.module.lib.Engine;
import com.module.lib.Session;
import com.module.lib.Settings;

import com.smartengines.R;
import com.smartengines.common.Image;
import com.smartengines.doc.DocProcessingSettings;
import com.smartengines.doc.DocResult;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.Executors;

public class ExampleMainActivity extends AppCompatActivity {
    public static final String LIBRARY_NAME = "jnidocengine";
    public static final String SIGNATURE = "INSERT_SIGNATURE_FROM_README.html\";

    // Engine Instance of DocEngine
    public TextView resultTextField;
    TextView mask;
    LinearLayout resultView;
    ProgressBar progress;
    View panel;
    TextView version;

    public static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_example);

        try {
            // Load Controls
            resultView = findViewById(R.id.list);
            resultTextField = findViewById(R.id.info);
            progress = findViewById(R.id.progress);
            progress.setVisibility(View.INVISIBLE);
            panel = findViewById(R.id.panel);
            panel.setVisibility(View.INVISIBLE);
            mask = findViewById(R.id.mask);

            ImageButton selector = findViewById(R.id.selector);
            Button selectUpload = findViewById(R.id.gallery);
            Button selectCamera = findViewById(R.id.button_camera);
            version = findViewById(R.id.version);

            selector.setOnClickListener(v -> openSelector());
            selectCamera.setOnClickListener(v -> {
                resetRenderResult();
                // If mask is not defined
                if (mask.getText().toString().isEmpty()) {
                    showToast("Please select document");
                    return;
                }
                resetRenderResult();
                mStartCamera.launch(new Intent(this, ExampleCameraActivity.class));
            });

            selectUpload.setOnClickListener(v -> {
                resetRenderResult();
                // If mask is not defined
                if (mask.getText().toString().isEmpty()) {
                    showToast("Please select document");
                    return;
                }
                mUploadActivity.launch("image/*");
            });

            //resultTextField.setText("");

            Engine.loadingState.observe(this, loadingState -> {
                if (loadingState == Engine.LoadingState.Loading) {
                    resultTextField.setText("Engine loading...");
                } else if (loadingState == Engine.LoadingState.Ready) {
                    resultTextField.setText("Engine loaded: " + Engine.totalTime + "ms");
                    panel.setVisibility(View.VISIBLE);
                    version.setText("Version: " +  com.smartengines.doc.DocEngine.GetVersion());
                    runOnUiThread(this::onInitialized);
                } else if (loadingState == Engine.LoadingState.Error) {
                    resultTextField.setText("Engine init error");
                }
            });

            init();
            // Select default doc
//            final String[] documents = Engine.getDocumentsList();
//            if(documents.length>0)
//                selectDocument(documents[0]);

        } catch (Exception e) {
            showToast(e.getMessage());
        }
    }

    private void onInitialized() {

    }


    private void init() {
        // mask
        String[] mask = {"*"};
        ArrayList<String> strList = new ArrayList<>(Arrays.asList(mask));
        Settings.SetMask(strList);

        // options
        Map<String, String> options = new HashMap<>();
        options.put("common.sessionTimeout", "15.0");
        options.put("common.extractTemplateImages", "true");
        Settings.SetOptions(options);
        Settings.SetSignature(SIGNATURE);

        Engine.loadAsync(this);
    }

    ActivityResultLauncher<String> mUploadActivity = registerForActivityResult(new ActivityResultContracts.GetContent(),
            uri -> {
                resetRenderResult();

                if (uri == null) return;

                progress.setVisibility(View.VISIBLE);
                try {
                    Executors.newSingleThreadExecutor().execute(() -> {
                        try {
                            // Create image from uri
                            Image image = com.module.lib.Image.createFromUri(String.valueOf(uri), this);

                            Session.createImageSession();
                            // Create processing settings
                            DocProcessingSettings ps = Session.session.CreateProcessingSettings();
                            // Process image
                            Session.session.ProcessImage(image,ps);
                            // Get result
                            DocResult finalResult = Session.session.GetCurrentResult();
                            ResultStore.instance.addResult(finalResult);
                            runOnUiThread(this::renderResult);
                            Log.i(TAG, "===== Recognized =====");
                        } catch (Exception e) {
                            Log.e(TAG, "Recognition error", e);
                            resetRenderResult();
                            String err = (e.getMessage().length() >= 800) ? e.getMessage().substring(0, 800) : e.getMessage();
                            showToast(err);
                        } finally {
                            progress.setVisibility(View.INVISIBLE);
                        }
                    });
                } catch (Exception e) {
                    Log.e(TAG, "recognition error", e);
                    resetRenderResult();
                }
    });

    ActivityResultLauncher<Intent> mStartCamera = registerForActivityResult(new ActivityResultContracts.StartActivityForResult(),
            result -> {
                if (result.getResultCode() == Activity.RESULT_OK) {
                    renderResult();
                }
            });

    // Document camera activity
    public void resetRenderResult() {
        progress.setVisibility(View.INVISIBLE);
        resultTextField.setText("");
        resultView.removeAllViews();
    }

    public void renderResult() {
        // Check if document found
        if (ResultStore.instance.isEmpty()) {
            resultTextField.setText("Document not found");
        }else{
            new ExampleResultAdapter(
                resultView,
                (LayoutInflater) getSystemService(Context.LAYOUT_INFLATER_SERVICE),
                ResultStore.instance.getResultData())
           .loadResult();
        }
    }

    private void openSelector() {
        final String[] documents = com.module.lib.Engine.getDocumentsList();

        AlertDialog.Builder builder = new AlertDialog.Builder(ExampleMainActivity.this);
        builder.setTitle("Select mode:mask");
        builder.setItems(documents, (dialog, item) -> {
            String docMask = documents[item];
            selectDocument(docMask);
        });
        builder.setCancelable(true);
        AlertDialog alert = builder.create();
        alert.show();
    }

    private void selectDocument(String docMask){
        int separator = docMask.indexOf(':');
        String currentMode = docMask.substring(0, separator);
        String currentMask = docMask.substring(separator + 1);
        mask.setText(currentMode + ':' + currentMask);
        ArrayList<String> mask_from_menu = new ArrayList<>(Collections.singletonList(currentMask));
        Settings.SetMode(currentMode);
        Settings.SetMask(mask_from_menu);
    }

    void showToast(String message) {
        runOnUiThread(() -> {
            Toast t = Toast.makeText(ExampleMainActivity.this, message, Toast.LENGTH_LONG);
            t.setGravity(Gravity.CENTER, 0, 0);
            t.show();
        });
    }
}
