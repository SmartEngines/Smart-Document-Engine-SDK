/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_session.h
 * @brief Smart Document Engine image processing session
 */

#ifndef DOCENGINE_DOC_SESSION_H_INCLUDED
#define DOCENGINE_DOC_SESSION_H_INCLUDED

#include <secommon/se_common.h>
#include <docengine/doc_forward_declarations.h>

namespace se { namespace doc {


/**
 * @brief The class representing image processing session - main processing
 *        class of Smart Document Engine
 */
class SE_DLL_EXPORT DocSession {
public:
  /// Default dtor
  virtual ~DocSession() = default;

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
 * @brief Processes an image
 * @param in_image - the input image to process
 * @param settings - DocProcessingSettings instance
 */
  virtual void ProcessImage(const se::common::Image& in_image,
                            const DocProcessingSettings* settings = nullptr) = 0;

  /// Resets the internal state of the processing session
  virtual void Reset() = 0;

  /// Returns the current result (const ref)
  virtual const DocResult& GetCurrentResult() const = 0;

  /// Returns the current result (const ptr)
  virtual const DocResult* GetCurrentResultPtr() const = 0;

  ///Returns session type
  virtual const char* GetType() const = 0;


public:
  /// METHODS TO BE DEPRECETED
  /// THESE METHODS ARE PART OF THE OLD INTERFACE
  /// THEY ARE TO BE DELETED IN FUTURE VERSIONS

  /**
  * @brief Registers a new image in the graphical structure
  * @param in_image - the input image to register
  * @return the ID of the view corresponding to the registered image
  */
  virtual int RegisterImage(const se::common::Image& in_image) = 0;

  /// Launches the document processing iteration with given settings
  virtual void Process(DocProcessingSettings& settings) = 0;

  /// Returns the current result (mutable ref)
  virtual DocResult& GetMutableCurrentResult() = 0;

  /// Returns the current result (mutable ptr)
  virtual DocResult* GetMutableCurrentResultPtr() = 0;
};


} } // namespace se::doc

#endif // DOCENGINE_DOC_SESSION_H_INCLUDED
