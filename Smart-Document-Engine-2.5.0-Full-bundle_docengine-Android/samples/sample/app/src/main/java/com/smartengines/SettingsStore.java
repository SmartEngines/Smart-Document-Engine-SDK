//  Copyright (c) 2016-2024, Smart Engines Service LLC
//  All rights reserved.

package com.smartengines;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

// Store for Engines settings
public class SettingsStore {

    /*
     * ========================================================================
     * ========================== Core methods ==============================
     * ========================================================================
     */

    public static Map<String, String> options = new HashMap<>();
    public static String currentMode = "default";
    public static ArrayList<String> currentMask;
    public static String signature = null;

    // We use ArrayList due react-native supported data structure
    public static void SetMask(ArrayList<String> mask) {
        currentMask = mask;
    }

    public static void SetMode(String mode) {
        currentMode = mode;
    }

    public static void SetSignature(String sign) {
        signature = sign;
    }

    public static void SetOptions(Map<String, String> map) {
        options = map;
    }

    /*
     * ========================================================================
     * ======================== Custom methods ==============================
     * ========================================================================
     */

    public static Map<String, Integer> cropCoords = new HashMap<>();

}
