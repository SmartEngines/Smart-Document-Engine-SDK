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

public class DocumentsMutableIterator : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  public DocumentsMutableIterator(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  public static global::System.Runtime.InteropServices.HandleRef getCPtr(DocumentsMutableIterator obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  public static global::System.Runtime.InteropServices.HandleRef swigRelease(DocumentsMutableIterator obj) {
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

  ~DocumentsMutableIterator() {
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
          csdocenginePINVOKE.delete_DocumentsMutableIterator(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public DocumentsMutableIterator(DocumentsMutableIterator other) : this(csdocenginePINVOKE.new_DocumentsMutableIterator(DocumentsMutableIterator.getCPtr(other)), true) {
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public int GetID() {
    int ret = csdocenginePINVOKE.DocumentsMutableIterator_GetID(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public Document GetDocument() {
    Document ret = new Document(csdocenginePINVOKE.DocumentsMutableIterator_GetDocument(swigCPtr), false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public Document GetMutableDocument() {
    Document ret = new Document(csdocenginePINVOKE.DocumentsMutableIterator_GetMutableDocument(swigCPtr), false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Advance() {
    csdocenginePINVOKE.DocumentsMutableIterator_Advance(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public bool Equals(DocumentsMutableIterator rvalue) {
    bool ret = csdocenginePINVOKE.DocumentsMutableIterator_Equals(swigCPtr, DocumentsMutableIterator.getCPtr(rvalue));
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public DocTagsCollection GetTags() {
    DocTagsCollection ret = new DocTagsCollection(csdocenginePINVOKE.DocumentsMutableIterator_GetTags(swigCPtr), false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}

}
