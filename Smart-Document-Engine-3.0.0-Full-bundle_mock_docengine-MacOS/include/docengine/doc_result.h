/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_result.h
 * @brief Smart Document Engine result representation
 */

#ifndef DOCENGINE_DOC_RESULT_H_INCLUDED
#define DOCENGINE_DOC_RESULT_H_INCLUDED

#include <secommon/se_common.h>
#include <docengine/doc_forward_declarations.h>
#include <docengine/doc_documents_iterator.h>
#include <docengine/doc_physical_document.h>
#include <docengine/doc_scene_info.h>

namespace se { namespace doc {

/**
 * @brief The class representing the document analysis and recognition result
 */
class SE_DLL_EXPORT DocResult {
public:
  /// Default dtor
  virtual ~DocResult() = default;

  /// Returns DoctResult copy without graphical structure or physical document
  virtual DocResult* PartialClone() const = 0;
  /// Returns DoctResult copy
  virtual DocResult* Clone() const = 0;


  /// Returns the number of found documents
  virtual int GetDocumentsCount() const = 0;
  /// Returns true iff there is a document with a given ID
  virtual bool HasDocument(int doc_id) const = 0;
  /// Returns a document with a given ID (const ref)
  virtual const Document& GetDocument(int doc_id) const = 0;
  /// Returns a document with a given ID (const ptr)
  virtual const Document* GetDocumentPtr(int doc_id) const = 0;

  /// Returns a constant 'begin' iterator to the collection of documents
  virtual DocumentsIterator DocumentsBegin() const = 0;
  /// Returns a constant 'end' iterator to the collection of documents
  virtual DocumentsIterator DocumentsEnd() const = 0;

  /// Serializes the result instance with a given serializer object
  virtual void Serialize(se::common::Serializer& serializer) const = 0;

  /// Returns a physical document with a given indice (const ref)
  virtual const DocPhysicalDocument& GetPhysicalDocument(int idx) const = 0;

  /// Returns a physical document with a given indice (const ptr)
  virtual const DocPhysicalDocument* GetPhysicalDocumentPtr(int idx) const = 0;

  /// Returns a count of scenes
  virtual int GetScenesCount() const = 0;

  /// Returns a scene info with a given indice (const ref)
  virtual const DocSceneInfo& GetSceneInfo(int idx) const = 0;

  /// Returns last scene info (const ref)
  virtual const DocSceneInfo& GetLastSceneInfo() const = 0;

  /// Returns a scene info with a given indice (const ptr)
  virtual const DocSceneInfo* GetSceneInfoPtr(int idx) const = 0;

  /// Returns last scene info (const ptr)
  virtual const DocSceneInfo* GetLastSceneInfoPtr() const = 0;

public:
  /// METHODS TO BE DEPRECATED
  /// THESE METHODS ARE A PART OF THE OLD INTERFACE
  /// THEY ARE TO BE DELETED IN FUTURE VERSIONS

  /// Returns the graphical structure of the analyzed images (const ref)
  virtual const DocGraphicalStructure& GetGraphicalStructure() const = 0;
  /// Returns the graphical structure of the analyzed images (mutable ref)
  virtual DocGraphicalStructure& GetMutableGraphicalStructure() = 0;
  /// Returns the graphical structure of the analyzed images (const ptr)
  virtual const DocGraphicalStructure* GetGraphicalStructurePtr() const = 0;
  /// Returns the graphical structure of the analyzed images (mutable ptr)
  virtual DocGraphicalStructure* GetMutableGraphicalStructurePtr() = 0;

  /// Returns a document with a given ID (mutable ref)
  virtual Document& GetMutableDocument(int doc_id) = 0;
  /// Returns the tags collection of a document with a given ID
  virtual const DocTagsCollection& GetDocumentTags(int doc_id) const = 0;
    /// Returns a document with a given ID (mutable ref)
  virtual Document* GetMutableDocumentPtr(int doc_id) = 0;
  /// Returns the tags collection of a document with a given ID
  virtual const DocTagsCollection* GetDocumentTagsPtr(int doc_id) const = 0;

  /// Adds a new document to the result
  virtual DocumentsMutableIterator AddDocument(const Document& doc) = 0;
  /// Sets a document with a given ID
  virtual void SetDocument(int doc_id, const Document& doc) = 0;
  /// Removes a document with a given ID
  virtual void RemoveDocument(int doc_id) = 0;
  /// Returns a mutable 'begin' iterator to the collection of documents
  virtual DocumentsMutableIterator MutableDocumentsBegin() = 0;
  /// Returns a mutable 'end' iterator to the collection of documents
  virtual DocumentsMutableIterator MutableDocumentsEnd() = 0;

  /// Returns a constant iterator to the subset of documents with a given tag
  virtual DocumentsSliceIterator DocumentsSlice(const char* tag) const = 0;

  /// Returns a mutable iterator to the subset of documents with a given tag
  virtual DocumentsMutableSliceIterator MutableDocumentsSlice(
      const char* tag) = 0;

  /// Checks if pdf/a buffer can be created
  virtual bool CanBuildPDFABuffer() const = 0;

  /// Converts result to pdf/a buffer
  virtual void BuildPDFABuffer() = 0;

  /// Returns the buffer with pdf/a result
  virtual void GetPDFABuffer(unsigned char* output_buf, unsigned long long buf_size) const = 0;

  /// Return the size of resulting buffer with pdf/a
  virtual int GetPDFABufferSize() const = 0;

  /// Sets the current mode of pdf/a serializing
  virtual void SetAddTextMode(const char* mode_name) = 0;

  /// Returns the current mode of pdf/a serializing
  virtual const char* GetAddTextMode() const = 0;

  /// Returns true if there is a supported mode of pdf/a serializing with a given name
  virtual bool HasAddTextMode(const char* mode_name) const = 0;

  /// Returns a 'begin' vector-like iterator to the list of supported mode names
  virtual se::common::StringsVectorIterator AddTextModesBegin() const = 0;
  /// Returns an 'end' vector-like iterator to the list of supported mode names
  virtual se::common::StringsVectorIterator AddTextModesEnd() const = 0;

  /// Sets the current mode of pdf/a serializing
  virtual void SetTextTypeMode(const char* mode_name) = 0;

  /// Returns the current mode of pdf/a serializing
  virtual const char* GetTextTypeMode() const = 0;

  /// Returns true if there is a supported mode of pdf/a serializing with a given name
  virtual bool HasTextTypeMode(const char* mode_name) const = 0;

  /// Returns a 'begin' vector-like iterator to the list of supported mode names
  virtual se::common::StringsVectorIterator TextTypeModesBegin() const = 0;
  /// Returns an 'end' vector-like iterator to the list of supported mode names
  virtual se::common::StringsVectorIterator TextTypeModesEnd() const = 0;

  /// Set to true if you want to save color elements of the images
  virtual void SetColourMode(const bool with_colour) = 0;

  /// Return the current color saving mode
  virtual bool GetColourMode() const = 0;
};

} } // namespace se::doc

#endif // DOCENGINE_DOC_RESULT_H_INCLUDED
