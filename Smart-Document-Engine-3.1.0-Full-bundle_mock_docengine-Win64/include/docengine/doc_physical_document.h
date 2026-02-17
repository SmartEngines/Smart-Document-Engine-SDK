/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_physical_document.h
 * @brief Smart Document Engine class for document pages processing result and graphical objects extraction
 */

#ifndef DOCENGINE_DOC_PHYSICAL_DOCUMENT_H_INCLUDED
#define DOCENGINE_DOC_PHYSICAL_DOCUMENT_H_INCLUDED

#include <secommon/se_common.h>
#include <docengine/doc_basic_objects_iterator.h>

#ifdef WITH_PDFCREATOR
#include <secommon/se_pdf_creator.h>
#endif

namespace se { namespace doc {


/**
 * @brief The additional infomation about a processed physical page
 */
class SE_DLL_EXPORT DocPageInfo {
public:
  /// Default dtor
  virtual ~DocPageInfo() = default;

  ///Returns true if the page is invalid
  virtual bool IsGarbage() const = 0;

  ///Returns the length of the array with reasons why the page is not valid
  virtual int GarbageReasonsCount() const = 0;

  ///Returns the reason with index idx from the array
  virtual const char* GarbageReason(int idx) const = 0;
};


/**
 * @brief The class representing the found physical page
 */
class SE_DLL_EXPORT DocPhysicalPage {
public:
  /// Default dtor
  virtual ~DocPhysicalPage() = default;

  ///Return an index of the scene
  virtual int GetSourceSceneID() const = 0;

  /// Returns a constant 'begin' iterator to the collection of text objects connected with a field with a given name
  virtual DocTextObjectsIterator TextObjectsBegin(const char* name) const = 0;
  /// Returns a constant 'end' iterator to the collection of text objects connected with a field with a given name
  virtual DocTextObjectsIterator TextObjectsEnd(const char* name) const = 0;
  /// Returns a constant 'begin' iterator to the collection of image objects connected with a field with a given name
  virtual DocImageObjectsIterator ImageObjectsBegin(const char* name) const = 0;
  /// Returns a constant 'end' iterator to the collection of image objects connected with a field with a given name
  virtual DocImageObjectsIterator ImageObjectsEnd(const char* name) const = 0;
  /// Returns a constant 'begin' iterator to the collection of table objects connected with a field with a given name
  virtual DocTableObjectsIterator TableObjectsBegin(const char* name) const = 0;
  /// Returns a constant 'end' iterator to the collection of table objects connected with a field with a given name
  virtual DocTableObjectsIterator TableObjectsEnd(const char* name) const = 0;
  /// Returns a constant 'begin' iterator to the collection of barcode objects connected with a field with a given name
  virtual DocBarcodeObjectsIterator BarcodeObjectsBegin(const char* name) const = 0;
  /// Returns a constant 'end' iterator to the collection of barcode objects connected with a field with a given name
  virtual DocBarcodeObjectsIterator BarcodeObjectsEnd(const char* name) const = 0;
  /// Returns a constant 'begin' iterator to the collection of checkbox objects connected with a field with a given name
  virtual DocCheckboxObjectsIterator CheckboxObjectsBegin(const char* name) const = 0;
  /// Returns a constant 'end' iterator to the collection of checkbox objects connected with a field with a given name
  virtual DocCheckboxObjectsIterator CheckboxObjectsEnd(const char* name) const = 0;
  /// Returns a constant 'begin' iterator to the collection of forensic objects connected with a field with a given name
  virtual DocMetaObjectsIterator ForensicObjectsBegin(const char* name) const = 0;
  /// Returns a constant 'end' iterator to the collection of forensic objects connected with a field with a given name
  virtual DocMetaObjectsIterator ForensicObjectsEnd(const char* name) const = 0;
  /// Returns a constant 'begin' iterator to the collection of forensic check objects connected with a field with a given name
  virtual DocForensicCheckObjectsIterator ForensicCheckObjectsBegin(const char* name) const = 0;
  /// Returns a constant 'end' iterator to the collection of forensic check objects connected with a field with a given name
  virtual DocForensicCheckObjectsIterator ForensicCheckObjectsEnd(const char* name) const = 0;
  /// Returns a number of text objects connected with a field with a given name
  virtual int GetTextObjectsCount(const char* name) const = 0;
  /// Returns a number of image objects connected with a field with a given name
  virtual int GetImageObjectsCount(const char* name) const = 0;
  /// Returns a number of table objects connected with a field with a given name
  virtual int GetTableObjectsCount(const char* name) const = 0;
  /// Returns a number of barcode objects connected with a field with a given name
  virtual int GetBarcodeObjectsCount(const char* name) const = 0;
  /// Returns a number of checkbox objects connected with a field with a given name
  virtual int GetCheckboxObjectsCount(const char* name) const = 0;
  /// Returns a number of forensic objects connected with a field with a given name
  virtual int GetForensicObjectsCount(const char* name) const = 0;
  /// Returns a number of forensic check objects connected with a field with a given name
  virtual int GetForensicCheckObjectsCount(const char* name) const = 0;

  /// Returns true if page has at least one object
  virtual bool HasBasicObjects() const = 0;

  /// Returns page information, in particular reasons of why page is not valid (const ref)
  virtual const DocPageInfo& GetPageInfo() const = 0;
  /// Returns page information, in particular reasons of why page is not valid (const ptr)
  virtual const DocPageInfo* GetPageInfoPtr() const = 0;

  /// Returns the quadrangle of the page in the original image (const ref)
  virtual const se::common::Quadrangle& GetPageQuadrangle() const = 0;
  /// Returns the polygon of the page in the original image
  virtual const se::common::Polygon& GetPagePolygon() const = 0;
  /// Returns the quadrangle of the page in the original image (const ptr)
  virtual const se::common::Quadrangle* GetPageQuadranglePtr() const = 0;
  /// Returns the polygon of the page in the original image (const ptr)
  virtual const se::common::Polygon* GetPagePolygonPtr() const = 0;

  /// Returns a constant 'begin' iterator to the collection of text objects
  virtual DocTextObjectsIterator GetFulltextBasicObjectsBegin() const = 0;
  /// Returns a constant 'end' iterator to the collection of text objects
  virtual DocTextObjectsIterator GetFulltextBasicObjectsEnd() const = 0;

  /// Returns image of the page
  virtual se::common::Image* GetPageImageFromScene(const se::common::Image& scene_image) const = 0;

  /// Returns a constant 'begin' iterator to the collection of raw text objects
  virtual DocTextObjectsIterator RawTextObjectsBegin() const = 0;
  /// Returns a constant 'end' iterator to the collection of raw text objects
  virtual DocTextObjectsIterator RawTextObjectsEnd() const = 0;
  /// Returns a number of raw text objects
  virtual int GetRawTextObjectsCount() const = 0;
  /// Returns true if page has a raw text object by name
  virtual bool HasRawTextObject(const char* name) const = 0;
  /// Returns a raw text object by name
  virtual const se::doc::DocTextObject& GetRawTextObject(const char* name) const = 0;

#ifdef WITH_PDFCREATOR
  /// Fills pdf container
  virtual void FillPDFContainer(se::pdf::PdfSourcesContainer* pdf_container, const se::common::Image& scene_image) const = 0;
#endif

public:
  /// METHODS TO BE DEPRECATED
  /// THESE METHODS ARE A PART OF THE OLD INTERFACE
  /// THEY ARE TO BE DELETED IN FUTURE VERSIONS

  /// Returns a constant 'begin' iterator to the collection of basic objects connected with a field with a given name
  virtual DocBasicObjectsIterator BasicObjectsBegin(const char* name) const = 0;
  /// Returns a constant 'end' iterator to the collection of basic objects connected with a field with a given name
  virtual DocBasicObjectsIterator BasicObjectsEnd(const char* name) const = 0;
  /// Returns a number of objects connected with a field with a given name
  virtual int GetBasicObjectsCount(const char* name) const = 0;
};


/**
 * @brief The class representing the found physical document
 */
class SE_DLL_EXPORT DocPhysicalDocument {
public:
  /// Default dtor
  virtual ~DocPhysicalDocument() = default;

  /// Returns a number of text objects connected with a field with a given name
  virtual int GetTextObjectsCount(const char* name) const = 0;
  /// Returns a number of table objects connected with a field with a given name
  virtual int GetTableObjectsCount(const char* name) const = 0;
  /// Returns a number of image objects connected with a field with a given name
  virtual int GetImageObjectsCount(const char* name) const = 0;
  /// Returns a number of forensic objects connected with a field with a given name
  virtual int GetForensicObjectsCount(const char* name) const = 0;
  /// Returns a number of forensic check objects connected with a field with a given name
  virtual int GetForensicCheckObjectsCount(const char* name) const = 0;
  /// Returns a number of barcode objects connected with a field with a given name
  virtual int GetBarcodeObjectsCount(const char* name) const = 0;
  /// Returns a number of checkbox objects connected with a field with a given name
  virtual int GetCheckboxObjectsCount(const char* name) const = 0;

  ///Returns a number of pages in the document
  virtual int GetPagesCount() const = 0;

  ///Returns a page by indices (const ref)
  virtual const DocPhysicalPage& GetPhysicalPage(int idx) const = 0;
  ///Returns a page by indices (const ptr)
  virtual const DocPhysicalPage* GetPhysicalPagePtr(int idx) const = 0;

public:
  /// METHODS TO BE DEPRECATED
  /// THESE METHODS ARE A PART OF THE OLD INTERFACE
  /// THEY ARE TO BE DELETED IN FUTURE VERSIONS

  /// Returns a number of objects connected with a field with a given name
  virtual int GetBasicObjectsCount(const char* name) const = 0;
};

}} //se::doc

#endif //DOCENGINE_DOC_PHYSICAL_DOCUMENT_H_INCLUDED
