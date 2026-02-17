/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_document.h
 * @brief Classes of Smart Document Engine document representation
 */

#ifndef DOCENGINE_DOC_DOCUMENT_H_INCLUDED
#define DOCENGINE_DOC_DOCUMENT_H_INCLUDED

#include <docengine/doc_fields_iterators.h>
#include <secommon/se_common.h>

namespace se { namespace doc {

/**
 * @brief Class representing a recognized Document
 */
class SE_DLL_EXPORT Document {
public:
  /// Service method, returns "Document"
  static const char* BaseClassNameStatic();

public:
  /// Default dtor
  virtual ~Document() = default;

  /// Returns the number of text fields in a document
  virtual int GetTextFieldsCount() const = 0;
  /// Checks if a text field exists by name
  virtual bool HasTextField(const char* name) const = 0;
  /// Text field getter by name
  virtual const DocTextField& GetTextField(const char* name) const = 0;
  /// Text field getter by name
  virtual const DocTextField* GetTextFieldPtr(const char* name) const = 0;
  /// Returns a begin-iterator for an internal collection of text fields
  virtual DocTextFieldsIterator TextFieldsBegin() const = 0;
  /// Returns an end-iterator for an internal collection of text fields
  virtual DocTextFieldsIterator TextFieldsEnd() const = 0;

  /// Returns the number of image fields in a document
  virtual int GetImageFieldsCount() const = 0;
  /// Checks if an image field exists by name
  virtual bool HasImageField(const char* name) const = 0;
  /// Image field getter by name
  virtual const DocImageField& GetImageField(const char* name) const = 0;
  /// Image field getter by name
  virtual const DocImageField* GetImageFieldPtr(const char* name) const = 0;
  /// Returns a begin-iterator for an internal collection of image fields
  virtual DocImageFieldsIterator ImageFieldsBegin() const = 0;
  /// Returns an end-iterator for an internal collection of image fields
  virtual DocImageFieldsIterator ImageFieldsEnd() const = 0;

  /// Returns the number of checkbox fields in a document
  virtual int GetCheckboxFieldsCount() const = 0;
  /// Checks if a checkbox field exists by name
  virtual bool HasCheckboxField(const char* name) const = 0;
  /// Checkbox field getter by name
  virtual const DocCheckboxField& GetCheckboxField(const char* name) const = 0;
  /// Checkbox field getter by name
  virtual const DocCheckboxField* GetCheckboxFieldPtr(const char* name) const = 0;
  /// Returns a begin-iterator for an internal collection of checkbox fields
  virtual DocCheckboxFieldsIterator CheckboxFieldsBegin() const = 0;
  /// Returns an end-iterator for an internal collection of checkbox fields
  virtual DocCheckboxFieldsIterator CheckboxFieldsEnd() const = 0;

  /// Returns the number of forensic fields in a document
  virtual int GetForensicFieldsCount() const = 0;
  /// Checks if a forensic field exists by name
  virtual bool HasForensicField(const char* name) const = 0;
  /// Forensic field getter by name
  virtual const DocForensicField& GetForensicField(const char* name) const = 0;
  /// Forensic field getter by name
  virtual const DocForensicField* GetForensicFieldPtr(const char* name) const = 0;
  /// Returns a begin-iterator for an internal collection of forensic fields
  virtual DocForensicFieldsIterator ForensicFieldsBegin() const = 0;
  /// Returns an end-iterator for an internal collection of forensic fields
  virtual DocForensicFieldsIterator ForensicFieldsEnd() const = 0;

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

  /// Returns the number of table fields in a document
  virtual int GetTableFieldsCount() const = 0;
  /// Checks if a table field exists by name
  virtual bool HasTableField(const char* name) const = 0;
  /// Table field getter by name
  virtual const DocTableField& GetTableField(const char* name) const = 0;
  /// Table field getter by name
  virtual const DocTableField* GetTableFieldPtr(const char* name) const = 0;
  /// Returns a begin-iterator for an internal collection of table fields
  virtual DocTableFieldsIterator TableFieldsBegin() const = 0;
  /// Returns an end-iterator for an internal collection of table fields
  virtual DocTableFieldsIterator TableFieldsEnd() const = 0;

  /// Returns the number of barcode fields in a document
  virtual int GetBarcodeFieldsCount() const = 0;
  /// Checks if a barcode field exists by name
  virtual bool HasBarcodeField(const char* name) const = 0;
  /// Barcode field getter by name
  virtual const DocBarcodeField& GetBarcodeField(const char* name) const = 0;
  /// Barcode field getter by name
  virtual const DocBarcodeField* GetBarcodeFieldPtr(const char* name) const = 0;
  /// Returns a begin-iterator for an internal collection of barcode fields
  virtual DocBarcodeFieldsIterator BarcodeFieldsBegin() const = 0;
  /// Returns an end-iterator for an internal collection of barcode fields
  virtual DocBarcodeFieldsIterator BarcodeFieldsEnd() const = 0;

  /// Returns the number of document attributes
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

  /// Returns document's type
  virtual const char* GetType() const = 0;

  /// Serializes the document instance with a given serializer object
  virtual void Serialize(se::common::Serializer& serializer) const = 0;

  /// Return indice of the connected physical document
  virtual int GetPhysicalDocIdx() const = 0;

public:
  /// METHODS TO BE DEPRECATED
  /// THESE METHODS ARE A PART OF THE OLD INTERFACE
  /// THEY ARE TO BE DELETED IN FUTURE VERSIONS

  /// Mutable text field getter by name
  virtual DocTextField& GetMutableTextField(const char* name) = 0;
  /// Mutable text field getter by name
  virtual DocTextField* GetMutableTextFieldPtr(const char* name) = 0;
  /// Text field setter
  virtual void SetTextField(const char* name, const DocTextField& field) = 0;
  /// Removes a text field with a given name
  virtual void RemoveTextField(const char* name) = 0;

  /// Mutable image field getter by name
  virtual DocImageField& GetMutableImageField(const char* name) = 0;
  /// Mutable image field getter by name
  virtual DocImageField* GetMutableImageFieldPtr(const char* name) = 0;
  /// Image field setter
  virtual void SetImageField(const char* name, const DocImageField& field) = 0;
  /// Removes an image field with a given name
  virtual void RemoveImageField(const char* name) = 0;

  /// Mutable checkbox field getter by name
  virtual DocCheckboxField& GetMutableCheckboxField(const char* name) = 0;
  /// Mutable checkbox field getter by name
  virtual DocCheckboxField* GetMutableCheckboxFieldPtr(const char* name) = 0;
  /// Checkbox field setter
  virtual void SetCheckboxField(const char* name, const DocCheckboxField& field) = 0;
  /// Removes a checkbox field with a given name
  virtual void RemoveCheckboxField(const char* name) = 0;

  /// Mutable forensic field getter by name
  virtual DocForensicField& GetMutableForensicField(const char* name) = 0;
  /// Mutable forensic field getter by name
  virtual DocForensicField* GetMutableForensicFieldPtr(const char* name) = 0;
  /// Forensic field setter
  virtual void SetForensicField(const char* name, const DocForensicField& field) = 0;
  /// Removes a forensic field with a given name
  virtual void RemoveForensicField(const char* name) = 0;

  /// Mutable forensic check field getter by name
  virtual DocForensicCheckField& GetMutableForensicCheckField(const char* name) = 0;
  /// Mutable forensic check field getter by name
  virtual DocForensicCheckField* GetMutableForensicCheckFieldPtr(const char* name) = 0;
  /// Forensic check field setter
  virtual void SetForensicCheckField(const char* name, const DocForensicCheckField& field) = 0;
  /// Removes a forensic check field with a given name
  virtual void RemoveForensicCheckField(const char* name) = 0;

  /// Mutable table field getter by name
  virtual DocTableField& GetMutableTableField(const char* name) = 0;
  /// Mutable table field getter by name
  virtual DocTableField* GetMutableTableFieldPtr(const char* name) = 0;
  /// Table field setter
  virtual void SetTableField(const char* name, const DocTableField& field) = 0;
  /// Removes a table field with a given name
  virtual void RemoveTableField(const char* name) = 0;

  /// Mutable barcode field getter by name
  virtual DocBarcodeField& GetMutableBarcodeField(const char* name) = 0;
  /// Mutable barcode field getter by name
  virtual DocBarcodeField* GetMutableBarcodeFieldPtr(const char* name) = 0;
  /// Barcode field setter
  virtual void SetBarcodeField(const char* name, const DocBarcodeField& field) = 0;
  /// Removes a barcode field with a given name
  virtual void RemoveBarcodeField(const char* name) = 0;
};


} } // namespace se::doc

#endif // DOCENGINE_DOC_DOCUMENT_H_INCLUDED
