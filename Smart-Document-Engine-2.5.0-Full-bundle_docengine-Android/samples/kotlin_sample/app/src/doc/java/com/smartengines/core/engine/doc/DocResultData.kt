/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

package com.smartengines.core.engine.doc

import android.graphics.Bitmap

data class DocResultData(
    val documents : List<DocumentData>,
    val cropBitmap: Bitmap?
){
    val isEmpty : Boolean get() = documents.isEmpty() && cropBitmap==null
}

data class DocumentData(
    val type        : String,
    val attributes  : List<Attribute>,
    val textFields  : List<TextField>,
    val images      : List<ImageField>
)

data class Attribute(
    val key         : String,
    val value       : String
)

data class TextField(
    val key         : String,
    val value       : String,
    val isAccepted  : Boolean,
    val attributes  : List<Attribute>
)

data class ImageField(
    val key         : String,
    val value       : Bitmap,
    val attributes  : List<Attribute>
)
