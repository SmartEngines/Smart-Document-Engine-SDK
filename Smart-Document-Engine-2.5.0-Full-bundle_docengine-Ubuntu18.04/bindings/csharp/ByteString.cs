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

public class ByteString : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  public ByteString(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  public static global::System.Runtime.InteropServices.HandleRef getCPtr(ByteString obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  public static global::System.Runtime.InteropServices.HandleRef swigRelease(ByteString obj) {
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

  ~ByteString() {
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
          cssecommonPINVOKE.delete_ByteString(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public ByteString() : this(cssecommonPINVOKE.new_ByteString__SWIG_0(), true) {
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
  }

  public ByteString(byte[] bytes, uint n) : this(cssecommonPINVOKE.new_ByteString__SWIG_1(bytes, n), true) {
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
  }

  public ByteString(ByteString other) : this(cssecommonPINVOKE.new_ByteString__SWIG_2(ByteString.getCPtr(other)), true) {
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
  }

  public void swap(ByteString other) {
    cssecommonPINVOKE.ByteString_swap(swigCPtr, ByteString.getCPtr(other));
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
  }

  public int GetLength() {
    int ret = cssecommonPINVOKE.ByteString_GetLength(swigCPtr);
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int GetRequiredBase64BufferLength() {
    int ret = cssecommonPINVOKE.ByteString_GetRequiredBase64BufferLength(swigCPtr);
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int CopyBase64ToBuffer(string out_buffer, int buffer_length) {
    int ret = cssecommonPINVOKE.ByteString_CopyBase64ToBuffer(swigCPtr, out_buffer, buffer_length);
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public MutableString GetBase64String() {
    MutableString ret = new MutableString(cssecommonPINVOKE.ByteString_GetBase64String(swigCPtr), true);
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int GetRequiredHexBufferLength() {
    int ret = cssecommonPINVOKE.ByteString_GetRequiredHexBufferLength(swigCPtr);
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int CopyHexToBuffer(string out_buffer, int buffer_length) {
    int ret = cssecommonPINVOKE.ByteString_CopyHexToBuffer(swigCPtr, out_buffer, buffer_length);
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public MutableString GetHexString() {
    MutableString ret = new MutableString(cssecommonPINVOKE.ByteString_GetHexString(swigCPtr), true);
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}

}
