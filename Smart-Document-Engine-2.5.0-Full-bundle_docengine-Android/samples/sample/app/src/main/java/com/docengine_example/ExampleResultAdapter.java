//  Copyright (c) 2016-2024, Smart Engines Service LLC
//  All rights reserved.

package com.docengine_example;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.util.Base64;
import android.util.Pair;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

import com.smartengines.R;
import com.smartengines.ResultStore;

import java.util.ArrayList;
import java.util.Map;


public class ExampleResultAdapter extends BaseAdapter {
    private static final int TYPE_ITEM = 0;
    private static final int TYPE_SECTION = 1;
    private static final int TYPE_IMG = 2;
    private static final int TYPE_ITEM_CHECKBOX = 3;
    private static final int TYPE_ITEM_TABLES = 4;
    private static final int TYPE_INFO = 5;

    private Context _context;

    ArrayList<Object> mData = new ArrayList<>();
    ArrayList<String> types = new ArrayList<>();

    private LayoutInflater mInflater;

    public ExampleResultAdapter(Context context) {

        _context = context;
        mInflater = (LayoutInflater) context
                .getSystemService(Context.LAYOUT_INFLATER_SERVICE);
    }

    public void clear() {
        mData.clear();
        types.clear();
        notifyDataSetChanged();

    }

    public void addItem(ResultStore.FieldInfo<String> item, String type) {
        mData.add(item);
        types.add(type);
        notifyDataSetChanged();
    }

    public void addTableItem(ResultStore.FieldInfo<ArrayList<Object>> item, String type) {
        mData.add(item);
        types.add(type);
        notifyDataSetChanged();
    }

    public void addSectionItem(String item, String type) {
        mData.add(item);
        types.add(type);
        notifyDataSetChanged();
    }

    public void addInfo(Map<String, String> item, String type) {
        mData.add(item);
        types.add(type);
        notifyDataSetChanged();
    }

    @Override
    public int getItemViewType(int position) {

        switch (types.get(position)) {
            case "info":
                return TYPE_INFO;
            case "field":
                return TYPE_ITEM;
            case "section":
                return TYPE_SECTION;
            case "image":
                return TYPE_IMG;
            case "table":
                return TYPE_ITEM_TABLES;
        }
        return 0;
    }

    @Override
    public int getViewTypeCount() {
        return 6;
    }

    @Override
    public int getCount() {
        return mData.size();
    }

    @Override
    public Object getItem(int position) {
        return mData.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {

        int rowType = getItemViewType(position);
        System.out.println(rowType);

        // Choose template
        if (convertView == null) {

            switch (rowType) {
                case TYPE_SECTION:
                    convertView = mInflater.inflate(R.layout.result_header, null);
                    break;
                case TYPE_IMG:
                    convertView = mInflater.inflate(R.layout.result_row_image, null);
                    break;
                case TYPE_ITEM:
                case TYPE_INFO:
                case TYPE_ITEM_CHECKBOX:
                case TYPE_ITEM_TABLES:
                    convertView = mInflater.inflate(R.layout.result_row_field, null);
                    break;
            }
        }

        // Fill template
        switch (rowType) {
//            case TYPE_ITEM_CHECKBOX:
            case TYPE_ITEM:
                ResultStore.FieldInfo<String> el = (ResultStore.FieldInfo<String>) mData.get(position);

                ((TextView) convertView.findViewById(R.id.name)).setText(el.key);
                ((TextView) convertView.findViewById(R.id.val)).setText(el.value);
                ((TextView) convertView.findViewById(R.id.isAccepted)).setText(String.valueOf(el.isAccepted));

                LinearLayout l = convertView.findViewById(R.id.attributes);
                l.removeAllViews();

                for (Map.Entry<String, String> attr : el.attr.entrySet()) {
                    TextView at = new TextView(_context);
                    at.setText(attr.getKey() + ":" + attr.getValue());
                    at.setTextColor(Color.parseColor("#454545"));
                    at.setTextSize(10);
                    l.addView(at);
                }
                break;

            case TYPE_ITEM_TABLES:
                ResultStore.FieldInfo<ArrayList<Object>> tb = (ResultStore.FieldInfo<ArrayList<Object>>) mData.get(position);

                ((TextView) convertView.findViewById(R.id.val)).setText(tb.key);
                (convertView.findViewById(R.id.isAccepted)).setVisibility(View.GONE);
                (convertView.findViewById(R.id.name)).setVisibility(View.GONE);

                // cells
                LinearLayout lb = convertView.findViewById(R.id.attributes);
                lb.removeAllViews();

                for (int j = 0; j < tb.value.size(); j++) {
                    TextView at = new TextView(_context);
                    ResultStore.TableCell cell = (ResultStore.TableCell) tb.value.get(j);
                    //((TextView) convertView.findViewById(R.id.val)).setText(cell.value);
                    at.setText("cell value:" + cell.value);
                    at.setTextColor(Color.parseColor("#454545"));
                    at.setTextSize(16);
                    lb.addView(at);
                }
                break;
            case TYPE_INFO:
                Map<String, String> ti = (Map<String, String>) mData.get(position);

                (convertView.findViewById(R.id.val)).setVisibility(View.GONE);
                (convertView.findViewById(R.id.isAccepted)).setVisibility(View.GONE);
                (convertView.findViewById(R.id.name)).setVisibility(View.GONE);

                // cells
                LinearLayout li = convertView.findViewById(R.id.attributes);
                li.removeAllViews();

                for (Map.Entry<String, String> attr : ti.entrySet()) {
                    TextView at = new TextView(_context);
                    at.setText(attr.getKey() + ":" + attr.getValue());
                    at.setTextColor(Color.parseColor("#454545"));
                    at.setTextSize(16);
                    li.addView(at);
                }
                break;
            case TYPE_IMG:
                ResultStore.FieldInfo<String> img = (ResultStore.FieldInfo<String>) mData.get(position);

                ((TextView) convertView.findViewById(R.id.name)).setText(img.key);
                byte[] bytes = Base64.decode(img.value, Base64.DEFAULT);
                Bitmap bmp = BitmapFactory.decodeByteArray(bytes, 0, bytes.length);
                ((ImageView) convertView.findViewById(R.id.imageView)).setImageBitmap(bmp);

                LinearLayout ll = convertView.findViewById(R.id.imgAttributes);
                ll.removeAllViews();

                for (Map.Entry<String, String> attr : img.attr.entrySet()) {
                    TextView at = new TextView(_context);
                    at.setText(attr.getKey() + ":" + attr.getValue());
                    at.setTextColor(Color.parseColor("#454545"));
                    at.setTextSize(10);
                    ll.addView(at);
                }

                break;

            case TYPE_SECTION:
                ((TextView) convertView.findViewById(R.id.header)).setText((String) mData.get(position));
                break;
        }

        return convertView;
    }


}

