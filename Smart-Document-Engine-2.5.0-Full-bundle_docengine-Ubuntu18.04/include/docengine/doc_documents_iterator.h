/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_documents_iterator.h
 * @brief Smart Document Engine documents iterator
 */

#ifndef DOCENGINE_DOC_DOCUMENTS_ITERATOR_H_INCLUDED
#define DOCENGINE_DOC_DOCUMENTS_ITERATOR_H_INCLUDED

#include <secommon/se_export_defs.h>
#include <docengine/doc_forward_declarations.h>

namespace se { namespace doc {

/// Forward declaration for the internal implementation of
///     the DocumentsIterator class
class DocumentsIteratorImpl;

/**
 * @brief A constant iterator for a collection of Document instances
 */
class SE_DLL_EXPORT DocumentsIterator {
private:
  /// Private ctor from internal implementation
  DocumentsIterator(const DocumentsIteratorImpl& pimpl);
public:
  /// Copy ctor
  DocumentsIterator(const DocumentsIterator& other);
  /// Assignment operator
  DocumentsIterator& operator =(const DocumentsIterator& other);
  /// Dtor (non-trivial)
  ~DocumentsIterator();

  /// A public handle for the internal ctor
  static DocumentsIterator ConstructFromImpl(
      const DocumentsIteratorImpl& pimpl);

  /// Returns a document ID
  int GetID() const;
  /// Constant getter for the document instance
  const Document& GetDocument() const;
  /// Constant getter for the document instance
  const Document* GetDocumentPtr() const;
  /// Moves the iterator to the next object in a collection
  void Advance();
  /// Operator which moves the iterator to the next object in a collection
  void operator ++();

  /// Checks whether the iterator points to the same object as rvalue
  bool Equals(const DocumentsIterator& rvalue) const;
  /// Operator which checks whether the iterator points to the same object
  bool operator ==(const DocumentsIterator& rvalue) const;
  /// Operator which checks whether the iterator points to a different object
  bool operator !=(const DocumentsIterator& rvalue) const;

public:
  /// METHODS TO BE DEPRECETED
  /// THESE METHODS ARE PART OF THE OLD INTERFACE
  /// THEY ARE TO BE DELETED IN FUTURE VERSIONS
  /// Returns a collection of tags associated with a document in the collection
  const DocTagsCollection& GetTags() const;
  /// Returns a collection of tags associated with a document in the collection
  const DocTagsCollection* GetTagsPtr() const;

private:
  /// Internal representation of the iterator
  DocumentsIteratorImpl* pimpl_;
};

/// Forward declaration for the internal implementation of
///     the DocumentsMutableIterator class
class DocumentsMutableIteratorImpl;

/**
 * @brief A mutable iterator for a collection of Document instances
 */
class SE_DLL_EXPORT DocumentsMutableIterator {
private:
  /// Private ctor from internal implementation
  DocumentsMutableIterator(const DocumentsMutableIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocumentsMutableIterator(const DocumentsMutableIterator& other);
  /// Assignment operator
  DocumentsMutableIterator& operator =(const DocumentsMutableIterator& other);
  /// Dtor (non-trivial)
  ~DocumentsMutableIterator();

  /// A public handle for the main ctor
  static DocumentsMutableIterator ConstructFromImpl(
      const DocumentsMutableIteratorImpl& pimpl);

  /// Returns a document ID
  int GetID() const;
  /// Constant getter for the document instance
  const Document& GetDocument() const;
  /// Mutable getter for the document instance
  Document& GetMutableDocument() const;
  /// Constant getter for the document instance
  const Document* GetDocumentPtr() const;
  /// Mutable getter for the document instance
  Document* GetMutableDocumentPtr() const;
  /// Moves the iterator to the next object in a collection
  void Advance();
  /// Operator which moves the iterator to the next object in a collection
  void operator ++();

  /// Checks whether the iterator points to the same object as rvalue
  bool Equals(const DocumentsMutableIterator& rvalue) const;
  /// Operator which checks whether the iterator points to the same object
  bool operator ==(const DocumentsMutableIterator& rvalue) const;
  /// Operator which checks whether the iterator points to a different object
  bool operator !=(const DocumentsMutableIterator& rvalue) const;

public:
  /// METHODS TO BE DEPRECETED
  /// THESE METHODS ARE PART OF THE OLD INTERFACE
  /// THEY ARE TO BE DELETED IN FUTURE VERSIONS
  /// Returns a collection of tags associated with a document in the collection
  const DocTagsCollection& GetTags() const;
  /// Returns a collection of tags associated with a document in the collection
  const DocTagsCollection* GetTagsPtr() const;

private:
  /// Internal representation of the iterator
  DocumentsMutableIteratorImpl* pimpl_;
};


/// CLASSES TO BE DEPRECETED
/// THESE CLASSES ARE PART OF THE OLD INTERFACE
/// THEY ARE TO BE DELETED IN FUTURE VERSIONS

/// Forward declaration for the internal implementation of
///     the DocumentsSliceIterator class
class DocumentsSliceIteratorImpl;

/**
 * @brief A const iterator for a subset of the collection of Document instances
 * TO BE DEPRECATED
 */
class SE_DLL_EXPORT DocumentsSliceIterator {
private:
  /// Private ctor from internal implementation
  DocumentsSliceIterator(const DocumentsSliceIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocumentsSliceIterator(const DocumentsSliceIterator& other);
  /// Assignment operator
  DocumentsSliceIterator& operator =(const DocumentsSliceIterator& other);
  /// Dtor (non-trivial)
  ~DocumentsSliceIterator();

  /// A public handle for the main ctor
  static DocumentsSliceIterator ConstructFromImpl(
      const DocumentsSliceIteratorImpl& pimpl);

  /// Returns a document ID
  int GetID() const;
  /// Constant getter for the document instance
  const Document& GetDocument() const;
  /// Returns a collection of tags associated with a document in the collection
  const DocTagsCollection& GetTags() const;
  /// Constant getter for the document instance
  const Document* GetDocumentPtr() const;
  /// Returns a collection of tags associated with a document in the collection
  const DocTagsCollection* GetTagsPtr() const;
  /// Moves the iterator to the next object in a collection
  void Advance();
  /// Operator which moves the iterator to the next object in a collection
  void operator ++();

  /// Returns true when the iterator reached the end of the subset
  bool Finished() const;

private:
  /// Internal representation of the iterator
  DocumentsSliceIteratorImpl* pimpl_;
};


/// Forward declaration for the internal implementation of
///     the DocumentsMutableSliceIterator class
class DocumentsMutableSliceIteratorImpl;

/**
 * @brief A mutable iterator for a subset of the collection of
 *        Document instances
 *        TO BE DEPRECATED
 */
class SE_DLL_EXPORT DocumentsMutableSliceIterator {
private:
  /// Private ctor from internal implementation
  DocumentsMutableSliceIterator(const DocumentsMutableSliceIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocumentsMutableSliceIterator(const DocumentsMutableSliceIterator& other);
  /// Assignment operator
  DocumentsMutableSliceIterator& operator =(
      const DocumentsMutableSliceIterator& other);
  /// Dtor (non-trivial)
  ~DocumentsMutableSliceIterator();

  /// A public handle for the main ctor
  static DocumentsMutableSliceIterator ConstructFromImpl(
      const DocumentsMutableSliceIteratorImpl& pimpl);

  /// Returns a document ID
  int GetID() const;
  /// Constant getter for the document instance
  const Document& GetDocument() const;
  /// Mutable getter for the document instance
  Document& GetMutableDocument() const;
  /// Returns a collection of tags associated with a document in the collection
  const DocTagsCollection& GetTags() const;
  /// Constant getter for the document instance
  const Document* GetDocumentPtr() const;
  /// Mutable getter for the document instance
  Document* GetMutableDocumentPtr() const;
  /// Returns a collection of tags associated with a document in the collection
  const DocTagsCollection* GetTagsPtr() const;
  /// Moves the iterator to the next object in a collection
  void Advance();
  /// Operator which moves the iterator to the next object in a collection
  void operator ++();

  /// Returns true when the iterator reached the end of the subset
  bool Finished() const;

private:
  /// Internal representation of the iterator
  DocumentsMutableSliceIteratorImpl* pimpl_;
};


} } // namespace se::doc

#endif // DOCENGINE_DOC_DOCUMENTS_ITERATOR_H_INCLUDED
