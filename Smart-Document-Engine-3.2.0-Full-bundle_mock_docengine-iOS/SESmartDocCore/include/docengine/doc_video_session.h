/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_video_session.h
 * @brief Smart Document Engine video processing session
 */

#ifndef DOCENGINE_DOC_VIDEO_SESSION_H_INCLUDED
#define DOCENGINE_DOC_VIDEO_SESSION_H_INCLUDED

#include <secommon/se_common.h>
#include <docengine/doc_forward_declarations.h>

namespace se { namespace doc {


/**
 * @brief The class representing video processing session
 * CLASS TO BE DEPRECATED
 */
class SE_DLL_EXPORT DocVideoSession {
public:
  /// Default dtor
  virtual ~DocVideoSession() = default;

  /**
   * @brief Creates a processing settings instance
   * @return A newly created processing settings instance. An object is
   *         allocated, the caller is responsible for deleting it.
   */
  virtual DocProcessingSettings* CreateProcessingSettings() const = 0;

  /**
   * @brief Get an activation request for this session (valid for SDK built with dynamic activation feature)
   * @return A string with activation request
   */
  virtual const char* GetActivationRequest() = 0;

  /**
   * @brief Activate current session (valid for SDK built with dynamic activation feature)
   * @param activation_response - the response from activation server
   */
  virtual void Activate(const char* activation_response) = 0;

  /**
   * @brief Check if current session was activated (valid for SDK built with dynamic activation feature)
   * @return Boolen check (true/false)
   */
  virtual bool IsActivated() const = 0;

  /**
   * @brief Launches processing of a video frame with given processing settings
   * @param in_image - input image for processing
   * @param settings - processing settings instance
   */
  virtual void ProcessImage(
      const se::common::Image&     in_image,
      const DocProcessingSettings& settings) = 0;

  /// Resets the internal state of the session
  virtual void Reset() = 0;

  /// Returns the current result (const ref)
  virtual const DocResult& GetCurrentResult() const = 0;
  /// Returns the current result (mutable ref)
  virtual DocResult& GetMutableCurrentResult() = 0;

  /// Returns the current result (const ptr)
  virtual const DocResult* GetCurrentResultPtr() const = 0;
  /// Returns the current result (mutable ptr)
  virtual DocResult* GetMutableCurrentResultPtr() = 0;
};


} } // namespace se::doc

#endif // DOCENGINE_DOC_VIDEO_SESSION_H_INCLUDED
