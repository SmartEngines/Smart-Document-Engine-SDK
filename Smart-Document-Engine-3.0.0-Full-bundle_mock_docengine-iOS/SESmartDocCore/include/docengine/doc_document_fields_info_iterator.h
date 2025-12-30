/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_document_fields_info_iterator.h
 * @brief Classes of Smart Document Engine fields iterators
 */

#ifndef DOCENGINE_DOC_DOCUMENT_FIELDS_INFO_ITERATOR_H_INCLUDED
#define DOCENGINE_DOC_DOCUMENT_FIELDS_INFO_ITERATOR_H_INCLUDED

#include <secommon/se_export_defs.h>
#include <docengine/doc_forward_declarations.h>

namespace se { namespace doc {

/// Forward declaration for the internal implementation of
///     the DocDocumentFieldsInfoIterator class
class DocDocumentFieldsInfoIteratorImpl;

/**
 * @brief Const-ref iterator for a collection of document fields info
 */
class SE_DLL_EXPORT DocDocumentFieldsInfoIterator {
private:
  /// Private ctor from internal implementation
  DocDocumentFieldsInfoIterator(const DocDocumentFieldsInfoIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocDocumentFieldsInfoIterator(const DocDocumentFieldsInfoIterator& other);
  /// Assignment operator
  DocDocumentFieldsInfoIterator& operator =(const DocDocumentFieldsInfoIterator& other);
  /// Non-trivial dtor
  ~DocDocumentFieldsInfoIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocDocumentFieldsInfoIterator ConstructFromImpl(
      const DocDocumentFieldsInfoIteratorImpl& pimpl);

  /// Returns the field name (the collection key)
  const char* GetKey() const;
  /// Returns the field value (const ref)
  const DocDocumentFieldInfo& GetDocumentFieldInfo() const;
  /// Returns the field value (const ptr)
  const DocDocumentFieldInfo* GetDocumentFieldInfoPtr() const;
  /// Switches the iterator to point on the next field in its collection
  void Advance();
  /// Switches the iterator to point on the next field in its collection
  void operator ++();

  /// Returns true iff this instance and rvalue point to the same field
  bool Equals(const DocDocumentFieldsInfoIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same field
  bool operator ==(const DocDocumentFieldsInfoIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the different fields
  bool operator !=(const DocDocumentFieldsInfoIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  class DocDocumentFieldsInfoIteratorImpl* pimpl_;
};







} } // namespace se::doc

#endif // DOCENGINE_DOC_DOCUMENT_FIELDS_INFO_ITERATOR_H_INCLUDED
