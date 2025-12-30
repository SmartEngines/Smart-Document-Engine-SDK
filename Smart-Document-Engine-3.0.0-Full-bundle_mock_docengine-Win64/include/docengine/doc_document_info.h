/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_document_info.h
 * @brief Reference information about document type
 */

#ifndef DOCENGINE_DOC_DOCUMENT_INFO_H_INCLUDED
#define DOCENGINE_DOC_DOCUMENT_INFO_H_INCLUDED

#include <secommon/se_export_defs.h>
#include <docengine/doc_document_fields_info_iterator.h>

namespace se { namespace doc{

/**
  * @brief Reference information about document type
  */
class SE_DLL_EXPORT DocDocumentInfo {
public:
  /// Default dtor
  virtual ~DocDocumentInfo() = default;

  /// Returns human-readable name of the document
  virtual const char* GetDocumentName() const = 0;

  /// Returns human-readable name of the document in the local language
  virtual const char* GetDocumentNameLocal() const = 0;

  /// Returns human-readable short name of the document in the local language
  virtual const char* GetDocumentShortNameLocal() const = 0;

  /// Returns information about whether fields in the document
  virtual bool GetDocumentNoFields() const = 0;

  /// Returns a 'begin' iterator to the map of reference information about document fields
  virtual DocDocumentFieldsInfoIterator DocumentFieldsInfoBegin() const = 0;
  
  /// Returns an 'end' iterator to the map of reference information about document fields
  virtual DocDocumentFieldsInfoIterator DocumentFieldsInfoEnd() const = 0;

 public:
  /// METHODS TO BE DEPRECATED
  /// THESE METHODS ARE A PART OF THE OLD INTERFACE
  /// THEY ARE TO BE DELETED IN FUTURE VERSIONS

  /// Returns information about whether the document is multipage
  virtual bool GetDocumentMultipageInfo() const = 0;
};


}} // namespace se::doc

#endif // DOCENGINE_DOC_DOCUMENT_INFO_H_INCLUDED
