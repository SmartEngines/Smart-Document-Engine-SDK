/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (https://www.swig.org).
 * Version 4.1.1
 *
 * Do not make changes to this file unless you know what you are doing - modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.smartengines.doc;

import com.smartengines.common.*;

public class DocForensicCheckField {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  public DocForensicCheckField(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  public static long getCPtr(DocForensicCheckField obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  public static long swigRelease(DocForensicCheckField obj) {
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
        jnidocengineJNI.delete_DocForensicCheckField(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public DocBaseFieldInfo GetBaseFieldInfo() {
    return new DocBaseFieldInfo(jnidocengineJNI.DocForensicCheckField_GetBaseFieldInfo(swigCPtr, this), false);
  }

  public DocBaseFieldInfo GetMutableBaseFieldInfo() {
    return new DocBaseFieldInfo(jnidocengineJNI.DocForensicCheckField_GetMutableBaseFieldInfo(swigCPtr, this), false);
  }

  public String GetStatus() {
    return jnidocengineJNI.DocForensicCheckField_GetStatus(swigCPtr, this);
  }

  public void SetStatus(String status) {
    jnidocengineJNI.DocForensicCheckField_SetStatus(swigCPtr, this, status);
  }

  public int GetAttributesCount() {
    return jnidocengineJNI.DocForensicCheckField_GetAttributesCount(swigCPtr, this);
  }

  public StringsMapIterator AttributesBegin() {
    return new StringsMapIterator(jnidocengineJNI.DocForensicCheckField_AttributesBegin(swigCPtr, this), true);
  }

  public StringsMapIterator AttributesEnd() {
    return new StringsMapIterator(jnidocengineJNI.DocForensicCheckField_AttributesEnd(swigCPtr, this), true);
  }

  public void Serialize(Serializer serializer) {
    jnidocengineJNI.DocForensicCheckField_Serialize(swigCPtr, this, Serializer.getCPtr(serializer), serializer);
  }

}
