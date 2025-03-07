/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (https://www.swig.org).
 * Version 4.1.1
 *
 * Do not make changes to this file unless you know what you are doing - modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.smartengines.doc;

import com.smartengines.common.*;

public class DocObjectsCollectionsIterator {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  public DocObjectsCollectionsIterator(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  public static long getCPtr(DocObjectsCollectionsIterator obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  public static long swigRelease(DocObjectsCollectionsIterator obj) {
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
        jnidocengineJNI.delete_DocObjectsCollectionsIterator(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public DocObjectsCollectionsIterator(DocObjectsCollectionsIterator other) {
    this(jnidocengineJNI.new_DocObjectsCollectionsIterator(DocObjectsCollectionsIterator.getCPtr(other), other), true);
  }

  public int GetID() {
    return jnidocengineJNI.DocObjectsCollectionsIterator_GetID(swigCPtr, this);
  }

  public DocObjectsCollection GetObjectsCollection() {
    return new DocObjectsCollection(jnidocengineJNI.DocObjectsCollectionsIterator_GetObjectsCollection(swigCPtr, this), false);
  }

  public DocTagsCollection GetTags() {
    return new DocTagsCollection(jnidocengineJNI.DocObjectsCollectionsIterator_GetTags(swigCPtr, this), false);
  }

  public void Advance() {
    jnidocengineJNI.DocObjectsCollectionsIterator_Advance(swigCPtr, this);
  }

  public boolean Equals(DocObjectsCollectionsIterator rvalue) {
    return jnidocengineJNI.DocObjectsCollectionsIterator_Equals(swigCPtr, this, DocObjectsCollectionsIterator.getCPtr(rvalue), rvalue);
  }

}
