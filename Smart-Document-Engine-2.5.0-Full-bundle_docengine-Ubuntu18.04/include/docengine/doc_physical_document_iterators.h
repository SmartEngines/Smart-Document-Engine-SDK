/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_physical_document_iterators.h
 * @brief Smart Document Engine class for iterators used in document pages processing result and graphical objects extraction
 */

#ifndef DOCENGINE_DOC_PHYSICAL_DOCUMENT_ITERATORS_H_INCLUDED
#define DOCENGINE_DOC_PHYSICAL_DOCUMENT_ITERATORS_H_INCLUDED

#include <secommon/se_common.h>
#include <docengine/doc_basic_object.h>

namespace se { namespace doc {

/// Forward declaration for the internal implementation of
///     the DocBasicObjectsCrossPageIterator class
//class DocBasicObjectsCrossPageIteratorImpl;

class DocTextObjectsCrossPageIteratorImpl;
class DocForensicCheckObjectsCrossPageIteratorImpl;
class DocImageObjectsCrossPageIteratorImpl;
class DocTableObjectsCrossPageIteratorImpl;
class DocCheckboxObjectsCrossPageIteratorImpl;
class DocMetaObjectsCrossPageIteratorImpl;
class DocBarcodeObjectsCrossPageIteratorImpl;


/**
 * @brief Basic const-ref iterator for a collection of text objects from several pages
 */

class SE_DLL_EXPORT DocTextObjectsCrossPageIterator {
private:
    /// Private ctor from internal implementation
    DocTextObjectsCrossPageIterator(const DocTextObjectsCrossPageIteratorImpl& pimpl);

public:
    /// Copy ctor
    DocTextObjectsCrossPageIterator(const DocTextObjectsCrossPageIterator& other);
    /// Assignment operator
    DocTextObjectsCrossPageIterator& operator =(const DocTextObjectsCrossPageIterator& other);
    /// Non-trivial dtor
    ~DocTextObjectsCrossPageIterator();

    /// Factory method - constructs an iterator from its internal implementation
    static DocTextObjectsCrossPageIterator ConstructFromImpl(
        const DocTextObjectsCrossPageIteratorImpl& pimpl);

    /// Return ID of a physical page contaning current object
    int GetPhysicalPageID() const;

    /// Return ID of an object
    int GetObjectID() const;

    /// Returns the text object (const ref)
    const DocTextObject& GetTextObject() const;
    /// Returns the text object (const ptr)
    const DocTextObject* GetTextObjectPtr() const;
    /// Switches the iterator to point on the next object in its collection
    void Advance();

    /// Returns true iff this instance and rvalue point to the same object
    bool Equals(const DocTextObjectsCrossPageIterator& rvalue) const;
    /// Returns true iff this instance and rvalue point to the same object
    bool operator ==(const DocTextObjectsCrossPageIterator& rvalue) const;
    /// Returns true iff this instance and rvalue point to the different objects
    bool operator !=(const DocTextObjectsCrossPageIterator& rvalue) const;

private:
    /// Pointer to internal implementation
    DocTextObjectsCrossPageIteratorImpl* pimpl_;
};

/**
 * @brief Basic const-ref iterator for a collection of forensic check objects from several pages
 */

class SE_DLL_EXPORT DocForensicCheckObjectsCrossPageIterator {
private:
    /// Private ctor from internal implementation
    DocForensicCheckObjectsCrossPageIterator(const DocForensicCheckObjectsCrossPageIteratorImpl& pimpl);

public:
    /// Copy ctor
    DocForensicCheckObjectsCrossPageIterator(const DocForensicCheckObjectsCrossPageIterator& other);
    /// Assignment operator
    DocForensicCheckObjectsCrossPageIterator& operator =(const DocForensicCheckObjectsCrossPageIterator& other);
    /// Non-trivial dtor
    ~DocForensicCheckObjectsCrossPageIterator();

    /// Factory method - constructs an iterator from its internal implementation
    static DocForensicCheckObjectsCrossPageIterator ConstructFromImpl(
        const DocForensicCheckObjectsCrossPageIteratorImpl& pimpl);

    /// Return ID of a physsicak page contaning current object
    int GetPhysicalPageID() const;

    /// Returns the forensic check object (const ref)
    const DocForensicCheckObject& GetForensicCheckObject() const;
    /// Returns the forensic check object (const ptr)
    const DocForensicCheckObject* GetForensicCheckObjectPtr() const;
    /// Switches the iterator to point on the next object in its collection
    void Advance();

    /// Returns true iff this instance and rvalue point to the same object
    bool Equals(const DocForensicCheckObjectsCrossPageIterator& rvalue) const;
    /// Returns true iff this instance and rvalue point to the same object
    bool operator ==(const DocForensicCheckObjectsCrossPageIterator& rvalue) const;
    /// Returns true iff this instance and rvalue point to the different objects
    bool operator !=(const DocForensicCheckObjectsCrossPageIterator& rvalue) const;

private:
    /// Pointer to internal implementation
    DocForensicCheckObjectsCrossPageIteratorImpl* pimpl_;
};

/**
 * @brief Basic const-ref iterator for a collection of image objects from several pages
 */

class SE_DLL_EXPORT DocImageObjectsCrossPageIterator {
private:
    /// Private ctor from internal implementation
    DocImageObjectsCrossPageIterator(const DocImageObjectsCrossPageIteratorImpl& pimpl);

public:
    /// Copy ctor
    DocImageObjectsCrossPageIterator(const DocImageObjectsCrossPageIterator& other);
    /// Assignment operator
    DocImageObjectsCrossPageIterator& operator =(const DocImageObjectsCrossPageIterator& other);
    /// Non-trivial dtor
    ~DocImageObjectsCrossPageIterator();

    /// Factory method - constructs an iterator from its internal implementation
    static DocImageObjectsCrossPageIterator ConstructFromImpl(
        const DocImageObjectsCrossPageIteratorImpl& pimpl);

    /// Return ID of a physical page contaning current object
    int GetPhysicalPageID() const;

    /// Return ID of an object
    int GetObjectID() const;

    /// Returns the basic image (const ref)
    const DocImageObject& GetImageObject() const;
    /// Returns the image object (const ptr)
    const DocImageObject* GetImageObjectPtr() const;
    /// Switches the iterator to point on the next object in its collection
    void Advance();

    /// Returns true iff this instance and rvalue point to the same object
    bool Equals(const DocImageObjectsCrossPageIterator& rvalue) const;
    /// Returns true iff this instance and rvalue point to the same object
    bool operator ==(const DocImageObjectsCrossPageIterator& rvalue) const;
    /// Returns true iff this instance and rvalue point to the different objects
    bool operator !=(const DocImageObjectsCrossPageIterator& rvalue) const;

private:
    /// Pointer to internal implementation
    DocImageObjectsCrossPageIteratorImpl* pimpl_;
};

/**
 * @brief Basic const-ref iterator for a collection of table objects from several pages
 */

class SE_DLL_EXPORT DocTableObjectsCrossPageIterator {
private:
    /// Private ctor from internal implementation
    DocTableObjectsCrossPageIterator(const DocTableObjectsCrossPageIteratorImpl& pimpl);

public:
    /// Copy ctor
    DocTableObjectsCrossPageIterator(const DocTableObjectsCrossPageIterator& other);
    /// Assignment operator
    DocTableObjectsCrossPageIterator& operator =(const DocTableObjectsCrossPageIterator& other);
    /// Non-trivial dtor
    ~DocTableObjectsCrossPageIterator();

    /// Factory method - constructs an iterator from its internal implementation
    static DocTableObjectsCrossPageIterator ConstructFromImpl(
        const DocTableObjectsCrossPageIteratorImpl& pimpl);

    /// Return ID of a physical page contaning current object
    int GetPhysicalPageID() const;

    /// Return ID of an object
    int GetObjectID() const;

    /// Returns the table object (const ref)
    const DocTableObject& GetTableObject() const;
    /// Returns the table object (const ptr)
    const DocTableObject* GetTableObjectPtr() const;
    /// Switches the iterator to point on the next object in its collection
    void Advance();

    /// Returns true iff this instance and rvalue point to the same object
    bool Equals(const DocTableObjectsCrossPageIterator& rvalue) const;
    /// Returns true iff this instance and rvalue point to the same object
    bool operator ==(const DocTableObjectsCrossPageIterator& rvalue) const;
    /// Returns true iff this instance and rvalue point to the different objects
    bool operator !=(const DocTableObjectsCrossPageIterator& rvalue) const;

private:
    /// Pointer to internal implementation
    DocTableObjectsCrossPageIteratorImpl* pimpl_;
};

/**
 * @brief Basic const-ref iterator for a collection of checkbox objects from several pages
 */

class SE_DLL_EXPORT DocCheckboxObjectsCrossPageIterator {
private:
    /// Private ctor from internal implementation
    DocCheckboxObjectsCrossPageIterator(const DocCheckboxObjectsCrossPageIteratorImpl& pimpl);

public:
    /// Copy ctor
    DocCheckboxObjectsCrossPageIterator(const DocCheckboxObjectsCrossPageIterator& other);
    /// Assignment operator
    DocCheckboxObjectsCrossPageIterator& operator =(const DocCheckboxObjectsCrossPageIterator& other);
    /// Non-trivial dtor
    ~DocCheckboxObjectsCrossPageIterator();

    /// Factory method - constructs an iterator from its internal implementation
    static DocCheckboxObjectsCrossPageIterator ConstructFromImpl(
        const DocCheckboxObjectsCrossPageIteratorImpl& pimpl);

    /// Return ID of a physsicak page contaning current object
    int GetPhysicalPageID() const;

    /// Returns the checkbox object (const ref)
    const DocCheckboxObject& GetCheckboxObject() const;
    /// Returns the checkbox object (const ptr)
    const DocCheckboxObject* GetCheckboxObjectPtr() const;
    /// Switches the iterator to point on the next object in its collection
    void Advance();

    /// Returns true iff this instance and rvalue point to the same object
    bool Equals(const DocCheckboxObjectsCrossPageIterator& rvalue) const;
    /// Returns true iff this instance and rvalue point to the same object
    bool operator ==(const DocCheckboxObjectsCrossPageIterator& rvalue) const;
    /// Returns true iff this instance and rvalue point to the different objects
    bool operator !=(const DocCheckboxObjectsCrossPageIterator& rvalue) const;

private:
    /// Pointer to internal implementation
    DocCheckboxObjectsCrossPageIteratorImpl* pimpl_;
};

/**
 * @brief Basic const-ref iterator for a collection of meta objects from several pages
 */

class SE_DLL_EXPORT DocMetaObjectsCrossPageIterator {
private:
    /// Private ctor from internal implementation
    DocMetaObjectsCrossPageIterator(const DocMetaObjectsCrossPageIteratorImpl& pimpl);

public:
    /// Copy ctor
    DocMetaObjectsCrossPageIterator(const DocMetaObjectsCrossPageIterator& other);
    /// Assignment operator
    DocMetaObjectsCrossPageIterator& operator =(const DocMetaObjectsCrossPageIterator& other);
    /// Non-trivial dtor
    ~DocMetaObjectsCrossPageIterator();

    /// Factory method - constructs an iterator from its internal implementation
    static DocMetaObjectsCrossPageIterator ConstructFromImpl(
        const DocMetaObjectsCrossPageIteratorImpl& pimpl);

    /// Return ID of a physsicak page contaning current object
    int GetPhysicalPageID() const;

    /// Returns the meta object (const ref)
    const DocMetaObject& GetMetaObject() const;
    /// Returns the Meta object (const ptr)
    const DocMetaObject* GetMetaObjectPtr() const;
    /// Switches the iterator to point on the next object in its collection
    void Advance();

    /// Returns true iff this instance and rvalue point to the same object
    bool Equals(const DocMetaObjectsCrossPageIterator& rvalue) const;
    /// Returns true iff this instance and rvalue point to the same object
    bool operator ==(const DocMetaObjectsCrossPageIterator& rvalue) const;
    /// Returns true iff this instance and rvalue point to the different objects
    bool operator !=(const DocMetaObjectsCrossPageIterator& rvalue) const;

private:
    /// Pointer to internal implementation
    DocMetaObjectsCrossPageIteratorImpl* pimpl_;
};

/**
 * @brief Basic const-ref iterator for a collection of barcode objects from several pages
 */

class SE_DLL_EXPORT DocBarcodeObjectsCrossPageIterator {
private:
    /// Private ctor from internal implementation
    DocBarcodeObjectsCrossPageIterator(const DocBarcodeObjectsCrossPageIteratorImpl& pimpl);

public:
    /// Copy ctor
    DocBarcodeObjectsCrossPageIterator(const DocBarcodeObjectsCrossPageIterator& other);
    /// Assignment operator
    DocBarcodeObjectsCrossPageIterator& operator =(const DocBarcodeObjectsCrossPageIterator& other);
    /// Non-trivial dtor
    ~DocBarcodeObjectsCrossPageIterator();

    /// Factory method - constructs an iterator from its internal implementation
    static DocBarcodeObjectsCrossPageIterator ConstructFromImpl(
        const DocBarcodeObjectsCrossPageIteratorImpl& pimpl);

    /// Return ID of a physsicak page contaning current object
    int GetPhysicalPageID() const;

    /// Returns the barcode object (const ref)
    const DocBarcodeObject& GetBarcodeObject() const;
    /// Returns the barcode object (const ptr)
    const DocBarcodeObject* GetBarcodeObjectPtr() const;
    /// Switches the iterator to point on the next object in its collection
    void Advance();

    /// Returns true iff this instance and rvalue point to the same object
    bool Equals(const DocBarcodeObjectsCrossPageIterator& rvalue) const;
    /// Returns true iff this instance and rvalue point to the same object
    bool operator ==(const DocBarcodeObjectsCrossPageIterator& rvalue) const;
    /// Returns true iff this instance and rvalue point to the different objects
    bool operator !=(const DocBarcodeObjectsCrossPageIterator& rvalue) const;

private:
    /// Pointer to internal implementation
    DocBarcodeObjectsCrossPageIteratorImpl* pimpl_;
};


}} //se::doc

#endif //DOCENGINE_DOC_PHYSICAL_DOCUMENT_ITERATORS_H_INCLUDED
