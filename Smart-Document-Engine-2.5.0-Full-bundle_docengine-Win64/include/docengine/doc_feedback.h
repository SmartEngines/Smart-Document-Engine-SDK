/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

/**
 * @file doc_feedback.h
 * @brief Smart Document Engine feedback reporting classes
 */

#ifndef DOCENGINE_DOC_FEEDBACK_H_INCLUDED
#define DOCENGINE_DOC_FEEDBACK_H_INCLUDED

#include <secommon/se_common.h>

#include <secommon/se_export_defs.h>
#include <docengine/doc_forward_declarations.h>

namespace se { namespace doc {

/**
 * @brief The class representing a feedback for one raw field.
 */
class SE_DLL_EXPORT DocRawFieldFeedback {
public:
    /// Default dtor
    virtual ~DocRawFieldFeedback() = default;

    /// Returns name of the raw field
    virtual const char* GetName() const = 0;

    /// Returns true iff field has quadrangle
    virtual bool HasQuadrangle() const = 0;

    /// Returns raw field quadrangle in the source page
    virtual const se::common::Quadrangle& GetQuadrangle() const = 0;

    /// Returns type of the raw field
    virtual const char* GetType() const = 0;

    /// Returns recognized value of the raw field
    virtual const se::common::OcrString GetOcrString() const = 0;
};


/**
 * @brief The class representing a feedback container for raw fields.
 */
class SE_DLL_EXPORT DocRawFieldsFeedbackContainer {
public:
    /// Default dtor
    virtual ~DocRawFieldsFeedbackContainer() = default;

    /// Returns the number of raw fields
    virtual int GetRawFieldCount() const = 0;

    /// Returns ID of the source page
    virtual int GetSourcePageID() const = 0;

    /// Return feedback for the raw field with given indice
    virtual const DocRawFieldFeedback& GetRawFieldFeedback(const int idx) const = 0;
};

/**
 * @brief The class representing a feedback for one page.
 */
class SE_DLL_EXPORT DocPageFeedback {
public:
    /// Default dtor
    virtual ~DocPageFeedback() = default;

    /// Returns page quadrangle in the original scene
    virtual const se::common::Quadrangle& GetQuadrangle() const = 0;

    /// Return ID of the page
    virtual int GetID() const = 0;

    /// Returns document type of teh page
    virtual const char* GetType() const = 0;

    /// Return 'true' if the page is not to be processed
    virtual bool IsPageRejected() const = 0;
};

/**
 * @brief The class representing a feedback container for pages.
 */
class SE_DLL_EXPORT DocPagesFeedbackContainer {
public:
    /// Default dtor
    virtual ~DocPagesFeedbackContainer() = default;

    /// Returns the number of pages
    virtual int GetPageCount() const = 0;

    /// Return feedback for the page with given indice
    virtual const DocPageFeedback& GetPageFeedback(const int idx) const = 0;
};

/**
 * @brief The class representing a custom feedback container. Not implemented
 *        in the current version of Smart Document Engine
 *  CLASS TO BE DEPRECATED
 */
class SE_DLL_EXPORT DocFeedbackContainer {
public:
  /// Default dtor
  virtual ~DocFeedbackContainer() = default;
  /// Returns a begin-iterator for an internal collection of feedback text fields
  virtual se::common::StringsMapIterator FeedbackFieldIteratorBegin() const = 0;
  /// Returns a end-iterator for an internal collection of feedback text fields
  virtual se::common::StringsMapIterator FeedbackFieldIteratorEnd() const = 0;
  /// Returns a begin-iterator for an internal collection of feedback quadrangles
  virtual se::common::QuadranglesMapIterator FeedbackQuadIteratorBegin() const = 0;
  /// Returns a end-iterator for an internal collection of feedback quadrangles
  virtual se::common::QuadranglesMapIterator FeedbackQuadIteratorEnd() const = 0;
  /// Feedback field setter
  virtual void SetFeedbackField(const char* key, const char* field) = 0;
  /// Feedback quad setter
  virtual void SetFeedbackQuad(const char* key, const se::common::Quadrangle& quad) = 0;
};


/**
 * @brief Abstract interface for receiving Smart Document Engine callbacks. All
 *        callbacks must be implemented.
 */
class SE_DLL_EXPORT DocFeedback {
public:
  /// Default dtor
  virtual ~DocFeedback() = default;

  /**
   * @brief Callback for receiving custom feedback container
   * @param container - the received feedback container
   * Method to be deprecated
   */
  virtual void FeedbackReceived(const DocFeedbackContainer& container) = 0;

  /// Returns true if localization feedback is needed
  /// Returns true by default
  virtual bool AcceptsPagesLocalizationFeedback() const;

  /**
   * @brief Callback for receiving feedback container with pages localization results
   * @param container - the received feedback container
   */
  virtual void PagesLocalizationFeedbackReceived(const DocPagesFeedbackContainer& container) const = 0;

  /// Returns true if page preprocessing feedback is needed
  /// Returns true by default
  virtual bool AcceptsPagePreprocessingFeedback() const;

  /**
   * @brief Callback for receiving feedback container with pages preprocessing results
   * @param container - the received feedback container
   */
  virtual void PagePrepocessingFeedbackReceived(const DocPagesFeedbackContainer& container) const = 0;

  /// Returns true if fields' localization feedback is needed
  /// Returns true by default
  virtual bool AcceptsRawFieldsLocalizationFeedback() const;

  /**
   * @brief Callback for receiving feedback container with raw fields localization results
   * @param container - the received feedback container
   */
  virtual void RawFieldsLocalizationFeedbackReceived(const DocRawFieldsFeedbackContainer& container) const = 0;

  /// Returns true if fields' raw recognition feedback is needed
  /// Returns true by default
  virtual bool AcceptsRawFieldsRecognitionFeedback() const;

  /**
   * @brief Callback for receiving feedback container with raw fields recognition results
   * @param container - the received feedback container
   */
  virtual void RawFiedlsRecognitionFeedbackReceived(const DocRawFieldsFeedbackContainer& container) const = 0;


  /**
   * @brief Callback for receiving an updated stream recognition result
   * @param result_received - the received recognition result
   */
  virtual void ResultReceived(const DocResult& result_received) = 0;
};


} } // namespace se::doc

#endif // DOCENGINE_DOC_FEEDBACK_H_INCLUDED
