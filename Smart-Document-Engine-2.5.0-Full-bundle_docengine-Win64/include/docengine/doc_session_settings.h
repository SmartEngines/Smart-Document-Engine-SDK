/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_session_settings.h
 * @brief Smart Document Engine session settings
 */

#ifndef DOCENGINE_DOC_SESSION_SETTINGS_H_INCLUDED
#define DOCENGINE_DOC_SESSION_SETTINGS_H_INCLUDED

#include <secommon/se_common.h>
#include <docengine/doc_document_info.h>


namespace se { namespace doc {


/**
 * @brief The class representing the document processing session settings
 */
class SE_DLL_EXPORT DocSessionSettings {
public:
  /// Default dtor
  virtual ~DocSessionSettings() = default;

  /**
   * @brief Clones the session settings object
   * @return A newly created object - deep copy of an instance. The object is
   *         allocated, the caller is responsible for deleting it.
   */
  virtual DocSessionSettings* Clone() const = 0;

  /// Returns the number of session options
  virtual int GetOptionsCount() const = 0;
  /// Returns true iff there is a session option with a given name
  virtual bool HasOption(const char* option_name) const = 0;
  /// Returns the session option with a given name
  virtual const char* GetOption(const char* option_name) const = 0;
  /// Sets a session option as a key-value pair
  virtual void SetOption(const char* option_name, const char* option_value) = 0;
  /// Removes the session option with a given name
  virtual void RemoveOption(const char* option_name) = 0;
  /// Returns a 'begin' map-like iterator to the collection of session options
  virtual se::common::StringsMapIterator OptionsBegin() const = 0;
  /// Returns an 'end' map-like iterator to the collection of session options
  virtual se::common::StringsMapIterator OptionsEnd() const = 0;

  /// Returns the number of supported modes
  virtual int GetSupportedModesCount() const = 0;
  /// Returns true iff there is a supported mode with a given name
  virtual bool HasSupportedMode(const char* mode_name) const = 0;
  /// Returns the supported mode name with a given index
  virtual const char* GetSupportedMode(int mode_id) const = 0;
  /// Returns a 'begin' vector-like iterator to the list of supported mode names
  virtual se::common::StringsVectorIterator SupportedModesBegin() const = 0;
  /// Returns an 'end' vector-like iterator to the list of supported mode names
  virtual se::common::StringsVectorIterator SupportedModesEnd() const = 0;

  /// Returns the current session mode
  virtual const char* GetCurrentMode() const = 0;
  /// Sets the current session mode
  virtual void SetCurrentMode(const char* mode_name) = 0;

  /// Returns the number of available internal engines
  virtual int GetInternalEnginesCount() const = 0;
  /// Returns the number of supported document types within an internal engin
  ///     with a given index
  virtual int GetSupportedDocumentTypesCount(int engine_id) const = 0;
  /// Returns true iff there is a supported document type with a given name
  ///     within an internal engine with a given index
  virtual bool HasSupportedDocumentType(
      int         engine_id,
      const char* doc_name) const = 0;
  /// Returns the supported document type name with a given indices of the
  ///     internal engine and document type
  virtual const char* GetSupportedDocumentType(
      int engine_id,
      int doc_id) const = 0;

  /// Returns the number of enabled document types
  virtual int GetEnabledDocumentTypesCount() const = 0;
  /// Returns true iff there is an enabled document type with a given name
  virtual bool HasEnabledDocumentType(const char* doc_name) const = 0;
  /// Returns the enabled document type name with a given index
  virtual const char* GetEnabledDocumentType(int doc_id) const = 0;
  /// Gets reference information about document type
  virtual const DocDocumentInfo& GetDocumentInfo(const char* doc_name) const = 0;
  /// Gets reference information about document type
  virtual const DocDocumentInfo* GetDocumentInfoPtr(const char* doc_name) const = 0;

  /**
   * @brief Adds enabled document types to the session settings, within the
   *        currently active mode
   * @param doc_type_mask - a document type, or a mask with wildcards ('*'). The
   *        wildcard symbol will match any sequence of characters, and the
   *        lookup dictionary for matched document types are taken from the set
   *        of supported document types within the currently active mode.
   *
   * @details NB: the set of matched document types must belong to a single
   *          internal engine.
   */
  virtual void AddEnabledDocumentTypes(const char* doc_type_mask) = 0;

  /**
   * @brief Removes the document types from the set of enabled ones
   * @param doc_type_mask - a document type, or a mask with wildcards ('*'). The
   *        wildcard symbol will match any sequence of characters, and the
   *        lookup dictionary for matched document types are taken from the set
   *        of supported document types within the currently active mode.
   */
  virtual void RemoveEnabledDocumentTypes(const char* doc_type_mask) = 0;

  /// Returns a 'begin' iterator to the set of permissible prefix document masks
  ///     for the current mode
  virtual se::common::StringsSetIterator PermissiblePrefixDocMasksBegin() = 0;
  /// Returns an 'end' iterator to the set of permissible prefix document masks
  ///     for the current mode
  virtual se::common::StringsSetIterator PermissiblePrefixDocMasksEnd() = 0;

  /// Returns true iff the document forensics functionality is enabled
  virtual bool IsForensicsEnabled() const = 0;

  /// Enables the document forensics functionality
  virtual void EnableForensics() = 0;

  /// Disables the document forensics functionality
  virtual void DisableForensics() = 0;

};


} } // namespace se::doc

#endif // DOCENGINE_DOC_SESSION_SETTINGS_H_INCLUDED
