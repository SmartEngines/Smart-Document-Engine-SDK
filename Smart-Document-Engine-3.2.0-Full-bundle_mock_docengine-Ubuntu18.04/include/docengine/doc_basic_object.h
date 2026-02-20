/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_basic_object.h
 * @brief Basic graphical object for Smart Document Engine
 */

#ifndef DOCENGINE_DOC_BASIC_OBJECT_H_INCLUDED
#define DOCENGINE_DOC_BASIC_OBJECT_H_INCLUDED

#include <docengine/doc_forward_declarations.h>
#include <secommon/se_common.h>

namespace se { namespace doc {


/**
 * @brief The class representing basic information about a graphical object
 */
class SE_DLL_EXPORT DocBaseObjectInfo {
public:
  /// Default dtor
  virtual ~DocBaseObjectInfo() = default;

  /// Returns the object confidence value (double in range [0.0, 1.0])
  virtual double GetConfidence() const = 0;
  /// Returns the object acceptance flag
  virtual bool GetAcceptFlag() const = 0;

  /// Returns the object geometry in a Polygon form, in a coordinate space of
  ///     the page image in which this object is placed (const ref)
  virtual const se::common::Polygon& GetGeometryOnPage() const = 0;

  /// Returns the object geometry in a Polygon form, in a coordinate space of
  ///     the page image in which this object is placed (const ptr)
  virtual const se::common::Polygon* GetGeometryOnPagePtr() const = 0;

  /// Returns the object geometry in a Polygon form, in a coordinate space of
  ///     the scene image in which this object is placed (const ref)
  virtual const se::common::Polygon& GetGeometryOnScene() const = 0;

  /// Returns the object geometry in a Polygon form, in a coordinate space of
  ///     the scene image in which this object is placed (const ptr)
  virtual const se::common::Polygon* GetGeometryOnScenePtr() const = 0;

  /// Gets the number of attributes of the object
  virtual int GetAttributesCount() const = 0;
  /// Returns true iff there is an object attribute with a given name
  virtual bool HasAttribute(const char* attr_name) const = 0;
  /// Returns the value of an object attribute with a given name
  virtual const char* GetAttribute(const char* attr_name) const = 0;
  /// Return a 'begin' map-like iterator for the object attributes
  virtual se::common::StringsMapIterator AttributesBegin() const = 0;
  /// Return an 'end' map-like iterator for the object attributes
  virtual se::common::StringsMapIterator AttributesEnd() const = 0;

  /// Serializes the object info instance with a given serializer object
  virtual void Serialize(se::common::Serializer& serializer) const = 0;

public:
  /// METHODS TO BE DEPRECATED
  /// THESE METHODS ARE A PART OF THE OLD INTERFACE
  /// THEY ARE TO BE DELETED IN FUTURE VERSIONS

  /// Sets the object confidence value (double in range [0.0, 1.0])
  /// Method to be deprecated
  virtual void SetConfidence(double conf) = 0;
  /// Sets the object acceptance flag
  /// Method to be deprecated
  virtual void SetAcceptFlag(bool is_accepted) = 0;
  /// Sets an object attribute (key-value pair)
  /// Method to be deprecated
  virtual void SetAttribute(const char* attr_name, const char* attr_value) = 0;
  /// Removes the object attribute with a given name
  /// Method to be deprecated
  virtual void RemoveAttribute(const char* attr_name) = 0;

  /// Returns the object geometry in a Polygon form, in a coordinate space of
  ///     the collection in which this object is placed (const ref)
  /// Method to be deprecated
  virtual const se::common::Polygon& GetGeometry() const = 0;
  /// Returns the object geometry in a Polygon form, in a coordinate space of
  ///     the collection in which this object is placed (mutable ref)
  /// Method to be deprecated
  virtual se::common::Polygon& GetMutableGeometry() = 0;
  /// Returns the object geometry in a Polygon form, in a coordinate space of
  ///     the collection in which this object is placed (const ptr)
  /// Method to be deprecated
  virtual const se::common::Polygon* GetGeometryPtr() const = 0;
  /// Returns the object geometry in a Polygon form, in a coordinate space of
  ///     the collection in which this object is placed (mutable ptr)
  /// Method to be deprecated
  virtual se::common::Polygon* GetMutableGeometryPtr() = 0;
  /// Sets the object geometry in a Polygon form, in a coordinate space of
  ///     the collection in which this object is placed
  /// Method to be deprecated
  virtual void SetGeometry(const se::common::Polygon& geometry) = 0;
  /// Returns an ID of a DocView which is associated with this object
  /// Method to be deprecated
  virtual int GetViewID() const = 0;
  /// Sets an ID of a DocView which is associated with this object
  /// Method to be deprecated
  virtual void SetViewID(int view_id) = 0;

};


/**
 * @brief The class representing a basic graphical object
 */
class SE_DLL_EXPORT DocBasicObject {
public:
  /// Static class name method, returns 'DocBasicObject'
  static const char* BaseClassNameStatic();

public:
  /// Default dtor
  virtual ~DocBasicObject() = default;

  /// Returns the name of the concrete object type
  virtual const char* ObjectType() const = 0;

  /// Returns the general basic object info (const ref)
  virtual const DocBaseObjectInfo& GetBaseObjectInfo() const = 0;
  /// Returns the general basic object info (mutable ref ref)
  virtual DocBaseObjectInfo& GetMutableBaseObjectInfo() = 0;
  /// Returns the general basic object info (const ptr)
  virtual const DocBaseObjectInfo* GetBaseObjectInfoPtr() const = 0;
  /// Returns the general basic object info (mutable ptr)
  virtual DocBaseObjectInfo* GetMutableBaseObjectInfoPtr() = 0;

  /// Serializes the object instance with a given serializer object
  virtual void Serialize(se::common::Serializer& serializer) const = 0;
};


} } // namespace se::doc

#endif // DOCENGINE_DOC_BASIC_OBJECT_H_INCLUDED
