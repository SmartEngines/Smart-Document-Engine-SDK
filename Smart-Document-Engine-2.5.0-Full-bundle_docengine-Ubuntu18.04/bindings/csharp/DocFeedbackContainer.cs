//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.1.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------

namespace se.doc {

using se.common;

public class DocFeedbackContainer : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  public DocFeedbackContainer(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  public static global::System.Runtime.InteropServices.HandleRef getCPtr(DocFeedbackContainer obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  public static global::System.Runtime.InteropServices.HandleRef swigRelease(DocFeedbackContainer obj) {
    if (obj != null) {
      if (!obj.swigCMemOwn)
        throw new global::System.ApplicationException("Cannot release ownership as memory is not owned");
      global::System.Runtime.InteropServices.HandleRef ptr = obj.swigCPtr;
      obj.swigCMemOwn = false;
      obj.Dispose();
      return ptr;
    } else {
      return new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
    }
  }

  ~DocFeedbackContainer() {
    Dispose(false);
  }

  public void Dispose() {
    Dispose(true);
    global::System.GC.SuppressFinalize(this);
  }

  protected virtual void Dispose(bool disposing) {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          csdocenginePINVOKE.delete_DocFeedbackContainer(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public virtual StringsMapIterator FeedbackFieldIteratorBegin() {
    StringsMapIterator ret = new StringsMapIterator(csdocenginePINVOKE.DocFeedbackContainer_FeedbackFieldIteratorBegin(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual StringsMapIterator FeedbackFieldIteratorEnd() {
    StringsMapIterator ret = new StringsMapIterator(csdocenginePINVOKE.DocFeedbackContainer_FeedbackFieldIteratorEnd(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual QuadranglesMapIterator FeedbackQuadIteratorBegin() {
    QuadranglesMapIterator ret = new QuadranglesMapIterator(csdocenginePINVOKE.DocFeedbackContainer_FeedbackQuadIteratorBegin(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual QuadranglesMapIterator FeedbackQuadIteratorEnd() {
    QuadranglesMapIterator ret = new QuadranglesMapIterator(csdocenginePINVOKE.DocFeedbackContainer_FeedbackQuadIteratorEnd(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void SetFeedbackField(string key, string field) {
    csdocenginePINVOKE.DocFeedbackContainer_SetFeedbackField(swigCPtr, key, field);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual void SetFeedbackQuad(string key, Quadrangle quad) {
    csdocenginePINVOKE.DocFeedbackContainer_SetFeedbackQuad(swigCPtr, key, Quadrangle.getCPtr(quad));
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

}

}
