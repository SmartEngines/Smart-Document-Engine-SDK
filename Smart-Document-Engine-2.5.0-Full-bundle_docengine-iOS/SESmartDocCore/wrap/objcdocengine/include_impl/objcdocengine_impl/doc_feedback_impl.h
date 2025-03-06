/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_FEEDBACK_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_FEEDBACK_H_INCLUDED

#import <objcdocengine/doc_feedback.h>

#include <docengine/doc_feedback.h>

@interface SEDocFeedbackContainerRef (Internal)

- (instancetype) initFromInternalFeedbackContainerPointer:(se::doc::DocFeedbackContainer *)containerptr
                                       withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocFeedbackContainer *) getInternalFeedbackContainerPointer;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_FEEDBACK_H_INCLUDED