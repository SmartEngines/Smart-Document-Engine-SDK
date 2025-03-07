/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (https://www.swig.org).
 * Version 4.1.1
 *
 * Do not make changes to this file unless you know what you are doing - modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.smartengines.doc;

import com.smartengines.common.*;

public class DocTextObjectsIterator {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  public DocTextObjectsIterator(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  public static long getCPtr(DocTextObjectsIterator obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  public static long swigRelease(DocTextObjectsIterator obj) {
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
        jnidocengineJNI.delete_DocTextObjectsIterator(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public DocTextObjectsIterator(DocTextObjectsIterator other) {
    this(jnidocengineJNI.new_DocTextObjectsIterator(DocTextObjectsIterator.getCPtr(other), other), true);
  }

  public DocTextObject GetTextObject() {
    return new DocTextObject(jnidocengineJNI.DocTextObjectsIterator_GetTextObject(swigCPtr, this), false);
  }

  public void Advance() {
    jnidocengineJNI.DocTextObjectsIterator_Advance(swigCPtr, this);
  }

  public boolean Equals(DocTextObjectsIterator rvalue) {
    return jnidocengineJNI.DocTextObjectsIterator_Equals(swigCPtr, this, DocTextObjectsIterator.getCPtr(rvalue), rvalue);
  }

}
