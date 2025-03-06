/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_objects.h
 * @brief Types of graphical structure objects of Smart Document Engine
 */

#ifndef DOCENGINE_DOC_OBJECTS_H_INCLUDED
#define DOCENGINE_DOC_OBJECTS_H_INCLUDED

#include <secommon/se_common.h>
#include <docengine/doc_forward_declarations.h>
#include <docengine/doc_basic_object.h>

namespace se { namespace doc {


/**
 * @brief The graphical object representing a text line
 */
class SE_DLL_EXPORT DocTextObject : public DocBasicObject {
public:
  /// Default dtor
  virtual ~DocTextObject() override = default;

  /// Returns the object type name
  static const char* ObjectTypeStatic();

  /// Returns the text line recognition result (const ref)
  virtual const se::common::OcrString& GetOcrString() const = 0;
  /// Returns the text line recognition result (mutable ref)
  virtual se::common::OcrString& GetMutableOcrString() = 0;
  /// Returns the text line recognition result (const ptr)
  virtual const se::common::OcrString* GetOcrStringPtr() const = 0;
  /// Returns the text line recognition result (mutable ptr)
  virtual se::common::OcrString* GetMutableOcrStringPtr() = 0;
  /// Sets the text line recognition result
  virtual void SetOcrString(const se::common::OcrString& ocrstring) = 0;
};

/**
 * @brief The graphical object representing a text line
 */
class SE_DLL_EXPORT DocForensicCheckObject : public DocBasicObject {
public:
  /// Default dtor
  virtual ~DocForensicCheckObject() override = default;

  /// Returns the object type name
  static const char* ObjectTypeStatic();

  /// Returns the forensic check result (const ref)
  virtual const se::common::OcrString& GetOcrString() const = 0;
  /// Returns the forensic check result (mutable ref)
  virtual se::common::OcrString& GetMutableOcrString() = 0;
  /// Returns the forensic check result (const ptr)
  virtual const se::common::OcrString* GetOcrStringPtr() const = 0;
  /// Returns the forensic check result (mutable ptr)
  virtual se::common::OcrString* GetMutableOcrStringPtr() = 0;
};

/**
 * @brief The graphical object representing a checkbox
 */
class SE_DLL_EXPORT DocCheckboxObject : public DocBasicObject {
public:
  /// Default dtor
  virtual ~DocCheckboxObject() override = default;

  /// Returns the object type name
  static const char* ObjectTypeStatic();

  /// Returns the OcrString representation of the analysis result (const ref)
  virtual const se::common::OcrString& GetOcrString() const = 0;
  /// Returns the OcrString representation of the analysis result (mutable ref)
  virtual se::common::OcrString& GetMutableOcrString() = 0;
  /// Returns the OcrString representation of the analysis result (const ptr)
  virtual const se::common::OcrString* GetOcrStringPtr() const = 0;
  /// Returns the OcrString representation of the analysis result (mutable ptr)
  virtual se::common::OcrString* GetMutableOcrStringPtr() = 0;
  /// Sets the OcrString representation of the analysis result
  virtual void SetOcrString(const se::common::OcrString& ocrstring) = 0;
};


/**
 * @brief The graphical object representing a fixed subform template
 */
class SE_DLL_EXPORT DocTemplateObject : public DocBasicObject {
public:
  /// Default dtor
  virtual ~DocTemplateObject() override = default;

  /// Returns the object type name
  static const char* ObjectTypeStatic();
};


/**
 * @brief The graphical object representing a straight line segment
 */
class SE_DLL_EXPORT DocLineObject : public DocBasicObject {
public:
  /// Default dtor
  virtual ~DocLineObject() override = default;

  /// Returns the object type name
  static const char* ObjectTypeStatic();
};


/**
 * @brief The graphical object representing a localized document zone
 */
class SE_DLL_EXPORT DocZoneObject : public DocBasicObject {
public:
  /// Default dtor
  virtual ~DocZoneObject() override = default;

  /// Returns the object type name
  static const char* ObjectTypeStatic();

  /// Returns the standard pixel size of the zone (const ref)
  virtual const se::common::Size& GetSize() const = 0;
  /// Returns the standard pixel size of the zone (mutable ref)
  virtual se::common::Size& GetMutableSize() = 0;
  /// Returns the standard pixel size of the zone (const ptr)
  virtual const se::common::Size* GetSizePtr() const = 0;
  /// Returns the standard pixel size of the zone (mutable ptr)
  virtual se::common::Size* GetMutableSizePtr() = 0;
  /// Sets the standard pixel size of the zone
  virtual void SetSize(const se::common::Size& size) = 0;
};


/**
 * @brief The graphical object representing a text object with multiple lines
 */
class SE_DLL_EXPORT DocMultiStringTextObject : public DocBasicObject {
public:
  /// Default dtor
  virtual ~DocMultiStringTextObject() override = default;

  /// Returns the object type name
  static const char* ObjectTypeStatic();

  /// Return the number of text lines
  virtual int GetStringsCount() const = 0;
  /// Sets the number of text lines
  virtual void SetStringsCount(int count) = 0;

  /// Returns the text object by line index (const ref)
  virtual const DocTextObject& GetStringObject(int index) const = 0;
  /// Returns the text object by line index (mutable ref)
  virtual DocTextObject& GetMutableStringObject(int index) = 0;
  /// Returns the text object by line index (const ptr)
  virtual const DocTextObject* GetStringObjectPtr(int index) const = 0;
  /// Returns the text object by line index (mutable ptr)
  virtual DocTextObject* GetMutableStringObjectPtr(int index) = 0;
  /// Sets the text object by line index
  virtual void SetStringObject(
      int index, const DocTextObject& text_object) = 0;
};


/**
 * @brief The graphical object representing a meta object
 */
class SE_DLL_EXPORT DocMetaObject : public DocBasicObject {
public:
  /// Default dtor
  virtual ~DocMetaObject() override = default;

  /// Returns the object type name
  static const char* ObjectTypeStatic();

  /// Returns the OcrString representation (const ref)
  virtual const se::common::OcrString& GetOcrString() const = 0;
  /// Returns the OcrString representation (mutable ref)
  virtual se::common::OcrString& GetMutableOcrString() = 0;
  /// Returns the OcrString representation (const ptr)
  virtual const se::common::OcrString* GetOcrStringPtr() const = 0;
  /// Returns the OcrString representation (mutable ptr)
  virtual se::common::OcrString* GetMutableOcrStringPtr() = 0;
  /// Sets the OcrString representation
  virtual void SetOcrString(const se::common::OcrString& ocrstring) = 0;
};


/**
 * @brief The graphical object representing a table
 */
class SE_DLL_EXPORT DocTableObject : public DocBasicObject {
public:
  /// Default dtor
  virtual ~DocTableObject() override = default;

  /// Returns the object type name
  static const char* ObjectTypeStatic();

  /// Returns the number of table rows
  virtual int GetRowsCount() const = 0;

  /// Returns the number of table columns. Rows may contain different number
  ///     of columns
  virtual int GetColsCount(int row) const = 0;
  /// Returns the cell by given row and column indices (const ref)
  virtual const DocMultiStringTextObject& GetCell(int row, int col) const = 0;
  /// Returns the cell by given row and column indices (mutable ref)
  virtual DocMultiStringTextObject& GetMutableCell(int row, int col) = 0;
  /// Returns the cell by given row and column indices (const ptr)
  virtual const DocMultiStringTextObject* GetCellPtr(int row, int col) const = 0;
  /// Returns the cell by given row and column indices (mutable ptr)
  virtual DocMultiStringTextObject* GetMutableCellPtr(int row, int col) = 0;
  /// Sets the cell by given row and column indices
  virtual void SetCell(
      int row,
      int col,
      const DocMultiStringTextObject& multi_string_text_object) = 0;

  /// Resizes the set of rows
  virtual void ResizeRows(int rows) = 0;
  /// Resizes the set of columns
  virtual void ResizeCols(int row, int cols) = 0;

  /// Returns the name of the column
  virtual const char* GetColName(int col, int row) const = 0;
  /// Sets the name of the column. Number of columns in first row limits the
  /// number of column names
  virtual void SetColName(int col, int first_row, const char* col_name) = 0;
};


/**
 * @brief The graphical object representing an image region of a document
 */
class SE_DLL_EXPORT DocImageObject : public DocBasicObject {
public:
  /// Default dtor
  virtual ~DocImageObject() override = default;

  /// Returns the object type name
  static const char* ObjectTypeStatic();
};


/**
 * @brief The graphical object representing a barcode
 */
class SE_DLL_EXPORT DocBarcodeObject : public DocBasicObject {
public:
  /// Default dtor
  virtual ~DocBarcodeObject() override = default;

  /// Returns the object type name
  static const char* ObjectTypeStatic();

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
};

/**
 * @brief The graphical object representing a remark or correction on a document
 */
class SE_DLL_EXPORT DocMarkObject : public DocBasicObject {
public:
  /// Default dtor
  virtual ~DocMarkObject() override = default;

  /// Returns the object type name
  static const char* ObjectTypeStatic();
};


} } // namespace se::doc

#endif // DOCENGINE_DOC_OBJECTS_H_INCLUDED
