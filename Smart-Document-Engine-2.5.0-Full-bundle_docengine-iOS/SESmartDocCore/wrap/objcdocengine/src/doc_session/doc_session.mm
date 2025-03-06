/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_session_impl.h>

#import <objcdocengine_impl/doc_processing_settings_impl.h>
#import <objcsecommon_impl/se_image_impl.h>
#import <objcdocengine_impl/doc_result_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocSession {
  std::unique_ptr<se::doc::DocSession> internal;
  std::unique_ptr<ProxyFeedback> proxyFeedback;
  std::unique_ptr<ProxyExternalProcessor> proxyExternalProcessor;
}

- (instancetype) initFromCreatedSession:(se::doc::DocSession *)sessionptr
               withCreatedProxyFeedback:(ProxyFeedback *)feedback_reporter
      withCreatedProxyExternalProcessor:(ProxyExternalProcessor *)external_processor {
  if (self = [super init]) {
    internal.reset(sessionptr);
    proxyFeedback.reset(feedback_reporter);
    proxyExternalProcessor.reset(external_processor);
  }
  return self;
}

- (se::doc::DocSession &) getInternalSession {
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

- (int) registerImage:(SECommonImageRef *)image {
  try {
    return internal->RegisterImage(*[image getInternalImagePointer]);
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return -1;
}

- (void) process:(SEDocProcessingSettings *)settings {
  try {
    internal->Process([settings getInternalProcessingSettings]);
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
}

- (void) processImage:(nonnull SECommonImageRef *)image
withProcessingSettings:(nonnull SEDocProcessingSettings *)settings{
  try {
      internal->ProcessImage(*[image getInternalImagePointer], [[settings getRef] getInternalProcessingSettingsPointer]);
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
