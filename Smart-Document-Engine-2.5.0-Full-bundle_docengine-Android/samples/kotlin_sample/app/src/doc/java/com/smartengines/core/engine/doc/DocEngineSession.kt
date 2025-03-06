/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

package com.smartengines.core.engine.doc

import android.graphics.Bitmap
import android.util.Log
import com.smartengines.common.Image
import com.smartengines.core.engine.Quad
import com.smartengines.core.engine.Session
import com.smartengines.core.engine.common.Utils
import com.smartengines.doc.DocEngine
import com.smartengines.doc.DocSession
import com.smartengines.doc.DocSessionSettings

import kotlinx.coroutines.flow.Flow

private const val TAG = "myapp.DocEngineSession"

class DocEngineSession(
    docEngine : DocEngine,
    sessionSettings: DocSessionSettings,
    signature : String
) : Session {
    val docSession : DocSession

    override var isEnded: Boolean = false
    override var isTerminal: Boolean = false
    override val isSelfieCheckRequired: Boolean = false
    override val quadsPrimary  : Flow<Set<Quad>>? = null
    override val quadsSecondary: Flow<Set<Quad>>? = null
    override val instruction   : Flow<String>? = null
    init {
        // Create session
        docSession = docEngine.SpawnSession(sessionSettings,signature)
    }


    override fun processImage(bitmap: Bitmap) {
        val image: Image = Utils.imageFromBitmap(bitmap)
        // Create processing settings
        val processingSettings = docSession.CreateProcessingSettings()

        // Register image
        val imageId = docSession.RegisterImage(image)

        // Set image as source
        processingSettings.SetCurrentSourceID(imageId)

        // Process image
        docSession.Process(processingSettings)

        // Set finished flag (one-shot session)
        isEnded = true
        isTerminal = true

        Log.d(TAG, "processImage finished, doc count: ${docSession.GetCurrentResult().GetDocumentsCount()}")
    }

}