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

public class Quadrangle : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  public Quadrangle(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  public static global::System.Runtime.InteropServices.HandleRef getCPtr(Quadrangle obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  public static global::System.Runtime.InteropServices.HandleRef swigRelease(Quadrangle obj) {
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

  ~Quadrangle() {
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
          cssecommonPINVOKE.delete_Quadrangle(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public Quadrangle() : this(cssecommonPINVOKE.new_Quadrangle__SWIG_0(), true) {
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
  }

  public Quadrangle(Point a, Point b, Point c, Point d) : this(cssecommonPINVOKE.new_Quadrangle__SWIG_1(Point.getCPtr(a), Point.getCPtr(b), Point.getCPtr(c), Point.getCPtr(d)), true) {
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
  }

  public Point GetPoint(int index) {
    Point ret = new Point(cssecommonPINVOKE.Quadrangle_GetPoint(swigCPtr, index), false);
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public Point GetMutablePoint(int index) {
    Point ret = new Point(cssecommonPINVOKE.Quadrangle_GetMutablePoint(swigCPtr, index), false);
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void SetPoint(int index, Point p) {
    cssecommonPINVOKE.Quadrangle_SetPoint(swigCPtr, index, Point.getCPtr(p));
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
  }

  public Rectangle GetBoundingRectangle() {
    Rectangle ret = new Rectangle(cssecommonPINVOKE.Quadrangle_GetBoundingRectangle(swigCPtr), true);
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Serialize(Serializer serializer) {
    cssecommonPINVOKE.Quadrangle_Serialize(swigCPtr, Serializer.getCPtr(serializer));
    if (cssecommonPINVOKE.SWIGPendingException.Pending) throw cssecommonPINVOKE.SWIGPendingException.Retrieve();
  }

}

}
