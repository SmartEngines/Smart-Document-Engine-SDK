/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

package com.smartengines.kotlin_sample.targets

import com.smartengines.doc.DocSessionSettings

data class DocTarget(
    val mode : String,
    val mask : String
) : AppTarget {
    override val name: String
        get() = "$mode : $mask"
    override val description: String?
        get() = null
    override val cropImage: Boolean
        get() = false

    override fun fillSessionSettings(sessionSettings: Any) {
        with(sessionSettings as DocSessionSettings) {
            // Set common options
            SetOption("global.sessionTimeout", "15.0")

            // Engine-depending settings
            SetCurrentMode(mode)
            AddEnabledDocumentTypes(mask) // many masks could be set
        }
    }
}