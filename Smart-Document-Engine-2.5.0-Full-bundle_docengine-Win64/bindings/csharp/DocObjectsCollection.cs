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

public class DocObjectsCollection : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  public DocObjectsCollection(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  public static global::System.Runtime.InteropServices.HandleRef getCPtr(DocObjectsCollection obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  public static global::System.Runtime.InteropServices.HandleRef swigRelease(DocObjectsCollection obj) {
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

  ~DocObjectsCollection() {
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
          csdocenginePINVOKE.delete_DocObjectsCollection(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public static string BaseClassNameStatic() {
    string ret = csdocenginePINVOKE.DocObjectsCollection_BaseClassNameStatic();
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static DocObjectsCollection Create(string object_type) {
    global::System.IntPtr cPtr = csdocenginePINVOKE.DocObjectsCollection_Create(object_type);
    DocObjectsCollection ret = (cPtr == global::System.IntPtr.Zero) ? null : new DocObjectsCollection(cPtr, true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocBasicObject CreateObject() {
    global::System.IntPtr cPtr = csdocenginePINVOKE.DocObjectsCollection_CreateObject(swigCPtr);
    DocBasicObject ret = (cPtr == global::System.IntPtr.Zero) ? null : new DocBasicObject(cPtr, true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocObjectsCollection Clone() {
    global::System.IntPtr cPtr = csdocenginePINVOKE.DocObjectsCollection_Clone(swigCPtr);
    DocObjectsCollection ret = (cPtr == global::System.IntPtr.Zero) ? null : new DocObjectsCollection(cPtr, true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual string ObjectType() {
    string ret = csdocenginePINVOKE.DocObjectsCollection_ObjectType(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual int GetFrameID() {
    int ret = csdocenginePINVOKE.DocObjectsCollection_GetFrameID(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void SetFrameID(int frame_id) {
    csdocenginePINVOKE.DocObjectsCollection_SetFrameID(swigCPtr, frame_id);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual int GetObjectsCount() {
    int ret = csdocenginePINVOKE.DocObjectsCollection_GetObjectsCount(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual bool HasObject(int obj_id) {
    bool ret = csdocenginePINVOKE.DocObjectsCollection_HasObject(swigCPtr, obj_id);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocBasicObject GetObject(int obj_id) {
    DocBasicObject ret = new DocBasicObject(csdocenginePINVOKE.DocObjectsCollection_GetObject(swigCPtr, obj_id), false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocBasicObject GetMutableObject(int obj_id) {
    DocBasicObject ret = new DocBasicObject(csdocenginePINVOKE.DocObjectsCollection_GetMutableObject(swigCPtr, obj_id), false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocTagsCollection GetObjectTags(int obj_id) {
    DocTagsCollection ret = new DocTagsCollection(csdocenginePINVOKE.DocObjectsCollection_GetObjectTags(swigCPtr, obj_id), false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocBasicObjectsMutableIterator AddObject(DocBasicObject obj) {
    DocBasicObjectsMutableIterator ret = new DocBasicObjectsMutableIterator(csdocenginePINVOKE.DocObjectsCollection_AddObject(swigCPtr, DocBasicObject.getCPtr(obj)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void SetObject(int obj_id, DocBasicObject obj) {
    csdocenginePINVOKE.DocObjectsCollection_SetObject(swigCPtr, obj_id, DocBasicObject.getCPtr(obj));
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual void RemoveObject(int obj_id) {
    csdocenginePINVOKE.DocObjectsCollection_RemoveObject(swigCPtr, obj_id);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual void RemoveObjectDeep(int obj_id, DocViewsCollection views_collection) {
    csdocenginePINVOKE.DocObjectsCollection_RemoveObjectDeep(swigCPtr, obj_id, DocViewsCollection.getCPtr(views_collection));
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual DocBasicObjectsIterator BasicObjectsBegin() {
    DocBasicObjectsIterator ret = new DocBasicObjectsIterator(csdocenginePINVOKE.DocObjectsCollection_BasicObjectsBegin(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocBasicObjectsIterator BasicObjectsEnd() {
    DocBasicObjectsIterator ret = new DocBasicObjectsIterator(csdocenginePINVOKE.DocObjectsCollection_BasicObjectsEnd(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocBasicObjectsMutableIterator MutableBasicObjectsBegin() {
    DocBasicObjectsMutableIterator ret = new DocBasicObjectsMutableIterator(csdocenginePINVOKE.DocObjectsCollection_MutableBasicObjectsBegin(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocBasicObjectsMutableIterator MutableBasicObjectsEnd() {
    DocBasicObjectsMutableIterator ret = new DocBasicObjectsMutableIterator(csdocenginePINVOKE.DocObjectsCollection_MutableBasicObjectsEnd(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocBasicObjectsSliceIterator BasicObjectsSlice(string tag) {
    DocBasicObjectsSliceIterator ret = new DocBasicObjectsSliceIterator(csdocenginePINVOKE.DocObjectsCollection_BasicObjectsSlice(swigCPtr, tag), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocBasicObjectsMutableSliceIterator MutableBasicObjectsSlice(string tag) {
    DocBasicObjectsMutableSliceIterator ret = new DocBasicObjectsMutableSliceIterator(csdocenginePINVOKE.DocObjectsCollection_MutableBasicObjectsSlice(swigCPtr, tag), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void Serialize(Serializer serializer) {
    csdocenginePINVOKE.DocObjectsCollection_Serialize(swigCPtr, Serializer.getCPtr(serializer));
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

}

}
