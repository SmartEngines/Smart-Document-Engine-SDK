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

public class DocBaseFieldInfo : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  public DocBaseFieldInfo(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  public static global::System.Runtime.InteropServices.HandleRef getCPtr(DocBaseFieldInfo obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  public static global::System.Runtime.InteropServices.HandleRef swigRelease(DocBaseFieldInfo obj) {
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

  ~DocBaseFieldInfo() {
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
          csdocenginePINVOKE.delete_DocBaseFieldInfo(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public virtual string GetName() {
    string ret = csdocenginePINVOKE.DocBaseFieldInfo_GetName(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void SetName(string name) {
    csdocenginePINVOKE.DocBaseFieldInfo_SetName(swigCPtr, name);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual double GetConfidence() {
    double ret = csdocenginePINVOKE.DocBaseFieldInfo_GetConfidence(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void SetConfidence(double conf) {
    csdocenginePINVOKE.DocBaseFieldInfo_SetConfidence(swigCPtr, conf);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual bool GetAcceptFlag() {
    bool ret = csdocenginePINVOKE.DocBaseFieldInfo_GetAcceptFlag(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void SetAcceptFlag(bool is_accepted) {
    csdocenginePINVOKE.DocBaseFieldInfo_SetAcceptFlag(swigCPtr, is_accepted);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual int GetAttributesCount() {
    int ret = csdocenginePINVOKE.DocBaseFieldInfo_GetAttributesCount(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual bool HasAttribute(string attr_name) {
    bool ret = csdocenginePINVOKE.DocBaseFieldInfo_HasAttribute(swigCPtr, attr_name);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual string GetAttribute(string attr_name) {
    string ret = csdocenginePINVOKE.DocBaseFieldInfo_GetAttribute(swigCPtr, attr_name);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void SetAttribute(string attr_name, string attr_value) {
    csdocenginePINVOKE.DocBaseFieldInfo_SetAttribute(swigCPtr, attr_name, attr_value);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual void RemoveAttribute(string attr_name) {
    csdocenginePINVOKE.DocBaseFieldInfo_RemoveAttribute(swigCPtr, attr_name);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual StringsMapIterator AttributesBegin() {
    StringsMapIterator ret = new StringsMapIterator(csdocenginePINVOKE.DocBaseFieldInfo_AttributesBegin(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual StringsMapIterator AttributesEnd() {
    StringsMapIterator ret = new StringsMapIterator(csdocenginePINVOKE.DocBaseFieldInfo_AttributesEnd(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocTextObjectsCrossPageIterator ConnectedTextObjectsBegin(DocPhysicalDocument phys_doc) {
    DocTextObjectsCrossPageIterator ret = new DocTextObjectsCrossPageIterator(csdocenginePINVOKE.DocBaseFieldInfo_ConnectedTextObjectsBegin(swigCPtr, DocPhysicalDocument.getCPtr(phys_doc)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocTextObjectsCrossPageIterator ConnectedTextObjectsEnd(DocPhysicalDocument phys_doc) {
    DocTextObjectsCrossPageIterator ret = new DocTextObjectsCrossPageIterator(csdocenginePINVOKE.DocBaseFieldInfo_ConnectedTextObjectsEnd(swigCPtr, DocPhysicalDocument.getCPtr(phys_doc)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocTableObjectsCrossPageIterator ConnectedTableObjectsBegin(DocPhysicalDocument phys_doc) {
    DocTableObjectsCrossPageIterator ret = new DocTableObjectsCrossPageIterator(csdocenginePINVOKE.DocBaseFieldInfo_ConnectedTableObjectsBegin(swigCPtr, DocPhysicalDocument.getCPtr(phys_doc)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocTableObjectsCrossPageIterator ConnectedTableObjectsEnd(DocPhysicalDocument phys_doc) {
    DocTableObjectsCrossPageIterator ret = new DocTableObjectsCrossPageIterator(csdocenginePINVOKE.DocBaseFieldInfo_ConnectedTableObjectsEnd(swigCPtr, DocPhysicalDocument.getCPtr(phys_doc)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocImageObjectsCrossPageIterator ConnectedImageObjectsBegin(DocPhysicalDocument phys_doc) {
    DocImageObjectsCrossPageIterator ret = new DocImageObjectsCrossPageIterator(csdocenginePINVOKE.DocBaseFieldInfo_ConnectedImageObjectsBegin(swigCPtr, DocPhysicalDocument.getCPtr(phys_doc)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocImageObjectsCrossPageIterator ConnectedImageObjectsEnd(DocPhysicalDocument phys_doc) {
    DocImageObjectsCrossPageIterator ret = new DocImageObjectsCrossPageIterator(csdocenginePINVOKE.DocBaseFieldInfo_ConnectedImageObjectsEnd(swigCPtr, DocPhysicalDocument.getCPtr(phys_doc)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocCheckboxObjectsCrossPageIterator ConnectedCheckboxObjectsBegin(DocPhysicalDocument phys_doc) {
    DocCheckboxObjectsCrossPageIterator ret = new DocCheckboxObjectsCrossPageIterator(csdocenginePINVOKE.DocBaseFieldInfo_ConnectedCheckboxObjectsBegin(swigCPtr, DocPhysicalDocument.getCPtr(phys_doc)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocCheckboxObjectsCrossPageIterator ConnectedCheckboxObjectsEnd(DocPhysicalDocument phys_doc) {
    DocCheckboxObjectsCrossPageIterator ret = new DocCheckboxObjectsCrossPageIterator(csdocenginePINVOKE.DocBaseFieldInfo_ConnectedCheckboxObjectsEnd(swigCPtr, DocPhysicalDocument.getCPtr(phys_doc)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocTextObjectsCrossPageIterator ConnectedForensicCheckObjectsBegin(DocPhysicalDocument phys_doc) {
    DocTextObjectsCrossPageIterator ret = new DocTextObjectsCrossPageIterator(csdocenginePINVOKE.DocBaseFieldInfo_ConnectedForensicCheckObjectsBegin(swigCPtr, DocPhysicalDocument.getCPtr(phys_doc)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocTextObjectsCrossPageIterator ConnectedForensicCheckObjectsEnd(DocPhysicalDocument phys_doc) {
    DocTextObjectsCrossPageIterator ret = new DocTextObjectsCrossPageIterator(csdocenginePINVOKE.DocBaseFieldInfo_ConnectedForensicCheckObjectsEnd(swigCPtr, DocPhysicalDocument.getCPtr(phys_doc)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocMetaObjectsCrossPageIterator ConnectedForensicObjectsBegin(DocPhysicalDocument phys_doc) {
    DocMetaObjectsCrossPageIterator ret = new DocMetaObjectsCrossPageIterator(csdocenginePINVOKE.DocBaseFieldInfo_ConnectedForensicObjectsBegin(swigCPtr, DocPhysicalDocument.getCPtr(phys_doc)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocMetaObjectsCrossPageIterator ConnectedForensicObjectsEnd(DocPhysicalDocument phys_doc) {
    DocMetaObjectsCrossPageIterator ret = new DocMetaObjectsCrossPageIterator(csdocenginePINVOKE.DocBaseFieldInfo_ConnectedForensicObjectsEnd(swigCPtr, DocPhysicalDocument.getCPtr(phys_doc)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocBarcodeObjectsCrossPageIterator ConnectedBarcodeObjectsBegin(DocPhysicalDocument phys_doc) {
    DocBarcodeObjectsCrossPageIterator ret = new DocBarcodeObjectsCrossPageIterator(csdocenginePINVOKE.DocBaseFieldInfo_ConnectedBarcodeObjectsBegin(swigCPtr, DocPhysicalDocument.getCPtr(phys_doc)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocBarcodeObjectsCrossPageIterator ConnectedBarcodeObjectsEnd(DocPhysicalDocument phys_doc) {
    DocBarcodeObjectsCrossPageIterator ret = new DocBarcodeObjectsCrossPageIterator(csdocenginePINVOKE.DocBaseFieldInfo_ConnectedBarcodeObjectsEnd(swigCPtr, DocPhysicalDocument.getCPtr(phys_doc)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void Serialize(Serializer serializer) {
    csdocenginePINVOKE.DocBaseFieldInfo_Serialize(swigCPtr, Serializer.getCPtr(serializer));
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual DocBasicObjectsCrossSliceIterator ConnectedBasicObjectsBegin(DocGraphicalStructure graphical) {
    DocBasicObjectsCrossSliceIterator ret = new DocBasicObjectsCrossSliceIterator(csdocenginePINVOKE.DocBaseFieldInfo_ConnectedBasicObjectsBegin(swigCPtr, DocGraphicalStructure.getCPtr(graphical)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocBasicObjectsCrossSliceIterator ConnectedBasicObjectsEnd(DocGraphicalStructure graphical) {
    DocBasicObjectsCrossSliceIterator ret = new DocBasicObjectsCrossSliceIterator(csdocenginePINVOKE.DocBaseFieldInfo_ConnectedBasicObjectsEnd(swigCPtr, DocGraphicalStructure.getCPtr(graphical)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocBasicObjectsMutableCrossSliceIterator MutableConnectedBasicObjectsBegin(DocGraphicalStructure graphical) {
    DocBasicObjectsMutableCrossSliceIterator ret = new DocBasicObjectsMutableCrossSliceIterator(csdocenginePINVOKE.DocBaseFieldInfo_MutableConnectedBasicObjectsBegin(swigCPtr, DocGraphicalStructure.getCPtr(graphical)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocBasicObjectsMutableCrossSliceIterator MutableConnectedBasicObjectsEnd(DocGraphicalStructure graphical) {
    DocBasicObjectsMutableCrossSliceIterator ret = new DocBasicObjectsMutableCrossSliceIterator(csdocenginePINVOKE.DocBaseFieldInfo_MutableConnectedBasicObjectsEnd(swigCPtr, DocGraphicalStructure.getCPtr(graphical)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void ConnectBasicObject(int coll_id, int obj_id) {
    csdocenginePINVOKE.DocBaseFieldInfo_ConnectBasicObject(swigCPtr, coll_id, obj_id);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

}

}
