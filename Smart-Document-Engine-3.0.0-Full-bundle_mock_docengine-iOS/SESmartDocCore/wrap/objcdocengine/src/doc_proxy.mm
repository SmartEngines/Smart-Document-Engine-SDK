/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_proxy_impl.h>

ProxyFeedback::ProxyFeedback(id<SEDocFeedback> feedback_reporter) {
  feedbackReporter_ = feedback_reporter;
  recalculateCache();
}

void ProxyFeedback::setReporter(id<SEDocFeedback> feedback_reporter) {
  feedbackReporter_ = feedback_reporter;
  recalculateCache();
}

void ProxyFeedback::recalculateCache() {
  responds_to_feedback_received =
      [feedbackReporter_ respondsToSelector:@selector(feedbackReceived:)];
}

void ProxyFeedback::FeedbackReceived(
    const se::doc::DocFeedbackContainer& container) {
  if (feedbackReporter_ && responds_to_feedback_received) {
    [feedbackReporter_ feedbackReceived:[[SEDocFeedbackContainerRef alloc]
        initFromInternalFeedbackContainerPointer:const_cast<se::doc::DocFeedbackContainer*>(&container)
                              withMutabilityFlag:NO]];
  }
}

void ProxyFeedback::ResultReceived(const se::doc::DocResult &result_received) {
    
}

bool ProxyFeedback::AcceptsPagePreprocessingFeedback() {
    return true;
}

bool ProxyFeedback::AcceptsPagesLocalizationFeedback() {
    return true;
}

bool ProxyFeedback::AcceptsRawFieldsRecognitionFeedback() {
    return true;
}

bool ProxyFeedback::AcceptsRawFieldsLocalizationFeedback() {
    return true;
}

void ProxyFeedback::PagePrepocessingFeedbackReceived(const se::doc::DocPagesFeedbackContainer &container) const {
    
}

void ProxyFeedback::PagesLocalizationFeedbackReceived(const se::doc::DocPagesFeedbackContainer &container) const {
    
}

void ProxyFeedback::RawFiedlsRecognitionFeedbackReceived(const se::doc::DocRawFieldsFeedbackContainer &container) const {
    
}

void ProxyFeedback::RawFieldsLocalizationFeedbackReceived(const se::doc::DocRawFieldsFeedbackContainer &container) const {
    
}
///

ProxyExternalProcessor::ProxyExternalProcessor(id<SEDocExternalProcessor> external_processor) {
  externalProcessor_ = external_processor;
  recalculateCache();
}

void ProxyExternalProcessor::setExternalProcessor(id<SEDocExternalProcessor> external_processor) {
  externalProcessor_ = external_processor;
  recalculateCache();
}

void ProxyExternalProcessor::recalculateCache() {
  responds_to_process =
      [externalProcessor_ respondsToSelector:@selector(processWithRecognitionResult:withProcessingSettings:withProcessingArguments:)];
}

void ProxyExternalProcessor::Process(
    se::doc::DocResult&                    recognition_result,
    const se::doc::DocProcessingSettings&  processing_settings,
    const se::doc::DocProcessingArguments& processing_arguments) {
  if (externalProcessor_ && responds_to_process) {
    [externalProcessor_ processWithRecognitionResult:[[SEDocResultRef alloc]
        initFromInternalResultPointer:&recognition_result
                   withMutabilityFlag:YES]
                              withProcessingSettings:[[SEDocProcessingSettingsRef alloc]
        initFromInternalProcessingSettingsPointer:const_cast<se::doc::DocProcessingSettings*>(&processing_settings)
                               withMutabilityFlag:NO]
                             withProcessingArguments:[[SEDocProcessingArgumentsRef alloc]
        initFromInternalProcessingArgumentsPointer:const_cast<se::doc::DocProcessingArguments*>(&processing_arguments)
                                withMutabilityFlag:NO]];
  }
}
