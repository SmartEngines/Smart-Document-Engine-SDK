/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_graphical_structure.h
 * @brief Classes of Smart Document Engine graphical result structure
 */

#ifndef DOCENGINE_DOC_GRAPHICAL_STRUCTURE_H_INCLUDED
#define DOCENGINE_DOC_GRAPHICAL_STRUCTURE_H_INCLUDED

#include <secommon/se_common.h>
#include <docengine/doc_forward_declarations.h>
#include <docengine/doc_objects_collections_iterator.h>

namespace se { namespace doc {


/**
 * @brief The class represting a graphical structure - a result of graphical
 *        document processing and graphical objects extraction
 *  CLASS TO BE DEPRECATED
 */
class SE_DLL_EXPORT DocGraphicalStructure {
public:
  /// Default dtor
  virtual ~DocGraphicalStructure() = default;

  /// Returns the number of object collections
  virtual int GetCollectionsCount() const = 0;
  /// Returns true iff there is a collection with a given ID
  virtual bool HasCollection(int c_id) const = 0;
  /// Returns the collection with a given ID (const ref)
  virtual const DocObjectsCollection& GetCollection(int c_id) const = 0;
  /// Returns the collection with a given ID (mutable ref)
  virtual DocObjectsCollection& GetMutableCollection(int c_id) = 0;
  /// Returns the tags associated with a collection with a given ID
  virtual const DocTagsCollection& GetCollectionTags(int c_id) const = 0;
  /// Returns the collection with a given ID (const ptr)
  virtual const DocObjectsCollection* GetCollectionPtr(int c_id) const = 0;
  /// Returns the collection with a given ID (mutable ptr)
  virtual DocObjectsCollection* GetMutableCollectionPtr(int c_id) = 0;
  /// Returns the tags associated with a collection with a given ID
  virtual const DocTagsCollection* GetCollectionTagsPtr(int c_id) const = 0;
  /// Adds a new object collection to the graphical structure
  virtual DocObjectsCollectionsMutableIterator AddCollection(
      const DocObjectsCollection& collection) = 0;
  /// Adds a new object collection to the graphical structure
  virtual DocObjectsCollectionsMutableIterator AddCollection(
      const DocObjectsCollection& collection,
      const DocTagsCollection& tags) = 0;
  /// Sets a new object collection by the given ID
  virtual void SetCollection(
      int c_id, const DocObjectsCollection& collection) = 0;
  /// Removes the object collection with a given ID
  virtual void RemoveCollection(int c_id) = 0;

  /// Returns a constant 'begin' iterator to the object collections
  virtual DocObjectsCollectionsIterator ObjectsCollectionsBegin() const = 0;
  /// Returns a constant 'end' iterator to the object collections
  virtual DocObjectsCollectionsIterator ObjectsCollectionsEnd() const = 0;

  /// Returns a mutable 'begin' iterator to the object collections
  virtual DocObjectsCollectionsMutableIterator
  MutableObjectsCollectionsBegin() = 0;
  /// Returns a mutable 'end' iterator to the object collections
  virtual DocObjectsCollectionsMutableIterator
  MutableObjectsCollectionsEnd() = 0;

  /// Returns a const iterator to the object collections
  ///     with a given tag
  virtual DocObjectsCollectionsSliceIterator ObjectsCollectionsSlice(
      const char* tag) const = 0;

  /// Returns a mutable iterator to the object collections
  ///     with a given tag
  virtual DocObjectsCollectionsMutableSliceIterator MutableObjectsCollectionsSlice(
      const char* tag) = 0;

  /// Returns the collection of view in the graphical structure (const ref)
  virtual const DocViewsCollection& GetViewsCollection() const = 0;
  /// Returns the collection of view in the graphical structure (mutable ref)
  virtual DocViewsCollection& GetMutableViewsCollection() = 0;
  /// Returns the collection of view in the graphical structure (const ptr)
  virtual const DocViewsCollection* GetViewsCollectionPtr() const = 0;
  /// Returns the collection of view in the graphical structure (mutable ptr)
  virtual DocViewsCollection* GetMutableViewsCollectionPtr() = 0;

  /// Serializes the instance with a given serializer object
  virtual void Serialize(se::common::Serializer& serializer) const = 0;
};


} } // namespace se::doc

#endif // DOCENGINE_DOC_GRAPHICAL_STRUCTURE_H_INCLUDED
