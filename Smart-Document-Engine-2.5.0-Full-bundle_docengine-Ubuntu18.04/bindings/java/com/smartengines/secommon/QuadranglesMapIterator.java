/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (https://www.swig.org).
 * Version 4.1.1
 *
 * Do not make changes to this file unless you know what you are doing - modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.smartengines.common;

public class QuadranglesMapIterator {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  public QuadranglesMapIterator(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  public static long getCPtr(QuadranglesMapIterator obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  public static long swigRelease(QuadranglesMapIterator obj) {
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
        jnisecommonJNI.delete_QuadranglesMapIterator(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public QuadranglesMapIterator(QuadranglesMapIterator other) {
    this(jnisecommonJNI.new_QuadranglesMapIterator(QuadranglesMapIterator.getCPtr(other), other), true);
  }

  public String GetKey() {
    return jnisecommonJNI.QuadranglesMapIterator_GetKey(swigCPtr, this);
  }

  public Quadrangle GetValue() {
    return new Quadrangle(jnisecommonJNI.QuadranglesMapIterator_GetValue(swigCPtr, this), false);
  }

  public boolean Equals(QuadranglesMapIterator rvalue) {
    return jnisecommonJNI.QuadranglesMapIterator_Equals(swigCPtr, this, QuadranglesMapIterator.getCPtr(rvalue), rvalue);
  }

  public void Advance() {
    jnisecommonJNI.QuadranglesMapIterator_Advance(swigCPtr, this);
  }

}
