//  Copyright (c) 2016-2025, Smart Engines Service LLC
//  All rights reserved.

package com.module.lib;

import android.content.Context;
import android.content.res.AssetManager;
import android.util.Log;

import androidx.lifecycle.MutableLiveData;

import com.smartengines.common.StringsSetIterator;
import com.smartengines.common.StringsVectorIterator;
import com.smartengines.doc.DocEngine;
import com.smartengines.doc.DocSessionSettings;


import org.json.JSONObject;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.TimeUnit;

/**
 * Engine helper class
 * Implements engine loading. Singleton only!
 * Exposes the engine loading state as a LiveData.
 */
public class Engine {
  private static final String TAG = "myapp.Engine";
  private static com.smartengines.doc.DocEngine instance = null;
  private static long startTime;
  public static long totalTime;

  public enum LoadingState {Empty, Loading, Ready, Error}

  ;
  public static MutableLiveData<LoadingState> loadingState = new MutableLiveData<>(LoadingState.Empty);

  public static String error = null;

  // Get instance already initiated
  public static com.smartengines.doc.DocEngine getInstance() {
    return instance;
  }

  /**
   * Load instance without blocking UI. Typically used for native platform
   */
  public static void loadAsync(Context context) {
    if (loadingState.getValue() == LoadingState.Empty) {
      new Thread(() -> initEngine(context)).start();
    }
  }

  /**
   * Load instance synchronously.
   * Typically used for Flutter/ React Native where synchronous call does not block the UI
   */
  public static void loadSync(Context context) {
    if (loadingState.getValue() == LoadingState.Empty) {
      initEngine(context);
    }
  }


  // ============================= PRIVATE =============================

  /**
   * Load required data from local file system
   * and create the Instance object as result.
   *
   * @param context - the application context for file reading operations
   */

  private static void initEngine(Context context) {

    try {
      // Benchmark
      startTime = System.nanoTime();

      loadingState.postValue(LoadingState.Loading);
      // Load library
      System.loadLibrary("jnidocengine");

      // Load config file
      byte[] config_data = loadConfigFile(context);

      // Create Engine instance
      instance = com.smartengines.doc.DocEngine.Create(config_data, true);
      loadingState.postValue(LoadingState.Ready);
      Log.i(TAG, "Engine instance created successfully");

      long elapsedTime = System.nanoTime() - startTime;
      totalTime = TimeUnit.MILLISECONDS.convert(elapsedTime, TimeUnit.NANOSECONDS);
      Log.i("Init engine: ", "Engine load time: " + totalTime + " ms");

    } catch (UnsatisfiedLinkError e) {
      Log.e(TAG, "Native library not found", e);
      error = e.getMessage();
      loadingState.postValue(LoadingState.Error);
    } catch (Exception e) {
      Log.e(TAG, "Load engine", e);
      error = e.getMessage();
      loadingState.postValue(LoadingState.Error);
    }

  }

  /**
   * Load the content of your config file (it should be in assets/config folder)
   *
   * @param context - the application context
   * @return the file content as array of bytes
   * @throws IOException
   */

  private static byte[] loadConfigFile(Context context) throws IOException {
    AssetManager assetManager = context.getAssets();
    String[] fileList = assetManager.list("data");
    String configFilename = null;

    for (String file : fileList) {
      if (file.endsWith(".se")) {
        configFilename = file;
        break;
      }
    }

    if (configFilename == null) {
      throw new IOException("configuration file is not found");
    }

    try (InputStream is = assetManager.open("data" + File.separator + configFilename);
         ByteArrayOutputStream os = new ByteArrayOutputStream()) {
      byte[] buffer = new byte[0xFFFF];
      int len;
      while ((len = is.read(buffer)) != -1) {
        os.write(buffer, 0, len);
      }
      return os.toByteArray();
    }
  }

  /**
   * Return Array of document list.
   * Often used to create a selector UI element in samples
   *
   * @return String[]
   */

  public static String[] getDocumentsList() {

    List<String> documents = new ArrayList<>();
    DocEngine engine = getInstance();
    DocSessionSettings sessionSettings = engine.CreateSessionSettings();

    for (StringsVectorIterator mt = sessionSettings.SupportedModesBegin(); !mt
            .Equals(sessionSettings.SupportedModesEnd()); mt.Advance()) {

      sessionSettings.SetCurrentMode(mt.GetValue());

      for (StringsSetIterator dt = sessionSettings.PermissiblePrefixDocMasksBegin();
           !dt.Equals(sessionSettings.PermissiblePrefixDocMasksEnd());
           dt.Advance()) {
        documents.add(mt.GetValue() + ':' + dt.GetValue());
      }
    }

    String[] array = new String[documents.size()];
    documents.toArray(array);

    return array;
  }

  /**
   * Return Array of Supported Session Types.
   *
   * @return List<String>
   */

  public static List<String> getSessionTypes() {
    List<String> sessionTypes = new ArrayList<>();
    JSONObject engineJson;
    try {

    } catch (Exception e) {
      throw new RuntimeException(e);
    }
    return sessionTypes;
  }
}

