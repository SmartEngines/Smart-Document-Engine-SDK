/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (https://www.swig.org).
 * Version 4.1.1
 *
 * Do not make changes to this file unless you know what you are doing - modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.smartengines.doc;

import com.smartengines.common.*;

public class DocBarcodeObject extends DocBasicObject {
  private transient long swigCPtr;

  public DocBarcodeObject(long cPtr, boolean cMemoryOwn) {
    super(jnidocengineJNI.DocBarcodeObject_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  public static long getCPtr(DocBarcodeObject obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  public static long swigRelease(DocBarcodeObject obj) {
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
        jnidocengineJNI.delete_DocBarcodeObject(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public static String ObjectTypeStatic() {
    return jnidocengineJNI.DocBarcodeObject_ObjectTypeStatic();
  }

  public MutableString GetDecodedString() {
    return new MutableString(jnidocengineJNI.DocBarcodeObject_GetDecodedString(swigCPtr, this), false);
  }

  public MutableString GetMutableDecodedString() {
    return new MutableString(jnidocengineJNI.DocBarcodeObject_GetMutableDecodedString(swigCPtr, this), false);
  }

  public void SetDecodedString(MutableString decstring) {
    jnidocengineJNI.DocBarcodeObject_SetDecodedString(swigCPtr, this, MutableString.getCPtr(decstring), decstring);
  }

}
