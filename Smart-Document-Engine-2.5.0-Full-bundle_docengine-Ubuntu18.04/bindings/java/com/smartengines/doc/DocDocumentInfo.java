/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (https://www.swig.org).
 * Version 4.1.1
 *
 * Do not make changes to this file unless you know what you are doing - modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.smartengines.doc;

import com.smartengines.common.*;

public class DocDocumentInfo {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  public DocDocumentInfo(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  public static long getCPtr(DocDocumentInfo obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  public static long swigRelease(DocDocumentInfo obj) {
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
        jnidocengineJNI.delete_DocDocumentInfo(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public String GetDocumentName() {
    return jnidocengineJNI.DocDocumentInfo_GetDocumentName(swigCPtr, this);
  }

  public String GetDocumentNameLocal() {
    return jnidocengineJNI.DocDocumentInfo_GetDocumentNameLocal(swigCPtr, this);
  }

  public String GetDocumentShortNameLocal() {
    return jnidocengineJNI.DocDocumentInfo_GetDocumentShortNameLocal(swigCPtr, this);
  }

  public boolean GetDocumentMultipageInfo() {
    return jnidocengineJNI.DocDocumentInfo_GetDocumentMultipageInfo(swigCPtr, this);
  }

  public boolean GetDocumentNoFields() {
    return jnidocengineJNI.DocDocumentInfo_GetDocumentNoFields(swigCPtr, this);
  }

  public DocDocumentFieldsInfoIterator DocumentFieldsInfoBegin() {
    return new DocDocumentFieldsInfoIterator(jnidocengineJNI.DocDocumentInfo_DocumentFieldsInfoBegin(swigCPtr, this), true);
  }

  public DocDocumentFieldsInfoIterator DocumentFieldsInfoEnd() {
    return new DocDocumentFieldsInfoIterator(jnidocengineJNI.DocDocumentInfo_DocumentFieldsInfoEnd(swigCPtr, this), true);
  }

}
