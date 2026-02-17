/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_feedback_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocFeedbackContainerRef {
  se::doc::DocFeedbackContainer* ptr;
  bool is_mutable;
}

- (instancetype) initFromInternalFeedbackContainerPointer:(se::doc::DocFeedbackContainer *)containerptr
                                       withMutabilityFlag:(BOOL)mutabilityFlag; {
  if (self = [super init]) {
    ptr = containerptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocFeedbackContainer *) getInternalFeedbackContainerPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

@end
