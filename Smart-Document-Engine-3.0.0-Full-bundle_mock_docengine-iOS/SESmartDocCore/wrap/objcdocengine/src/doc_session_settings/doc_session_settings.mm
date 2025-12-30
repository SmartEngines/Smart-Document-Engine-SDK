/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_session_settings_impl.h>

#import <objcsecommon_impl/se_strings_iterator_impl.h>
#import <objcsecommon_impl/se_common_proxy_impl.h>
#import <objcdocengine_impl/doc_document_info_impl.h>

#include <memory>

@implementation SEDocSessionSettings {
  std::unique_ptr<se::doc::DocSessionSettings> internal;
}

- (instancetype) initFromCreatedSessionSettings:(se::doc::DocSessionSettings *)settingsptr {
  if (self = [super init]) {
    internal.reset(settingsptr);
  }
  return self;
}

- (const se::doc::DocSessionSettings &) getInternalSessionSettings {
  return *internal;
}

- (instancetype) clone {
  return [[SEDocSessionSettings alloc]
      initFromCreatedSessionSettings:internal->Clone()];
}

- (int) getOptionsCount {
  return internal->GetOptionsCount();
}

- (BOOL) hasOptionWithName:(NSString *)option_name {
  return internal->HasOption([option_name UTF8String])? YES : NO;
}

- (NSString *) getOptionWithName:(NSString *)option_name {
  try {
    return [NSString stringWithUTF8String:internal->GetOption([option_name UTF8String])];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (void) setOptionWithName:(NSString *)option_name
                        to:(NSString *)option_value {
  try {
    internal->SetOption([option_name UTF8String], [option_value UTF8String]);
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
}

- (void) removeOptionWithName:(NSString *)option_name {
  try {
    internal->RemoveOption([option_name UTF8String]);
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
}

- (SECommonStringsMapIterator *) optionsBegin {
  return [[SECommonStringsMapIterator alloc]
      initFromInternalStringsMapIterator:internal->OptionsBegin()];
}

- (SECommonStringsMapIterator *) optionsEnd {
  return [[SECommonStringsMapIterator alloc]
      initFromInternalStringsMapIterator:internal->OptionsEnd()];
}

- (int) getSupportedModesCount {
  return internal->GetSupportedModesCount();
}

- (BOOL) hasSupportedModeWithName:(NSString *)mode_name {
  return internal->HasSupportedMode([mode_name UTF8String])? YES : NO;
}

- (NSString *) getSupportedModeAt:(int)mode_id {
  try {
    return [NSString stringWithUTF8String:internal->GetSupportedMode(mode_id)];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SECommonStringsVectorIterator *) supportedModesBegin {
  return [[SECommonStringsVectorIterator alloc]
      initFromInternalStringsVectorIterator:internal->SupportedModesBegin()];
}

- (SECommonStringsVectorIterator *) supportedModesEnd {
  return [[SECommonStringsVectorIterator alloc]
      initFromInternalStringsVectorIterator:internal->SupportedModesEnd()];
}

- (NSString *) getCurrentMode {
  return [NSString stringWithUTF8String:internal->GetCurrentMode()];
}

- (void) setCurrentModeTo:(NSString *)mode_name {
  try {
    internal->SetCurrentMode([mode_name UTF8String]);
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
}

- (int) getInternalEnginesCount {
  return internal->GetInternalEnginesCount();
}

- (int) getSupportedDocumentTypesCountForEngine:(int)engine_id {
  try {
    return internal->GetSupportedDocumentTypesCount(engine_id);
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return -1;
}

- (BOOL) hasSupportedDocumentTypeForEngine:(int)engine_id
                      withDocumentTypeName:(NSString *)doc_name {
  try {
    return internal->HasSupportedDocumentType(engine_id, [doc_name UTF8String])? YES : NO;
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return NO;
}

- (NSString *) getSupportedDocumentTypeForEngine:(int)engine_id
                              withDocumentTypeID:(int)doc_id {
  try {
    return [NSString stringWithUTF8String:internal->GetSupportedDocumentType(engine_id, doc_id)];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (int) getEnabledDocumentTypesCount {
  return internal->GetEnabledDocumentTypesCount();
}

- (BOOL) hasEnabledDocumentTypeWithName:(NSString *)doc_name {
  return internal->HasEnabledDocumentType([doc_name UTF8String])? YES : NO;
}

- (NSString *) getEnabledDocumentTypeAt:(int)doc_id {
  try {
    return [NSString stringWithUTF8String:internal->GetEnabledDocumentType(doc_id)];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (void) addEnabledDocumentTypesWithMask:(NSString *)doc_type_mask {
  try {
    internal->AddEnabledDocumentTypes([doc_type_mask UTF8String]);
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
}

- (void) removeEnabledDocumentTypesWithMask:(NSString *)doc_type_mask {
  try {
    internal->RemoveEnabledDocumentTypes([doc_type_mask UTF8String]);
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }  
}

- (SEDocDocumentInfoRef *) getDocumentInfoForDocument:(NSString *)doc_name {
  try {
    return [[SEDocDocumentInfoRef alloc]
        initFromInternalDocumentInfoPointer:const_cast<se::doc::DocDocumentInfo*>(&internal->GetDocumentInfo([doc_name UTF8String]))
                         withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SECommonStringsSetIterator *) permissiblePrefixDocMasksBegin {
  try {
    return [[SECommonStringsSetIterator alloc]
        initFromInternalStringsSetIterator:internal->PermissiblePrefixDocMasksBegin()];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;  
}

- (SECommonStringsSetIterator *) permissiblePrefixDocMasksEnd {
  try {
    return [[SECommonStringsSetIterator alloc]
        initFromInternalStringsSetIterator:internal->PermissiblePrefixDocMasksEnd()];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;  
}

@end
