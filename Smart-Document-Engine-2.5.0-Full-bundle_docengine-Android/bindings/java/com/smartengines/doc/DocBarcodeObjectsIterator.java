/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (https://www.swig.org).
 * Version 4.1.1
 *
 * Do not make changes to this file unless you know what you are doing - modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.smartengines.doc;

import com.smartengines.common.*;

public class DocBarcodeObjectsIterator {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  public DocBarcodeObjectsIterator(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  public static long getCPtr(DocBarcodeObjectsIterator obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  public static long swigRelease(DocBarcodeObjectsIterator obj) {
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
        jnidocengineJNI.delete_DocBarcodeObjectsIterator(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public DocBarcodeObjectsIterator(DocBarcodeObjectsIterator other) {
    this(jnidocengineJNI.new_DocBarcodeObjectsIterator(DocBarcodeObjectsIterator.getCPtr(other), other), true);
  }

  public DocBarcodeObject GetBarcodeObject() {
    return new DocBarcodeObject(jnidocengineJNI.DocBarcodeObjectsIterator_GetBarcodeObject(swigCPtr, this), false);
  }

  public DocBarcodeObject GetBarcodeObjectPtr() {
    long cPtr = jnidocengineJNI.DocBarcodeObjectsIterator_GetBarcodeObjectPtr(swigCPtr, this);
    return (cPtr == 0) ? null : new DocBarcodeObject(cPtr, false);
  }

  public void Advance() {
    jnidocengineJNI.DocBarcodeObjectsIterator_Advance(swigCPtr, this);
  }

  public boolean Equals(DocBarcodeObjectsIterator rvalue) {
    return jnidocengineJNI.DocBarcodeObjectsIterator_Equals(swigCPtr, this, DocBarcodeObjectsIterator.getCPtr(rvalue), rvalue);
  }

}
