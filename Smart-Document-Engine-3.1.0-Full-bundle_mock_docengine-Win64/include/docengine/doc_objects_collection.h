/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_objects_collection.h
 * @brief Collection of basic objects for Smart Document Engine
 */

#ifndef DOCENGINE_DOC_OBJECTS_COLLECTION_H_INCLUDED
#define DOCENGINE_DOC_OBJECTS_COLLECTION_H_INCLUDED

#include <secommon/se_serialization.h>
#include <secommon/se_export_defs.h>

#include <docengine/doc_forward_declarations.h>
#include <docengine/doc_basic_objects_iterator.h>


namespace se { namespace doc {


/**
 * @brief The class representing a collection of graphical objects
 * CLASS TO BE DEPRECATED
 */
class SE_DLL_EXPORT DocObjectsCollection {
public:
  /// Service method, returns the object name
  static const char* BaseClassNameStatic();

public:
  /**
   * @brief Factory method, creates a new collection for objects with a given
   *        object type name
   * @param object_type - the name of the graphical object type
   * @return A newly created collection. The object is allocated, the caller is
   *         responsible for deleting it.
   */
  static DocObjectsCollection* Create(const char* object_type);

  /**
   * @brief Factory method, creates a new graphical object of the type stored
   *        in this object collection instance
   * @return A newly created graphical object. The object is allocated, the
   *         caller is responsible for deleting it.
   */
  virtual DocBasicObject* CreateObject() const = 0;

public:
  /// Default dtor
  virtual ~DocObjectsCollection() = default;

  /**
   * @brief Clones the collection, returning a deep copy.
   * @return A newly created collection. The object is allocated, the caller is
   *         responsible for deleting it.
   */
  virtual DocObjectsCollection* Clone() const = 0;

  /// Returns the name of the stored graphical object type
  virtual const char* ObjectType() const = 0;

  /// Returns the view ID on which the collected objects are placed
  virtual int GetFrameID() const = 0;
  /// Sets the view ID on which the collected objects are placed
  virtual void SetFrameID(int frame_id) = 0;

  /// Returns the number of stored objects
  virtual int GetObjectsCount() const = 0;
  /// Returns true iff there is a stored object with a given ID
  virtual bool HasObject(int obj_id) const = 0;
  /// Returns the object with a given ID (const ref)
  virtual const DocBasicObject& GetObject(int obj_id) const = 0;
  /// Returns the object with a given ID (mutable ref)
  virtual DocBasicObject& GetMutableObject(int obj_id) = 0;
  /// Returns the object with a given ID (const ptr)
  virtual const DocBasicObject* GetObjectPtr(int obj_id) const = 0;
  /// Returns the object with a given ID (mutable ptr)
  virtual DocBasicObject* GetMutableObjectPtr(int obj_id) = 0;
  /// Returns the tags collection associated with an object with a given ID
  virtual const DocTagsCollection& GetObjectTags(int obj_id) const = 0;
  /// Returns the tags collection associated with an object with a given ID
  virtual const DocTagsCollection* GetObjectTagsPtr(int obj_id) const = 0;
  /// Adds a new object to the collection
  virtual DocBasicObjectsMutableIterator AddObject(
      const DocBasicObject& obj) = 0;
  /// Sets an object value with a given ID
  virtual void SetObject(int obj_id, const DocBasicObject& obj) = 0;
  /// Removes an object with a given ID
  virtual void RemoveObject(int obj_id) = 0;
  /// Removes an object with a given ID and removes the view associated with
  ///     the removed object.
  virtual void RemoveObjectDeep(
      int              obj_id,
      DocViewsCollection& views_collection) = 0;

  /// Returns a constant 'begin' iterator to the collection of objects
  virtual DocBasicObjectsIterator BasicObjectsBegin() const = 0;
  /// Returns a constant 'end' iterator to the collection of objects
  virtual DocBasicObjectsIterator BasicObjectsEnd() const = 0;

  /// Returns a mutable 'begin' iterator to the collection of objects
  virtual DocBasicObjectsMutableIterator MutableBasicObjectsBegin() = 0;
  /// Returns a mutable 'end' iterator to the collection of objects
  virtual DocBasicObjectsMutableIterator MutableBasicObjectsEnd() = 0;

  /// Returns a constant iterator to the subset of objects with a given tag
  virtual DocBasicObjectsSliceIterator BasicObjectsSlice(
      const char* tag) const = 0;

  /// Returns a mutable iterator to the subset of objects with a given tag
  virtual DocBasicObjectsMutableSliceIterator MutableBasicObjectsSlice(
      const char* tag) = 0;

  /// Serializes the collection instance with a given serializer object
  virtual void Serialize(se::common::Serializer& serializer) const = 0;
};


} } // namespace se::doc

#endif // DOCENGINE_DOC_OBJECTS_COLLECTION_H_INCLUDED
