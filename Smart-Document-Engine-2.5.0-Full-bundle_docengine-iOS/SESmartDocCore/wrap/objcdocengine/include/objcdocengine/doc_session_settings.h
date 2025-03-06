/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_SESSION_SETTINGS_H_INCLUDED
#define OBJCDOCENGINE_DOC_SESSION_SETTINGS_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_document_info.h>

@interface SEDocSessionSettings : NSObject

- (nonnull instancetype) clone;

- (int) getOptionsCount;
- (BOOL) hasOptionWithName:(nonnull NSString *)option_name;
- (nonnull NSString *) getOptionWithName:(nonnull NSString *)option_name;
- (void) setOptionWithName:(nonnull NSString *)option_name
                        to:(nonnull NSString *)option_value;
- (void) removeOptionWithName:(nonnull NSString *)option_name;
- (nonnull SECommonStringsMapIterator *) optionsBegin;
- (nonnull SECommonStringsMapIterator *) optionsEnd;

- (int) getSupportedModesCount;
- (BOOL) hasSupportedModeWithName:(nonnull NSString *)mode_name;
- (nonnull NSString *) getSupportedModeAt:(int)mode_id;
- (nonnull SECommonStringsVectorIterator *) supportedModesBegin;
- (nonnull SECommonStringsVectorIterator *) supportedModesEnd;

- (nonnull NSString *) getCurrentMode;
- (void) setCurrentModeTo:(nonnull NSString *)mode_name;

- (int) getInternalEnginesCount;
- (int) getSupportedDocumentTypesCountForEngine:(int)engine_id;
- (BOOL) hasSupportedDocumentTypeForEngine:(int)engine_id
                      withDocumentTypeName:(nonnull NSString *)doc_name;
- (nonnull NSString *) getSupportedDocumentTypeForEngine:(int)engine_id
                                      withDocumentTypeID:(int)doc_id;

- (int) getEnabledDocumentTypesCount;
- (BOOL) hasEnabledDocumentTypeWithName:(nonnull NSString *)doc_name;
- (nonnull NSString *) getEnabledDocumentTypeAt:(int)doc_id;

- (void) addEnabledDocumentTypesWithMask:(nonnull NSString *)doc_type_mask;
- (void) removeEnabledDocumentTypesWithMask:(nonnull NSString *)doc_type_mask;

- (nonnull SEDocDocumentInfoRef *) getDocumentInfoForDocument:(nonnull NSString *)doc_name;

- (nonnull SECommonStringsSetIterator *) permissiblePrefixDocMasksBegin;
- (nonnull SECommonStringsSetIterator *) permissiblePrefixDocMasksEnd;

@end

#endif // OBJCDOCENGINE_DOC_SESSION_SETTINGS_H_INCLUDED