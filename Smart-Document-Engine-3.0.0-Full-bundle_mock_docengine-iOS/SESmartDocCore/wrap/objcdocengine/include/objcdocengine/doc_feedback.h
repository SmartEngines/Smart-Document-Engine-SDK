/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_FEEDBACK_H_INCLUDED
#define OBJCDOCENGINE_DOC_FEEDBACK_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_result.h>

@interface SEDocFeedbackContainerRef : NSObject

- (BOOL) isMutable;

@end

@interface SEDocPagesFeedbackConteinerRef : NSObject

- (BOOL) isMutable;

@end

@interface SEDocRawFieldsFeedbackConteinerRef : NSObject

- (BOOL) isMutable;

@end


@protocol SEDocFeedback <NSObject>

@optional

- (void) feedbackReceived:(nonnull SEDocFeedbackContainerRef *)feedback_container;

- (bool) acceptsPagesLocalizationFeedback;

- (bool) acceptsPagePreprocessingFeedback;

- (bool) acceptsRawFieldsLocalizationFeedback;

- (bool) acceptsRawFieldsRecognitionFeedback;

- (void) pagesLocalizationFeedbackReceived:(nonnull SEDocPagesFeedbackConteinerRef *)container;

- (void) pagePrepocessingFeedbackReceived:(nonnull SEDocPagesFeedbackConteinerRef *)container;

- (void) rawFieldsLocalizationFeedbackReceived:(nonnull SEDocRawFieldsFeedbackConteinerRef *)container;

- (void) rawFiedlsRecognitionFeedbackReceived:(nonnull SEDocRawFieldsFeedbackConteinerRef *)container;

- (void) resultReceived:(nonnull SEDocResultRef *)result;

@end

#endif // OBJCDOCENGINE_DOC_FEEDBACK_H_INCLUDED
