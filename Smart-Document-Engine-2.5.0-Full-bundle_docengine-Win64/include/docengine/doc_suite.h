/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_suite.h
 * @brief Class of Smart Document Engine Document Suite representation
 */

#ifndef DOCENGINE_DOC_SUITE_H_INCLUDED
#define DOCENGINE_DOC_SUITE_H_INCLUDED

#include <secommon/se_common.h>

#include <docengine/doc_forward_declarations.h>

namespace se { namespace doc {

class SE_DLL_EXPORT DocInventoryLine {
public:
  ///default dtor
  virtual ~DocInventoryLine() = default;

  /// Getter for mask of document type
  virtual const char* GetDocTypeMask() const = 0;

  /// Getter of the amount of documents with a corresponding doc mask
  virtual int GetDocAmount() const = 0;

  /// Getter of a prediacte to correpond a document with an inventory line
  virtual const char* GetLinePredicate() const = 0;

};

/**
 * @brief The class representing an inventory of a suite of documents
 */

class SE_DLL_EXPORT DocSuiteInventory {
public:
  ///default dtor
  virtual ~DocSuiteInventory() = default;

  /// Checks if the suite is closed
  virtual bool IsSuiteClosed() const = 0;

  /// Checks if the suite is complete
  virtual bool IsSuiteComplete() const = 0;


};

/**
 * @brief The class representing a suite of documents
 */

class SE_DLL_EXPORT DocSuite {
public:
  //default dtor
  virtual ~DocSuite() = default;

  /// Returns the number of documents in a suite
  virtual int GetDocumentsCount() const = 0;

  /// Document getter by indice
  virtual const Document& GetDocument(const int idx) const = 0;

  /// Document getter by indice
  virtual const Document* GetDocumentPtr(const int idx) const = 0;

  /// Document getter by ID
  virtual const se::doc::Document& GetDocumentByID(const int doc_id) const = 0;

  /// Document getter by ID
  virtual const se::doc::Document* GetDocumentPtrByID(const int doc_id) const = 0;

  /// DocSuiteInventory getter
  virtual const DocSuiteInventory& GetDocSuiteInventory() const = 0;

  /// Mutable DocSuiteInventory getter
  virtual DocSuiteInventory& GetMutableDocSuiteInventory() = 0;

  /// DocSuiteInventory getter
  virtual const DocSuiteInventory* GetDocSuiteInventoryPtr() const = 0;

  /// Mutable DocSuiteInventory getter
  virtual DocSuiteInventory* GetMutableDocSuiteInventoryPtr() = 0;

  ///Get ID of the scene where the suite began
  virtual int BeginningSceneID() const = 0;

  ///Get ID of the scene where the suite closed
  virtual int ClosingSceneID() const = 0;

  /// Returns the number of suite attributes
  virtual int GetAttributesCount() const = 0;
  /// Checks if an attributes exists with a given name
  virtual bool HasAttribute(const char* attr_name) const = 0;
  /// Returns an attribute value for a given name
  virtual const char* GetAttribute(const char* attr_name) const = 0;
  /// Sets an attribute key-value pair
  virtual void SetAttribute(const char* attr_name, const char* attr_value) = 0;
  /// Removes an attribute with a given name
  virtual void RemoveAttribute(const char* attr_name) = 0;
  /// Returns a begin-iterator for an internal collection of attributes
  virtual se::common::StringsMapIterator AttributesBegin() const = 0;
  /// Returns an end-iterator for an internal collection of attributes
  virtual se::common::StringsMapIterator AttributesEnd() const = 0;

};

} } // namespace se::doc

#endif // DOCENGINE_DOC_SUITE_H_INCLUDED
