/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_PROCESSING_SETTINGS_H_INCLUDED
#define OBJCDOCENGINE_DOC_PROCESSING_SETTINGS_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_forward_declarations.h>

@interface SEDocProcessingSettingsRef : NSObject

- (BOOL) isMutable;

- (int) getCurrentSourceID;
- (void) setCurrentSourceIDTo:(int)source_id;

- (int) getOptionsCount;
- (BOOL) hasOptionWithName:(nonnull NSString *)option_name;
- (nonnull NSString *) getOptionWithName:(nonnull NSString *)option_name;
- (void) setOptionWithName:(nonnull NSString *)option_name
                        to:(nonnull NSString *)option_value;
- (void) removeOptionWithName:(nonnull NSString *)option_name;
- (nonnull SECommonStringsMapIterator *) optionsBegin;
- (nonnull SECommonStringsMapIterator *) optionsEnd;

- (int) getAvailableRoutinesCount;
- (BOOL) hasAvailableRoutineWithName:(nonnull NSString *)routine_name;
- (nonnull SECommonStringsMapIterator *) availableRoutinesBegin;
- (nonnull SECommonStringsMapIterator *) availableRoutinesEnd;

- (int) routinesQueueSize;
- (nonnull NSString *) routinesQueueFront;
- (void) routinesQueuePush:(nonnull NSString *)routine_name;
- (void) routinesQueuePop;
- (void) routinesQueueClear;

- (int) getSessionOptionsCount;
- (BOOL) hasSessionOptionWithName:(nonnull NSString *)option_name;
- (nonnull NSString *) getSessionOptionWithName:(nonnull NSString *)option_name;
- (nonnull SECommonStringsMapIterator *) sessionOptionsBegin;
- (nonnull SECommonStringsMapIterator *) sessionOptionsEnd;

- (int) getEnabledDocumentTypesCount;
- (BOOL) hasEnabledDocumentTypeWithName:(nonnull NSString *)doc_name;
- (nonnull NSString *) getEnabledDocumentTypeAt:(int)doc_id;

@end


@interface SEDocProcessingSettings : NSObject

- (nonnull SEDocProcessingSettingsRef *) getRef;
- (nonnull SEDocProcessingSettingsRef *) getMutableRef;

@end

#endif // OBJCDOCENGINE_DOC_PROCESSING_SETTINGS_H_INCLUDED