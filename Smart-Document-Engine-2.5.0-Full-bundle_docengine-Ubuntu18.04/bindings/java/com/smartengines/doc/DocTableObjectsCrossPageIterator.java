/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (https://www.swig.org).
 * Version 4.1.1
 *
 * Do not make changes to this file unless you know what you are doing - modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.smartengines.doc;

import com.smartengines.common.*;

public class DocTableObjectsCrossPageIterator {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  public DocTableObjectsCrossPageIterator(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  public static long getCPtr(DocTableObjectsCrossPageIterator obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  public static long swigRelease(DocTableObjectsCrossPageIterator obj) {
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
        jnidocengineJNI.delete_DocTableObjectsCrossPageIterator(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public DocTableObjectsCrossPageIterator(DocTableObjectsCrossPageIterator other) {
    this(jnidocengineJNI.new_DocTableObjectsCrossPageIterator(DocTableObjectsCrossPageIterator.getCPtr(other), other), true);
  }

  public int GetPhysicalPageID() {
    return jnidocengineJNI.DocTableObjectsCrossPageIterator_GetPhysicalPageID(swigCPtr, this);
  }

  public int GetObjectID() {
    return jnidocengineJNI.DocTableObjectsCrossPageIterator_GetObjectID(swigCPtr, this);
  }

  public DocTableObject GetTableObject() {
    return new DocTableObject(jnidocengineJNI.DocTableObjectsCrossPageIterator_GetTableObject(swigCPtr, this), false);
  }

  public void Advance() {
    jnidocengineJNI.DocTableObjectsCrossPageIterator_Advance(swigCPtr, this);
  }

  public boolean Equals(DocTableObjectsCrossPageIterator rvalue) {
    return jnidocengineJNI.DocTableObjectsCrossPageIterator_Equals(swigCPtr, this, DocTableObjectsCrossPageIterator.getCPtr(rvalue), rvalue);
  }

}
