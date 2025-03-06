//  Copyright (c) 2016-2024, Smart Engines Service LLC
//  All rights reserved.

package com.docengine_example;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.ImageDecoder;
import android.os.Build;
import android.os.Bundle;
import android.provider.MediaStore;
import android.util.Log;
import android.util.Pair;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import com.smartengines.DocEngine;
import com.smartengines.ResultStore;
import com.smartengines.SettingsStore;
import com.smartengines.common.Image;
import com.smartengines.databinding.ActivityExampleBinding;
import com.smartengines.doc.DocResult;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.Executors;

public class ExampleMainActivity extends AppCompatActivity {

    Context context = this;
    // Engine Instance of DocEngine
    public TextView resultTextField;
    com.smartengines.DocEngine engine = new DocEngine();
    TextView mask;
    ListView listView;
    ExampleResultAdapter adapter;
    ProgressBar progress;
    private ActivityExampleBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        try {
            binding = ActivityExampleBinding.inflate(getLayoutInflater());
            View view = binding.getRoot();
            setContentView(view);

            context = getBaseContext();

            listView = binding.list;
            resultTextField = binding.info;
            progress = binding.progress;
            progress.setVisibility(View.INVISIBLE);
            mask = binding.mask;


            // ListView
            adapter = new ExampleResultAdapter(context);
            listView.setAdapter(adapter);

            ImageButton selector = binding.selector;
            Button selectUpload = binding.gallery;
            Button selectCamera = binding.buttonCamera;
            TextView version = binding.version;

            version.setText("Version: " + engine.getVersion(context));

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

            initSESettings();
            resultTextField.setText("");

        } catch (Exception e) {
            showToast(e.getMessage());
        }
    }

    private void initSESettings() {
        String signature = "INSERT_SIGNATURE_FROM_README.html\";
        SettingsStore.SetSignature(signature);

        // mask
        String[] mask = {"*"};
        ArrayList<String> strList = new ArrayList<>(Arrays.asList(mask));
        SettingsStore.SetMask(strList);

        // options
        Map<String, String> options = new HashMap<>();
        options.put("common.sessionTimeout", "15.0");
        options.put("common.extractTemplateImages", "true");
        SettingsStore.SetOptions(options);
    }

    ActivityResultLauncher<String> mUploadActivity = registerForActivityResult(new ActivityResultContracts.GetContent(),
            uri -> {
                resetRenderResult();

                if (uri == null) return;

                progress.setVisibility(View.VISIBLE);
                try {
                    // Get bitmap from file
                    Bitmap imageData;
                    if (Build.VERSION.SDK_INT >= 29) {
                        imageData = ImageDecoder.decodeBitmap(ImageDecoder.createSource(context.getContentResolver(), uri), (imageDecoder, imageInfo, source1) -> imageDecoder.setMutableRequired(true));
                    } else {
                        imageData = MediaStore.Images.Media.getBitmap(context.getContentResolver(), uri);
                    }

                    try {
                        Executors.newSingleThreadExecutor().execute(() -> {
                            try {
                                Image se_image = DocEngine.SEImageFromBitmap(imageData);
                                DocResult finalResult = DocEngine.recognizeImage(se_image, context);
                                ResultStore.instance.addResult(finalResult);

                                runOnUiThread(() -> {
                                    renderResult();
                                    progress.setVisibility(View.INVISIBLE);
                                });
                                Log.i("SMARTENGINES", "===== Recognized =====");
                            } catch (Exception e) {
                                Log.e("SMARTENGINES", e.getMessage());
                                resetRenderResult();
                                String err = (e.getMessage().length() >= 800) ? e.getMessage().substring(0, 800) : e.getMessage();
                                Toast t = Toast.makeText(getApplicationContext(), err, Toast.LENGTH_LONG);
                                t.show();
                                Log.e("SMARTENGINES", err);
                                // resultTextField.setText("Exception");
                            }
                        });
                    } catch (Exception e) {
                        resetRenderResult();
                        Log.d("SMARTENGINES", e.getMessage());
                    }
                } catch (IOException e) {
                    resetRenderResult();
                    resultTextField.setText(e.getMessage());
                    e.printStackTrace();
                }
            });

    ActivityResultLauncher<Intent> mStartCamera = registerForActivityResult(new ActivityResultContracts.StartActivityForResult(),
            result -> {
                if (result.getResultCode() == Activity.RESULT_OK) {
                    renderResult();
                    Log.i("SMARTENGINES", "Activity result");
                    // Handle the Intent
                }
            });

    // Document camera activity
    public void resetRenderResult() {
        progress.setVisibility(View.INVISIBLE);
        resultTextField.setText("");
        adapter.clear();
    }

    public void renderResult() {

        // Get count
        int docCount = ResultStore.instance.getDocCount();

        // Check if document found
        if (docCount == 0) {
            resultTextField.setText("Document not found");
            return;
        }

        // Iterate all documents
        for (int i = 0; i < docCount; ++i) {
            // Get data from store
            String docType = ResultStore.instance.getDocType(i);
            Map<String, String> docAttr = ResultStore.instance.getDocAttr(i);
            Map<String, ResultStore.FieldInfo<String>> fields = ResultStore.instance.getFields(i);
            Map<String, ResultStore.FieldInfo<String>> images = ResultStore.instance.getImages(i);
            Map<String, ResultStore.FieldInfo<ArrayList<Object>>> tables = ResultStore.instance.getTables(i);

            // TODO: checkboxes
            // Map<String, ResultStore.FieldInfo<String>> checkboxes = ResultStore.instance.getCheckboxes(i);

            // Add first section to result view
            adapter = new ExampleResultAdapter(context);
            // Put fields to result
            adapter.addSectionItem("Document Info", "section");
            adapter.addInfo(docAttr, "info");

            // Put fields to result
            adapter.addSectionItem(docType, "section");
            for (Map.Entry<String, ResultStore.FieldInfo<String>> set : fields.entrySet()) {
                adapter.addItem(set.getValue(), "field");
            }

            // Put images to result
            adapter.addSectionItem("Images", "section");
            for (Map.Entry<String, ResultStore.FieldInfo<String>> set : images.entrySet()) {
                adapter.addItem(set.getValue(), "image");
            }

            // Put tables to result
            adapter.addSectionItem("Tables", "section");
            for (String key : tables.keySet()) {
                ResultStore.FieldInfo<ArrayList<Object>> el = tables.get(key);
                adapter.addTableItem(el, "table");
            }
//            adapter.addSectionItem("Checkboxes", "section");
//            for (Map.Entry<String, ResultStore.FieldInfo<String>> set : checkboxes.entrySet()) {
//                adapter.addItem(set.getValue(), "checkbox");
//            }


        }
        listView.setAdapter(adapter);
        // resultTextField.setText(ResultStore.instance.getType());
    }

    private void openSelector() {
        final String[] documents = com.smartengines.DocEngine.getDocumentsList(context);

        AlertDialog.Builder builder = new AlertDialog.Builder(ExampleMainActivity.this);
        builder.setTitle("Select mode:mask");
        builder.setItems(documents, (dialog, item) -> {

            String docMask = documents[item];
            int separator = docMask.indexOf(':');
            String currentMode = docMask.substring(0, separator);
            String currentMask = docMask.substring(separator + 1);
            mask.setText(currentMode + ':' + currentMask);
            ArrayList<String> mask_from_menu = new ArrayList<>(Arrays.asList(currentMask));
            SettingsStore.SetMode(currentMode);
            SettingsStore.SetMask(mask_from_menu);
        });

        builder.setCancelable(true);
        AlertDialog alert = builder.create();
        alert.show();
    }

    void showToast(String message) {
        runOnUiThread(() -> {
            Toast t = Toast.makeText(context, message, Toast.LENGTH_LONG);
            t.setGravity(Gravity.CENTER, 0, 0);
            t.show();
        });
    }
}
