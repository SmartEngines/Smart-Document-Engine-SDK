//  Copyright (c) 2016-2024, Smart Engines Service LLC
//  All rights reserved.

package com.smartengines;

import android.util.Base64;
import android.util.Log;

import com.smartengines.common.SerializationParameters;
import com.smartengines.common.Serializer;
import com.smartengines.common.StringsMapIterator;
import com.smartengines.doc.DocCheckboxFieldsIterator;
import com.smartengines.doc.DocGraphicalStructure;
import com.smartengines.doc.DocImageFieldsIterator;
import com.smartengines.doc.DocObjectsCollectionsIterator;
import com.smartengines.doc.DocResult;
import com.smartengines.doc.DocTableField;
import com.smartengines.doc.DocTableFieldsIterator;
import com.smartengines.doc.DocTextField;
import com.smartengines.doc.DocTextFieldsIterator;
import com.smartengines.doc.DocViewsSliceIterator;
import com.smartengines.doc.Document;
import com.smartengines.doc.DocumentsIterator;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

public class ResultStore {

    /**
     * Result fields
     */
    public static class DocumentData {
        public String docType = "";
        public Map<String, String> docAttr;

        public Map<String, FieldInfo<String>> fields;
        public Map<String, FieldInfo<String>> images;
        public Map<String, FieldInfo<String>> checkboxes;
        public Map<String, FieldInfo<ArrayList<Object>>> tables;
        public Map<String, String> template; // custom data
        public DocumentData(String docType,
                            Map<String, String> docAttr,
                            Map<String, FieldInfo<String>> fields,
                            Map<String, FieldInfo<String>> images,
                            Map<String, FieldInfo<String>> checkboxes,
                            Map<String, FieldInfo<ArrayList<Object>>> tables) {

            this.docAttr = docAttr;
            this.docType = docType;
            this.fields = fields;
            this.tables = tables;
            this.checkboxes = checkboxes;
            this.images = images;
        }

        public DocumentData(Map<String,String> template) {
            this.template = template;

        }
    }

    /**
     * Document fields
     */
    public static class FieldInfo<T> {
        // String or Arraylist
        public final T value;
        public String key;
        public boolean isAccepted;
        public Map<String, String> attr;

        // Text fields, forensics
        FieldInfo(String key, final T value, final boolean accepted, final Map<String, String> attr) {
            this.key = key; // we duplicate the key name for object universality. React, Flutter...
            this.value = value;
            this.isAccepted = accepted;
            this.attr = attr;
        }

        // Image fields
        FieldInfo(String key,final T value, final Map<String, String> attr) {
            this.key = key;
            this.value = value;
            this.attr = attr;
        }


    }

    public static class TableCell
    {
        public String value;
        public boolean isAccepted;
        public TableCell(String value,  boolean isAccepted) {
            this.value = value;
            this.isAccepted = isAccepted;

        }
    }
    /*
     * ====================================================================
     * ===================== ResultStore Storage ==========================
     * ====================================================================
     */

    public static final ResultStore instance = new ResultStore();
    private static int docCount = 0;
    private static final ArrayList<DocumentData> resultFolder = new ArrayList<>();


    /*
     * ====================================================================
     * ===================== ResultStore Methods ==========================
     * ====================================================================
     */

    public void addResult(DocResult result) {

        resetStore();

        // Checking if some documents are found
        if (result.GetDocumentsCount() > 0) {

            docCount = result.GetDocumentsCount();

            // Result for crop and crop_advanced modes.
            // Crop: finds, cuts.
            // Crop_advanced: finds, cuts, and corrects document rotation.

            if (SettingsStore.currentMode.equals("crop") || SettingsStore.currentMode.equals("crop_advanced")) {

                DocGraphicalStructure graphical = result.GetGraphicalStructure();
                for (DocObjectsCollectionsIterator it = graphical.ObjectsCollectionsBegin();
                     !it.Equals(graphical.ObjectsCollectionsEnd());
                     it.Advance()) {

                    Map<String, String> document = new HashMap<>();

                    if (it.GetObjectsCollection().ObjectType().equals("template")) {
                        if (it.GetObjectsCollection().GetObjectsCount() > 0) {
                            SerializationParameters ser_params = new SerializationParameters();
                            Serializer serializer = Serializer.CreateJSONSerializer(ser_params);
                            it.GetObjectsCollection().BasicObjectsBegin().GetBasicObject()
                                    .GetBaseObjectInfo().GetGeometry().Serialize(serializer);

                            document.put("template", serializer.GetCStr());

                            DocViewsSliceIterator finalViewsIter = result.GetGraphicalStructure()
                                    .GetViewsCollection().ViewsSlice("final");
                            if (!finalViewsIter.Finished()) {
                                String value = finalViewsIter.GetView().GetImage().GetBase64String().GetCStr();
                                document.put("template_image", value);
                            }

                            resultFolder.add( new DocumentData(document));
                            break;
                        }
                    }
                }
            }

            // Document recognition result

            // Information about finds templates
            // DocGraphicalStructure graphical = result.GetGraphicalStructure();
            // documentFolder.put("collections", graphical.GetCollectionsCount());
            // documentFolder.put("views", graphical.GetViewsCollection().GetViewsCount());

            // DocDocumentInfo doc_info = sessionSettings.GetDocumentInfo(doc.GetAttribute("type"));
            // document.put("id", doc_it.GetID());
            // document.put("docType", doc.GetAttribute("type"));
            // document.put("name", doc_info.GetDocumentName());
            // document.put("nameLocal", doc_info.GetDocumentNameLocal());
            // document.put("nameShort", doc_info.GetDocumentShortNameLocal());
            // document.put("isMultipage", doc_info.GetDocumentMultipageInfo());

            // Get text fields
            for (DocumentsIterator doc_it = result.DocumentsBegin(); !doc_it.Equals(result.DocumentsEnd()); doc_it.Advance()) {

                Document doc = doc_it.GetDocument();
                String docType = doc.GetAttribute("type");

                Map<String, String> docAttr = new HashMap<>(); // Document attr
                Map<String, FieldInfo<String>> fields = new HashMap<>();  // Document text fileds with attr
                Map<String, FieldInfo<String>> images = new HashMap<>();  // Document images with attr
                Map<String, FieldInfo<ArrayList<Object>>> tables = new HashMap<>(); // Document tables
                Map<String, FieldInfo<String>> checkboxes = new HashMap<>(); // Document checkboxes

                // Document attributes
                for (StringsMapIterator attr_it = doc.AttributesBegin();
                     !attr_it.Equals(doc.AttributesEnd());attr_it.Advance()) {
                    docAttr.put(attr_it.GetKey(), attr_it.GetValue());
                }

                //Text fields
                for (DocTextFieldsIterator f_it = doc.TextFieldsBegin(); !f_it.Equals(doc.TextFieldsEnd()); f_it.Advance()) {
                    //fields
                    String key = f_it.GetKey();
                    String val = f_it.GetField().GetOcrString().GetFirstString().GetCStr();
                    boolean is_accepted = f_it.GetField().GetBaseFieldInfo().GetAcceptFlag();

                    // attr
                    Map<String, String> attr = new HashMap<>();
                    for (StringsMapIterator attr_it = f_it.GetField().GetBaseFieldInfo().AttributesBegin();
                         !attr_it.Equals(f_it.GetField().GetBaseFieldInfo().AttributesEnd());
                         attr_it.Advance()) {
                        attr.put(attr_it.GetKey(), attr_it.GetValue());
                    }
                    fields.put(key, new FieldInfo<>(key, val, is_accepted, attr));
                }

                // Image fields
                for (DocImageFieldsIterator f_it = doc.ImageFieldsBegin();
                     !f_it.Equals(doc.ImageFieldsEnd());
                     f_it.Advance()) {

                    String key = f_it.GetKey();
                    String val = f_it.GetField().GetImage().GetBase64String().GetCStr();

                    // attr
                    Map<String, String> attr = new HashMap<>();
                    for (StringsMapIterator attr_it = f_it.GetField().GetBaseFieldInfo().AttributesBegin();
                         !attr_it.Equals(f_it.GetField().GetBaseFieldInfo().AttributesEnd());
                         attr_it.Advance()) {
                        attr.put(attr_it.GetKey(), attr_it.GetValue());
                    }

                    images.put(key, new FieldInfo<>(key,val, attr));
                }


                // tables
                for (DocTableFieldsIterator f_it = doc.TableFieldsBegin();
                     !f_it.Equals(doc.TableFieldsEnd());
                     f_it.Advance()) {

                    ArrayList<Object> t = new ArrayList<>();

                    String key = f_it.GetKey();
                    DocTableField field = f_it.GetField();
                    boolean is_accepted = field.GetBaseFieldInfo().GetAcceptFlag();

                    for (int i_row = 0; i_row < field.GetRowsCount(); i_row++) {
                        for (int i_col = 0; i_col <field.GetColsCount(); i_col++) {
                            DocTextField cell = field.GetCell(i_row, i_col);
                            //  cell and attr
                            TableCell table = new TableCell( cell.GetOcrString().GetFirstString().GetCStr(), is_accepted);
                            t.add(table);
                        }
                        tables.put(key, new FieldInfo<>(key, t, new HashMap<>()));
                    }
                }

                // Checkbox fields
                for (DocCheckboxFieldsIterator f_it = doc.CheckboxFieldsBegin();
                     !f_it.Equals(doc.CheckboxFieldsEnd());
                     f_it.Advance()) {

                    String key = f_it.GetField().GetBaseFieldInfo().GetName();
                    String val = String.valueOf(f_it.GetField().GetTickStatus());
                    boolean is_accepted = f_it.GetField().GetBaseFieldInfo().GetAcceptFlag();

                    // attr
                    Map<String, String> attr = new HashMap<>();
                    for (StringsMapIterator attr_it = f_it.GetField().GetBaseFieldInfo().AttributesBegin();
                         !attr_it.Equals(f_it.GetField().GetBaseFieldInfo().AttributesEnd());
                         attr_it.Advance()) {
                        attr.put(attr_it.GetKey(), attr_it.GetValue());
                    }
                    checkboxes.put(key, new FieldInfo<>(key, val, is_accepted, attr));
                }

                DocumentData document = new DocumentData(docType, docAttr, fields, images, checkboxes, tables);
                resultFolder.add(document);
            }
        }
    }

    private void resetStore() {
        resultFolder.clear();
        docCount = 0;
    }

    public int getDocCount() {
        return docCount;
    }

    public String getDocType(int index) {
        return resultFolder.get(index).docType;
    }
    public Map<String, String> getDocAttr(int index) {
        return resultFolder.get(index).docAttr;
    }
    public Map<String, FieldInfo<String>> getFields(int index) {
        return resultFolder.get(index).fields;
    }

    public Map<String, FieldInfo<String>> getImages(int index) {
        return resultFolder.get(index).images;
    }

    public Map<String, FieldInfo<String>> getCheckboxes(int index) {
        return resultFolder.get(index).checkboxes;
    }

    public Map<String, FieldInfo<ArrayList<Object>>> getTables(int index) {
        return resultFolder.get(index).tables;
    }

    public Map<String, String> getTemplate(int index) {
        return resultFolder.get(index).template;
    }

    // Decode base64 and save to local folder. JSON file will become much lighter.
    // React Native passes the json file from the native part with the images encoded
    // in base64 for quite a long time. Flutter doesn't have this problem.
    // Visually it works faster with base64 images. Tested on Mediatek Helio G95

    private String getUriAfterImageSave(String base64, String prefix) {
        // image name
        String filename = prefix + "-" + UUID.randomUUID().toString();
        String str = null;

        byte[] dd = Base64.decode(base64, 0);

        try {
            File createTempFile = File.createTempFile(
                    filename,
                    ".jpg",
                    null // if null it become as context.getCacheDir().
            );
            OutputStream fileOutputStream = new FileOutputStream(createTempFile);
            fileOutputStream.write(dd);
            fileOutputStream.close();
            str = createTempFile.getAbsolutePath();

        } catch (IOException e) {
            Log.e("Exception", "File write failed: " + e);
        }
        return str;
    }
}