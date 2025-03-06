/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_external_processor.h
 * @brief Smart Document Engine external processor interface and
 *        auxilliary classes
 */

#ifndef DOCENGINE_DOC_EXTERNAL_PROCESSOR_H_INCLUDED
#define DOCENGINE_DOC_EXTERNAL_PROCESSOR_H_INCLUDED

#include <secommon/se_export_defs.h>
#include <docengine/doc_forward_declarations.h>

namespace se { namespace doc {


/**
 * @brief The class representing the processing arguments for a custom
 *        document processor
 * CLASS TO BE DEPRECATED
 */
class SE_DLL_EXPORT DocProcessingArguments {
public:
  /// Default dtor
  virtual ~DocProcessingArguments() = default;

  /// Returns the number of arguments
  virtual int GetTagArgumentsCount() const = 0;
  /// Returns the argument by index
  virtual const char* GetTagArgument(int index) const = 0;
  /// Sets the argument by index
  virtual void SetTagArgument(int index, const char* argument) = 0;
  /// Resizes the array of arguments
  virtual void Resize(int size) = 0;
};


/**
 * @brief The abstract interface for custom document processor
 * CLASS TO BE DEPRECATED
 */
class SE_DLL_EXPORT DocExternalProcessorInterface {
public:
  /// Default dtor
  virtual ~DocExternalProcessorInterface() = default;

  /**
   * @brief Processes the current result structure with a given processing
   *        settings and arguments. Needs to be implemented in a derived
   *        custom processing class.
   * @param recognition_result - mutable current document processing and
   *        recognition result structure.
   * @param processing_settings - current source processing settings
   * @param processing_arguments - processing arguments for the current custom
   *        document processor
   */
  virtual void Process(
      DocResult&                    recognition_result,
      const DocProcessingSettings&  processing_settings,
      const DocProcessingArguments& processing_arguments) = 0;
};


} } // namespace se::doc

#endif // DOCENGINE_DOC_EXTERNAL_PROCESSOR_H_INCLUDED
