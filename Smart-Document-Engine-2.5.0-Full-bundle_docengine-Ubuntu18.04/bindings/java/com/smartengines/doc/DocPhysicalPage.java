/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (https://www.swig.org).
 * Version 4.1.1
 *
 * Do not make changes to this file unless you know what you are doing - modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.smartengines.doc;

import com.smartengines.common.*;

public class DocPhysicalPage {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  public DocPhysicalPage(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  public static long getCPtr(DocPhysicalPage obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  public static long swigRelease(DocPhysicalPage obj) {
    long ptr = 0;
    if (obj != null) {
      if (!obj.swigCMemOwn)
        throw new RuntimeException("Cannot release ownership as memory is not owned");
      ptr = obj.swigCPtr;
      obj.swigCMemOwn = false;
      obj.delete();
    }
    return ptr;
  }

  @SuppressWarnings("deprecation")
  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        jnidocengineJNI.delete_DocPhysicalPage(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public int GetSourceSceneID() {
    return jnidocengineJNI.DocPhysicalPage_GetSourceSceneID(swigCPtr, this);
  }

  public DocTextObjectsIterator TextObjectsBegin(String name) {
    return new DocTextObjectsIterator(jnidocengineJNI.DocPhysicalPage_TextObjectsBegin(swigCPtr, this, name), true);
  }

  public DocTextObjectsIterator TextObjectsEnd(String name) {
    return new DocTextObjectsIterator(jnidocengineJNI.DocPhysicalPage_TextObjectsEnd(swigCPtr, this, name), true);
  }

  public DocImageObjectsIterator ImageObjectsBegin(String name) {
    return new DocImageObjectsIterator(jnidocengineJNI.DocPhysicalPage_ImageObjectsBegin(swigCPtr, this, name), true);
  }

  public DocImageObjectsIterator ImageObjectsEnd(String name) {
    return new DocImageObjectsIterator(jnidocengineJNI.DocPhysicalPage_ImageObjectsEnd(swigCPtr, this, name), true);
  }

  public DocTableObjectsIterator TableObjectsBegin(String name) {
    return new DocTableObjectsIterator(jnidocengineJNI.DocPhysicalPage_TableObjectsBegin(swigCPtr, this, name), true);
  }

  public DocTableObjectsIterator TableObjectsEnd(String name) {
    return new DocTableObjectsIterator(jnidocengineJNI.DocPhysicalPage_TableObjectsEnd(swigCPtr, this, name), true);
  }

  public DocBarcodeObjectsIterator BarcodeObjectsBegin(String name) {
    return new DocBarcodeObjectsIterator(jnidocengineJNI.DocPhysicalPage_BarcodeObjectsBegin(swigCPtr, this, name), true);
  }

  public DocBarcodeObjectsIterator BarcodeObjectsEnd(String name) {
    return new DocBarcodeObjectsIterator(jnidocengineJNI.DocPhysicalPage_BarcodeObjectsEnd(swigCPtr, this, name), true);
  }

  public DocCheckboxObjectsIterator CheckboxObjectsBegin(String name) {
    return new DocCheckboxObjectsIterator(jnidocengineJNI.DocPhysicalPage_CheckboxObjectsBegin(swigCPtr, this, name), true);
  }

  public DocCheckboxObjectsIterator CheckboxObjectsEnd(String name) {
    return new DocCheckboxObjectsIterator(jnidocengineJNI.DocPhysicalPage_CheckboxObjectsEnd(swigCPtr, this, name), true);
  }

  public DocMetaObjectsIterator ForensicObjectsBegin(String name) {
    return new DocMetaObjectsIterator(jnidocengineJNI.DocPhysicalPage_ForensicObjectsBegin(swigCPtr, this, name), true);
  }

  public DocMetaObjectsIterator ForensicObjectsEnd(String name) {
    return new DocMetaObjectsIterator(jnidocengineJNI.DocPhysicalPage_ForensicObjectsEnd(swigCPtr, this, name), true);
  }

  public DocForensicCheckObjectsIterator ForensicCheckObjectsBegin(String name) {
    return new DocForensicCheckObjectsIterator(jnidocengineJNI.DocPhysicalPage_ForensicCheckObjectsBegin(swigCPtr, this, name), true);
  }

  public DocForensicCheckObjectsIterator ForensicCheckObjectsEnd(String name) {
    return new DocForensicCheckObjectsIterator(jnidocengineJNI.DocPhysicalPage_ForensicCheckObjectsEnd(swigCPtr, this, name), true);
  }

  public int GetTextObjectsCount(String name) {
    return jnidocengineJNI.DocPhysicalPage_GetTextObjectsCount(swigCPtr, this, name);
  }

  public int GetImageObjectsCount(String name) {
    return jnidocengineJNI.DocPhysicalPage_GetImageObjectsCount(swigCPtr, this, name);
  }

  public int GetTableObjectsCount(String name) {
    return jnidocengineJNI.DocPhysicalPage_GetTableObjectsCount(swigCPtr, this, name);
  }

  public int GetBarcodeObjectsCount(String name) {
    return jnidocengineJNI.DocPhysicalPage_GetBarcodeObjectsCount(swigCPtr, this, name);
  }

  public int GetCheckboxObjectsCount(String name) {
    return jnidocengineJNI.DocPhysicalPage_GetCheckboxObjectsCount(swigCPtr, this, name);
  }

  public int GetForensicObjectsCount(String name) {
    return jnidocengineJNI.DocPhysicalPage_GetForensicObjectsCount(swigCPtr, this, name);
  }

  public int GetForensicCheckObjectsCount(String name) {
    return jnidocengineJNI.DocPhysicalPage_GetForensicCheckObjectsCount(swigCPtr, this, name);
  }

  public boolean HasBasicObjects() {
    return jnidocengineJNI.DocPhysicalPage_HasBasicObjects(swigCPtr, this);
  }

  public Quadrangle GetPageQuadrangle() {
    return new Quadrangle(jnidocengineJNI.DocPhysicalPage_GetPageQuadrangle(swigCPtr, this), false);
  }

  public Polygon GetPagePolygon() {
    return new Polygon(jnidocengineJNI.DocPhysicalPage_GetPagePolygon(swigCPtr, this), false);
  }

  public DocTextObjectsIterator GetFulltextBasicObjectsBegin() {
    return new DocTextObjectsIterator(jnidocengineJNI.DocPhysicalPage_GetFulltextBasicObjectsBegin(swigCPtr, this), true);
  }

  public DocTextObjectsIterator GetFulltextBasicObjectsEnd() {
    return new DocTextObjectsIterator(jnidocengineJNI.DocPhysicalPage_GetFulltextBasicObjectsEnd(swigCPtr, this), true);
  }

  public Image GetPageImageFromScene(Image scene_image) {
    long cPtr = jnidocengineJNI.DocPhysicalPage_GetPageImageFromScene(swigCPtr, this, Image.getCPtr(scene_image), scene_image);
    return (cPtr == 0) ? null : new Image(cPtr, false);
  }

  public DocBasicObjectsIterator BasicObjectsBegin(String name) {
    return new DocBasicObjectsIterator(jnidocengineJNI.DocPhysicalPage_BasicObjectsBegin(swigCPtr, this, name), true);
  }

  public DocBasicObjectsIterator BasicObjectsEnd(String name) {
    return new DocBasicObjectsIterator(jnidocengineJNI.DocPhysicalPage_BasicObjectsEnd(swigCPtr, this, name), true);
  }

  public int GetBasicObjectsCount(String name) {
    return jnidocengineJNI.DocPhysicalPage_GetBasicObjectsCount(swigCPtr, this, name);
  }

}
