//  Copyright (c) 2016-2025, Smart Engines Service LLC
//  All rights reserved.

package com.module.lib;

import static com.docengine_example.ExampleMainActivity.SIGNATURE;

import android.util.Log;


import com.smartengines.doc.DocSession;
import com.smartengines.doc.DocSessionSettings;

import org.json.JSONObject;
import org.json.JSONTokener;

import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Map;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;

import javax.net.ssl.HttpsURLConnection;

/**
 * SESSION helper class
 */
public class Session {
    static String TAG = "Session";
    public static long totalTime;

    // The session object
    public static DocSession session;

    // ==================================================================
    //                          SESSION CREATION
    // ==================================================================

    /**
     * Example of creating session for image recognition.
     * 1. Get Engine instance
     * 2. Create session
     * 3. Send file to Session
     * 4. Get first result
     * 5. Reset session
     */

    public static void createImageSession() {
        try {
            // Benchmark
            long startTime = System.nanoTime();

            // 1. Get engine instance
            com.smartengines.doc.DocEngine engine = Engine.getInstance();

            // 2. Create new session settings object
            DocSessionSettings docSettings = engine.CreateSessionSettings();
            docSettings.SetCurrentMode(Settings.currentMode);

            // 2.1 Set document mask
            ArrayList<String> docArray = Settings.currentMask;
            for (String name : docArray) {
                // System.out.println(name);
                docSettings.AddEnabledDocumentTypes(name);
            }
            // 2.2 Set custom options
            Map<String, String> map = Settings.options;
            for (Map.Entry<String, String> entry : map.entrySet()) {
                String key = entry.getKey();
                String value = entry.getValue();
                docSettings.SetOption(key, value);
            }

            // 3. Spawn recognition session
            session = engine.SpawnSession(docSettings, SIGNATURE);

            // Dynamic activation
            if (!session.IsActivated()) {
                String dynKey = session.GetActivationRequest();
                String actKey = getActivationKey(dynKey);
                session.Activate(actKey);
            }

            long elapsedTime = System.nanoTime() - startTime;
            totalTime = TimeUnit.MILLISECONDS.convert(elapsedTime, TimeUnit.NANOSECONDS);

            Log.i(TAG, "Create ImageSession time: " + totalTime);

        } catch (Exception e) {
            Log.e(TAG, "Create ImageSession error", e);
        }
    }

    // ===========================================================================

    private static String getActivationKey(String dynKey) {
        try {

            String apiKey = "YOUR_X_API_KEY_HERE";
            String actUrl = "https://dev.license.aihouse.am/api/v1/organization/sign_message/";

            String data = "{\"action\": \"activate_id_session\",  \"message\": \"" + dynKey + "\" }";
            System.out.printf("data is " + data + "\n");
            URL requestUrl = new URL(actUrl);

            HttpsURLConnection httpsURLConnection = (HttpsURLConnection) requestUrl.openConnection();
            httpsURLConnection.setConnectTimeout(4 * 1000);
            httpsURLConnection.setReadTimeout(4 * 1000);
            httpsURLConnection.setRequestMethod("POST");
            httpsURLConnection.setRequestProperty("Accept", "application/json");
            httpsURLConnection.setRequestProperty("Content-Type", "application/json");
            httpsURLConnection.setRequestProperty("X-API-Key", apiKey);
            httpsURLConnection.setRequestProperty("Charset", "UTF-8");
            httpsURLConnection.setRequestProperty("User-Agent", System.getProperty("http.agent"));
            httpsURLConnection.setUseCaches(false);
            httpsURLConnection.setDoOutput(true);

            byte[] message = data.getBytes(StandardCharsets.UTF_8);
            httpsURLConnection.setRequestProperty("Content-Length", "" + message.length);

            OutputStreamWriter out = new OutputStreamWriter(httpsURLConnection.getOutputStream(), StandardCharsets.UTF_8);
            out.write(data);
            out.flush();
            out.close();

            // If response is not successful
            if (httpsURLConnection.getResponseCode() != 200) {
                // Server exceptions
                String error;
                try (Scanner scanner = new Scanner(httpsURLConnection.getErrorStream())) {
                    String json = scanner.useDelimiter("\\A").next();
                    System.out.printf("json0 " + json + "\n");
                    JSONObject object = (JSONObject) new JSONTokener(json).nextValue();
                    error = object.getString("detail");
                }
                throw new RuntimeException(error);
            }

            InputStream response = httpsURLConnection.getInputStream();
            try (Scanner scanner = new Scanner(response)) {
                String json = scanner.useDelimiter("\\A").next();
                JSONObject object = (JSONObject) new JSONTokener(json).nextValue();
                return object.getString("message");
            }

        } catch (Exception e) {
            System.out.println(e);
            throw new RuntimeException("Network activation: " + e.getMessage());
        }
    }

}
