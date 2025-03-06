/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_views_collection.h
 * @brief Smart Document Engine views collection
 */

#ifndef DOCENGINE_DOC_VIEWS_COLLECTION_H_INCLUDED
#define DOCENGINE_DOC_VIEWS_COLLECTION_H_INCLUDED

#include <secommon/se_common.h>
#include <docengine/doc_forward_declarations.h>
#include <docengine/doc_views_iterator.h>

namespace se { namespace doc {


/**
 * @brief The class representing the collection of views
 * CLASS TO BE DEPRECATED
 */
class SE_DLL_EXPORT DocViewsCollection {
public:
  /// Service method, returns object class name
  static const char* BaseClassNameStatic();

public:
  /// Default dtor
  virtual ~DocViewsCollection() = default;

  /// Returns the number of views
  virtual int GetViewsCount() const = 0;
  /// Returns true iff there is a view with a given ID
  virtual bool HasView(int view_id) const = 0;
  /// Returns the view with a given ID (const ref)
  virtual const DocView& GetView(int view_id) const = 0;
  /// Returns the view with a given ID (mutable ref)
  virtual DocView& GetMutableView(int view_id) = 0;
  /// Returns the tags collection of the view with a given ID
  virtual const DocTagsCollection& GetViewTags(int view_id) const = 0;
  /// Returns the view with a given ID (const ptr)
  virtual const DocView* GetViewPtr(int view_id) const = 0;
  /// Returns the view with a given ID (mutable ptr)
  virtual DocView* GetMutableViewPtr(int view_id) = 0;
  /// Returns the tags collection of the view with a given ID
  virtual const DocTagsCollection* GetViewTagsPtr(int view_id) const = 0;

  /**
   * @brief Registers a new top-level view
   * @param image - the image to associate with a new view
   * @return A mutable views iterator pointing to the newly created view
   */
  virtual DocViewsMutableIterator RegisterView(
      const se::common::Image& image) = 0;

  /**
   * @brief Registers a new derived view
   * @param image - the image to associate with a new view
   * @param ancestor_id - the ID of an immediate ancestor
   * @param transform - the projective tranform from immediate ancestor to
   *        the new view
   * @return A mutable views iterator pointing to the newly created view
   */
  virtual DocViewsMutableIterator RegisterDerivedView(
      const se::common::Image&               image,
      int                                    ancestor_id,
      const se::common::ProjectiveTransform& transform) = 0;

  /// Removes all views whose immediate ancestors do not exist
  virtual void DeleteOrphans() = 0;
  /// Removes the view with a given ID
  virtual void DeleteView(int view_id) = 0;

  /// Returns a constant 'begin' iterator to the views collection
  virtual DocViewsIterator ViewsBegin() const = 0;
  /// Returns a constant 'end' iterator to the views collection
  virtual DocViewsIterator ViewsEnd() const = 0;

  /// Returns a mutable 'begin' iterator to the views collection
  virtual DocViewsMutableIterator MutableViewsBegin() = 0;
  /// Returns a mutable 'end' iterator to the views collection
  virtual DocViewsMutableIterator MutableViewsEnd() = 0;

  /// Returns a constant iterator to the subset of views with a given tag
  virtual DocViewsSliceIterator ViewsSlice(const char* tag) const = 0;

  /// Returns a mutable iterator to the subset of views with a given tag
  virtual DocViewsMutableSliceIterator MutableViewsSlice(const char* tag) = 0;

  /// Serializes the instance with a given serializer object
  virtual void Serialize(se::common::Serializer& serializer) const = 0;
};


} } // namespace se::doc

#endif // DOCENGINE_DOC_VIEWS_COLLECTION_H_INCLUDED
