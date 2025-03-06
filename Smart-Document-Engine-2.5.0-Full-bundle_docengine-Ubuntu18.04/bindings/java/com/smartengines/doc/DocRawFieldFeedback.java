/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (https://www.swig.org).
 * Version 4.1.1
 *
 * Do not make changes to this file unless you know what you are doing - modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.smartengines.doc;

import com.smartengines.common.*;

public class DocRawFieldFeedback {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  public DocRawFieldFeedback(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  public static long getCPtr(DocRawFieldFeedback obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  public static long swigRelease(DocRawFieldFeedback obj) {
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
        jnidocengineJNI.delete_DocRawFieldFeedback(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public String GetName() {
    return jnidocengineJNI.DocRawFieldFeedback_GetName(swigCPtr, this);
  }

  public boolean HasQuadrangle() {
    return jnidocengineJNI.DocRawFieldFeedback_HasQuadrangle(swigCPtr, this);
  }

  public Quadrangle GetQuadrangle() {
    return new Quadrangle(jnidocengineJNI.DocRawFieldFeedback_GetQuadrangle(swigCPtr, this), false);
  }

  public String GetType() {
    return jnidocengineJNI.DocRawFieldFeedback_GetType(swigCPtr, this);
  }

  public OcrString GetOcrString() {
    return new OcrString(jnidocengineJNI.DocRawFieldFeedback_GetOcrString(swigCPtr, this), true);
  }

}
