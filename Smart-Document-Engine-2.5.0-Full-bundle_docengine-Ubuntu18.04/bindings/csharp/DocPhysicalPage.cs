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

public class DocPhysicalPage : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  public DocPhysicalPage(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  public static global::System.Runtime.InteropServices.HandleRef getCPtr(DocPhysicalPage obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  public static global::System.Runtime.InteropServices.HandleRef swigRelease(DocPhysicalPage obj) {
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

  ~DocPhysicalPage() {
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
          csdocenginePINVOKE.delete_DocPhysicalPage(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public virtual int GetSourceSceneID() {
    int ret = csdocenginePINVOKE.DocPhysicalPage_GetSourceSceneID(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocTextObjectsIterator TextObjectsBegin(string name) {
    DocTextObjectsIterator ret = new DocTextObjectsIterator(csdocenginePINVOKE.DocPhysicalPage_TextObjectsBegin(swigCPtr, name), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocTextObjectsIterator TextObjectsEnd(string name) {
    DocTextObjectsIterator ret = new DocTextObjectsIterator(csdocenginePINVOKE.DocPhysicalPage_TextObjectsEnd(swigCPtr, name), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocImageObjectsIterator ImageObjectsBegin(string name) {
    DocImageObjectsIterator ret = new DocImageObjectsIterator(csdocenginePINVOKE.DocPhysicalPage_ImageObjectsBegin(swigCPtr, name), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocImageObjectsIterator ImageObjectsEnd(string name) {
    DocImageObjectsIterator ret = new DocImageObjectsIterator(csdocenginePINVOKE.DocPhysicalPage_ImageObjectsEnd(swigCPtr, name), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocTableObjectsIterator TableObjectsBegin(string name) {
    DocTableObjectsIterator ret = new DocTableObjectsIterator(csdocenginePINVOKE.DocPhysicalPage_TableObjectsBegin(swigCPtr, name), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocTableObjectsIterator TableObjectsEnd(string name) {
    DocTableObjectsIterator ret = new DocTableObjectsIterator(csdocenginePINVOKE.DocPhysicalPage_TableObjectsEnd(swigCPtr, name), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocBarcodeObjectsIterator BarcodeObjectsBegin(string name) {
    DocBarcodeObjectsIterator ret = new DocBarcodeObjectsIterator(csdocenginePINVOKE.DocPhysicalPage_BarcodeObjectsBegin(swigCPtr, name), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocBarcodeObjectsIterator BarcodeObjectsEnd(string name) {
    DocBarcodeObjectsIterator ret = new DocBarcodeObjectsIterator(csdocenginePINVOKE.DocPhysicalPage_BarcodeObjectsEnd(swigCPtr, name), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocCheckboxObjectsIterator CheckboxObjectsBegin(string name) {
    DocCheckboxObjectsIterator ret = new DocCheckboxObjectsIterator(csdocenginePINVOKE.DocPhysicalPage_CheckboxObjectsBegin(swigCPtr, name), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocCheckboxObjectsIterator CheckboxObjectsEnd(string name) {
    DocCheckboxObjectsIterator ret = new DocCheckboxObjectsIterator(csdocenginePINVOKE.DocPhysicalPage_CheckboxObjectsEnd(swigCPtr, name), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocMetaObjectsIterator ForensicObjectsBegin(string name) {
    DocMetaObjectsIterator ret = new DocMetaObjectsIterator(csdocenginePINVOKE.DocPhysicalPage_ForensicObjectsBegin(swigCPtr, name), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocMetaObjectsIterator ForensicObjectsEnd(string name) {
    DocMetaObjectsIterator ret = new DocMetaObjectsIterator(csdocenginePINVOKE.DocPhysicalPage_ForensicObjectsEnd(swigCPtr, name), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocForensicCheckObjectsIterator ForensicCheckObjectsBegin(string name) {
    DocForensicCheckObjectsIterator ret = new DocForensicCheckObjectsIterator(csdocenginePINVOKE.DocPhysicalPage_ForensicCheckObjectsBegin(swigCPtr, name), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocForensicCheckObjectsIterator ForensicCheckObjectsEnd(string name) {
    DocForensicCheckObjectsIterator ret = new DocForensicCheckObjectsIterator(csdocenginePINVOKE.DocPhysicalPage_ForensicCheckObjectsEnd(swigCPtr, name), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual int GetTextObjectsCount(string name) {
    int ret = csdocenginePINVOKE.DocPhysicalPage_GetTextObjectsCount(swigCPtr, name);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual int GetImageObjectsCount(string name) {
    int ret = csdocenginePINVOKE.DocPhysicalPage_GetImageObjectsCount(swigCPtr, name);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual int GetTableObjectsCount(string name) {
    int ret = csdocenginePINVOKE.DocPhysicalPage_GetTableObjectsCount(swigCPtr, name);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual int GetBarcodeObjectsCount(string name) {
    int ret = csdocenginePINVOKE.DocPhysicalPage_GetBarcodeObjectsCount(swigCPtr, name);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual int GetCheckboxObjectsCount(string name) {
    int ret = csdocenginePINVOKE.DocPhysicalPage_GetCheckboxObjectsCount(swigCPtr, name);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual int GetForensicObjectsCount(string name) {
    int ret = csdocenginePINVOKE.DocPhysicalPage_GetForensicObjectsCount(swigCPtr, name);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual int GetForensicCheckObjectsCount(string name) {
    int ret = csdocenginePINVOKE.DocPhysicalPage_GetForensicCheckObjectsCount(swigCPtr, name);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual bool HasBasicObjects() {
    bool ret = csdocenginePINVOKE.DocPhysicalPage_HasBasicObjects(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual Quadrangle GetPageQuadrangle() {
    Quadrangle ret = new Quadrangle(csdocenginePINVOKE.DocPhysicalPage_GetPageQuadrangle(swigCPtr), false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual Polygon GetPagePolygon() {
    Polygon ret = new Polygon(csdocenginePINVOKE.DocPhysicalPage_GetPagePolygon(swigCPtr), false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocTextObjectsIterator GetFulltextBasicObjectsBegin() {
    DocTextObjectsIterator ret = new DocTextObjectsIterator(csdocenginePINVOKE.DocPhysicalPage_GetFulltextBasicObjectsBegin(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocTextObjectsIterator GetFulltextBasicObjectsEnd() {
    DocTextObjectsIterator ret = new DocTextObjectsIterator(csdocenginePINVOKE.DocPhysicalPage_GetFulltextBasicObjectsEnd(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual Image GetPageImageFromScene(Image scene_image) {
    global::System.IntPtr cPtr = csdocenginePINVOKE.DocPhysicalPage_GetPageImageFromScene(swigCPtr, Image.getCPtr(scene_image));
    Image ret = (cPtr == global::System.IntPtr.Zero) ? null : new Image(cPtr, false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocBasicObjectsIterator BasicObjectsBegin(string name) {
    DocBasicObjectsIterator ret = new DocBasicObjectsIterator(csdocenginePINVOKE.DocPhysicalPage_BasicObjectsBegin(swigCPtr, name), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocBasicObjectsIterator BasicObjectsEnd(string name) {
    DocBasicObjectsIterator ret = new DocBasicObjectsIterator(csdocenginePINVOKE.DocPhysicalPage_BasicObjectsEnd(swigCPtr, name), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual int GetBasicObjectsCount(string name) {
    int ret = csdocenginePINVOKE.DocPhysicalPage_GetBasicObjectsCount(swigCPtr, name);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}

}
