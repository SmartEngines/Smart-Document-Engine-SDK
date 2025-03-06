/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

package com.smartengines.kotlin_sample

import android.graphics.Bitmap
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.rememberScrollState
import androidx.compose.foundation.verticalScroll
import androidx.compose.material3.Card
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.remember
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.asImageBitmap
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import com.smartengines.core.engine.doc.Attribute
import com.smartengines.core.engine.doc.DocEngineSession
import com.smartengines.core.engine.doc.DocResultData
import com.smartengines.core.engine.doc.DocumentData
import com.smartengines.core.engine.doc.ImageField
import com.smartengines.core.engine.Session
import com.smartengines.core.engine.doc.TextField
import com.smartengines.core.engine.doc.parse
import com.smartengines.kotlin_sample.ui.theme.Kotlin_sampleTheme

/**
 * TAKE THE SESSION => GET AND SHOW THE CURRENT RESULT
 */

@Composable
fun DocResultScreen(session: Session) {
    val docResultData = remember{ (session as DocEngineSession).docSession.GetCurrentResult().parse() }

    // Screen
    if(docResultData.isEmpty){
        NoResult()
    }else{
        DocResultScreen(resultData = docResultData)
    }
}

@Composable
private fun NoResult() {
    Text("Document not found")
}

@Composable
private fun DocResultScreen(resultData: DocResultData) {
    Box(modifier = Modifier.fillMaxSize(),
        contentAlignment = Alignment.TopStart
    ) {
        Column(
            modifier = Modifier
                .verticalScroll(rememberScrollState())
                .fillMaxWidth()
                .padding(horizontal = 10.dp),
            verticalArrangement = Arrangement.Top
        ) {
            resultData.cropBitmap?.let {
                CropScreen(it)
            }
            resultData.documents.forEach {
                DocumentScreen(it)
            }
        }
    }
}
@Composable
private fun CropScreen(bitmap:Bitmap){
    Section(text = "Crop result")
    Image(bitmap = bitmap.asImageBitmap(), contentDescription = null)
}
@Composable
fun DocumentScreen(document: DocumentData){
    with(document){
        Text(text = type)

        // ATTRIBUTES
        attributes.forEach{
            AttributeRow(it)
        }

        // TEXT FIELDS
        Section(text = "Text fields")
        textFields.forEach{
            TextFieldRow(it)
        }

        // IMAGES
        Section(text = "Images")
        images.forEach{
            ImageRow(imageField = it)
        }
    }
}
@Composable
private fun Section(text:String){
    Text(
        text = text,
        style = MaterialTheme.typography.headlineSmall,
        fontWeight = FontWeight.Bold,
        modifier = Modifier.padding(top = 20.dp)
    )
}

@Composable
private fun AttributeRow(attribute: Attribute) {
    with(attribute) {
        Row(Modifier.fillMaxWidth()) {
            Spacer(modifier = Modifier.weight(0.3f))
            Text(text = key,   style = MaterialTheme.typography.bodySmall, modifier = Modifier.weight(1f)  )
            Text(text = value, style = MaterialTheme.typography.bodySmall, modifier = Modifier.weight(1f), fontWeight = FontWeight.Bold    )
        }
    }
}

@Composable
private fun TextFieldRow(textField: TextField) {
    with(textField) {
        Card(Modifier.fillMaxWidth()){ Column(
            Modifier
                .fillMaxWidth()
                .padding(5.dp)) {
            // key + isAccepted
            Row(Modifier.fillMaxWidth()) {
                Text(text = key,
                    modifier = Modifier.weight(1f))
                Text(text = isAccepted.toString())
            }
            // Value
            Text(text = value, fontWeight = FontWeight.Bold)
            // Attributes
            attributes.forEach {
                AttributeRow(attribute = it)
            }
        }}
        Spacer(modifier = Modifier.height(8.dp))
    }
}
@Composable
private fun ImageRow(imageField: ImageField) {
    with(imageField) {
        Card(Modifier.fillMaxWidth()){ Column(
            Modifier
                .fillMaxWidth()
                .padding(5.dp)) {
            // key
            Text(text = key)
            // Value
            Image(bitmap = value.asImageBitmap(), contentDescription = "")
            // Attributes
            attributes.forEach {
                AttributeRow(it)
            }
        }
        }
        Spacer(modifier = Modifier.height(10.dp))
    }
}

//--------------------------------------------------------------------------------------------------
// PREVIEW
@Preview(showBackground = true, showSystemUi = false)
@Composable
private fun DataResultScreen_Preview() {
    val context = LocalContext.current
    Kotlin_sampleTheme {
        DocResultScreen(
            DocResultData(
                documents = listOf(
                    DocumentData(
                        type = "doc.type.sample",
                        attributes = listOf(
                            Attribute("ke1","value1"), Attribute("ke2","value2")
                        ),
                        textFields = listOf(
                            TextField("key", "Field value",
                                true,
                                attributes = listOf(Attribute("ke1","value1"), Attribute("ke2","value2"))
                            )
                        ),
                        images = emptyList()
                    )
                ),
                cropBitmap = null
            )
        )
    }
}
