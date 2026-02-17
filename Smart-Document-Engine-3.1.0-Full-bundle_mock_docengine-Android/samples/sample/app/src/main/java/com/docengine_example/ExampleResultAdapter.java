//  Copyright (c) 2016-2025, Smart Engines Service LLC
//  All rights reserved.

package com.docengine_example;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.GridLayout;
import android.widget.ImageView;
import android.widget.TextView;

import com.module.ResultStore;
import com.smartengines.R;

import java.util.Comparator;
import java.util.List;
import java.util.Map;

/**
 * Result data visualization.
 * Loads result data to a LinearLayout control
 */
public class ExampleResultAdapter {
    ViewGroup container ;
    LayoutInflater inflater;
    ResultStore.ResultData result;
    ExampleResultAdapter(ViewGroup container, LayoutInflater inflater, ResultStore.ResultData result){
        this.container = container;
        this.inflater = inflater;
        this.result = result;
    }

    public void loadResult(){
        // Clear container
        container.removeAllViews();

        // Iterate all docs
        for (ResultStore.DocumentData document : result.documents){
            loadDocument(document);
        }

    }
    private void loadDocument(ResultStore.DocumentData document) {
        // Header
        loadDocHeader(document);

        // Attributes
        loadSectionTitle("Attributes");
        loadAttributes(container, document.docAttr);



        // Text Fields
        if(!document.fields.isEmpty()) {
            loadSectionTitle("Text Fields");
            document.fields.values().stream()
                    .sorted(new TextFieldComparator())
                    .forEach(this::loadTextField);
        }

        // Image Fields
        if(!document.images.isEmpty()) {
            loadSectionTitle("Images");
            document.images.values().stream()
                    .sorted(new ImageFieldComparator())
                    .forEach(this::loadImageField);
        }

        // Table Fields
        if(!document.tables.isEmpty()) {
            loadSectionTitle("Tables");
            document.tables.values().stream()
                .sorted(new TableFieldComparator())
                .forEach(this::loadTableField);
        }
    }

    private void loadDocHeader(ResultStore.DocumentData document) {
        View view = inflater.inflate(R.layout.result_doc_header, null);
        ((TextView) view.findViewById(R.id.header)) .setText(document.docType);
        container.addView(view);
    }
    private void loadSectionTitle(String text) {
        View view = inflater.inflate(R.layout.result_section_title, null);
        ((TextView) view.findViewById(R.id.header)) .setText(text);
        container.addView(view);
    }
    private void loadAttributes(ViewGroup container, Map<String,String> attributes) {
        for (Map.Entry<String, String> attr : attributes.entrySet()) {
            View view = inflater.inflate(R.layout.result_row_attr, null);
            ((TextView) view.findViewById(R.id.key))    .setText(attr.getKey());
            ((TextView) view.findViewById(R.id.value))  .setText(attr.getValue());
            container.addView(view);
        }
    }
    private void loadTextField(ResultStore.TextField field) {
        View view = inflater.inflate(R.layout.result_row_field, null);
        ((TextView) view.findViewById(R.id.key))        .setText(field.info.key);
        ((TextView) view.findViewById(R.id.isAccepted)) .setText( String.valueOf(field.info.isAccepted) );
        ((TextView) view.findViewById(R.id.value))      .setText(field.value);
        loadAttributes(
            (ViewGroup) view.findViewById(R.id.attributes),
            field.info.attr
        );
        container.addView(view);
    }
    private void loadImageField(ResultStore.ImageField image) {
        View view = inflater.inflate(R.layout.result_row_image, null);
        ((TextView) view.findViewById(R.id.key))        .setText(image.info.key);
        ((ImageView) view.findViewById(R.id.imageView)) .setImageBitmap(image.value);
        loadAttributes(
                (ViewGroup) view.findViewById(R.id.attributes),
                image.info.attr
        );
        container.addView(view);
    }
    private void loadTableField(ResultStore.TableField table){
        View view = inflater.inflate(R.layout.result_row_table, null);
        // TITLE
        ((TextView) view.findViewById(R.id.key))        .setText(table.info.key);
        ((TextView) view.findViewById(R.id.isAccepted)) .setText( String.valueOf(table.info.isAccepted) );
        // ATTRIBUTES
        loadAttributes(
                (ViewGroup) view.findViewById(R.id.attributes),
                table.info.attr
        );

        // ROWS
        if(!table.rows.isEmpty()) {
            GridLayout grid = view.findViewById(R.id.grid);
            // Set grid size
            //grid.setRowCount(table.rows.size());
            grid.setColumnCount(table.rows.get(0).size()); // just by first row
            // Fill cells
            int i=0;
            for(List<String> row : table.rows) {
                i++;
                int j=0;
                for(String cell : row) {
                    j++;
                    Log.w("myapp.ResAdapter",i+" : "+j+" : "+cell);
                    TextView v = (TextView) inflater.inflate(R.layout.result_row_table_cell, null);
                    v.setText(cell);
                    grid.addView(v);
                }
            }
        }
        container.addView(view);
    }


    //----------------------------------------------------------------------------------------------
    // COMPARATORS
    private static class TextFieldComparator implements Comparator<ResultStore.TextField> {
        public int compare(ResultStore.TextField a, ResultStore.TextField b) {
            return a.info.key.compareTo(b.info.key);
        }
    }
    private static class ImageFieldComparator implements Comparator<ResultStore.ImageField> {
        public int compare(ResultStore.ImageField a, ResultStore.ImageField b) {
            return a.info.key.compareTo(b.info.key);
        }
    }
    private static class TableFieldComparator implements Comparator<ResultStore.TableField> {
        public int compare(ResultStore.TableField a, ResultStore.TableField b) {
            return a.info.key.compareTo(b.info.key);
        }
    }
}

