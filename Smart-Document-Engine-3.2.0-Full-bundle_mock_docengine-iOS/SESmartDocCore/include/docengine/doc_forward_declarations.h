/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_forward_declarations.h
 * @brief Forward declarations for Smart Document Engine classes
 */

#ifndef DOCENGINE_DOC_FORWARD_DECLARATIONS_H_INCLUDED
#define DOCENGINE_DOC_FORWARD_DECLARATIONS_H_INCLUDED

#include <secommon/se_export_defs.h>

namespace se { namespace doc {

class SE_DLL_EXPORT DocTagsCollection;

class SE_DLL_EXPORT DocView;
class SE_DLL_EXPORT DocViewsCollection;
class SE_DLL_EXPORT DocBaseObjectInfo;
class SE_DLL_EXPORT DocBasicObject;
class SE_DLL_EXPORT DocObjectsCollection;
class SE_DLL_EXPORT DocGraphicalStructure;

class SE_DLL_EXPORT DocTemplateObject;
class SE_DLL_EXPORT DocTextObject;
class SE_DLL_EXPORT DocForensicCheckObject;
class SE_DLL_EXPORT DocImageObject;
class SE_DLL_EXPORT DocTableObject;
class SE_DLL_EXPORT DocMultiStringTextObjectImpl;
class SE_DLL_EXPORT DocZoneObject;
class SE_DLL_EXPORT DocCheckboxObject;
class SE_DLL_EXPORT DocLineObject;
class SE_DLL_EXPORT DocTableObject;
class SE_DLL_EXPORT DocMetaObject;
class SE_DLL_EXPORT DocBarcodeObject;
class SE_DLL_EXPORT DocMarkObject;

class SE_DLL_EXPORT DocTextField;
class SE_DLL_EXPORT DocImageField;
class SE_DLL_EXPORT DocCheckboxField;
class SE_DLL_EXPORT DocForensicField;
class SE_DLL_EXPORT DocForensicCheckField;
class SE_DLL_EXPORT DocTableField;
class SE_DLL_EXPORT DocBarcodeField;
class SE_DLL_EXPORT Document;

class SE_DLL_EXPORT DocResult;

class SE_DLL_EXPORT DocSessionSettings;
class SE_DLL_EXPORT DocSession;
class SE_DLL_EXPORT DocVideoSession;
class SE_DLL_EXPORT DocProcessingSettings;
class SE_DLL_EXPORT DocFeedback;
class SE_DLL_EXPORT DocProcessingArguments;
class SE_DLL_EXPORT DocExternalProcessorInterface;

class SE_DLL_EXPORT DocDocumentFieldInfo;
class SE_DLL_EXPORT DocDocumentTableFieldColumnInfo;

} } // namespace se::doc

#endif // DOCENGINE_DOC_FORWARD_DECLARATIONS_H_INCLUDED
