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

public class DocResult : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  public DocResult(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  public static global::System.Runtime.InteropServices.HandleRef getCPtr(DocResult obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  public static global::System.Runtime.InteropServices.HandleRef swigRelease(DocResult obj) {
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

  ~DocResult() {
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
          csdocenginePINVOKE.delete_DocResult(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public virtual DocResult PartialClone() {
    global::System.IntPtr cPtr = csdocenginePINVOKE.DocResult_PartialClone(swigCPtr);
    DocResult ret = (cPtr == global::System.IntPtr.Zero) ? null : new DocResult(cPtr, false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual int GetDocumentsCount() {
    int ret = csdocenginePINVOKE.DocResult_GetDocumentsCount(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual bool HasDocument(int doc_id) {
    bool ret = csdocenginePINVOKE.DocResult_HasDocument(swigCPtr, doc_id);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual Document GetDocument(int doc_id) {
    Document ret = new Document(csdocenginePINVOKE.DocResult_GetDocument(swigCPtr, doc_id), false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocumentsIterator DocumentsBegin() {
    DocumentsIterator ret = new DocumentsIterator(csdocenginePINVOKE.DocResult_DocumentsBegin(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocumentsIterator DocumentsEnd() {
    DocumentsIterator ret = new DocumentsIterator(csdocenginePINVOKE.DocResult_DocumentsEnd(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void Serialize(Serializer serializer) {
    csdocenginePINVOKE.DocResult_Serialize(swigCPtr, Serializer.getCPtr(serializer));
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual DocPhysicalDocument GetPhysicalDocument(int idx) {
    DocPhysicalDocument ret = new DocPhysicalDocument(csdocenginePINVOKE.DocResult_GetPhysicalDocument(swigCPtr, idx), false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocPhysicalDocument GetPhysicalDocumentPtr(int idx) {
    global::System.IntPtr cPtr = csdocenginePINVOKE.DocResult_GetPhysicalDocumentPtr(swigCPtr, idx);
    DocPhysicalDocument ret = (cPtr == global::System.IntPtr.Zero) ? null : new DocPhysicalDocument(cPtr, false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual int GetScenesCount() {
    int ret = csdocenginePINVOKE.DocResult_GetScenesCount(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocSceneInfo GetSceneInfo(int idx) {
    DocSceneInfo ret = new DocSceneInfo(csdocenginePINVOKE.DocResult_GetSceneInfo(swigCPtr, idx), false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocSceneInfo GetLastSceneInfo() {
    DocSceneInfo ret = new DocSceneInfo(csdocenginePINVOKE.DocResult_GetLastSceneInfo(swigCPtr), false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocGraphicalStructure GetGraphicalStructure() {
    DocGraphicalStructure ret = new DocGraphicalStructure(csdocenginePINVOKE.DocResult_GetGraphicalStructure(swigCPtr), false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocGraphicalStructure GetMutableGraphicalStructure() {
    DocGraphicalStructure ret = new DocGraphicalStructure(csdocenginePINVOKE.DocResult_GetMutableGraphicalStructure(swigCPtr), false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual Document GetMutableDocument(int doc_id) {
    Document ret = new Document(csdocenginePINVOKE.DocResult_GetMutableDocument(swigCPtr, doc_id), false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocTagsCollection GetDocumentTags(int doc_id) {
    DocTagsCollection ret = new DocTagsCollection(csdocenginePINVOKE.DocResult_GetDocumentTags(swigCPtr, doc_id), false);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocumentsMutableIterator AddDocument(Document doc) {
    DocumentsMutableIterator ret = new DocumentsMutableIterator(csdocenginePINVOKE.DocResult_AddDocument(swigCPtr, Document.getCPtr(doc)), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void SetDocument(int doc_id, Document doc) {
    csdocenginePINVOKE.DocResult_SetDocument(swigCPtr, doc_id, Document.getCPtr(doc));
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual void RemoveDocument(int doc_id) {
    csdocenginePINVOKE.DocResult_RemoveDocument(swigCPtr, doc_id);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual DocumentsMutableIterator MutableDocumentsBegin() {
    DocumentsMutableIterator ret = new DocumentsMutableIterator(csdocenginePINVOKE.DocResult_MutableDocumentsBegin(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocumentsMutableIterator MutableDocumentsEnd() {
    DocumentsMutableIterator ret = new DocumentsMutableIterator(csdocenginePINVOKE.DocResult_MutableDocumentsEnd(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocumentsSliceIterator DocumentsSlice(string tag) {
    DocumentsSliceIterator ret = new DocumentsSliceIterator(csdocenginePINVOKE.DocResult_DocumentsSlice(swigCPtr, tag), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual DocumentsMutableSliceIterator MutableDocumentsSlice(string tag) {
    DocumentsMutableSliceIterator ret = new DocumentsMutableSliceIterator(csdocenginePINVOKE.DocResult_MutableDocumentsSlice(swigCPtr, tag), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual bool CanBuildPDFABuffer() {
    bool ret = csdocenginePINVOKE.DocResult_CanBuildPDFABuffer(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void BuildPDFABuffer() {
    csdocenginePINVOKE.DocResult_BuildPDFABuffer(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual void GetPDFABuffer(byte[] output_buf, ulong buf_size) {
    csdocenginePINVOKE.DocResult_GetPDFABuffer(swigCPtr, output_buf, buf_size);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual int GetPDFABufferSize() {
    int ret = csdocenginePINVOKE.DocResult_GetPDFABufferSize(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void SetAddTextMode(string mode_name) {
    csdocenginePINVOKE.DocResult_SetAddTextMode(swigCPtr, mode_name);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual string GetAddTextMode() {
    string ret = csdocenginePINVOKE.DocResult_GetAddTextMode(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual bool HasAddTextMode(string mode_name) {
    bool ret = csdocenginePINVOKE.DocResult_HasAddTextMode(swigCPtr, mode_name);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual StringsVectorIterator AddTextModesBegin() {
    StringsVectorIterator ret = new StringsVectorIterator(csdocenginePINVOKE.DocResult_AddTextModesBegin(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual StringsVectorIterator AddTextModesEnd() {
    StringsVectorIterator ret = new StringsVectorIterator(csdocenginePINVOKE.DocResult_AddTextModesEnd(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void SetTextTypeMode(string mode_name) {
    csdocenginePINVOKE.DocResult_SetTextTypeMode(swigCPtr, mode_name);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual string GetTextTypeMode() {
    string ret = csdocenginePINVOKE.DocResult_GetTextTypeMode(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual bool HasTextTypeMode(string mode_name) {
    bool ret = csdocenginePINVOKE.DocResult_HasTextTypeMode(swigCPtr, mode_name);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual StringsVectorIterator TextTypeModesBegin() {
    StringsVectorIterator ret = new StringsVectorIterator(csdocenginePINVOKE.DocResult_TextTypeModesBegin(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual StringsVectorIterator TextTypeModesEnd() {
    StringsVectorIterator ret = new StringsVectorIterator(csdocenginePINVOKE.DocResult_TextTypeModesEnd(swigCPtr), true);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void SetColourMode(bool with_colour) {
    csdocenginePINVOKE.DocResult_SetColourMode(swigCPtr, with_colour);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual bool GetColourMode() {
    bool ret = csdocenginePINVOKE.DocResult_GetColourMode(swigCPtr);
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}

}
