/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_processing_settings.h
 * @brief Smart Document Engine source processing settings
 */

#ifndef DOCENGINE_DOC_PROCESSING_SETTINGS_H_INCLUDED
#define DOCENGINE_DOC_PROCESSING_SETTINGS_H_INCLUDED

#include <secommon/se_common.h>
#include <docengine/doc_feedback.h>
#include <docengine/doc_forward_declarations.h>

namespace se { namespace doc {

/**
 * @brief The class representing the settings of a single processing iteration
 */
class SE_DLL_EXPORT DocProcessingSettings {
public:
  /// Default dtor
  virtual ~DocProcessingSettings() = default;

  /// Returns the number of processing options
  virtual int GetOptionsCount() const = 0;
  /// Returns true iff there exists a processing option with a given name
  virtual bool HasOption(const char* option_name) const = 0;
  /// Returns the processing option with a given name
  virtual const char* GetOption(const char* option_name) const = 0;
  /// Sets the processing option as a key-value pair
  virtual void SetOption(const char* option_name, const char* option_value) = 0;
  /// Removes the processing option with a given name
  virtual void RemoveOption(const char* option_name) = 0;
  /// Returns a 'begin' map-like iterator to the processing options
  virtual se::common::StringsMapIterator OptionsBegin() const = 0;
  /// Returns an 'end' map-like iterator to the processing options
  virtual se::common::StringsMapIterator OptionsEnd() const = 0;

  /// Returns the number of session options
  virtual int GetSessionOptionsCount() const = 0;
  /// Returns true iff there exists a session option with a given name
  virtual bool HasSessionOption(const char* option_name) const = 0;
  /// Returns the session option with a given name
  virtual const char* GetSessionOption(const char* option_name) const = 0;
  /// Returns a 'begin' map-like iterator to the session options
  virtual se::common::StringsMapIterator SessionOptionsBegin() const = 0;
  /// Returns an 'end' map-like iterator to the session options
  virtual se::common::StringsMapIterator SessionOptionsEnd() const = 0;

  /// Returns the number of enabled document types
  virtual int GetEnabledDocumentTypesCount() const = 0;
  /// Returns true iff there is an enabled document type with a given name
  virtual bool HasEnabledDocumentType(const char* doc_name) const = 0;
  /// Returns a name of enabled document type by index
  virtual const char* GetEnabledDocumentType(int doc_id) const = 0;

public:
  /// METHODS TO BE DEPRECATED
  /// THESE METHODS ARE A PART OF THE OLD INTERFACE
  /// THEY ARE TO BE DELETED IN FUTURE VERSIONS

  /// Returns the ID of a view which is marked as a current source
  virtual int GetCurrentSourceID() const = 0;
  /// Sets the ID of a view which is marked as a current source
  virtual void SetCurrentSourceID(int source_id) = 0;
  /// Returns the number of available routines
  virtual int GetAvailableRoutinesCount() const = 0;
  /// Returns true iff there exists an available routine with a given name
  virtual bool HasAvailableRoutine(const char* routine_name) const = 0;
  /// Returns a 'begin' map-like iterator to the list of routine names
  virtual se::common::StringsMapIterator AvailableRoutinesBegin() const = 0;
  /// Returns an 'end' map-like iterator to the list of routine names
  virtual se::common::StringsMapIterator AvailableRoutinesEnd() const = 0;

  /// Returns the size of the current routines queue
  virtual int RoutinesQueueSize() const = 0;
  /// Returns the routine name at the front of the queue
  virtual const char* RoutinesQueueFront() const = 0;
  /// Pushes a routine to the back of the current routines queue
  virtual void RoutinesQueuePush(const char* routine_name) = 0;
  /// Pops a routine from the front of the current routines queue
  virtual void RoutinesQueuePop() = 0;
  /// Cleas the routines queue
  virtual void RoutinesQueueClear() = 0;

  ///  Binds feedback reporter to processing settings
  virtual void BindFeedbackReporter(DocFeedback* feedback_reporter) = 0;
  /// Returns pointer to feedback reporter
  virtual DocFeedback* GetFeedbackReporter() const = 0;

};


} } // namespace se::doc

#endif // DOCENGINE_DOC_PROCESSING_SETTINGS_H_INCLUDED
