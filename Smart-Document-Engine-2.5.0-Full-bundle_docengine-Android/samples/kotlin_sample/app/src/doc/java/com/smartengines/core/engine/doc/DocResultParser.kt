/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

package com.smartengines.core.engine.doc

import android.graphics.Bitmap
import android.graphics.BitmapFactory
import android.util.Base64
import android.util.Log
import com.smartengines.common.StringsMapIterator
import com.smartengines.doc.DocBaseFieldInfo
import com.smartengines.doc.DocImageFieldsIterator
import com.smartengines.doc.DocResult
import com.smartengines.doc.Document

private const val TAG = "engine.DocResultParser"

/**
 * PARSE DocResult => DocResultData
 */
fun DocResult.parse(): DocResultData {
    return DocResultData(
        documents  = parseDocuments(),
        cropBitmap = parseCropBitmap()
    )
}

//--------------------------------------------------------------------------------------------------
// CROP bitmap
fun DocResult.parseCropBitmap():Bitmap?{
    try {
        with(GetGraphicalStructure()){
            val viewsIterator = GetViewsCollection().ViewsSlice("final")
            if(!viewsIterator.Finished()){
                val base64String = viewsIterator.GetView().GetImage().GetBase64String().GetCStr()
                val base64Buf = Base64.decode(base64String, Base64.DEFAULT)
                return BitmapFactory.decodeByteArray(base64Buf, 0, base64Buf.size)
            }
        }
    }catch (e:Exception){
        Log.e(TAG,"DocResult.parse()", e)
    }
    return null
}

//--------------------------------------------------------------------------------------------------
// DOCUMENTS
fun DocResult.parseDocuments():List<DocumentData>{
    return ArrayList<DocumentData>().apply {
        val iterator = DocumentsBegin()
        val end      = DocumentsEnd()
        while (!iterator.Equals(end)){
            add(
                iterator.GetDocument().parse()
            )
            iterator.Advance()
        }
    }
}

fun Document.parse(): DocumentData {
    return DocumentData(
        type        = GetType(),
        attributes  = parseAttributes(),
        textFields  = parseTextFields(),
        images      = parseImages()
    )
}

/**
 * PARSE Document => List<Attribute>
 */
fun Document.parseAttributes():List<Attribute>{
    return ArrayList<Attribute>().apply {
        val iterator = AttributesBegin()
        val end      = AttributesEnd()
        while (!iterator.Equals(end)) {
            add( iterator.parseAttribute() )
            iterator.Advance()
        }
    }
}

//--------------------------------------------------------------------------------------------------
// TEXT FIELDS
/**
 * PARSE Document => List < TextField >
 */
fun Document.parseTextFields():List<TextField>{
    return ArrayList<TextField>().apply {
        val iterator = TextFieldsBegin()
        val end      = TextFieldsEnd()
        while (!iterator.Equals(end)) {
            val field = iterator.GetField()
            add(
                TextField(
                    key   = iterator.GetKey(),
                    value = field.GetOcrString().GetFirstString().GetCStr(),
                    isAccepted = iterator.GetField().GetBaseFieldInfo().GetAcceptFlag(),
                    attributes = field.GetBaseFieldInfo().parseAttributes()
                )
            )
            iterator.Advance()
        }
    }
}
fun DocBaseFieldInfo.parseAttributes():List<Attribute>{
    return ArrayList<Attribute>().apply {
        val iterator = AttributesBegin()
        val end      = AttributesEnd()
        while(!iterator.Equals(end)){
            add(iterator.parseAttribute())
            iterator.Advance()
        }
    }
}

//--------------------------------------------------------------------------------------------------
// IMAGES
/**
 * IdResult => IMAGES
 */
fun Document.parseImages():List<ImageField>{
    return ArrayList<ImageField>().apply {
        val iterator = ImageFieldsBegin()
        val iterEnd  = ImageFieldsEnd()
        while (!iterator.Equals(iterEnd)) {
            try {
                add(iterator.parseImage())
            }catch(e:Exception){
                Log.e(TAG,"IdResult.parseImages",e)
            }
            iterator.Advance()
        }
    }
}
/**
 * PARSE IdTextFieldsMapIterator => ImageInfo
 */
fun DocImageFieldsIterator.parseImage(): ImageField {
    val field = GetField()
    val base64String = field.GetImage().GetBase64String().GetCStr()
    val base64Buf = Base64.decode(base64String, Base64.DEFAULT)
    return  ImageField(
        key         = GetKey(),
        value       = BitmapFactory.decodeByteArray(base64Buf, 0, base64Buf.size),
        attributes  = field.GetBaseFieldInfo().parseAttributes()
    )
}

//--------------------------------------------------------------------------------------------------
// Attribute
fun StringsMapIterator.parseAttribute(): Attribute {
    return Attribute(
        key   = GetKey(),
        value = GetValue()
    )
}


