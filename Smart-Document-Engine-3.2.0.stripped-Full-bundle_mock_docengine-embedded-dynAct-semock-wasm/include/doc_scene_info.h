/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_scene_info.h
 * @brief Smart Document Engine information abbout processed scenes
 */

#ifndef DOCENGINE_DOC_SCENE_INFO_H_INCLUDED
#define DOCENGINE_DOC_SCENE_INFO_H_INCLUDED

#include <secommon/se_common.h>
#include <docengine/doc_fields_iterators.h>

namespace se { namespace doc {

/**
 * @brief The class representing basic information about a scene
 */
class SE_DLL_EXPORT DocSceneInfo {

public:

  /// Enumeration of possible image sources
  enum class SceneOriginType {
    UNDEFINED = -1,
    DIGITAL_BORN = 0,
    OPTICAL_SCANNER = 1,
    OPTICAL_CAMERA = 2
  };

  /// Default dtor
  virtual ~DocSceneInfo() = default;

  ///Returns true iff the scene is invalid
  virtual bool IsGarbage() const = 0;

  ///Returns scene ID in the flow
  virtual int SceneID() const = 0;

  ///Returns the number of garbage reasons for the scene
  virtual int GarbageReasonsCount() const = 0;

  ///Returns the garbage reason with a given indice
  virtual const char* GarbageReason(int idx) const = 0;

  ///Returns the scene origin type
  virtual SceneOriginType GetSceneOriginType() const = 0;


  ///Results of scene-based forensic checks

  /// Returns the number of forensic check fields in a document
  virtual int GetForensicCheckFieldsCount() const = 0;
  /// Checks if a forensic check field exists by name
  virtual bool HasForensicCheckField(const char* name) const = 0;
  /// Forensic check field getter by name
  virtual const DocForensicCheckField& GetForensicCheckField(const char* name) const = 0;
  /// Forensic check field getter by name
  virtual const DocForensicCheckField* GetForensicCheckFieldPtr(const char* name) const = 0;
  /// Returns a begin-iterator for an internal collection of forensic check fields
  virtual DocForensicCheckFieldsIterator ForensicCheckFieldsBegin() const = 0;
  /// Returns an end-iterator for an internal collection of forensic check fields
  virtual DocForensicCheckFieldsIterator ForensicCheckFieldsEnd() const = 0;

};



} } // namespace se::doc

#endif // DOCENGINE_DOC_SCENE_INFO_H_INCLUDED
