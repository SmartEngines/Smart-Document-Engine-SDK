/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_PROXY_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_PROXY_H_INCLUDED

#import <objcdocengine_impl/doc_feedback_impl.h>
#import <objcdocengine_impl/doc_external_processor_impl.h>

#import <objcdocengine_impl/doc_result_impl.h>
#import <objcdocengine_impl/doc_processing_settings_impl.h>

#import <docengine/doc_feedback.h>
#import <docengine/doc_external_processor.h>

class ProxyFeedback : public se::doc::DocFeedback {
public:
  ProxyFeedback(id<SEDocFeedback> feedback_reporter);

  void setReporter(id<SEDocFeedback> feedback_reporter);

  virtual void FeedbackReceived(
      const se::doc::DocFeedbackContainer& container) override final;
    
  virtual void ResultReceived(
      const se::doc::DocResult& result) override final;

  virtual bool AcceptsPagesLocalizationFeedback();
    
  virtual bool AcceptsPagePreprocessingFeedback();
    
  virtual bool AcceptsRawFieldsLocalizationFeedback();
  
  virtual bool AcceptsRawFieldsRecognitionFeedback();
  
  virtual void PagesLocalizationFeedbackReceived(const se::doc::DocPagesFeedbackContainer& container) const override final;
  
  virtual void PagePrepocessingFeedbackReceived(const se::doc::DocPagesFeedbackContainer& container) const override final;
  
  virtual void RawFieldsLocalizationFeedbackReceived(const se::doc::DocRawFieldsFeedbackContainer& container) const override final;
  
  virtual void RawFiedlsRecognitionFeedbackReceived(const se::doc::DocRawFieldsFeedbackContainer& container) const override final;
private:
  void recalculateCache();

  id<SEDocFeedback> feedbackReporter_;

  bool responds_to_feedback_received = false;
};

class ProxyExternalProcessor : public se::doc::DocExternalProcessorInterface {
public:
  ProxyExternalProcessor(id<SEDocExternalProcessor> external_processor);

  void setExternalProcessor(id<SEDocExternalProcessor> external_processor);

  virtual void Process(
      se::doc::DocResult&                    recognition_result,
      const se::doc::DocProcessingSettings&  processing_settings,
      const se::doc::DocProcessingArguments& processing_arguments) override final;

private:
  void recalculateCache();

  id<SEDocExternalProcessor> externalProcessor_;

  bool responds_to_process = false;
};

#endif // OBJCDOCENGINE_IMPL_DOC_PROXY_H_INCLUDED
