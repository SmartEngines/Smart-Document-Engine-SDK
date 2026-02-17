/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_document_field_info.h
 * @brief Reference information about fields in document
 */

#ifndef DOCENGINE_DOC_DOCUMENT_FIELD_INFO_H_INCLUDED
#define DOCENGINE_DOC_DOCUMENT_FIELD_INFO_H_INCLUDED

#include <secommon/se_export_defs.h>
#include <docengine/doc_document_fields_info_iterator.h>

namespace se { namespace doc{

/**
  * @brief  Reference information about fields in document
  */
class SE_DLL_EXPORT DocDocumentFieldInfo {
public:
  /// Default dtor
  virtual ~DocDocumentFieldInfo() = default;

  /// Returns human-readable name of the field
  virtual const char* GetDocumentFieldName() const = 0;

  /// Returns human-readable name of the field in the local language
  virtual const char* GetDocumentFieldNameLocal() const = 0;

  /// Returns human-readable short name of the field in the local language
  virtual const char* GetDocumentFieldShortNameLocal() const = 0;

  /// Returns human-readable format of the field
  virtual const char* GetDocumentFieldFormat() const = 0;

  /// Return human-readable extended format of the field
  virtual const char* GetDocumentFieldExtFormat() const = 0;

  /// Returns human-readable type of the field
  virtual const char* GetDocumentFieldType() const = 0;

  /// Returns a 'begin' iterator to the map of reference information about table field's columns
  virtual DocDocumentTableFieldColumnsInfoInterator DocumentTableFieldColumnsInfoInteratorBegin() const = 0;

  /// Returns a 'end' iterator to the map of reference information about table field's columns
  virtual DocDocumentTableFieldColumnsInfoInterator DocumentTableFieldColumnsInfoInteratorEnd() const = 0;

  /// Returns document table field column info (const ref)
  virtual const DocDocumentTableFieldColumnInfo& GetDocumentTableFieldColumnInfo(const char* name) const = 0;

  /// Returns document table field column info (const ptr)
  virtual const DocDocumentTableFieldColumnInfo* GetDocumentTableFieldColumnInfoPtr(const char* name) const = 0;

};


class SE_DLL_EXPORT DocDocumentTableFieldColumnInfo {
public:
  /// Default dtor
  virtual ~DocDocumentTableFieldColumnInfo() = default;

  /// Returns human-readable name of the field
  virtual const char* GetDocumentTableFieldColumnName() const = 0;

  /// Returns human-readable name of the field in the local language
  virtual const char* GetDocumentTableFieldColumnNameLocal() const = 0;

  /// Returns human-readable short name of the field in the local language
  virtual const char* GetDocumentTableFieldColumnShortNameLocal() const = 0;

  /// Returns human-readable format of the field
  virtual const char* GetDocumentTableFieldColumnFormat() const = 0;

  /// Return human-readable extended format of the field
  virtual const char* GetDocumentTableFieldColumnExtFormat() const = 0;

  /// Returns human-readable type of the field
  virtual const char* GetDocumentTableFieldColumnType() const = 0;


};


}} // namespace se::doc

#endif // DOCENGINE_DOC_DOCUMENT_FIELD_INFO_H_INCLUDED
