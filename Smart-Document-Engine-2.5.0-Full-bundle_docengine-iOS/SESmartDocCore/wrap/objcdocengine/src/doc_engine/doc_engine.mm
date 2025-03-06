/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_engine_impl.h>

#import <objcdocengine_impl/doc_session_settings_impl.h>
#import <objcdocengine_impl/doc_session_impl.h>
#import <objcdocengine_impl/doc_video_session_impl.h>
#import <objcdocengine_impl/doc_feedback_impl.h>
#import <objcdocengine_impl/doc_external_processor_impl.h>
#import <objcdocengine_impl/doc_proxy_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocEngine {
  std::unique_ptr<se::doc::DocEngine> internal;
}

+ (NSString *) getVersion {
  return [NSString stringWithUTF8String:se::doc::DocEngine::GetVersion()];
}

- (se::doc::DocEngine &) getInternalEngine {
  return *internal;
}

- (instancetype) initFromFile:(NSString *)filename
                 withLazyInit:(BOOL)lazy_initialization {
  if (self = [super init]) {
    try {
      internal.reset(se::doc::DocEngine::Create(
          [filename UTF8String],
          YES == lazy_initialization));
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
      return nil;
    }
  }
  return self;
}

- (instancetype) initFromBuffer:(unsigned char *)buffer
                 withBufferSize:(int)buffer_size
                   withLazyInit:(BOOL)lazy_initialization {
  if (self = [super init]) {
    try {
      internal.reset(se::doc::DocEngine::Create(
          buffer,
          buffer_size,
          YES == lazy_initialization));
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
      return nil;
    }
  }
  return self;
}

- (instancetype) initEmbeddedWithLazyInit:(BOOL)lazy_initialization {
  if (self = [super init]) {
    try {
      internal.reset(se::doc::DocEngine::CreateFromEmbeddedBundle(
          YES == lazy_initialization));
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
      return nil;
    }
  }
  return self;
}

- (SEDocSessionSettings *) createSessionSettings {
  return [[SEDocSessionSettings alloc]
      initFromCreatedSessionSettings:internal->CreateSessionSettings()];
}

- (SEDocSession *) spawnSessionWithSettings:(SEDocSessionSettings *)settings
                              withSignature:(NSString *)signature
                       withFeedbackReporter:(nullable id<SEDocFeedback>)feedback_reporter
                      withExternalProcessor:(nullable id<SEDocExternalProcessor>)external_processor {
  try {
    std::unique_ptr<ProxyFeedback> proxy_feedback(
        new ProxyFeedback(feedback_reporter));
    std::unique_ptr<ProxyExternalProcessor> proxy_external_processor(
        new ProxyExternalProcessor(external_processor));
    ProxyFeedback* proxy_feedback_ptr = proxy_feedback.get();
    ProxyExternalProcessor* proxy_external_ptr = proxy_external_processor.get();
    return [[SEDocSession alloc]
        initFromCreatedSession:internal->SpawnSession(
            [settings getInternalSessionSettings],
            [signature UTF8String],
            proxy_feedback_ptr,
            proxy_external_ptr)
        withCreatedProxyFeedback:proxy_feedback.release()
        withCreatedProxyExternalProcessor:proxy_external_processor.release()];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SEDocSessionSettings *) createVideoSessionSettings {
  return [[SEDocSessionSettings alloc]
      initFromCreatedSessionSettings:internal->CreateVideoSessionSettings()];
}

- (SEDocVideoSession *) spawnVideoSessionWithSettings:(SEDocSessionSettings *)settings 
                                        withSignature:(NSString *)signature
                                 withFeedbackReporter:(nullable id<SEDocFeedback>)feedback_reporter {
  try {
    std::unique_ptr<ProxyFeedback> proxy_feedback(
        new ProxyFeedback(feedback_reporter));
    ProxyFeedback* proxy_feedback_ptr = proxy_feedback.get();
    return [[SEDocVideoSession alloc]
        initFromCreatedVideoSession:internal->SpawnVideoSession(
            [settings getInternalSessionSettings],
            [signature UTF8String],
            proxy_feedback_ptr)
        withCreatedProxyFeedback:proxy_feedback.release()];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

@end
