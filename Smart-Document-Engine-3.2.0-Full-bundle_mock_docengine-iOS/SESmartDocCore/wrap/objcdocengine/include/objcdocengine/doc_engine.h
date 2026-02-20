/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_ENGINE_H_INCLUDED
#define OBJCDOCENGINE_DOC_ENGINE_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_forward_declarations.h>

#import <objcdocengine/doc_feedback.h>
#import <objcdocengine/doc_external_processor.h>

@interface SEDocEngine : NSObject

+ (nonnull NSString *) getVersion;

- (nonnull instancetype) initFromFile:(nonnull NSString *)filename
                         withLazyInit:(BOOL)lazy_initialization;

- (nonnull instancetype) initFromFile:(nonnull NSString *)filename
                         withLazyInit:(BOOL)lazy_initialization
                                error:(NSError * _Nullable * _Nullable)error;

- (nonnull instancetype) initFromBuffer:(nonnull unsigned char *)buffer
                         withBufferSize:(int)buffer_size
                           withLazyInit:(BOOL)lazy_initialization;

- (nonnull instancetype) initEmbeddedWithLazyInit:(BOOL)lazy_initialization;

- (nonnull instancetype) initEmbeddedWithLazyInit:(BOOL)lazy_initialization
                                            error:(NSError * _Nullable * _Nullable)error;

- (nonnull SEDocSessionSettings *) createSessionSettings;
- (nonnull SEDocSession *) spawnSessionWithSettings:(nonnull SEDocSessionSettings *)settings
                                      withSignature:(nonnull NSString *)signature
                               withFeedbackReporter:(nullable id<SEDocFeedback>)feedback_reporter
                              withExternalProcessor:(nullable id<SEDocExternalProcessor>)external_processor;

- (nonnull SEDocSessionSettings *) createVideoSessionSettings;
- (nonnull SEDocVideoSession *) spawnVideoSessionWithSettings:(nonnull SEDocSessionSettings *)settings
                                                withSignature:(nonnull NSString *)signature
                                         withFeedbackReporter:(nullable id<SEDocFeedback>)feedback_reporter;

@end

#endif // OBJCDOCENGINE_DOC_ENGINE_H_INCLUDED
