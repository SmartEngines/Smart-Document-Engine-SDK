/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_view.h
 * @brief Smart Document Engine image view
 */

#ifndef DOCENGINE_DOC_VIEW_H_INCLUDED
#define DOCENGINE_DOC_VIEW_H_INCLUDED

#include <secommon/se_common.h>
#include <docengine/doc_forward_declarations.h>

namespace se { namespace doc {


/**
 * @brief The class representing an image view stored in the graphical structure
 * CLASS TO BE DEPRECATED
 */
class SE_DLL_EXPORT DocView {
public:
  /// Service method, returns object class name
  static const char* BaseClassNameStatic();

public:
  /// Default dtor
  virtual ~DocView() = default;

  /// Returns the associated image (const ref)
  virtual const se::common::Image& GetImage() const = 0;
  /// Returns the associated image (mutable ref)
  virtual se::common::Image& GetMutableImage() = 0;
  /// Returns the associated image (const ptr)
  virtual const se::common::Image* GetImagePtr() const = 0;
  /// Returns the associated image (mutable ptr)
  virtual se::common::Image* GetMutableImagePtr() = 0;
  /// Sets the associated image
  virtual void SetImage(const se::common::Image& image) = 0;

  /// Returns the immediate ancestor view ID in the views tree
  virtual int GetAncestorID() const = 0;
  /// Sets the immediate ancestor view ID in the views tree
  virtual void SetAncestorID(int anc_id) = 0;

  /// Returns the highest ancestor view ID in the views tree
  virtual int GetRootAncestorID() const = 0;
  /// Sets the highest ancestor view ID in the views tree
  virtual void SetRootAncestorID(int root_anc_id) = 0;

  /// Returns the projective transform from immediate ancestor to the current
  ///     view (const ref)
  virtual const se::common::ProjectiveTransform& GetTransform() const = 0;
  /// Returns the projective transform from immediate ancestor to the current
  ///     view (mutable ref)
  virtual se::common::ProjectiveTransform& GetMutableTransform() = 0;
  /// Sets the projective transform from immediate ancestor to the current view
  virtual void SetTransform(const se::common::ProjectiveTransform& transform) = 0;

  /// Returns the projective transform from immediate ancestor to the current
  ///     view (const ptr)
  virtual const se::common::ProjectiveTransform* GetTransformPtr() const = 0;
  /// Returns the projective transform from immediate ancestor to the current
  ///     view (mutable ptr)
  virtual se::common::ProjectiveTransform* GetMutableTransformPtr() = 0;

  /// Serializes the view instance with a given serializer object
  virtual void Serialize(se::common::Serializer& serializer) const = 0;
};


} } // namespace se::doc

#endif // DOCENGINE_DOC_VIEW_H_INCLUDED
