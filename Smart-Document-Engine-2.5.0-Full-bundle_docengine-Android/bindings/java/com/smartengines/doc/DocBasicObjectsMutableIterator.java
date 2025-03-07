/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (https://www.swig.org).
 * Version 4.1.1
 *
 * Do not make changes to this file unless you know what you are doing - modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.smartengines.doc;

import com.smartengines.common.*;

public class DocBasicObjectsMutableIterator {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  public DocBasicObjectsMutableIterator(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  public static long getCPtr(DocBasicObjectsMutableIterator obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  public static long swigRelease(DocBasicObjectsMutableIterator obj) {
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
        jnidocengineJNI.delete_DocBasicObjectsMutableIterator(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public DocBasicObjectsMutableIterator(DocBasicObjectsMutableIterator other) {
    this(jnidocengineJNI.new_DocBasicObjectsMutableIterator(DocBasicObjectsMutableIterator.getCPtr(other), other), true);
  }

  public int GetID() {
    return jnidocengineJNI.DocBasicObjectsMutableIterator_GetID(swigCPtr, this);
  }

  public DocBasicObject GetBasicObject() {
    return new DocBasicObject(jnidocengineJNI.DocBasicObjectsMutableIterator_GetBasicObject(swigCPtr, this), false);
  }

  public DocBasicObject GetMutableBasicObject() {
    return new DocBasicObject(jnidocengineJNI.DocBasicObjectsMutableIterator_GetMutableBasicObject(swigCPtr, this), false);
  }

  public DocTagsCollection GetTags() {
    return new DocTagsCollection(jnidocengineJNI.DocBasicObjectsMutableIterator_GetTags(swigCPtr, this), false);
  }

  public void Advance() {
    jnidocengineJNI.DocBasicObjectsMutableIterator_Advance(swigCPtr, this);
  }

  public boolean Equals(DocBasicObjectsMutableIterator rvalue) {
    return jnidocengineJNI.DocBasicObjectsMutableIterator_Equals(swigCPtr, this, DocBasicObjectsMutableIterator.getCPtr(rvalue), rvalue);
  }

}
