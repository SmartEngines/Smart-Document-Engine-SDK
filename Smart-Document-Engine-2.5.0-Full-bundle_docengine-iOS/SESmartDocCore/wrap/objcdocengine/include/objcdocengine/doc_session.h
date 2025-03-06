/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_SESSION_H_INCLUDED
#define OBJCDOCENGINE_DOC_SESSION_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_forward_declarations.h>

@interface SEDocSession : NSObject

- (nonnull NSString *) getActivationRequest;
- (void) activate:(nonnull NSString *)activation_response;

- (BOOL) isActivated;

- (nonnull SEDocProcessingSettings *) createProcessingSettings;

- (int) registerImage:(nonnull SECommonImageRef *)image;

- (void) process:(nonnull SEDocProcessingSettings *)settings;

- (void) processImage:(nonnull SECommonImageRef *)image
withProcessingSettings:(nonnull SEDocProcessingSettings *)settings;

- (void) reset;

- (nonnull SEDocResultRef *) getCurrentResult;
- (nonnull SEDocResultRef *) getMutableCurrentResult;

@end

#endif // OBJCDOCENGINE_DOC_SESSION_H_INCLUDED