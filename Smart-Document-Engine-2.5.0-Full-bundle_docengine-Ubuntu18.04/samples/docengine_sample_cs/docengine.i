//  Copyright (c) 2016-2024, Smart Engines Service LLC
//  All rights reserved.

%module(directors="1") csdocengine

%feature("director") se::doc::DocExternalProcessorInterface;
%feature("director") se::doc::DocFeedback;

%include std_map.i
%include std_string.i
%include std_vector.i
%include stdint.i
%include typemaps.i
%include exception.i
%include std_except.i

%include "secommon_include.i"

%{

#include "secommon/se_export_defs.h"
#include "secommon/se_serialization.h"
#include "secommon/se_geometry.h"
#include "secommon/se_image.h"
#include "secommon/se_string.h"
#include "secommon/se_exception.h"
#include "secommon/se_common.h"

#include "docengine/doc_scene_info.h"
#include "docengine/doc_basic_object.h"
#include "docengine/doc_physical_document_iterators.h"
#include "docengine/doc_objects.h"
#include "docengine/doc_basic_objects_iterator.h"
#include "docengine/doc_physical_document.h"
#include "docengine/doc_objects_collection.h"
#include "docengine/doc_objects_collections_iterator.h"
#include "docengine/doc_graphical_structure.h"
#include "docengine/doc_view.h"
#include "docengine/doc_views_collection.h"
#include "docengine/doc_views_iterator.h"
#include "docengine/doc_tags_collection.h"
#include "docengine/doc_forward_declarations.h"
#include "docengine/doc_fields.h"  
#include "docengine/doc_fields_iterators.h"
#include "docengine/doc_document.h"
#include "docengine/doc_document_fields_info_iterator.h"
#include "docengine/doc_document_field_info.h"
#include "docengine/doc_document_info.h"
#include "docengine/doc_documents_iterator.h"
#include "docengine/doc_engine.h"
#include "docengine/doc_external_processor.h"
#include "docengine/doc_result.h"
#include "docengine/doc_processing_settings.h"
#include "docengine/doc_session_settings.h"
#include "docengine/doc_session.h"
#include "docengine/doc_video_session.h"
#include "docengine/doc_feedback.h"
%}


%pragma(csharp) imclassimports=%{
using se.common;
%}

%typemap(csimports) SWIGTYPE %{
using se.common;
%}

%pragma(csharp) imclassimports=%{
using System.Runtime.InteropServices;
using System;
using System.Text;
%}

%pragma(csharp) imclasscode=%{
public class SimpleMarshaler : ICustomMarshaler {
    static SimpleMarshaler myself = new SimpleMarshaler();

    public object MarshalNativeToManaged(IntPtr pNativeData) {
        int size_buffer = 0;
        while (Marshal.ReadByte(pNativeData, size_buffer) != 0) {
            ++size_buffer;
        }
        byte[] byte_buffer = new byte[size_buffer];
        Marshal.Copy((IntPtr)pNativeData, byte_buffer, 0, size_buffer);
        return Encoding.UTF8.GetString(byte_buffer);
    }

    public IntPtr MarshalManagedToNative( Object ManagedObj ) => throw new NotImplementedException();

    public void CleanUpNativeData( IntPtr nativeData ) {
        Marshal.FreeHGlobal(nativeData);
    }

    public void CleanUpManagedData( Object ManagedObj ) => throw new NotImplementedException();
    public int GetNativeDataSize() => throw new NotImplementedException();

    public static ICustomMarshaler GetInstance(string cookie) {
        return myself;
    }
}
%}

SWIG_CSBODY_PROXY(public, public, SWIGTYPE)
SWIG_CSBODY_TYPEWRAPPER(public, public, public, SWIGTYPE)


%exception { 
    try {
        $action
    } catch (const se::common::BaseException& e) {
        SWIG_exception(SWIG_RuntimeError, (std::string(e.ExceptionName()) + ": " + e.what()).c_str());
    } catch (const std::exception& e) {
        SWIG_exception(SWIG_RuntimeError, (std::string("CRITICAL!: STL exception caught: ") + e.what()).c_str());
    } catch (...) {
        SWIG_exception(SWIG_RuntimeError, "CRITICAL!: Unknown exception caught");
    }
}

%apply unsigned char OUTPUT[] { unsigned char* output_buf };

%newobject  se::doc::DocEngine::CreateSessionSettings;
%newobject  se::doc::DocEngine::SpawnSession;
%newobject  se::doc::DocEngine::CreateVideoSessionSettings;
%newobject  se::doc::DocEngine::SpawnVideoSession;
%newobject  se::doc::DocEngine::Create;
%newobject  se::doc::DocEngine::CreateFromEmbeddedBundle;
%newobject  se::doc::DocObjectsCollection::Create;
%newobject  se::doc::DocObjectsCollection::CreateObject;
%newobject  se::doc::DocObjectsCollection::Clone;
%newobject  se::doc::DocSession::CreateProcessingSettings;
%newobject  se::doc::DocSessionSettings::Clone;
%newobject  se::doc::DocVideoSession::CreateProcessingSettings;
%newobject  se::doc::DocTagsCollection::Create;

%ignore   ConstructFromImpl;
%ignore GetGeometryPtr;
%ignore GetMutableGeometryPtr;
%ignore GetBaseObjectInfoPtr;
%ignore GetMutableBaseObjectInfoPtr;
%ignore GetBasicObjectPtr;
%ignore GetTagsPtr;
%ignore GetMutableBasicObjectPtr;
%ignore GetDocumentFieldInfoPtr;
%ignore GetTextFieldPtr;
%ignore GetMutableTextFieldPtr;
%ignore GetImageFieldPtr;
%ignore GetMutableImageFieldPtr;
%ignore GetCheckboxFieldPtr;
%ignore GetMutableCheckboxFieldPtr;
%ignore GetForensicFieldPtr;
%ignore GetMutableForensicFieldPtr;
%ignore GetTableFieldPtr;
%ignore GetMutableTableFieldPtr;
%ignore GetBarcodeFieldPtr;
%ignore GetMutableBarcodeFieldPtr;
%ignore GetDocumentPtr;
%ignore GetMutableDocumentPtr;
%ignore GetBaseFieldInfoPtr;
%ignore GetMutableBaseFieldInfoPtr;
%ignore GetOcrStringPtr;
%ignore GetMutableOcrStringPtr;
%ignore GetImagePtr;
%ignore GetMutableImagePtr;
%ignore GetCellPtr;
%ignore GetMutableCellPtr;
%ignore GetDecodedStringPtr;
%ignore GetMutableDecodedStringPtr;
%ignore GetFieldPtr;
%ignore GetCollectionPtr;
%ignore GetMutableCollectionPtr;
%ignore GetCollectionTagsPtr;
%ignore GetViewsCollectionPtr;
%ignore GetMutableViewsCollectionPtr;
%ignore GetObjectPtr;
%ignore GetMutableObjectPtr;
%ignore GetObjectTagsPtr;
%ignore GetObjectsCollectionPtr;
%ignore GetMutableObjectsCollectionPtr;
%ignore GetSizePtr;
%ignore GetMutableSizePtr;
%ignore GetStringObjectPtr;
%ignore GetMutableStringObjectPtr;
%ignore GetGraphicalStructurePtr;
%ignore GetMutableGraphicalStructurePtr;
%ignore GetDocumentTagsPtr;
%ignore GetMutableCurrentResultPtr;
%ignore GetDocumentInfoPtr;
%ignore GetCurrentResultPtr;
%ignore GetTransformPtr;
%ignore GetMutableTransformPtr;
%ignore GetViewPtr;
%ignore GetMutableViewPtr;
%ignore GetViewTagsPtr;
%ignore AddEmptyDocSuiteSettings;
%ignore GetDocSuiteSettings;
%ignore GetMultableDocSuiteSettings;
%ignore GetDocSuiteSettingsPtr;
%ignore GetMultableDocSuiteSettingsPtr;
%ignore GetDocSuitesCount;
%ignore GetDocSuite;
%ignore GetDocSuitePtr;
%ignore GetMutableSuite;
%ignore GetMutableSuitePtr;
%ignore GetCheckboxObjectPtr;
%ignore GetTextObjectPtr;
%ignore GetForensicCheckObjectPtr;
%ignore GetTableObjectPtr;
%ignore GetImageObjectPtr;

%include "docengine/doc_tags_collection.h"

%typemap(imtype,
         outattributes="\n  [return: global::System.Runtime.InteropServices.MarshalAs(global::System.Runtime.InteropServices.UnmanagedType.CustomMarshaler, MarshalTypeRef = typeof(SimpleMarshaler))] \n ") const char * "string"; 
    %include "docengine/doc_scene_info.h"
    %include "docengine/doc_basic_object.h"
    %include "docengine/doc_objects.h"
    %include "docengine/doc_physical_document_iterators.h"
    %include "docengine/doc_basic_objects_iterator.h"
    %include "docengine/doc_physical_document.h"
    %include "docengine/doc_view.h"
    %include "docengine/doc_views_iterator.h"
    %include "docengine/doc_views_collection.h"
    %include "docengine/doc_objects_collection.h"
    %include "docengine/doc_objects_collections_iterator.h"
    %include "docengine/doc_graphical_structure.h"
    %include "docengine/doc_fields.h" 
    %include "docengine/doc_fields_iterators.h"
    %include "docengine/doc_forward_declarations.h"
    %include "docengine/doc_feedback.h"
    %include "docengine/doc_document.h"
    %include "docengine/doc_document_fields_info_iterator.h"
    %include "docengine/doc_document_field_info.h"
    %include "docengine/doc_document_info.h"
    %include "docengine/doc_documents_iterator.h"
    %include "docengine/doc_engine.h"
    %include "docengine/doc_external_processor.h"
    %include "docengine/doc_result.h"
    %include "docengine/doc_processing_settings.h"
    %include "docengine/doc_session.h"
    %include "docengine/doc_session_settings.h"
    %include "docengine/doc_video_session.h"
%typemap(imtype) const char *;
