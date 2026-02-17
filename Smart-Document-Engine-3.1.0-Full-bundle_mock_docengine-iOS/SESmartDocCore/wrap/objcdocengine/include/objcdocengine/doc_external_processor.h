/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_EXTERNAL_PROCESSOR_H_INCLUDED
#define OBJCDOCENGINE_DOC_EXTERNAL_PROCESSOR_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_forward_declarations.h>

@interface SEDocProcessingArgumentsRef : NSObject

- (BOOL) isMutable;

- (int) getTagArgumentsCount;

- (nonnull NSString *) getTagArgumentAt:(int)index;
- (void) setTagArgumentAt:(int)index
                       to:(nonnull NSString *)argument;

- (void) resizeTo:(int)size;

@end


@protocol SEDocExternalProcessor <NSObject>

@optional

- (void) processWithRecognitionResult:(nonnull SEDocResultRef *)recognition_result
               withProcessingSettings:(nonnull SEDocProcessingSettingsRef *)processing_settings
              withProcessingArguments:(nonnull SEDocProcessingArgumentsRef *)processing_arguments;

@end

#endif // OBJCDOCENGINE_DOC_EXTERNAL_PROCESSOR_H_INCLUDED