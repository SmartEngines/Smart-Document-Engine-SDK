/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (https://www.swig.org).
 * Version 4.1.1
 *
 * Do not make changes to this file unless you know what you are doing - modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.smartengines.doc;

import com.smartengines.common.*;

public class DocProcessingSettings {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  public DocProcessingSettings(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  public static long getCPtr(DocProcessingSettings obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  public static long swigRelease(DocProcessingSettings obj) {
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
        jnidocengineJNI.delete_DocProcessingSettings(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public int GetOptionsCount() {
    return jnidocengineJNI.DocProcessingSettings_GetOptionsCount(swigCPtr, this);
  }

  public boolean HasOption(String option_name) {
    return jnidocengineJNI.DocProcessingSettings_HasOption(swigCPtr, this, option_name);
  }

  public String GetOption(String option_name) {
    return jnidocengineJNI.DocProcessingSettings_GetOption(swigCPtr, this, option_name);
  }

  public void SetOption(String option_name, String option_value) {
    jnidocengineJNI.DocProcessingSettings_SetOption(swigCPtr, this, option_name, option_value);
  }

  public void RemoveOption(String option_name) {
    jnidocengineJNI.DocProcessingSettings_RemoveOption(swigCPtr, this, option_name);
  }

  public StringsMapIterator OptionsBegin() {
    return new StringsMapIterator(jnidocengineJNI.DocProcessingSettings_OptionsBegin(swigCPtr, this), true);
  }

  public StringsMapIterator OptionsEnd() {
    return new StringsMapIterator(jnidocengineJNI.DocProcessingSettings_OptionsEnd(swigCPtr, this), true);
  }

  public int GetSessionOptionsCount() {
    return jnidocengineJNI.DocProcessingSettings_GetSessionOptionsCount(swigCPtr, this);
  }

  public boolean HasSessionOption(String option_name) {
    return jnidocengineJNI.DocProcessingSettings_HasSessionOption(swigCPtr, this, option_name);
  }

  public String GetSessionOption(String option_name) {
    return jnidocengineJNI.DocProcessingSettings_GetSessionOption(swigCPtr, this, option_name);
  }

  public StringsMapIterator SessionOptionsBegin() {
    return new StringsMapIterator(jnidocengineJNI.DocProcessingSettings_SessionOptionsBegin(swigCPtr, this), true);
  }

  public StringsMapIterator SessionOptionsEnd() {
    return new StringsMapIterator(jnidocengineJNI.DocProcessingSettings_SessionOptionsEnd(swigCPtr, this), true);
  }

  public int GetEnabledDocumentTypesCount() {
    return jnidocengineJNI.DocProcessingSettings_GetEnabledDocumentTypesCount(swigCPtr, this);
  }

  public boolean HasEnabledDocumentType(String doc_name) {
    return jnidocengineJNI.DocProcessingSettings_HasEnabledDocumentType(swigCPtr, this, doc_name);
  }

  public String GetEnabledDocumentType(int doc_id) {
    return jnidocengineJNI.DocProcessingSettings_GetEnabledDocumentType(swigCPtr, this, doc_id);
  }

  public int GetCurrentSourceID() {
    return jnidocengineJNI.DocProcessingSettings_GetCurrentSourceID(swigCPtr, this);
  }

  public void SetCurrentSourceID(int source_id) {
    jnidocengineJNI.DocProcessingSettings_SetCurrentSourceID(swigCPtr, this, source_id);
  }

  public int GetAvailableRoutinesCount() {
    return jnidocengineJNI.DocProcessingSettings_GetAvailableRoutinesCount(swigCPtr, this);
  }

  public boolean HasAvailableRoutine(String routine_name) {
    return jnidocengineJNI.DocProcessingSettings_HasAvailableRoutine(swigCPtr, this, routine_name);
  }

  public StringsMapIterator AvailableRoutinesBegin() {
    return new StringsMapIterator(jnidocengineJNI.DocProcessingSettings_AvailableRoutinesBegin(swigCPtr, this), true);
  }

  public StringsMapIterator AvailableRoutinesEnd() {
    return new StringsMapIterator(jnidocengineJNI.DocProcessingSettings_AvailableRoutinesEnd(swigCPtr, this), true);
  }

  public int RoutinesQueueSize() {
    return jnidocengineJNI.DocProcessingSettings_RoutinesQueueSize(swigCPtr, this);
  }

  public String RoutinesQueueFront() {
    return jnidocengineJNI.DocProcessingSettings_RoutinesQueueFront(swigCPtr, this);
  }

  public void RoutinesQueuePush(String routine_name) {
    jnidocengineJNI.DocProcessingSettings_RoutinesQueuePush(swigCPtr, this, routine_name);
  }

  public void RoutinesQueuePop() {
    jnidocengineJNI.DocProcessingSettings_RoutinesQueuePop(swigCPtr, this);
  }

  public void RoutinesQueueClear() {
    jnidocengineJNI.DocProcessingSettings_RoutinesQueueClear(swigCPtr, this);
  }

  public void BindFeedbackReporter(DocFeedback feedback_reporter) {
    jnidocengineJNI.DocProcessingSettings_BindFeedbackReporter(swigCPtr, this, DocFeedback.getCPtr(feedback_reporter), feedback_reporter);
  }

  public DocFeedback GetFeedbackReporter() {
    long cPtr = jnidocengineJNI.DocProcessingSettings_GetFeedbackReporter(swigCPtr, this);
    return (cPtr == 0) ? null : new DocFeedback(cPtr, false);
  }

}
