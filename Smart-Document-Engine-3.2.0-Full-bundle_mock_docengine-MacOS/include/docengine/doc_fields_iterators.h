/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_fields_iterators.h
 * @brief Classes of Smart Document Engine fields iterators
 */

#ifndef DOCENGINE_DOC_FIELDS_ITERATORS_H_INCLUDED
#define DOCENGINE_DOC_FIELDS_ITERATORS_H_INCLUDED

#include <secommon/se_export_defs.h>
#include <docengine/doc_forward_declarations.h>

namespace se { namespace doc {

/// Forward declaration for the internal implementation of
///     the DocTextFieldsIterator class
class DocTextFieldsIteratorImpl;

/**
 * @brief Const-ref iterator for a collection of text fields
 */
class SE_DLL_EXPORT DocTextFieldsIterator {
private:
  /// Private ctor from internal implementation
  DocTextFieldsIterator(const DocTextFieldsIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocTextFieldsIterator(const DocTextFieldsIterator& other);
  /// Assignment operator
  DocTextFieldsIterator& operator =(const DocTextFieldsIterator& other);
  /// Non-trivial dtor
  ~DocTextFieldsIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocTextFieldsIterator ConstructFromImpl(
      const DocTextFieldsIteratorImpl& pimpl);

  /// Returns the field name (the collection key)
  const char* GetKey() const;
  /// Returns the field value (const ref)
  const DocTextField& GetField() const;
  /// Returns the field value (const ptr)
  const DocTextField* GetFieldPtr() const;
  /// Switches the iterator to point on the next field in its collection
  void Advance();
  /// Switches the iterator to point on the next field in its collection
  void operator ++();

  /// Returns true iff this instance and rvalue point to the same field
  bool Equals(const DocTextFieldsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same field
  bool operator ==(const DocTextFieldsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the different fields
  bool operator !=(const DocTextFieldsIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  class DocTextFieldsIteratorImpl* pimpl_;
};


/// Forward declaration for the internal implementation of
///     the DocImageFieldsIterator class
class DocImageFieldsIteratorImpl;

/**
 * @brief Const-ref iterator for a collection of image fields
 */
class SE_DLL_EXPORT DocImageFieldsIterator {
private:
  /// Private ctor from internal implementation
  DocImageFieldsIterator(const DocImageFieldsIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocImageFieldsIterator(const DocImageFieldsIterator& other);
  /// Assignment operator
  DocImageFieldsIterator& operator =(const DocImageFieldsIterator& other);
  /// Non-trivial dtor
  ~DocImageFieldsIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocImageFieldsIterator ConstructFromImpl(
      const DocImageFieldsIteratorImpl& pimpl);

  /// Returns the field name (the collection key)
  const char* GetKey() const;
  /// Returns the field value (const ref)
  const DocImageField& GetField() const;
  /// Returns the field value (const ptr)
  const DocImageField* GetFieldPtr() const;
  /// Switches the iterator to point on the next field in its collection
  void Advance();
  /// Switches the iterator to point on the next field in its collection
  void operator ++();

  /// Returns true iff this instance and rvalue point to the same field
  bool Equals(const DocImageFieldsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same field
  bool operator ==(const DocImageFieldsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the different fields
  bool operator !=(const DocImageFieldsIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  class DocImageFieldsIteratorImpl* pimpl_;
};


/// Forward declaration for the internal implementation of
///     the DocCheckboxFieldsIterator class
class DocCheckboxFieldsIteratorImpl;

/**
 * @brief Const-ref iterator for a collection of checkbox fields
 */
class SE_DLL_EXPORT DocCheckboxFieldsIterator {
private:
  /// Private ctor from internal implementation
  DocCheckboxFieldsIterator(const DocCheckboxFieldsIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocCheckboxFieldsIterator(const DocCheckboxFieldsIterator& other);
  /// Assignment operator
  DocCheckboxFieldsIterator& operator =(const DocCheckboxFieldsIterator& other);
  /// Non-trivial dtor
  ~DocCheckboxFieldsIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocCheckboxFieldsIterator ConstructFromImpl(
      const DocCheckboxFieldsIteratorImpl& pimpl);

  /// Returns the field name (the collection key)
  const char* GetKey() const;
  /// Returns the field value (const ref)
  const DocCheckboxField& GetField() const;
  /// Returns the field value (const ptr)
  const DocCheckboxField* GetFieldPtr() const;
  /// Switches the iterator to point on the next field in its collection
  void Advance();
  /// Switches the iterator to point on the next field in its collection
  void operator ++();

  /// Returns true iff this instance and rvalue point to the same field
  bool Equals(const DocCheckboxFieldsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same field
  bool operator ==(const DocCheckboxFieldsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the different fields
  bool operator !=(const DocCheckboxFieldsIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  class DocCheckboxFieldsIteratorImpl* pimpl_;
};


/// Forward declaration for the internal implementation of
///     the DocForensicFieldsIterator class
class DocForensicFieldsIteratorImpl;

/**
 * @brief Const-ref iterator for a collection of forensic fields
 */
class SE_DLL_EXPORT DocForensicFieldsIterator {
private:
  /// Private ctor from internal implementation
  DocForensicFieldsIterator(const DocForensicFieldsIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocForensicFieldsIterator(const DocForensicFieldsIterator& other);
  /// Assignment operator
  DocForensicFieldsIterator& operator =(const DocForensicFieldsIterator& other);
  /// Non-trivial dtor
  ~DocForensicFieldsIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocForensicFieldsIterator ConstructFromImpl(
      const DocForensicFieldsIteratorImpl& pimpl);

  /// Returns the field name (the collection key)
  const char* GetKey() const;
  /// Returns the field value (const ref)
  const DocForensicField& GetField() const;
  /// Returns the field value (const ptr)
  const DocForensicField* GetFieldPtr() const;
  /// Switches the iterator to point on the next field in its collection
  void Advance();
  /// Switches the iterator to point on the next field in its collection
  void operator ++();

  /// Returns true iff this instance and rvalue point to the same field
  bool Equals(const DocForensicFieldsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same field
  bool operator ==(const DocForensicFieldsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the different fields
  bool operator !=(const DocForensicFieldsIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  class DocForensicFieldsIteratorImpl* pimpl_;
};

/// Forward declaration for the internal implementation of
///     the DocForensicCheckFieldsIterator class
class DocForensicCheckFieldsIteratorImpl;

/**
 * @brief Const-ref iterator for a collection of forensic check fields
 */
class SE_DLL_EXPORT DocForensicCheckFieldsIterator {
private:
  /// Private ctor from internal implementation
  DocForensicCheckFieldsIterator(const DocForensicCheckFieldsIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocForensicCheckFieldsIterator(const DocForensicCheckFieldsIterator& other);
  /// Assignment operator
  DocForensicCheckFieldsIterator& operator =(const DocForensicCheckFieldsIterator& other);
  /// Non-trivial dtor
  ~DocForensicCheckFieldsIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocForensicCheckFieldsIterator ConstructFromImpl(
      const DocForensicCheckFieldsIteratorImpl& pimpl);

  /// Returns the field name (the collection key)
  const char* GetKey() const;
  /// Returns the field value (const ref)
  const DocForensicCheckField& GetField() const;
  /// Returns the field value (const ptr)
  const DocForensicCheckField* GetFieldPtr() const;
  /// Switches the iterator to point on the next field in its collection
  void Advance();
  /// Switches the iterator to point on the next field in its collection
  void operator ++();

  /// Returns true iff this instance and rvalue point to the same field
  bool Equals(const DocForensicCheckFieldsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same field
  bool operator ==(const DocForensicCheckFieldsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the different fields
  bool operator !=(const DocForensicCheckFieldsIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  class DocForensicCheckFieldsIteratorImpl* pimpl_;
};


/// Forward declaration for the internal implementation of
///     the DocTableFieldsIterator class
class DocTableFieldsIteratorImpl;

/**
 * @brief Const-ref iterator for a collection of table fields
 */
class SE_DLL_EXPORT DocTableFieldsIterator {
private:
  /// Private ctor from internal implementation
  DocTableFieldsIterator(const DocTableFieldsIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocTableFieldsIterator(const DocTableFieldsIterator& other);
  /// Assignment operator
  DocTableFieldsIterator& operator =(const DocTableFieldsIterator& other);
  /// Non-trivial dtor
  ~DocTableFieldsIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocTableFieldsIterator ConstructFromImpl(
      const DocTableFieldsIteratorImpl& pimpl);

  /// Returns the field name (the collection key)
  const char* GetKey() const;
  /// Returns the field value (const ref)
  const DocTableField& GetField() const;
  /// Returns the field value (const ptr)
  const DocTableField* GetFieldPtr() const;
  /// Switches the iterator to point on the next field in its collection
  void Advance();
  /// Switches the iterator to point on the next field in its collection
  void operator ++();

  /// Returns true iff this instance and rvalue point to the same field
  bool Equals(const DocTableFieldsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same field
  bool operator ==(const DocTableFieldsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the different fields
  bool operator !=(const DocTableFieldsIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  class DocTableFieldsIteratorImpl* pimpl_;
};


/// Forward declaration for the internal implementation of
///     the DocBarcodeFieldsIterator class
class DocBarcodeFieldsIteratorImpl;

/**
 * @brief Const-ref iterator for a collection of barcode fields
 */
class SE_DLL_EXPORT DocBarcodeFieldsIterator {
private:
  /// Private ctor from internal implementation
  DocBarcodeFieldsIterator(const DocBarcodeFieldsIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocBarcodeFieldsIterator(const DocBarcodeFieldsIterator& other);
  /// Assignment operator
  DocBarcodeFieldsIterator& operator =(const DocBarcodeFieldsIterator& other);
  /// Non-trivial dtor
  ~DocBarcodeFieldsIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocBarcodeFieldsIterator ConstructFromImpl(
      const DocBarcodeFieldsIteratorImpl& pimpl);

  /// Returns the field name (the collection key)
  const char* GetKey() const;
  /// Returns the field value (const ref)
  const DocBarcodeField& GetField() const;
  /// Returns the field value (const ptr)
  const DocBarcodeField* GetFieldPtr() const;
  /// Switches the iterator to point on the next field in its collection
  void Advance();
  /// Switches the iterator to point on the next field in its collection
  void operator ++();

  /// Returns true iff this instance and rvalue point to the same field
  bool Equals(const DocBarcodeFieldsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same field
  bool operator ==(const DocBarcodeFieldsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the different fields
  bool operator !=(const DocBarcodeFieldsIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  class DocBarcodeFieldsIteratorImpl* pimpl_;
};

} } // namespace se::doc

#endif // DOCENGINE_DOC_FIELDS_ITERATORS_H_INCLUDED
