/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (https://www.swig.org).
 * Version 4.1.1
 *
 * Do not make changes to this file unless you know what you are doing - modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.smartengines.doc;

import com.smartengines.common.*;

public class DocPageFeedback {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  public DocPageFeedback(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  public static long getCPtr(DocPageFeedback obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  public static long swigRelease(DocPageFeedback obj) {
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
        jnidocengineJNI.delete_DocPageFeedback(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public Quadrangle GetQuadrangle() {
    return new Quadrangle(jnidocengineJNI.DocPageFeedback_GetQuadrangle(swigCPtr, this), false);
  }

  public int GetID() {
    return jnidocengineJNI.DocPageFeedback_GetID(swigCPtr, this);
  }

  public String GetType() {
    return jnidocengineJNI.DocPageFeedback_GetType(swigCPtr, this);
  }

  public boolean IsPageRejected() {
    return jnidocengineJNI.DocPageFeedback_IsPageRejected(swigCPtr, this);
  }

}
