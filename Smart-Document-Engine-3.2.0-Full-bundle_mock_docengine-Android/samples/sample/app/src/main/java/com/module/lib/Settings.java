//  Copyright (c) 2016-2025, Smart Engines Service LLC
//  All rights reserved.

package com.module.lib;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/**
 * Store for Engine settings
 */
public class Settings {

    public static String                currentMode = "default";
    public static ArrayList<String>     currentMask;
    public static Map<String, String>   options = new HashMap<>();
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

}
