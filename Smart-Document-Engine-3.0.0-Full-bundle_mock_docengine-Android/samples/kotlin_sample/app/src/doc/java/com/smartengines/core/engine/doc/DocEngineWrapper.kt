/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

package com.smartengines.core.engine.doc

import com.smartengines.doc.DocEngine
import com.smartengines.core.engine.Engine
import com.smartengines.core.engine.Session
import com.smartengines.core.engine.SessionTarget
import com.smartengines.core.engine.SessionType

class DocEngineWrapper(
    private val signature : String
): Engine {
    lateinit var docEngine: DocEngine
        private set
    override val isVideoModeAllowed=false

    override fun createEngine(bundle: ByteArray?) {
        // Create SDK engine
        docEngine = if(bundle!=null) DocEngine.Create(bundle, true)
                                else DocEngine.CreateFromEmbeddedBundle(true)
    }

    override fun createSession(target: SessionTarget, sessionType: SessionType): Session {
        // Create new session settings object
        val sessionSettings = docEngine.CreateSessionSettings()
        // Fill by the target
        target.fillSessionSettings(sessionSettings)
        // Create session
        return DocEngineSession(docEngine, sessionSettings, signature)
    }
}
