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

public class DocFeedback : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  public DocFeedback(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  public static global::System.Runtime.InteropServices.HandleRef getCPtr(DocFeedback obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  public static global::System.Runtime.InteropServices.HandleRef swigRelease(DocFeedback obj) {
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

  ~DocFeedback() {
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
          csdocenginePINVOKE.delete_DocFeedback(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public virtual void FeedbackReceived(DocFeedbackContainer container) {
    csdocenginePINVOKE.DocFeedback_FeedbackReceived(swigCPtr, DocFeedbackContainer.getCPtr(container));
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual bool AcceptsPagesLocalizationFeedback() {
    bool ret = (SwigDerivedClassHasMethod("AcceptsPagesLocalizationFeedback", swigMethodTypes1) ? csdocenginePINVOKE.DocFeedback_AcceptsPagesLocalizationFeedbackSwigExplicitDocFeedback(swigCPtr) : csdocenginePINVOKE.DocFeedback_AcceptsPagesLocalizationFeedback(swigCPtr));
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void PagesLocalizationFeedbackReceived(DocPagesFeedbackContainer container) {
    csdocenginePINVOKE.DocFeedback_PagesLocalizationFeedbackReceived(swigCPtr, DocPagesFeedbackContainer.getCPtr(container));
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual bool AcceptsPagePreprocessingFeedback() {
    bool ret = (SwigDerivedClassHasMethod("AcceptsPagePreprocessingFeedback", swigMethodTypes3) ? csdocenginePINVOKE.DocFeedback_AcceptsPagePreprocessingFeedbackSwigExplicitDocFeedback(swigCPtr) : csdocenginePINVOKE.DocFeedback_AcceptsPagePreprocessingFeedback(swigCPtr));
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void PagePrepocessingFeedbackReceived(DocPagesFeedbackContainer container) {
    csdocenginePINVOKE.DocFeedback_PagePrepocessingFeedbackReceived(swigCPtr, DocPagesFeedbackContainer.getCPtr(container));
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual bool AcceptsRawFieldsLocalizationFeedback() {
    bool ret = (SwigDerivedClassHasMethod("AcceptsRawFieldsLocalizationFeedback", swigMethodTypes5) ? csdocenginePINVOKE.DocFeedback_AcceptsRawFieldsLocalizationFeedbackSwigExplicitDocFeedback(swigCPtr) : csdocenginePINVOKE.DocFeedback_AcceptsRawFieldsLocalizationFeedback(swigCPtr));
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void RawFieldsLocalizationFeedbackReceived(DocRawFieldsFeedbackContainer container) {
    csdocenginePINVOKE.DocFeedback_RawFieldsLocalizationFeedbackReceived(swigCPtr, DocRawFieldsFeedbackContainer.getCPtr(container));
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual bool AcceptsRawFieldsRecognitionFeedback() {
    bool ret = (SwigDerivedClassHasMethod("AcceptsRawFieldsRecognitionFeedback", swigMethodTypes7) ? csdocenginePINVOKE.DocFeedback_AcceptsRawFieldsRecognitionFeedbackSwigExplicitDocFeedback(swigCPtr) : csdocenginePINVOKE.DocFeedback_AcceptsRawFieldsRecognitionFeedback(swigCPtr));
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual void RawFiedlsRecognitionFeedbackReceived(DocRawFieldsFeedbackContainer container) {
    csdocenginePINVOKE.DocFeedback_RawFiedlsRecognitionFeedbackReceived(swigCPtr, DocRawFieldsFeedbackContainer.getCPtr(container));
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual void ResultReceived(DocResult result_received) {
    csdocenginePINVOKE.DocFeedback_ResultReceived(swigCPtr, DocResult.getCPtr(result_received));
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
  }

  public DocFeedback() : this(csdocenginePINVOKE.new_DocFeedback(), true) {
    if (csdocenginePINVOKE.SWIGPendingException.Pending) throw csdocenginePINVOKE.SWIGPendingException.Retrieve();
    SwigDirectorConnect();
  }

  private void SwigDirectorConnect() {
    if (SwigDerivedClassHasMethod("FeedbackReceived", swigMethodTypes0))
      swigDelegate0 = new SwigDelegateDocFeedback_0(SwigDirectorMethodFeedbackReceived);
    if (SwigDerivedClassHasMethod("AcceptsPagesLocalizationFeedback", swigMethodTypes1))
      swigDelegate1 = new SwigDelegateDocFeedback_1(SwigDirectorMethodAcceptsPagesLocalizationFeedback);
    if (SwigDerivedClassHasMethod("PagesLocalizationFeedbackReceived", swigMethodTypes2))
      swigDelegate2 = new SwigDelegateDocFeedback_2(SwigDirectorMethodPagesLocalizationFeedbackReceived);
    if (SwigDerivedClassHasMethod("AcceptsPagePreprocessingFeedback", swigMethodTypes3))
      swigDelegate3 = new SwigDelegateDocFeedback_3(SwigDirectorMethodAcceptsPagePreprocessingFeedback);
    if (SwigDerivedClassHasMethod("PagePrepocessingFeedbackReceived", swigMethodTypes4))
      swigDelegate4 = new SwigDelegateDocFeedback_4(SwigDirectorMethodPagePrepocessingFeedbackReceived);
    if (SwigDerivedClassHasMethod("AcceptsRawFieldsLocalizationFeedback", swigMethodTypes5))
      swigDelegate5 = new SwigDelegateDocFeedback_5(SwigDirectorMethodAcceptsRawFieldsLocalizationFeedback);
    if (SwigDerivedClassHasMethod("RawFieldsLocalizationFeedbackReceived", swigMethodTypes6))
      swigDelegate6 = new SwigDelegateDocFeedback_6(SwigDirectorMethodRawFieldsLocalizationFeedbackReceived);
    if (SwigDerivedClassHasMethod("AcceptsRawFieldsRecognitionFeedback", swigMethodTypes7))
      swigDelegate7 = new SwigDelegateDocFeedback_7(SwigDirectorMethodAcceptsRawFieldsRecognitionFeedback);
    if (SwigDerivedClassHasMethod("RawFiedlsRecognitionFeedbackReceived", swigMethodTypes8))
      swigDelegate8 = new SwigDelegateDocFeedback_8(SwigDirectorMethodRawFiedlsRecognitionFeedbackReceived);
    if (SwigDerivedClassHasMethod("ResultReceived", swigMethodTypes9))
      swigDelegate9 = new SwigDelegateDocFeedback_9(SwigDirectorMethodResultReceived);
    csdocenginePINVOKE.DocFeedback_director_connect(swigCPtr, swigDelegate0, swigDelegate1, swigDelegate2, swigDelegate3, swigDelegate4, swigDelegate5, swigDelegate6, swigDelegate7, swigDelegate8, swigDelegate9);
  }

  private bool SwigDerivedClassHasMethod(string methodName, global::System.Type[] methodTypes) {
    global::System.Reflection.MethodInfo[] methodInfos = this.GetType().GetMethods(
        global::System.Reflection.BindingFlags.Public | global::System.Reflection.BindingFlags.NonPublic | global::System.Reflection.BindingFlags.Instance);
    foreach (global::System.Reflection.MethodInfo methodInfo in methodInfos) {
      if (methodInfo.DeclaringType == null)
        continue;

      if (methodInfo.Name != methodName)
        continue;

      var parameters = methodInfo.GetParameters();
      if (parameters.Length != methodTypes.Length)
        continue;

      bool parametersMatch = true;
      for (var i = 0; i < parameters.Length; i++) {
        if (parameters[i].ParameterType != methodTypes[i]) {
          parametersMatch = false;
          break;
        }
      }

      if (!parametersMatch)
        continue;

      if (methodInfo.IsVirtual && (methodInfo.DeclaringType.IsSubclassOf(typeof(DocFeedback))) &&
        methodInfo.DeclaringType != methodInfo.GetBaseDefinition().DeclaringType) {
        return true;
      }
    }

    return false;
  }

  private void SwigDirectorMethodFeedbackReceived(global::System.IntPtr container) {
    FeedbackReceived(new DocFeedbackContainer(container, false));
  }

  private bool SwigDirectorMethodAcceptsPagesLocalizationFeedback() {
    return AcceptsPagesLocalizationFeedback();
  }

  private void SwigDirectorMethodPagesLocalizationFeedbackReceived(global::System.IntPtr container) {
    PagesLocalizationFeedbackReceived(new DocPagesFeedbackContainer(container, false));
  }

  private bool SwigDirectorMethodAcceptsPagePreprocessingFeedback() {
    return AcceptsPagePreprocessingFeedback();
  }

  private void SwigDirectorMethodPagePrepocessingFeedbackReceived(global::System.IntPtr container) {
    PagePrepocessingFeedbackReceived(new DocPagesFeedbackContainer(container, false));
  }

  private bool SwigDirectorMethodAcceptsRawFieldsLocalizationFeedback() {
    return AcceptsRawFieldsLocalizationFeedback();
  }

  private void SwigDirectorMethodRawFieldsLocalizationFeedbackReceived(global::System.IntPtr container) {
    RawFieldsLocalizationFeedbackReceived(new DocRawFieldsFeedbackContainer(container, false));
  }

  private bool SwigDirectorMethodAcceptsRawFieldsRecognitionFeedback() {
    return AcceptsRawFieldsRecognitionFeedback();
  }

  private void SwigDirectorMethodRawFiedlsRecognitionFeedbackReceived(global::System.IntPtr container) {
    RawFiedlsRecognitionFeedbackReceived(new DocRawFieldsFeedbackContainer(container, false));
  }

  private void SwigDirectorMethodResultReceived(global::System.IntPtr result_received) {
    ResultReceived(new DocResult(result_received, false));
  }

  public delegate void SwigDelegateDocFeedback_0(global::System.IntPtr container);
  public delegate bool SwigDelegateDocFeedback_1();
  public delegate void SwigDelegateDocFeedback_2(global::System.IntPtr container);
  public delegate bool SwigDelegateDocFeedback_3();
  public delegate void SwigDelegateDocFeedback_4(global::System.IntPtr container);
  public delegate bool SwigDelegateDocFeedback_5();
  public delegate void SwigDelegateDocFeedback_6(global::System.IntPtr container);
  public delegate bool SwigDelegateDocFeedback_7();
  public delegate void SwigDelegateDocFeedback_8(global::System.IntPtr container);
  public delegate void SwigDelegateDocFeedback_9(global::System.IntPtr result_received);

  private SwigDelegateDocFeedback_0 swigDelegate0;
  private SwigDelegateDocFeedback_1 swigDelegate1;
  private SwigDelegateDocFeedback_2 swigDelegate2;
  private SwigDelegateDocFeedback_3 swigDelegate3;
  private SwigDelegateDocFeedback_4 swigDelegate4;
  private SwigDelegateDocFeedback_5 swigDelegate5;
  private SwigDelegateDocFeedback_6 swigDelegate6;
  private SwigDelegateDocFeedback_7 swigDelegate7;
  private SwigDelegateDocFeedback_8 swigDelegate8;
  private SwigDelegateDocFeedback_9 swigDelegate9;

  private static global::System.Type[] swigMethodTypes0 = new global::System.Type[] { typeof(DocFeedbackContainer) };
  private static global::System.Type[] swigMethodTypes1 = new global::System.Type[] {  };
  private static global::System.Type[] swigMethodTypes2 = new global::System.Type[] { typeof(DocPagesFeedbackContainer) };
  private static global::System.Type[] swigMethodTypes3 = new global::System.Type[] {  };
  private static global::System.Type[] swigMethodTypes4 = new global::System.Type[] { typeof(DocPagesFeedbackContainer) };
  private static global::System.Type[] swigMethodTypes5 = new global::System.Type[] {  };
  private static global::System.Type[] swigMethodTypes6 = new global::System.Type[] { typeof(DocRawFieldsFeedbackContainer) };
  private static global::System.Type[] swigMethodTypes7 = new global::System.Type[] {  };
  private static global::System.Type[] swigMethodTypes8 = new global::System.Type[] { typeof(DocRawFieldsFeedbackContainer) };
  private static global::System.Type[] swigMethodTypes9 = new global::System.Type[] { typeof(DocResult) };
}

}
