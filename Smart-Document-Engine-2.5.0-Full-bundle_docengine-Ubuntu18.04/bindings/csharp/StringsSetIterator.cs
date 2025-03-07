//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.1.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------

namespace se.common {

public class StringsSetIterator : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  public StringsSetIterator(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  public static global::System.Runtime.InteropServices.HandleRef getCPtr(StringsSetIterator obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  public static global::System.Runtime.InteropServices.HandleRef swigRelease(StringsSetIterator obj) {
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

  ~StringsSetIterator() {
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
          cssecommonPINVOKE.delete_StringsSetIterator(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public StringsSetIterator(StringsSetIterator other) : this(cssecommonPINVOKE.new_StringsSetIterator(StringsSetIterator.getCPtr(other)), true) {
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
  }

  public string GetValue() {
    string ret = cssecommonPINVOKE.StringsSetIterator_GetValue(swigCPtr);
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public bool Equals(StringsSetIterator rvalue) {
    bool ret = cssecommonPINVOKE.StringsSetIterator_Equals(swigCPtr, StringsSetIterator.getCPtr(rvalue));
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Advance() {
    cssecommonPINVOKE.StringsSetIterator_Advance(swigCPtr);
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
  }

}

}
