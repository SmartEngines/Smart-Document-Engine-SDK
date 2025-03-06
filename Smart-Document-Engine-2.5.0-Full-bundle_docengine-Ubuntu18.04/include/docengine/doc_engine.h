/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_engine.h
 * @brief Main engine class of Smart Document Engine
 */

#ifndef DOCENGINE_DOC_ENGINE_H_INCLUDED
#define DOCENGINE_DOC_ENGINE_H_INCLUDED

#include <secommon/se_common.h>
#include <docengine/doc_forward_declarations.h>

namespace se { namespace doc {


/**
 * @brief The main DocEngine class containing all configuration and resources
 *        of the Smart Document Engine.
 */
class SE_DLL_EXPORT DocEngine {
public:
  /// Default dtor
  virtual ~DocEngine() = default;

  /**
   * @brief Creates a Session Settings object with default processing and
   *        recognition settings, specified in the configuration bundle.
   * @return A newly created DocSessionSettings object. The object is allocated,
   *         the caller is responsible for deleting it.
   */
  virtual DocSessionSettings* CreateSessionSettings() const = 0;

  /**
   * @brief Spawns a new documents recognition session
   * @param settings - a settings object which are used to spawn a session
   * @param signature - a unique caller signature to unlock the internal
   *        library calls (provided with your SDK package)
   * @param feedback_reporter - an optional pointer to the implementation of
   *        feedback callbacks class
   * @return A newly created session (DocSession object). The object is
   *         allocated, the caller is responsible for deleting it.
   */
  virtual DocSession* SpawnSession(
      const DocSessionSettings& settings,
      const char*               signature,
      DocFeedback*              feedback_reporter = nullptr) const = 0;

public:
  /**
   * @brief The factory method for creating the DocEngine object with a
   *        configuration bundle file.
   * @param config_path - filesystem path to an engine configuration bundle
   * @param lazy_configuration - if true, some components of the internal
   *        engine structure will be initialized only when first needed. If
   *        false, all engine structure will be loaded and initialized
   *        immediately. Lazy configuration is enabled by default.
   * @return A newly created DocEngine object. The object is allocated,
   *         the caller is responsible for deleting it.
   */
  static DocEngine* Create(
      const char* config_path,
      bool        lazy_configuration = true);

  /**
   * @brief The factory method for creating the DocEngine object with a
   *        configuration bundle buffer.
   * @param config_data - pointer to the configuration bundle file buffer.
   * @param config_data_length - size of the configuration buffer in bytes.
   * @param lazy_configuration - if true, some components of the internal
   *        engine structure will be initialized only when first needed. If
   *        false, all engine structure will be loaded and initialized
   *        immediately. Lazy configuration is enabled by default.
   * @return A newly created DocEngine object. The object is allocated,
   *         the caller is responsible for deleting it.
   */
  static DocEngine* Create(
      unsigned char*  config_data,
      int             config_data_length,
      bool            lazy_configuration = true);

  /**
   * @brief The factory method for creating the DocEngine object with a
   *        configuration bundle buffer embedded within the library.
   * @param lazy_configuration - if true, some components of the internal
   *        engine structure will be initialized only when first needed. If
   *        false, all engine structure will be loaded and initialized
   *        immediately. Lazy configuration is enabled by default.
   * @return A newly created DocEngine object. The object is allocated,
   *         the caller is responsible for deleting it.
   */
  static DocEngine* CreateFromEmbeddedBundle(
      bool           lazy_configuration = true);

  /**
   * @brief Returns the Smart Document Engine version number
   * @return Smart Document Engine version number string
   */
  static const char* GetVersion();


 public:
  /// METHODS TO BE DEPRECETED
  /// THESE METHODS ARE PART OF THE OLD INTERFACE
  /// THEY ARE TO BE DELETED IN FUTURE VERSIONS
  /**
   * @brief Spawns a new documents recognition session
   * @param settings - a settings object which are used to spawn a session
   * @param signature - a unique caller signature to unlock the internal
   *        library calls (provided with your SDK package)
   * @param feedback_reporter - an optional pointer to the implementation of
   *        feedback callbacks class
   * @param external_processor - an optional pointer to the implementation of an
   *        external document processor
   * @return A newly created session (DocSession object). The object is
   *         allocated, the caller is responsible for deleting it.
   */
  virtual DocSession* SpawnSession(
      const DocSessionSettings& settings,
      const char*               signature,
      DocFeedback*              feedback_reporter,
      DocExternalProcessorInterface* external_processor) const = 0;

public:
  /// DEPRECATED METHODS
  /// NO LONGER WORKS
  /// THEY ARE TO BE DELETED IN FUTURE VERSIONS

  /**
  * @brief Creates a Video Session Settings object with default processing and
  *        recognition settings for a sequence of video frames, specified in
  *        the configuration bundle.
  * @return A newly created DocSessionSettings object. The object is allocated,
  *         the caller is responsible for deleting it.
  */
  virtual DocSessionSettings* CreateVideoSessionSettings() const = 0;

  /**
  * @brief Spawns a new video stream document recognition session
  * @param settings - a settings object which are used to spawn a session
  * @param signature - a unique caller signature to unlock the internal
  *        library calls (provided with your SDK package)
  * @param feedback_reporter - an optional pointer to the implementation of the
  *        feedback callbacks class
  * @return A newly created video session (DocVideoSession object). The object
  *         is allocated, the caller is responsible for deleting it.
  */
  virtual DocVideoSession* SpawnVideoSession(
    const DocSessionSettings& settings,
    const char*               signature,
    DocFeedback*              feedback_reporter = nullptr) const = 0;
};


} } // namespace se::doc

#endif // DOCENGINE_DOC_ENGINE_H_INCLUDED
