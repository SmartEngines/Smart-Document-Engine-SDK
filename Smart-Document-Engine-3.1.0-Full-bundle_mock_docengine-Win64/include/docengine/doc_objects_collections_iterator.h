/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_objects_collections_iterator.h
 * @brief Smart Document Engine basic graphical objects collections iterator
 */

#ifndef DOCENGINE_DOC_OBJECTS_COLLECTIONS_ITERATOR_H_INCLUDED
#define DOCENGINE_DOC_OBJECTS_COLLECTIONS_ITERATOR_H_INCLUDED

#include <secommon/se_export_defs.h>
#include <docengine/doc_forward_declarations.h>

namespace se { namespace doc {

/// Forward declaration for the internal implementation of
///     the DocObjectsCollectionsIterator class
class DocObjectsCollectionsIteratorImpl;

/**
 * @brief Basic const-ref iterator for graphical object collections
 * CLASS TO BE DEPRECATED
 */
class SE_DLL_EXPORT DocObjectsCollectionsIterator {
private:
  /// Private ctor from internal implementation
  DocObjectsCollectionsIterator(
      const DocObjectsCollectionsIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocObjectsCollectionsIterator(const DocObjectsCollectionsIterator& other);
  /// Assignment operator
  DocObjectsCollectionsIterator& operator =(
      const DocObjectsCollectionsIterator& other);
  /// Non-trivial dtor
  ~DocObjectsCollectionsIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocObjectsCollectionsIterator ConstructFromImpl(
      const DocObjectsCollectionsIteratorImpl& pimpl);

  /// Returns the collection ID
  int GetID() const;
  /// Returns the collection (const ref)
  const DocObjectsCollection& GetObjectsCollection() const;
  /// Returns the tags collection associated with this collection
  const DocTagsCollection& GetTags() const;
  /// Returns the collection (const ptr)
  const DocObjectsCollection* GetObjectsCollectionPtr() const;
  /// Returns the tags collection associated with this collection
  const DocTagsCollection* GetTagsPtr() const;
  /// Switches the iterator to point on the next collection
  void Advance();

  /// Returns true iff this instance and rvalue point to the same collection
  bool Equals(const DocObjectsCollectionsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same collection
  bool operator ==(const DocObjectsCollectionsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to a different collection
  bool operator !=(const DocObjectsCollectionsIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  DocObjectsCollectionsIteratorImpl* pimpl_;
};


/// Forward declaration for the internal implementation of
///     the DocObjectsCollectionsMutableIterator class
class DocObjectsCollectionsMutableIteratorImpl;

/**
 * @brief Mutable-ref iterator for graphical object collections
 */
class SE_DLL_EXPORT DocObjectsCollectionsMutableIterator {
private:
  /// Private ctor from internal implementation
  DocObjectsCollectionsMutableIterator(
      const DocObjectsCollectionsMutableIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocObjectsCollectionsMutableIterator(
      const DocObjectsCollectionsMutableIterator& other);
  /// Assignment operator
  DocObjectsCollectionsMutableIterator& operator =(
      const DocObjectsCollectionsMutableIterator& other);
  /// Non-trivial dtor
  ~DocObjectsCollectionsMutableIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocObjectsCollectionsMutableIterator ConstructFromImpl(
      const DocObjectsCollectionsMutableIteratorImpl& pimpl);

  /// Returns the collection ID
  int GetID() const;
  /// Returns the collection (const ptr)
  const DocObjectsCollection& GetObjectsCollection() const;
  /// Returns the collection (mutable ptr)
  DocObjectsCollection& GetMutableObjectsCollection() const;
  /// Returns the tags collection associated with this collection
  const DocTagsCollection& GetTags() const;

  /// Returns the collection (const ptr)
  const DocObjectsCollection* GetObjectsCollectionPtr() const;
  /// Returns the collection (mutable ptr)
  DocObjectsCollection* GetMutableObjectsCollectionPtr() const;
  /// Returns the tags collection associated with this collection
  const DocTagsCollection* GetTagsPtr() const;
  /// Switches the iterator to point on the next collection
  void Advance();

  /// Returns true iff this instance and rvalue point to the same collection
  bool Equals(const DocObjectsCollectionsMutableIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same collection
  bool operator ==(const DocObjectsCollectionsMutableIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to a different collection
  bool operator !=(const DocObjectsCollectionsMutableIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  DocObjectsCollectionsMutableIteratorImpl* pimpl_;
};


/// Forward declaration for the internal implementation of
///     the DocObjectsCollectionsSliceIterator class
class DocObjectsCollectionsSliceIteratorImpl;


/**
 * @brief Const-ref iterator for graphical object collections with a given tag
 */
class SE_DLL_EXPORT DocObjectsCollectionsSliceIterator {
private:
  /// Private ctor from internal implementation
  DocObjectsCollectionsSliceIterator(
      const DocObjectsCollectionsSliceIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocObjectsCollectionsSliceIterator(
      const DocObjectsCollectionsSliceIterator& other);
  /// Assignment operator
  DocObjectsCollectionsSliceIterator& operator =(
      const DocObjectsCollectionsSliceIterator& other);
  /// Non-trivial dtor
  ~DocObjectsCollectionsSliceIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocObjectsCollectionsSliceIterator ConstructFromImpl(
      const DocObjectsCollectionsSliceIteratorImpl& pimpl);

  /// Returns the collection ID
  int GetID() const;
  /// Returns the collection by const-ref
  const DocObjectsCollection& GetObjectsCollection() const;
  /// Returns the tags collection associated with this collection
  const DocTagsCollection& GetTags() const;
  /// Returns the collection (const ptr)
  const DocObjectsCollection* GetObjectsCollectionPtr() const;
  /// Returns the tags collection associated with this collection
  const DocTagsCollection* GetTagsPtr() const;
  /// Switches the iterator to point on the next collection
  void Advance();

  /// Returns true iff the iterator points to the end of the subset of
  ///     collections with a given tag.
  bool Finished() const;

private:
  /// Pointer to internal implementation
  DocObjectsCollectionsSliceIteratorImpl* pimpl_;
};


/// Forward declaration for the internal implementation of
///     the DocObjectsCollectionsMutableSliceIterator class
class DocObjectsCollectionsMutableSliceIteratorImpl;


/**
 * @brief Const-ref iterator for object collections with a given tag
 */
class SE_DLL_EXPORT DocObjectsCollectionsMutableSliceIterator {
private:
  /// Private ctor from internal implementation
  DocObjectsCollectionsMutableSliceIterator(
      const DocObjectsCollectionsMutableSliceIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocObjectsCollectionsMutableSliceIterator(
      const DocObjectsCollectionsMutableSliceIterator& other);
  /// Assignment operator
  DocObjectsCollectionsMutableSliceIterator& operator =(
      const DocObjectsCollectionsMutableSliceIterator& other);
  /// Non-trivial dtor
  ~DocObjectsCollectionsMutableSliceIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocObjectsCollectionsMutableSliceIterator ConstructFromImpl(
      const DocObjectsCollectionsMutableSliceIteratorImpl& pimpl);

  /// Returns the collection ID
  int GetID() const;
  /// Returns the collection by const-ref
  const DocObjectsCollection& GetObjectsCollection() const;
  /// Returns the collection by mutable-ref
  DocObjectsCollection& GetMutableObjectsCollection() const;
  /// Returns the tags collection associated with this collection
  const DocTagsCollection& GetTags() const;
  /// Returns the collection (const ptr)
  const DocObjectsCollection* GetObjectsCollectionPtr() const;
  /// Returns the collection (mutable ptr)
  DocObjectsCollection* GetMutableObjectsCollectionPtr() const;
  /// Returns the tags collection associated with this collection
  const DocTagsCollection* GetTagsPtr() const;
  /// Switches the iterator to point on the next collection
  void Advance();

  /// Returns true iff the iterator points to the end of the subset of
  ///     collections with a given tag.
  bool Finished() const;

private:
  /// Pointer to internal implementation
  DocObjectsCollectionsMutableSliceIteratorImpl* pimpl_;
};


} } // namespace se::doc

#endif // DOCENGINE_DOC_OBJECTS_COLLECTIONS_ITERATOR_H_INCLUDED
