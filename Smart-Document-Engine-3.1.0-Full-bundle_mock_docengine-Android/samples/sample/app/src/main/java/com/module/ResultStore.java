//  Copyright (c) 2016-2025, Smart Engines Service LLC
//  All rights reserved.

package com.module;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.util.Base64;

import com.smartengines.common.OcrString;
import com.smartengines.common.StringsMapIterator;
import com.smartengines.doc.DocBaseFieldInfo;
import com.smartengines.doc.DocImageField;
import com.smartengines.doc.DocImageFieldsIterator;
import com.smartengines.doc.DocResult;
import com.smartengines.doc.DocTableField;
import com.smartengines.doc.DocTableFieldsIterator;
import com.smartengines.doc.DocTextField;
import com.smartengines.doc.DocTextFieldsIterator;
import com.smartengines.doc.Document;
import com.smartengines.doc.DocumentsIterator;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Result store and parser
 */
public class ResultStore {
    //----------------------------------------------------------------------------------------------
    // STORAGE
    public static final ResultStore instance = new ResultStore();
    private ResultData resultData = null;

    //----------------------------------------------------------------------------------------------
    // INTERFACE
    public boolean isEmpty(){
        return resultData==null;
    }
    public void resetStore() {
        resultData = null;
    }
    public ResultData getResultData() {
        return resultData;
    }
    public void addResult(DocResult result) {
        resultData = parseDocResult(result);
    }

    //----------------------------------------------------------------------------------------------
    // DATA CLASSES
    /**
     * doc-engine result data
     * (parsed com.smartengines.doc.DocResult)
     */
    public static class ResultData {
        public List<DocumentData> documents;
        ResultData(List<DocumentData> documents){this.documents=documents;}
    }

    /**
     * Result document data
     * (parsed com.smartengines.doc.Document)
     */
    public static class DocumentData {
        public String                  docType;
        public Map<String, String>     docAttr;
        public Map<String, TextField>  fields;
        public Map<String, ImageField> images;
        public Map<String, TableField> tables;

        public DocumentData(String                  docType,
                            Map<String, String>     docAttr,
                            Map<String, TextField>  fields,
                            Map<String, ImageField> images,
                            Map<String, TableField> tables
        ) {this.docAttr = docAttr;this.docType = docType;this.fields = fields;this.tables = tables;this.images = images;}
    }

    /**
     * Common data of all document fields
     * (parsed DocBaseFieldInfo)
     */
    public static class FieldInfo {
        // String or Arraylist
        public String key;
        public boolean isAccepted;
        public Map<String, String> attr;

        FieldInfo(String key, final boolean accepted, final Map<String, String> attr) {
            this.key = key; // we duplicate the key name for object universality. React, Flutter...
            this.isAccepted = accepted;
            this.attr = attr;
        }
    }
    /**
     * Text document field
     * ( parsed DocTextField )
     */
    public static class TextField {
        public FieldInfo info;
        public String    value;
        TextField(FieldInfo info, String value){this.info=info; this.value=value;}
    }

    /**
     * Image document field
     * ( parsed DocImageField )
     */
    public static class ImageField {
        public FieldInfo info;
        public Bitmap value;
        ImageField(FieldInfo info, Bitmap value){this.info=info; this.value=value;}
    }

    /**
     * Table document field
     */
    public static class TableField {
        public FieldInfo           info;
        public List<List<String>>  rows;
        TableField(FieldInfo info, List<List<String>> rows){this.info=info; this.rows=rows;}
    }

    //----------------------------------------------------------------------------------------------
    // PARSERS
    private static ResultData parseDocResult(DocResult result) {
        if (result.GetDocumentsCount() == 0) return null;
        // Load documents
        ArrayList<DocumentData> documents = new ArrayList<>();
        DocumentsIterator iterator  = result.DocumentsBegin();
        DocumentsIterator end       = result.DocumentsEnd();
        while (!iterator.Equals(end)) {
            documents.add(
                parseDocument(iterator.GetDocument())
            );
            iterator.Advance();
        }
        return new ResultData(documents);
    }

    private static DocumentData parseDocument(Document document){
        return new DocumentData(
                document.GetType(),
                parseDocAttributes(document),
                parseTextFields(document),
                parseImageFields(document),
                parseTableFields(document)
        );
    }

    // ---------------------------------------------------
    // ATTRIBUTES
    private static Map<String,String> parseAttributes(
        StringsMapIterator iterator, StringsMapIterator end
    ){
        HashMap<String,String> attributes = new HashMap<>();
        while (!iterator.Equals(end)) {
            attributes.put(
                    iterator.GetKey(),
                    iterator.GetValue()
            );
            iterator.Advance();
        }
        return attributes;
    }
    private static Map<String,String> parseDocAttributes(Document document){
        return parseAttributes(
                document.AttributesBegin(),
                document.AttributesEnd()
        );
    }
    private static Map<String,String> parseFieldAttributes(DocBaseFieldInfo fieldInfo){
        return parseAttributes(
                fieldInfo.AttributesBegin(),
                fieldInfo.AttributesEnd()
        );
    }

    // ---------------------------------------------------
    // FIELD INFO
    private static FieldInfo parseFieldInfo(DocBaseFieldInfo fieldInfo){
        return new FieldInfo(
            fieldInfo.GetName(),
            fieldInfo.GetAcceptFlag(),
            parseFieldAttributes(fieldInfo)
        );
    }
    // ---------------------------------------------------
    // OCR String
    private static String parseOcrString(OcrString ocrString){
        return ocrString.GetFirstString().GetCStr();
    }

    // ---------------------------------------------------
    // TEXT FIELDS
    private static Map<String,TextField> parseTextFields(Document document){
        HashMap<String,TextField> map = new HashMap<>();
        DocTextFieldsIterator iterator = document.TextFieldsBegin();
        DocTextFieldsIterator end      = document.TextFieldsEnd();
        while (!iterator.Equals(end)) {
            map.put(
                iterator.GetKey(),
                parseTextField(iterator.GetField())
            );
            iterator.Advance();
        }
        return map;
    }
    private static TextField parseTextField(DocTextField field){
        return new TextField(
            parseFieldInfo(field.GetBaseFieldInfo()),
            parseOcrString(field.GetOcrString())
        );
    }

    //---------------------------------------------------
    // IMAGE FIELDS
    private static Map<String,ImageField> parseImageFields(Document document){
        HashMap<String,ImageField> map = new HashMap<>();
        DocImageFieldsIterator iterator = document.ImageFieldsBegin();
        DocImageFieldsIterator end      = document.ImageFieldsEnd();
        while (!iterator.Equals(end)) {
            map.put(
                    iterator.GetKey(),
                    parseImageField(iterator.GetField())
            );
            iterator.Advance();
        }
        return map;
    }
    private static ImageField parseImageField(DocImageField field){
        String base64String = field.GetImage().GetBase64String().GetCStr();
        byte[] base64Buf = Base64.decode(base64String, Base64.DEFAULT);
        return new ImageField(
                parseFieldInfo(field.GetBaseFieldInfo()),
                BitmapFactory.decodeByteArray(base64Buf, 0, base64Buf.length)
        );
    }
    //---------------------------------------------------
    // TABLE FIELDS
    private static Map<String,TableField> parseTableFields(Document document){
        HashMap<String,TableField> map = new HashMap<>();
        DocTableFieldsIterator iterator = document.TableFieldsBegin();
        DocTableFieldsIterator end      = document.TableFieldsEnd();
        while (!iterator.Equals(end)) {
            map.put(
                    iterator.GetKey(),
                    parseTableField(iterator.GetField())
            );
            iterator.Advance();
        }
        return map;
    }
    private static TableField parseTableField(DocTableField field){
        int colNum = field.GetColsCount();
        int rowNum = field.GetRowsCount();
        ArrayList<List<String>> rows = new ArrayList<>();
        for (int j = 0; j < rowNum; j++) {
            ArrayList<String> row = new ArrayList<>();
            for (int i = 0; i < colNum; i++) {
                DocTextField cell = field.GetCell(j,i);
                row.add(parseOcrString(cell.GetOcrString()));
            }
            rows.add(row);
        }
        return new TableField(
            parseFieldInfo(field.GetBaseFieldInfo()),
            rows
        );
    }
}