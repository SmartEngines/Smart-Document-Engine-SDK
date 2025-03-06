/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_views_iterator.h
 * @brief Smart Document Engine views iterator
 */

#ifndef DOCENGINE_DOC_VIEWS_ITERATOR_H_INCLUDED
#define DOCENGINE_DOC_VIEWS_ITERATOR_H_INCLUDED

#include <secommon/se_export_defs.h>
#include <docengine/doc_forward_declarations.h>

namespace se { namespace doc {


/// Forward declaration for the internal implementation of
///     the DocViewsIterator class
class DocViewsIteratorImpl;

/**
 * @brief Basic const-ref iterator for a collection of views
 * CLASS TO BE DEPRECATED
 */
class SE_DLL_EXPORT DocViewsIterator {
private:
  /// Private ctor from internal implementation
  DocViewsIterator(const DocViewsIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocViewsIterator(const DocViewsIterator& other);
  /// Assignment operator
  DocViewsIterator& operator =(const DocViewsIterator& other);
  /// Non-trivial dtor
  ~DocViewsIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocViewsIterator ConstructFromImpl(const DocViewsIteratorImpl& pimpl);

  /// Returns the view ID
  int GetID() const;
  /// Returns the view (const ref)
  const DocView& GetView() const;
  /// Returns the collection of tags associated with this view
  const DocTagsCollection& GetTags() const;
  /// Returns the view (const ptr)
  const DocView* GetViewPtr() const;
  /// Returns the collection of tags associated with this view
  const DocTagsCollection* GetTagsPtr() const;
  /// Switches the iterator to point on the next view
  void Advance();

  /// Returns true iff this instance and rvalue point to the same view
  bool Equals(const DocViewsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same view
  bool operator ==(const DocViewsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to different views
  bool operator !=(const DocViewsIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  DocViewsIteratorImpl* pimpl_;
};


/// Forward declaration for the internal implementation of
///     the DocViewsMutableIterator class
class DocViewsMutableIteratorImpl;

/**
 * @brief Mutable-ref iterator for a collection of views
 */
class SE_DLL_EXPORT DocViewsMutableIterator {
private:
  /// Private ctor from internal implementation
  DocViewsMutableIterator(const DocViewsMutableIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocViewsMutableIterator(const DocViewsMutableIterator& other);
  /// Assignment operator
  DocViewsMutableIterator& operator =(const DocViewsMutableIterator& other);
  /// Non-trivial dtor
  ~DocViewsMutableIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocViewsMutableIterator ConstructFromImpl(
      const DocViewsMutableIteratorImpl& pimpl);

  /// Returns the view ID
  int GetID() const;
  /// Returns the view (const ref)
  const DocView& GetView() const;
  /// Returns the view (mutable ref)
  DocView& GetMutableView() const;
  /// Returns the collection of tags associated with this view
  const DocTagsCollection& GetTags() const;
  /// Returns the view (const ptr)
  const DocView* GetViewPtr() const;
  /// Returns the view (mutable ptr)
  DocView* GetMutableViewPtr() const;
  /// Returns the collection of tags associated with this view
  const DocTagsCollection* GetTagsPtr() const;
  /// Switches the iterator to point on the next view
  void Advance();

  /// Returns true iff this instance and rvalue point to the same view
  bool Equals(const DocViewsMutableIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same view
  bool operator ==(const DocViewsMutableIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to different views
  bool operator !=(const DocViewsMutableIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  DocViewsMutableIteratorImpl* pimpl_;
};


/// Forward declaration for the internal implementation of
///     the DocViewsSliceIterator class
class DocViewsSliceIteratorImpl;

/**
 * @brief Const-ref iterator for views with a given tag
 */
class SE_DLL_EXPORT DocViewsSliceIterator {
private:
  /// Private ctor from internal implementation
  DocViewsSliceIterator(const DocViewsSliceIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocViewsSliceIterator(const DocViewsSliceIterator& other);
  /// Assignment operator
  DocViewsSliceIterator& operator =(const DocViewsSliceIterator& other);
  /// Non-trivial dtor
  ~DocViewsSliceIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocViewsSliceIterator ConstructFromImpl(
      const DocViewsSliceIteratorImpl& pimpl);

  /// Returns the view ID
  int GetID() const;
  /// Returns the view (const ref)
  const DocView& GetView() const;
  /// Returns the collection of tags associated with this view
  const DocTagsCollection& GetTags() const;
  /// Returns the view (const ptr)
  const DocView* GetViewPtr() const;
  /// Returns the collection of tags associated with this view
  const DocTagsCollection* GetTagsPtr() const;
  /// Switches the iterator to point on the next view
  void Advance();

  /// Returns true iff the iterator points to the end of the subset of views
  ///     with a given tag.
  bool Finished() const;

private:
  /// Pointer to internal implementation
  DocViewsSliceIteratorImpl* pimpl_;
};


/// Forward declaration for the internal implementation of
///     the DocViewsMutableSliceIterator class
class DocViewsMutableSliceIteratorImpl;

/**
 * @brief Mutable-ref iterator for views with a given tag
 */
class SE_DLL_EXPORT DocViewsMutableSliceIterator {
private:
  /// Private ctor from internal implementation
  DocViewsMutableSliceIterator(const DocViewsMutableSliceIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocViewsMutableSliceIterator(const DocViewsMutableSliceIterator& other);
  /// Assignment operator
  DocViewsMutableSliceIterator& operator =(
      const DocViewsMutableSliceIterator& other);
  /// Non-trivial dtor
  ~DocViewsMutableSliceIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocViewsMutableSliceIterator ConstructFromImpl(
      const DocViewsMutableSliceIteratorImpl& pimpl);

  /// Returns the view ID
  int GetID() const;
  /// Returns the view (const ref)
  const DocView& GetView() const;
  /// Returns the view (mutable ref)
  DocView& GetMutableView() const;
  /// Returns the collection of tags associated with this view
  const DocTagsCollection& GetTags() const;
  /// Returns the view (const ptr)
  const DocView* GetViewPtr() const;
  /// Returns the view (mutable ptr)
  DocView* GetMutableViewPtr() const;
  /// Returns the collection of tags associated with this view
  const DocTagsCollection* GetTagsPtr() const;
  /// Switches the iterator to point on the next view
  void Advance();

  /// Returns true iff the iterator points to the end of the subset of views
  ///     with a given tag.
  bool Finished() const;

private:
  /// Pointer to internal implementation
  DocViewsMutableSliceIteratorImpl* pimpl_;
};


} } // namespace se::doc

#endif // DOCENGINE_DOC_VIEWS_ITERATOR_H_INCLUDED
