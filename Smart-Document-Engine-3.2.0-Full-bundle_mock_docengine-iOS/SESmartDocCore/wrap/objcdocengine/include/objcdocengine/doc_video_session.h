/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_VIDEO_SESSION_H_INCLUDED
#define OBJCDOCENGINE_DOC_VIDEO_SESSION_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_forward_declarations.h>

@interface SEDocVideoSession : NSObject

- (nonnull NSString *) getActivationRequest;
- (void) activate:(nonnull NSString *)activation_response;

- (BOOL) isActivated;

- (nonnull SEDocProcessingSettings *) createProcessingSettings;

- (void) processImage:(nonnull SECommonImageRef *)image
         withSettings:(nonnull SEDocProcessingSettings *) settings;

- (void) reset;

- (nonnull SEDocResultRef *) getCurrentResult;
- (nonnull SEDocResultRef *) getMutableCurrentResult;

@end

#endif // OBJCDOCENGINE_DOC_VIDEO_SESSION_H_INCLUDED