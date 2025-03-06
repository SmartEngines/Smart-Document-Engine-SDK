/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_suite_settings.h
 * @brief Class of Smart Document Engine Document Suite settings
 */

#ifndef DOCENGINE_DOC_SUITE_SETTINGS_H_INCLUDED
#define DOCENGINE_DOC_SUITE_SETTINGS_H_INCLUDED

#include <secommon/se_common.h>

#include <docengine/doc_forward_declarations.h>

namespace se { namespace doc {

/**
 * @brief The class representing settings for a suite of documents
 */

class SE_DLL_EXPORT DocSuiteSettings {
public:
  //default dtor
  virtual ~DocSuiteSettings() = default;

  /**
   * @brief Clones the session settings object
   * @return A newly created object - deep copy of an instance. The object is
   *         allocated, the caller is responsible for deleting it.
   */
  virtual DocSuiteSettings* Clone() const = 0;

  virtual void SetDocSuiteSettingsType(const char* type) = 0;

  virtual void AddInventoryDocType(const char* doc_type) = 0;

  virtual void AddInventoryLine(const char* doc_type,
                                int amount,
                                const char* predicate) = 0;
};

} } // namespace se::doc

#endif // DOCENGINE_DOC_SUITE_SETTINGS_H_INCLUDED
