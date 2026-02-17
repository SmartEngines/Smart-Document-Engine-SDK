/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_fields.h
 * @brief Classes of Smart Document Engine fields representation
 */

#ifndef DOCENGINE_DOC_FIELDS_H_INCLUDED
#define DOCENGINE_DOC_FIELDS_H_INCLUDED

#include <secommon/se_common.h>

#include <docengine/doc_forward_declarations.h>
#include <docengine/doc_basic_objects_iterator.h>
#include <docengine/doc_physical_document.h>
#include <docengine/doc_physical_document_iterators.h>


namespace se { namespace doc {


/**
 * @brief The class representing basic document field information
 */
class SE_DLL_EXPORT DocBaseFieldInfo {
public:
  /// Default dtor
  virtual ~DocBaseFieldInfo() = default;

  /// Returns the name of the field
  virtual const char* GetName() const = 0;

  /// Returns the confidence of the field (double in range [0.0, 1.0])
  virtual double GetConfidence() const = 0;

  /// Returns the field acceptance flag
  virtual bool GetAcceptFlag() const = 0;

  /// Returns the field validity flag
  virtual bool IsValid() const = 0;

  /// Returns the number of field attributes
  virtual int GetAttributesCount() const = 0;
  /// Returns true iff there exists a field attribute with a given name
  virtual bool HasAttribute(const char* attr_name) const = 0;
  /// Returns the value of an attribute with a given name
  virtual const char* GetAttribute(const char* attr_name) const = 0;
  /// Returns a 'begin' map-like iterator to the collection of field attributes
  virtual se::common::StringsMapIterator AttributesBegin() const = 0;
  /// Returns an 'end' map-like iterator to the collection of field attributes
  virtual se::common::StringsMapIterator AttributesEnd() const = 0;

  /// Returns a constant 'begin' iterator to all connected text physical objects
  virtual DocTextObjectsCrossPageIterator ConnectedTextObjectsBegin(
      const DocPhysicalDocument& phys_doc) const = 0;
  /// Returns a constant 'end' iterator to all connected text physical objects
  virtual DocTextObjectsCrossPageIterator ConnectedTextObjectsEnd(
      const DocPhysicalDocument& phys_doc) const = 0;

  /// Returns a constant 'begin' iterator to all connected table physical objects
  virtual DocTableObjectsCrossPageIterator ConnectedTableObjectsBegin(
      const DocPhysicalDocument& phys_doc) const = 0;
  /// Returns a constant 'end' iterator to all connected table physical objects
  virtual DocTableObjectsCrossPageIterator ConnectedTableObjectsEnd(
      const DocPhysicalDocument& phys_doc) const = 0;

   /// Returns a constant 'begin' iterator to all connected image physical objects
   virtual DocImageObjectsCrossPageIterator ConnectedImageObjectsBegin(
       const DocPhysicalDocument& phys_doc) const = 0;
   /// Returns a constant 'end' iterator to all connected image physical objects
   virtual DocImageObjectsCrossPageIterator ConnectedImageObjectsEnd(
       const DocPhysicalDocument& phys_doc) const = 0;

   /// Returns a constant 'begin' iterator to all connected check box physical objects
   virtual DocCheckboxObjectsCrossPageIterator ConnectedCheckboxObjectsBegin(
       const DocPhysicalDocument& phys_doc) const = 0;
   /// Returns a constant 'end' iterator to all connected check box physical objects
   virtual DocCheckboxObjectsCrossPageIterator ConnectedCheckboxObjectsEnd(
       const DocPhysicalDocument& phys_doc) const = 0;

   /// Returns a constant 'begin' iterator to all connected check physical objects
   virtual DocTextObjectsCrossPageIterator ConnectedForensicCheckObjectsBegin(
       const DocPhysicalDocument& phys_doc) const = 0;
   /// Returns a constant 'end' iterator to all connected check physical objects
   virtual DocTextObjectsCrossPageIterator ConnectedForensicCheckObjectsEnd(
       const DocPhysicalDocument& phys_doc) const = 0;

  /// Returns a constant 'begin' iterator to all connected physical objects
  virtual DocMetaObjectsCrossPageIterator ConnectedForensicObjectsBegin(
      const DocPhysicalDocument& phys_doc) const = 0;
  /// Returns a constant 'end' iterator to all connected physical objects
  virtual DocMetaObjectsCrossPageIterator ConnectedForensicObjectsEnd(
      const DocPhysicalDocument& phys_doc) const = 0;

  /// Returns a constant 'begin' iterator to all connected physical objects
  virtual DocBarcodeObjectsCrossPageIterator ConnectedBarcodeObjectsBegin(
      const DocPhysicalDocument& phys_doc) const = 0;
  /// Returns a constant 'end' iterator to all connected physical objects
  virtual DocBarcodeObjectsCrossPageIterator ConnectedBarcodeObjectsEnd(
      const DocPhysicalDocument& phys_doc) const = 0;

  /// Serializes the field info instance with a given serializer object
  virtual void Serialize(se::common::Serializer& serializer) const = 0;

public:
  /// METHODS TO BE DEPRECATED
  /// THESE METHODS ARE A PART OF THE OLD INTERFACE
  /// THEY ARE TO BE DELETED IN FUTURE VERSIONS


  /// Sets the name of the field
  virtual void SetName(const char* name) = 0;
  /// Sets the confidence of the field (double in range [0.0, 1.0])
  virtual void SetConfidence(double conf) = 0;
  /// Sets the field acceptance flag
  virtual void SetAcceptFlag(bool is_accepted) = 0;
  /// Sets the field attribute as a key-value pair
  virtual void SetAttribute(const char* attr_name, const char* attr_value) = 0;
  /// Removes the field attribute with a given name
  virtual void RemoveAttribute(const char* attr_name) = 0;

  /// Returns a constant 'begin' iterator to all connected graphical objects
  virtual DocBasicObjectsCrossSliceIterator ConnectedBasicObjectsBegin(
    const DocGraphicalStructure& graphical) const = 0;
  /// Returns a constant 'end' iterator to all connected graphical objects
  virtual DocBasicObjectsCrossSliceIterator ConnectedBasicObjectsEnd(
    const DocGraphicalStructure& graphical) const = 0;

  /// Returns a mutable 'begin' iterator to all connected graphical objects
  virtual DocBasicObjectsMutableCrossSliceIterator
  MutableConnectedBasicObjectsBegin(DocGraphicalStructure& graphical) = 0;
  /// Returns a mutable 'end' iterator to all connected graphical objects
  virtual DocBasicObjectsMutableCrossSliceIterator
  MutableConnectedBasicObjectsEnd(DocGraphicalStructure& graphical) = 0;

  /// Connects a basic object obj_id from collection coll_id with this field
  virtual void ConnectBasicObject(int coll_id, int obj_id) = 0;
};


/**
 * @brief The class representing a text field of a document
 */
class SE_DLL_EXPORT DocTextField {
public:
  /// Default dtor
  virtual ~DocTextField() = default;

  /// Returns the basic field information (const ref)
  virtual const DocBaseFieldInfo& GetBaseFieldInfo() const = 0;
  /// Returns the basic field information (mutable ref)
  virtual DocBaseFieldInfo& GetMutableBaseFieldInfo() = 0;
  /// Returns the basic field information (const ptr)
  virtual const DocBaseFieldInfo* GetBaseFieldInfoPtr() const = 0;
  /// Returns the basic field information (mutable ptr)
  virtual DocBaseFieldInfo* GetMutableBaseFieldInfoPtr() = 0;

  /// Returns the field recognition result (const ref)
  virtual const se::common::OcrString& GetOcrString() const = 0;
  /// Returns the field recognition result (mutable ref)
  virtual se::common::OcrString& GetMutableOcrString() = 0;
  /// Returns the field recognition result (const ptr)
  virtual const se::common::OcrString* GetOcrStringPtr() const = 0;
  /// Returns the field recognition result (mutable ptr)
  virtual se::common::OcrString* GetMutableOcrStringPtr() = 0;
  /// Sets the field recognition result
  virtual void SetOcrString(const se::common::OcrString& ocrstring) = 0;

  /// Serializes the field instance with a given serializer object
  virtual void Serialize(se::common::Serializer& serializer) const = 0;
};


/**
 * @brief The class representing an image field of a document
 */
class SE_DLL_EXPORT DocImageField {
public:
  /// Default dtor
  virtual ~DocImageField() = default;

  /// Returns the basic field information (const ref)
  virtual const DocBaseFieldInfo& GetBaseFieldInfo() const = 0;
  /// Returns the basic field information (mutable ref)
  virtual DocBaseFieldInfo& GetMutableBaseFieldInfo() = 0;
  /// Returns the basic field information (const ptr)
  virtual const DocBaseFieldInfo* GetBaseFieldInfoPtr() const = 0;
  /// Returns the basic field information (mutable ptr)
  virtual DocBaseFieldInfo* GetMutableBaseFieldInfoPtr() = 0;

  /// Returns the image representation of a field (const ref)
  virtual const se::common::Image& GetImage() const = 0;
  /// Returns the image representation of a field (mutable ref)
  virtual se::common::Image& GetMutableImage() = 0;
  /// Returns the image representation of a field (const ptr)
  virtual const se::common::Image* GetImagePtr() const = 0;
  /// Returns the image representation of a field (mutable ptr)
  virtual se::common::Image* GetMutableImagePtr() = 0;
  /// Sets the image representation of a field
  virtual void SetImage(const se::common::Image& image) = 0;

  /// Serializes the field instance with a given serializer object
  virtual void Serialize(se::common::Serializer& serializer) const = 0;
};


/**
 * @brief The class representing a checkbox field of a document
 */
class SE_DLL_EXPORT DocCheckboxField {
public:
  /// Default dtor
  virtual ~DocCheckboxField() = default;

  /// Returns the basic field information (const ref)
  virtual const DocBaseFieldInfo& GetBaseFieldInfo() const = 0;
  /// Returns the basic field information (mutable ref)
  virtual DocBaseFieldInfo& GetMutableBaseFieldInfo() = 0;
  /// Returns the basic field information (const ptr)
  virtual const DocBaseFieldInfo* GetBaseFieldInfoPtr() const = 0;
  /// Returns the basic field information (mutable ptr)
  virtual DocBaseFieldInfo* GetMutableBaseFieldInfoPtr() = 0;

  /// Returns a boolean ticked status of a checkbox
  virtual bool GetTickStatus() const = 0;
  /// Sets a ticked status of a checkbox
  virtual void SetTickStatus(bool tick_status) = 0;

  /// Serializes the field instance with a given serializer object
  virtual void Serialize(se::common::Serializer& serializer) const = 0;
};


/**
 * @brief The class representing a forensic field of a document
 */
class SE_DLL_EXPORT DocForensicField {
public:
  /// Default dtor
  virtual ~DocForensicField() = default;

  /// Returns the basic field information (const ref)
  virtual const DocBaseFieldInfo& GetBaseFieldInfo() const = 0;
  /// Returns the basic field information (mutable ref)
  virtual DocBaseFieldInfo& GetMutableBaseFieldInfo() = 0;
  /// Returns the basic field information (const ptr)
  virtual const DocBaseFieldInfo* GetBaseFieldInfoPtr() const = 0;
  /// Returns the basic field information (mutable ptr)
  virtual DocBaseFieldInfo* GetMutableBaseFieldInfoPtr() = 0;

  /// Returns a forensic field value
  virtual const char* GetStatus() const = 0;
  /// Sets a forensic field value
  virtual void SetStatus(const char* status) = 0;

  /// Serializes the field instance with a given serializer object
  virtual void Serialize(se::common::Serializer& serializer) const = 0;
};

/**
 * @brief The class representing a forensic check field of a document
 */
class SE_DLL_EXPORT DocForensicCheckField {
public:
  /// Default dtor
  virtual ~DocForensicCheckField() = default;

  /// Returns the basic field information (const ref)
  virtual const DocBaseFieldInfo& GetBaseFieldInfo() const = 0;
  /// Returns the basic field information (mutable ref)
  virtual DocBaseFieldInfo& GetMutableBaseFieldInfo() = 0;
  /// Returns the basic field information (const ptr)
  virtual const DocBaseFieldInfo* GetBaseFieldInfoPtr() const = 0;
  /// Returns the basic field information (mutable ptr)
  virtual DocBaseFieldInfo* GetMutableBaseFieldInfoPtr() = 0;

  /// Returns a forensic field value
  virtual const char* GetStatus() const = 0;
  /// Sets a forensic field value
  virtual void SetStatus(const char* status) = 0;

  /// Serializes the field instance with a given serializer object
  virtual void Serialize(se::common::Serializer& serializer) const = 0;
};


/**
 * @brief The class representing a table field of a document
 */
class SE_DLL_EXPORT DocTableField {
public:
  /// Default dtor
  virtual ~DocTableField() = default;

  /// Returns the basic field information (const ref)
  virtual const DocBaseFieldInfo& GetBaseFieldInfo() const = 0;
  /// Returns the basic field information (mutable ref)
  virtual DocBaseFieldInfo& GetMutableBaseFieldInfo() = 0;
  /// Returns the basic field information (const ptr)
  virtual const DocBaseFieldInfo* GetBaseFieldInfoPtr() const = 0;
  /// Returns the basic field information (mutable ptr)
  virtual DocBaseFieldInfo* GetMutableBaseFieldInfoPtr() = 0;

  /// Returns the number of rows in the table
  virtual int GetRowsCount() const = 0;
  /// Returns the number of columns in the table
  virtual int GetColsCount() const = 0;
  /// Returns the cell of a table as a DocTextField (const ref)
  virtual const DocTextField& GetCell(int row, int col) const = 0;
  /// Returns the cell of a table as a DocTextField (mutable ref)
  virtual DocTextField& GetMutableCell(int row, int col) = 0;
  /// Returns the cell of a table as a DocTextField (const ptr)
  virtual const DocTextField* GetCellPtr(int row, int col) const = 0;
  /// Returns the cell of a table as a DocTextField (mutable ptr)
  virtual DocTextField* GetMutableCellPtr(int row, int col) = 0;
  /// Sets the cell of a table as a DocTextField
  virtual void SetCell(int row, int col, const DocTextField& text_field) = 0;

  /// Returns true if a column with given name exists, false, if not, or throws an exception if given column name is not in the documentation
  virtual bool HasColumnIndexByName(const char* col_name) const = 0;
  /// Returns index of the column with given name, or throws exception if given column is not in the table or in the documentation
  virtual int GetColumnIndexByName(const char* col_name) const = 0;

  /// Resizes the set of rows of the table
  virtual void ResizeRows(int rows) = 0;
  /// Resizes the set of rows of the table with a given filler cell value
  virtual void ResizeRows(int rows, const DocTextField& filler) = 0;
  /// Resizes the set of columns of the table
  virtual void ResizeCols(int cols) = 0;
  /// Resizes the set of columns of the table with a given filler cell value
  virtual void ResizeCols(int cols, const DocTextField& filler) = 0;

  /// Serializes the field instance with a given serializer object
  virtual void Serialize(se::common::Serializer& serializer) const = 0;

  /// Returns the number of rows in the table header
  virtual int GetHeaderRowsCount() const = 0;
  /// Returns the number of columns in the table header
  virtual int GetHeaderColsCount() const = 0;
  /// Returns the cell of a table header as a DocTextField (const ref)
  virtual const DocTextField& GetHeaderCell(int row, int col) const = 0;
  /// Returns the cell of a table header as a DocTextField (mutable ref)
  virtual DocTextField& GetHeaderMutableCell(int row, int col) = 0;
  /// Returns the cell of a table header as a DocTextField (const ptr)
  virtual const DocTextField* GetHeaderCellPtr(int row, int col) const = 0;
  /// Returns the cell of a table header as a DocTextField (mutable ptr)
  virtual DocTextField* GetHeaderMutableCellPtr(int row, int col) = 0;
  /// Sets the cell of a table header as a DocTextField
  virtual void SetHeaderCell(int row, int col, const DocTextField& text_field) = 0;

  /// Resizes the set of rows of the table header
  virtual void ResizeHeaderRows(int rows) = 0;
  /// Resizes the set of rows of the table header with a given filler cell value
  virtual void ResizeHeaderRows(int rows, const DocTextField& filler) = 0;
  /// Resizes the set of columns of the table header
  virtual void ResizeHeaderCols(int cols) = 0;
  /// Resizes the set of columns of the table header with a given filler cell value
  virtual void ResizeHeaderCols(int cols, const DocTextField& filler) = 0;


public:
  /// METHODS TO BE DEPRECATED
  /// THESE METHODS ARE A PART OF THE OLD INTERFACE
  /// THEY ARE TO BE DELETED IN FUTURE VERSIONS

  
  
  
  /// Returns the name of the column with a given index
  virtual const char* GetColName(int col) const = 0;
  /// Sets the name of the column with a given index
  virtual void SetColName(int col, const char* col_name) = 0;

};


/**
 * @brief The class representing a barcode field of a document
 */
class SE_DLL_EXPORT DocBarcodeField {
public:
  /// Default dtor
  virtual ~DocBarcodeField() = default;

  /// Returns the basic field information (const ref)
  virtual const DocBaseFieldInfo& GetBaseFieldInfo() const = 0;
  /// Returns the basic field information (mutable ref)
  virtual DocBaseFieldInfo& GetMutableBaseFieldInfo() = 0;
  /// Returns the basic field information (const ptr)
  virtual const DocBaseFieldInfo* GetBaseFieldInfoPtr() const = 0;
  /// Returns the basic field information (mutable ptr)
  virtual DocBaseFieldInfo* GetMutableBaseFieldInfoPtr() = 0;

  /// Returns the barcode decoded message (const ref)
  virtual const se::common::MutableString& GetDecodedString() const = 0;
  /// Returns the barcode decoded message (mutable ref)
  virtual se::common::MutableString& GetMutableDecodedString() = 0;
  /// Returns the barcode decoded message (const ptr)
  virtual const se::common::MutableString* GetDecodedStringPtr() const = 0;
  /// Returns the barcode decoded message (mutable ptr)
  virtual se::common::MutableString* GetMutableDecodedStringPtr() = 0;
  /// Sets the barcode decoded message
  virtual void SetDecodedString(const se::common::MutableString& decstring) = 0;

  /// Serializes the field instance with a given serializer object
  virtual void Serialize(se::common::Serializer& serializer) const = 0;
};


} } // namespace se::doc

#endif // DOCENGINE_DOC_FIELDS_H_INCLUDED
