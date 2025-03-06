/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_basic_objects_iterator.h
 * @brief Iterators for basic graphical objects
 */

#ifndef DOCENGINE_DOC_BASIC_OBJECTS_ITERATOR_H_INCLUDED
#define DOCENGINE_DOC_BASIC_OBJECTS_ITERATOR_H_INCLUDED

#include <secommon/se_export_defs.h>
#include <docengine/doc_forward_declarations.h>

namespace se { namespace doc {


/// Forward declaration for the internal implementation of
///     the DocBasicObjectsIterator class
class DocBasicObjectsIteratorImpl;

class DocTextObjectsIteratorImpl;
class DocForensicCheckObjectsIteratorImpl;
class DocImageObjectsIteratorImpl;
class DocTableObjectsIteratorImpl;
class DocBarcodeObjectsIteratorImpl;
class DocCheckboxObjectsIteratorImpl;
class DocMetaObjectsIteratorImpl;

/**
 * @brief Basic const-ref iterator for a collection of basic graphical objects
 */
class SE_DLL_EXPORT DocBasicObjectsIterator {
private:
  /// Private ctor from internal implementation
  DocBasicObjectsIterator(const DocBasicObjectsIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocBasicObjectsIterator(const DocBasicObjectsIterator& other);
  /// Assignment operator
  DocBasicObjectsIterator& operator =(const DocBasicObjectsIterator& other);
  /// Non-trivial dtor
  ~DocBasicObjectsIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocBasicObjectsIterator ConstructFromImpl(
      const DocBasicObjectsIteratorImpl& pimpl);

  /// Returns the basic object ID
  int GetID() const;
  /// Returns the basic object (const ref)
  const DocBasicObject& GetBasicObject() const;
  /// Returns the basic object (const ptr)
  const DocBasicObject* GetBasicObjectPtr() const;
  /// Switches the iterator to point on the next object in its collection
  void Advance();

  /// Returns true iff this instance and rvalue point to the same object
  bool Equals(const DocBasicObjectsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same object
  bool operator ==(const DocBasicObjectsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the different objects
  bool operator !=(const DocBasicObjectsIterator& rvalue) const;

public:
  /// METHODS TO BE DEPRECETED
  /// THESE METHODS ARE PART OF THE OLD INTERFACE
  /// THEY ARE TO BE DELETED IN FUTURE VERSIONS

  /// Returns the tags collection of this object in its collection
  /// Method to be deprecated
  const DocTagsCollection& GetTags() const;
  /// Returns the tags collection of this object in its collection
  /// Method to be deprecated
  const DocTagsCollection* GetTagsPtr() const;

private:
  /// Pointer to internal implementation
  DocBasicObjectsIteratorImpl* pimpl_;
};

class SE_DLL_EXPORT DocTextObjectsIterator {
private:
  /// Private ctor from internal implementation
  DocTextObjectsIterator(const DocTextObjectsIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocTextObjectsIterator(const DocTextObjectsIterator& other);
  /// Assignment operator
  DocTextObjectsIterator& operator =(const DocTextObjectsIterator& other);
  /// Non-trivial dtor
  ~DocTextObjectsIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocTextObjectsIterator ConstructFromImpl(
      const DocTextObjectsIteratorImpl& pimpl);

  /// Returns the text object (const ref)
  const DocTextObject& GetTextObject() const;
  /// Returns the text object (const ptr)
  const DocTextObject* GetTextObjectPtr() const;
  /// Switches the iterator to point on the next object in its collection
  void Advance();

  /// Returns true iff this instance and rvalue point to the same object
  bool Equals(const DocTextObjectsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same object
  bool operator ==(const DocTextObjectsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the different objects
  bool operator !=(const DocTextObjectsIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  DocTextObjectsIteratorImpl* pimpl_;
};


class SE_DLL_EXPORT DocForensicCheckObjectsIterator {
private:
  /// Private ctor from internal implementation
  DocForensicCheckObjectsIterator(const DocForensicCheckObjectsIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocForensicCheckObjectsIterator(const DocForensicCheckObjectsIterator& other);
  /// Assignment operator
  DocForensicCheckObjectsIterator& operator =(const DocForensicCheckObjectsIterator& other);
  /// Non-trivial dtor
  ~DocForensicCheckObjectsIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocForensicCheckObjectsIterator ConstructFromImpl(
      const DocForensicCheckObjectsIteratorImpl& pimpl);

  /// Returns the forensic check object (const ref)
  const DocForensicCheckObject& GetForensicCheckObject() const;
  /// Returns the forensic check object (const ptr)
  const DocForensicCheckObject* GetForensicCheckObjectPtr() const;
  /// Switches the iterator to point on the next object in its collection
  void Advance();

  /// Returns true iff this instance and rvalue point to the same object
  bool Equals(const DocForensicCheckObjectsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same object
  bool operator ==(const DocForensicCheckObjectsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the different objects
  bool operator !=(const DocForensicCheckObjectsIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  DocForensicCheckObjectsIteratorImpl* pimpl_;
};

class SE_DLL_EXPORT DocImageObjectsIterator {
private:
  /// Private ctor from internal implementation
  DocImageObjectsIterator(const DocImageObjectsIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocImageObjectsIterator(const DocImageObjectsIterator& other);
  /// Assignment operator
  DocImageObjectsIterator& operator =(const DocImageObjectsIterator& other);
  /// Non-trivial dtor
  ~DocImageObjectsIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocImageObjectsIterator ConstructFromImpl(
      const DocImageObjectsIteratorImpl& pimpl);

  /// Returns the image object (const ref)
  const DocImageObject& GetImageObject() const;
  /// Returns the image object (const ptr)
  const DocImageObject* GetImageObjectPtr() const;
  /// Switches the iterator to point on the next object in its collection
  void Advance();

  /// Returns true iff this instance and rvalue point to the same object
  bool Equals(const DocImageObjectsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same object
  bool operator ==(const DocImageObjectsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the different objects
  bool operator !=(const DocImageObjectsIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  DocImageObjectsIteratorImpl* pimpl_;
};

class SE_DLL_EXPORT DocTableObjectsIterator {
private:
  /// Private ctor from internal implementation
  DocTableObjectsIterator(const DocTableObjectsIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocTableObjectsIterator(const DocTableObjectsIterator& other);
  /// Assignment operator
  DocTableObjectsIterator& operator =(const DocTableObjectsIterator& other);
  /// Non-trivial dtor
  ~DocTableObjectsIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocTableObjectsIterator ConstructFromImpl(
      const DocTableObjectsIteratorImpl& pimpl);

  /// Returns the table object (const ref)
  const DocTableObject& GetTableObject() const;
  /// Returns the table object (const ptr)
  const DocTableObject* GetTableObjectPtr() const;
  /// Switches the iterator to point on the next object in its collection
  void Advance();

  /// Returns true iff this instance and rvalue point to the same object
  bool Equals(const DocTableObjectsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same object
  bool operator ==(const DocTableObjectsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the different objects
  bool operator !=(const DocTableObjectsIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  DocTableObjectsIteratorImpl* pimpl_;
};

class SE_DLL_EXPORT DocBarcodeObjectsIterator {
private:
  /// Private ctor from internal implementation
  DocBarcodeObjectsIterator(const DocBarcodeObjectsIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocBarcodeObjectsIterator(const DocBarcodeObjectsIterator& other);
  /// Assignment operator
  DocBarcodeObjectsIterator& operator =(const DocBarcodeObjectsIterator& other);
  /// Non-trivial dtor
  ~DocBarcodeObjectsIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocBarcodeObjectsIterator ConstructFromImpl(
      const DocBarcodeObjectsIteratorImpl& pimpl);

  /// Returns the barcode object (const ref)
  const DocBarcodeObject& GetBarcodeObject() const;
  /// Returns the barcode object (const ptr)
  const DocBarcodeObject* GetBarcodeObjectPtr() const;
  /// Switches the iterator to point on the next object in its collection
  void Advance();

  /// Returns true iff this instance and rvalue point to the same object
  bool Equals(const DocBarcodeObjectsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same object
  bool operator ==(const DocBarcodeObjectsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the different objects
  bool operator !=(const DocBarcodeObjectsIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  DocBarcodeObjectsIteratorImpl* pimpl_;
};

class SE_DLL_EXPORT DocCheckboxObjectsIterator {
private:
  /// Private ctor from internal implementation
  DocCheckboxObjectsIterator(const DocCheckboxObjectsIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocCheckboxObjectsIterator(const DocCheckboxObjectsIterator& other);
  /// Assignment operator
  DocCheckboxObjectsIterator& operator =(const DocCheckboxObjectsIterator& other);
  /// Non-trivial dtor
  ~DocCheckboxObjectsIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocCheckboxObjectsIterator ConstructFromImpl(
      const DocCheckboxObjectsIteratorImpl& pimpl);

  /// Returns the checkbox object (const ref)
  const DocCheckboxObject& GetCheckboxObject() const;
  /// Returns the checkbox object (const ptr)
  const DocCheckboxObject* GetCheckboxObjectPtr() const;
  /// Switches the iterator to point on the next object in its collection
  void Advance();

  /// Returns true iff this instance and rvalue point to the same object
  bool Equals(const DocCheckboxObjectsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same object
  bool operator ==(const DocCheckboxObjectsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the different objects
  bool operator !=(const DocCheckboxObjectsIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  DocCheckboxObjectsIteratorImpl* pimpl_;
};

class SE_DLL_EXPORT DocMetaObjectsIterator {
private:
  /// Private ctor from internal implementation
  DocMetaObjectsIterator(const DocMetaObjectsIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocMetaObjectsIterator(const DocMetaObjectsIterator& other);
  /// Assignment operator
  DocMetaObjectsIterator& operator =(const DocMetaObjectsIterator& other);
  /// Non-trivial dtor
  ~DocMetaObjectsIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocMetaObjectsIterator ConstructFromImpl(
      const DocMetaObjectsIteratorImpl& pimpl);

  /// Returns the meta object (const ref)
  const DocMetaObject& GetMetaObject() const;
  /// Returns the meta object (const ptr)
  const DocMetaObject* GetMetaObjectPtr() const;
  /// Switches the iterator to point on the next object in its collection
  void Advance();

  /// Returns true iff this instance and rvalue point to the same object
  bool Equals(const DocMetaObjectsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same object
  bool operator ==(const DocMetaObjectsIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the different objects
  bool operator !=(const DocMetaObjectsIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  DocMetaObjectsIteratorImpl* pimpl_;
};


/// Forward declaration for the internal implementation of
///     the DocBasicObjectsMutableIterator class
class DocBasicObjectsMutableIteratorImpl;

/**
 * @brief Mutable-ref iterator for a collection of basic graphical objects
 * THIS CLASS IS TO BE DEPRECACTED
 */
class SE_DLL_EXPORT DocBasicObjectsMutableIterator {
private:
  /// Private ctor from internal implementation
  DocBasicObjectsMutableIterator(const DocBasicObjectsMutableIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocBasicObjectsMutableIterator(const DocBasicObjectsMutableIterator& other);
  /// Assignment operator
  DocBasicObjectsMutableIterator& operator =(
      const DocBasicObjectsMutableIterator& other);
  /// Non-trivial dtor
  ~DocBasicObjectsMutableIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocBasicObjectsMutableIterator ConstructFromImpl(
      const DocBasicObjectsMutableIteratorImpl& pimpl);

  /// Returns the basic object ID
  int GetID() const;
  /// Returns the basic object (const ref)
  const DocBasicObject& GetBasicObject() const;
  /// Returns the basic object (mutable ref)
  DocBasicObject& GetMutableBasicObject() const;
  /// Returns the tags collection of this object in its collection
  const DocTagsCollection& GetTags() const;
  /// Returns the basic object (const ptr)
  const DocBasicObject* GetBasicObjectPtr() const;
  /// Returns the basic object (mutable ptr)
  DocBasicObject* GetMutableBasicObjectPtr() const;
  /// Returns the tags collection of this object in its collection
  const DocTagsCollection* GetTagsPtr() const;
  /// Switches the iterator to point on the next object in its collection
  void Advance();

  /// Returns true iff this instance and rvalue point to the same object
  bool Equals(const DocBasicObjectsMutableIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same object
  bool operator ==(const DocBasicObjectsMutableIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the different objects
  bool operator !=(const DocBasicObjectsMutableIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  DocBasicObjectsMutableIteratorImpl* pimpl_;
};


/// Forward declaration for the internal implementation of
///     the DocBasicObjectsSliceIterator class
class DocBasicObjectsSliceIteratorImpl;


/**
 * @brief Const-ref iterator for a basic objects which have a given tag
 * THIS CLASS IS TO BE DEPRECACTED
 */
class SE_DLL_EXPORT DocBasicObjectsSliceIterator {
private:
  /// Private ctor from internal implementation
  DocBasicObjectsSliceIterator(const DocBasicObjectsSliceIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocBasicObjectsSliceIterator(const DocBasicObjectsSliceIterator& other);
  /// Assignment operator
  DocBasicObjectsSliceIterator& operator =(
      const DocBasicObjectsSliceIterator& other);
  /// Non-trivial dtor
  ~DocBasicObjectsSliceIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocBasicObjectsSliceIterator ConstructFromImpl(
      const DocBasicObjectsSliceIteratorImpl& pimpl);

  /// Returns the basic object ID
  int GetID() const;
  /// Returns the basic object (const ref)
  const DocBasicObject& GetBasicObject() const;
  /// Returns the tags collection of this object in its collection
  const DocTagsCollection& GetTags() const;
  /// Returns the basic object (const ptr)
  const DocBasicObject* GetBasicObjectPtr() const;
  /// Returns the tags collection of this object in its collection
  const DocTagsCollection* GetTagsPtr() const;
  /// Switches the iterator to point on the next object in its collection
  void Advance();

  /// Returns true iff the iterator points to the end of the subset of objects
  ///     with a given tag.
  bool Finished() const;

private:
  /// Pointer to internal implementation
  DocBasicObjectsSliceIteratorImpl* pimpl_;
};


/// Forward declaration for the internal implementation of
///     the DocBasicObjectsMutableSliceIterator class
class DocBasicObjectsMutableSliceIteratorImpl;

/**
 * @brief Mutable-ref iterator for a basic objects which have a given tag
 * THIS CLASS IS TO BE DEPRECACTED
 */
class SE_DLL_EXPORT DocBasicObjectsMutableSliceIterator {
private:
  /// Private ctor from internal implementation
  DocBasicObjectsMutableSliceIterator(
      const DocBasicObjectsMutableSliceIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocBasicObjectsMutableSliceIterator(
      const DocBasicObjectsMutableSliceIterator& other);
  /// Assignment operator
  DocBasicObjectsMutableSliceIterator& operator =(
      const DocBasicObjectsMutableSliceIterator& other);
  /// Non-trivial dtor
  ~DocBasicObjectsMutableSliceIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocBasicObjectsMutableSliceIterator ConstructFromImpl(
      const DocBasicObjectsMutableSliceIteratorImpl& pimpl);

  /// Returns the basic object ID
  int GetID() const;
  /// Returns the basic object (const ref)
  const DocBasicObject& GetBasicObject() const;
  /// Returns the basic object (mutable ref)
  DocBasicObject& GetMutableBasicObject() const;
  /// Returns the tags collection of this object in its collection
  const DocTagsCollection& GetTags() const;
  /// Returns the basic object (const ptr)
  const DocBasicObject* GetBasicObjectPtr() const;
  /// Returns the basic object (mutable ptr)
  DocBasicObject* GetMutableBasicObjectPtr() const;
  /// Returns the tags collection of this object in its collection
  const DocTagsCollection* GetTagsPtr() const;
  /// Switches the iterator to point on the next object in its collection
  void Advance();

  /// Returns true iff the iterator points to the end of the subset of objects
  ///     with a given tag.
  bool Finished() const;

private:
  /// Pointer to internal implementation
  DocBasicObjectsMutableSliceIteratorImpl* pimpl_;
};


/// Forward declaration for the internal implementation of
///     the DocBasicObjectsCrossSliceIterator class
class DocBasicObjectsCrossSliceIteratorImpl;

/**
 * @brief Const-ref iterator for basic objects across multiple collections
 * THIS CLASS IS TO BE DEPRECACTED
 */
class SE_DLL_EXPORT DocBasicObjectsCrossSliceIterator {
private:
  /// Private ctor from internal implementation
  DocBasicObjectsCrossSliceIterator(
      const DocBasicObjectsCrossSliceIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocBasicObjectsCrossSliceIterator(
      const DocBasicObjectsCrossSliceIterator& other);
  /// Assignment operator
  DocBasicObjectsCrossSliceIterator& operator =(
      const DocBasicObjectsCrossSliceIterator& other);
  /// Non-trivial dtor
  ~DocBasicObjectsCrossSliceIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocBasicObjectsCrossSliceIterator ConstructFromImpl(
      const DocBasicObjectsCrossSliceIteratorImpl& pimpl);

  /// Returns the collection ID in which this basic object is placed
  int GetCollectionID() const;
  /// Returns the basic object ID
  int GetObjectID() const;
  /// Returns the basic object (const ref)
  const DocBasicObject& GetBasicObject() const;
  /// Returns the tags collection of this object in its collection
  const DocTagsCollection& GetTags() const;
  /// Returns the basic object (const ptr)
  const DocBasicObject* GetBasicObjectPtr() const;
  /// Returns the tags collection of this object in its collection
  const DocTagsCollection* GetTagsPtr() const;
  /// Switches the iterator to point on the next object
  void Advance();

  /// Returns true iff this instance and rvalue point to the same object
  bool Equals(const DocBasicObjectsCrossSliceIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same object
  bool operator ==(const DocBasicObjectsCrossSliceIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the different objects
  bool operator !=(const DocBasicObjectsCrossSliceIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  DocBasicObjectsCrossSliceIteratorImpl* pimpl_;
};


/// Forward declaration for the internal implementation of
///     the DocBasicObjectsMutableCrossSliceIterator class
class DocBasicObjectsMutableCrossSliceIteratorImpl;

/**
 * @brief Mutable-ref iterator for basic objects across multiple collections
 * THIS CLASS IS TO BE DEPRECACTED
 */
class SE_DLL_EXPORT DocBasicObjectsMutableCrossSliceIterator {
private:
  /// Private ctor from internal implementation
  DocBasicObjectsMutableCrossSliceIterator(
      const DocBasicObjectsMutableCrossSliceIteratorImpl& pimpl);

public:
  /// Copy ctor
  DocBasicObjectsMutableCrossSliceIterator(
      const DocBasicObjectsMutableCrossSliceIterator& other);
  /// Assignment operator
  DocBasicObjectsMutableCrossSliceIterator& operator =(
      const DocBasicObjectsMutableCrossSliceIterator& other);
  /// Non-trivial dtor
  ~DocBasicObjectsMutableCrossSliceIterator();

  /// Factory method - constructs an iterator from its internal implementation
  static DocBasicObjectsMutableCrossSliceIterator ConstructFromImpl(
      const DocBasicObjectsMutableCrossSliceIteratorImpl& pimpl);

  /// Returns the collection ID in which this basic object is placed
  int GetCollectionID() const;
  /// Returns the basic object ID
  int GetObjectID() const;
  /// Returns the basic object (const ref)
  const DocBasicObject& GetBasicObject() const;
  /// Returns the basic object (mutable ref)
  DocBasicObject& GetMutableBasicObject();
  /// Returns the tags collection of this object in its collection
  const DocTagsCollection& GetTags() const;
  /// Returns the basic object (const ptr)
  const DocBasicObject* GetBasicObjectPtr() const;
  /// Returns the basic object (mutable ptr)
  DocBasicObject* GetMutableBasicObjectPtr();
  /// Returns the tags collection of this object in its collection
  const DocTagsCollection* GetTagsPtr() const;
  /// Switches the iterator to point on the next object
  void Advance();

  /// Returns true iff this instance and rvalue point to the same object
  bool Equals(const DocBasicObjectsMutableCrossSliceIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the same object
  bool operator ==(
      const DocBasicObjectsMutableCrossSliceIterator& rvalue) const;
  /// Returns true iff this instance and rvalue point to the different objects
  bool operator !=(
      const DocBasicObjectsMutableCrossSliceIterator& rvalue) const;

private:
  /// Pointer to internal implementation
  DocBasicObjectsMutableCrossSliceIteratorImpl* pimpl_;
};


} } // namespace se::doc

#endif // DOCENGINE_DOC_BASIC_OBJECTS_ITERATOR_H_INCLUDED
