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

public class DocBasicObjectsMutableSliceIterator : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  public DocBasicObjectsMutableSliceIterator(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  public static global::System.Runtime.InteropServices.HandleRef getCPtr(DocBasicObjectsMutableSliceIterator obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  public static global::System.Runtime.InteropServices.HandleRef swigRelease(DocBasicObjectsMutableSliceIterator obj) {
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

  ~DocBasicObjectsMutableSliceIterator() {
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
          csdocenginePINVOKE.delete_DocBasicObjectsMutableSliceIterator(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public DocBasicObjectsMutableSliceIterator(DocBasicObjectsMutableSliceIterator other) : this(csdocenginePINVOKE.new_DocBasicObjectsMutableSliceIterator(DocBasicObjectsMutableSliceIterator.getCPtr(other)), true) {
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public int GetID() {
    int ret = csdocenginePINVOKE.DocBasicObjectsMutableSliceIterator_GetID(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public DocBasicObject GetBasicObject() {
    DocBasicObject ret = new DocBasicObject(csdocenginePINVOKE.DocBasicObjectsMutableSliceIterator_GetBasicObject(swigCPtr), false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public DocBasicObject GetMutableBasicObject() {
    DocBasicObject ret = new DocBasicObject(csdocenginePINVOKE.DocBasicObjectsMutableSliceIterator_GetMutableBasicObject(swigCPtr), false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public DocTagsCollection GetTags() {
    DocTagsCollection ret = new DocTagsCollection(csdocenginePINVOKE.DocBasicObjectsMutableSliceIterator_GetTags(swigCPtr), false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Advance() {
    csdocenginePINVOKE.DocBasicObjectsMutableSliceIterator_Advance(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public bool Finished() {
    bool ret = csdocenginePINVOKE.DocBasicObjectsMutableSliceIterator_Finished(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}

}
