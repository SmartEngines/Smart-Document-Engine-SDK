/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

package com.smartengines.kotlin_sample.targets

import android.util.Log
import com.smartengines.core.engine.Engine
import com.smartengines.core.engine.doc.DocEngineWrapper

private const val TAG = "myapp.DocTargetList"

object DocTargetList {
    fun loadTargets(engine: Engine): List<AppTarget> {
        val docEngine = (engine as DocEngineWrapper).docEngine
        return ArrayList<AppTarget>().apply {
            val sessionSettings = docEngine.CreateSessionSettings()
            // SUPPORTED MODES loop
            val modesIterator = sessionSettings.SupportedModesBegin()
            val modesEnd = sessionSettings.SupportedModesEnd()
            while (!modesIterator.Equals(modesEnd)) {
                val mode = modesIterator.GetValue()
                Log.w(TAG, " --- $mode")

                // Set current mode
                sessionSettings.SetCurrentMode(mode)

                // DOC MASKS loop
                val docMasksIterator = sessionSettings.PermissiblePrefixDocMasksBegin()
                val docMasksEnd = sessionSettings.PermissiblePrefixDocMasksEnd()
                while (!docMasksIterator.Equals(docMasksEnd)) {
                    val mask = docMasksIterator.GetValue()
                    Log.w(TAG, "    --- $mask")

                    // Add a new target
                    add(
                        DocTarget(
                            mode = mode,
                            mask = mask
                        )
                    )

                    // Next doc type
                    docMasksIterator.Advance()
                }

                // Next mode
                modesIterator.Advance()
            }
        }
    }

}