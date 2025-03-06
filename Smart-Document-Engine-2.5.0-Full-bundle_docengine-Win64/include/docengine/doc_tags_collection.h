/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_tags_collection.h
 * @brief Smart Document Engine tags collection
 */

#ifndef DOCENGINE_DOC_TAGS_COLLECTION_H_INCLUDED
#define DOCENGINE_DOC_TAGS_COLLECTION_H_INCLUDED

#include <secommon/se_common.h>
#include <docengine/doc_fields_iterators.h>

namespace se { namespace doc {

/**
 * @brief The class representing the collection of tags
 * CLASS TO BE DEPRECATED
 */
class SE_DLL_EXPORT DocTagsCollection {
public:
  /// Default dtor
  virtual ~DocTagsCollection() = default;

  /// Returns the number of tags
  virtual int GetTagsCount() const = 0;
  /// Returns true iff there is a tag with a given name in the collection
  virtual bool HasTag(const char* tag) const = 0;
  /// Adds a tag with a given name to the collection
  virtual void AddTag(const char* tag) = 0;
  /// Removes a tag with a given name from the collection
  virtual void RemoveTag(const char* tag) = 0;

  /// Returns a 'begin' set-like iterator to the collection
  virtual se::common::StringsSetIterator TagsBegin() const = 0;
  /// Returns an 'end' set-like iterator to the collection
  virtual se::common::StringsSetIterator TagsEnd() const = 0;

  /// Serializes the tags collection instance with a given serializer object
  virtual void Serialize(se::common::Serializer& serializer) const = 0;

public:
  /**
   * @brief Creates a new DocTagsCollection object
   * @return A newly created object with empty collection. The object is
   *         allocated, the caller is responsible for deleting it.
   */
  static DocTagsCollection* Create();
};


} } // namespace se::doc

#endif // DOCENGINE_DOC_TAGS_COLLECTION_H_INCLUDED
