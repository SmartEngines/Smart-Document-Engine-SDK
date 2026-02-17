/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

package com.smartengines.kotlin_sample

import androidx.compose.runtime.Composable
import com.smartengines.core.engine.Engine
import com.smartengines.core.engine.EngineBundle
import com.smartengines.core.engine.Session
import com.smartengines.core.engine.doc.DocEngineWrapper
import com.smartengines.kotlin_sample.targets.AppTarget
import com.smartengines.kotlin_sample.targets.DocTargetList

object AppFactory {
    val jniLibrary = "jnidocengine"
    val bundle     = EngineBundle.FirstFound("data", ".se")

    fun createEngineWrapper(signature:String) : Engine = DocEngineWrapper(signature)

    val loadTargetList:(Engine)->List<AppTarget> = DocTargetList::loadTargets

    val ResultScreen : @Composable (Session)->Unit = { DocResultScreen(session = it)}

}