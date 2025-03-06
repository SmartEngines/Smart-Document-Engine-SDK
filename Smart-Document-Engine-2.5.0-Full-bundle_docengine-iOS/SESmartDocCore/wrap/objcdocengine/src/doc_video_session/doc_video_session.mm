/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_video_session_impl.h>

#import <objcdocengine_impl/doc_processing_settings_impl.h>
#import <objcdocengine_impl/doc_result_impl.h>

#import <objcsecommon_impl/se_image_impl.h>
#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocVideoSession {
  std::unique_ptr<se::doc::DocVideoSession> internal;
  std::unique_ptr<ProxyFeedback> proxyFeedback;
}

- (instancetype) initFromCreatedVideoSession:(se::doc::DocVideoSession *)sessionptr
                    withCreatedProxyFeedback:(ProxyFeedback *)feedback_reporter {
  if (self = [super init]) {
    internal.reset(sessionptr);
    proxyFeedback.reset(feedback_reporter);
  }
  return self;
}

- (se::doc::DocVideoSession &) getInternalVideoSession {
  return *internal;
}

- (NSString *) getActivationRequest {
  try {
    return [NSString stringWithUTF8String:internal->GetActivationRequest()];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (void) activate:(NSString *)activation_response {
  try {
    internal->Activate([activation_response UTF8String]);
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
}

- (BOOL) isActivated {
  try {
    return internal->IsActivated()? YES : NO;
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return false;
}

- (SEDocProcessingSettings *) createProcessingSettings {
  return [[SEDocProcessingSettings alloc]
      initFromCreatedProcessingSettings:internal->CreateProcessingSettings()];
}

- (void) processImage:(SECommonImageRef *)image
         withSettings:(SEDocProcessingSettings *) settings {
  try {
    internal->ProcessImage(
        *[image getInternalImagePointer],
        [settings getInternalProcessingSettings]);
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
}

- (void) reset {
  internal->Reset();
}

- (SEDocResultRef *) getCurrentResult {
  return [[SEDocResultRef alloc]
      initFromInternalResultPointer:const_cast<se::doc::DocResult*>(&internal->GetCurrentResult())
                 withMutabilityFlag:NO];
}

- (SEDocResultRef *) getMutableCurrentResult {
  return [[SEDocResultRef alloc]
      initFromInternalResultPointer:&internal->GetMutableCurrentResult()
                 withMutabilityFlag:YES];
}

@end
