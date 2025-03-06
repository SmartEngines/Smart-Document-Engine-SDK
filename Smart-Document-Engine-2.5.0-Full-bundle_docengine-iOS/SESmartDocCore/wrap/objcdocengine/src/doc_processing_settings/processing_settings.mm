/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_processing_settings_impl.h>

#import <objcsecommon_impl/se_strings_iterator_impl.h>
#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocProcessingSettingsRef {
  se::doc::DocProcessingSettings* ptr;
  bool is_mutable;
}

- (instancetype) initFromInternalProcessingSettingsPointer:(se::doc::DocProcessingSettings *)settingsptr
                                        withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = settingsptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocProcessingSettings *) getInternalProcessingSettingsPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (int) getCurrentSourceID {
  return ptr->GetCurrentSourceID();
}

- (void) setCurrentSourceIDTo:(int)source_id {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->SetCurrentSourceID(source_id);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (int) getOptionsCount {
  return ptr->GetOptionsCount();
}

- (BOOL) hasOptionWithName:(NSString *)option_name {
  return ptr->HasOption([option_name UTF8String])? YES : NO;
}

- (NSString *) getOptionWithName:(NSString *)option_name {
  try {
    return [NSString stringWithUTF8String:ptr->GetOption([option_name UTF8String])];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (void) setOptionWithName:(NSString *)option_name
                        to:(NSString *)option_value {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->SetOption([option_name UTF8String], [option_value UTF8String]);      
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (void) removeOptionWithName:(NSString *)option_name {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->RemoveOption([option_name UTF8String]);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (SECommonStringsMapIterator *) optionsBegin {
  return [[SECommonStringsMapIterator alloc]
      initFromInternalStringsMapIterator:ptr->OptionsBegin()];
}

- (SECommonStringsMapIterator *) optionsEnd {
  return [[SECommonStringsMapIterator alloc]
      initFromInternalStringsMapIterator:ptr->OptionsEnd()];
}

- (int) getAvailableRoutinesCount {
  return ptr->GetAvailableRoutinesCount();
}

- (BOOL) hasAvailableRoutineWithName:(NSString *)routine_name {
  return ptr->HasAvailableRoutine([routine_name UTF8String])? YES : NO;
}

- (SECommonStringsMapIterator *) availableRoutinesBegin {
  return [[SECommonStringsMapIterator alloc]
      initFromInternalStringsMapIterator:ptr->AvailableRoutinesBegin()];
}

- (SECommonStringsMapIterator *) availableRoutinesEnd {
  return [[SECommonStringsMapIterator alloc]
      initFromInternalStringsMapIterator:ptr->AvailableRoutinesEnd()];
}

- (int) routinesQueueSize {
  return ptr->RoutinesQueueSize();
}

- (NSString *) routinesQueueFront {
  try {
    return [NSString stringWithUTF8String:ptr->RoutinesQueueFront()];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (void) routinesQueuePush:(NSString *)routine_name {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->RoutinesQueuePush([routine_name UTF8String]);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (void) routinesQueuePop {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->RoutinesQueuePop();
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (void) routinesQueueClear {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->RoutinesQueueClear();
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (int) getSessionOptionsCount {
  return ptr->GetSessionOptionsCount();
}

- (BOOL) hasSessionOptionWithName:(NSString *)option_name {
  return ptr->HasSessionOption([option_name UTF8String])? YES : NO;
}

- (NSString *) getSessionOptionWithName:(NSString *)option_name {
  try {
    return [NSString stringWithUTF8String:ptr->GetSessionOption([option_name UTF8String])];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SECommonStringsMapIterator *) sessionOptionsBegin {
  return [[SECommonStringsMapIterator alloc]
      initFromInternalStringsMapIterator:ptr->SessionOptionsBegin()];
}

- (SECommonStringsMapIterator *) sessionOptionsEnd {
  return [[SECommonStringsMapIterator alloc]
      initFromInternalStringsMapIterator:ptr->SessionOptionsEnd()];
}

- (int) getEnabledDocumentTypesCount {
  return ptr->GetEnabledDocumentTypesCount();
}

- (BOOL) hasEnabledDocumentTypeWithName:(NSString *)doc_name {
  return ptr->HasEnabledDocumentType([doc_name UTF8String])? YES : NO;
}

- (NSString *) getEnabledDocumentTypeAt:(int)doc_id {
  try {
    return [NSString stringWithUTF8String:ptr->GetEnabledDocumentType(doc_id)];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

@end


@implementation SEDocProcessingSettings {
  std::unique_ptr<se::doc::DocProcessingSettings> internal;
}

- (instancetype) initFromCreatedProcessingSettings:(se::doc::DocProcessingSettings *)settingsptr {
  if (self = [super init]) {
    internal.reset(settingsptr);
  }
  return self;
}

- (se::doc::DocProcessingSettings &) getInternalProcessingSettings {
  return *internal;
}

- (SEDocProcessingSettingsRef *) getRef {
  return [[SEDocProcessingSettingsRef alloc]
      initFromInternalProcessingSettingsPointer:internal.get()
                             withMutabilityFlag:NO];
}

- (SEDocProcessingSettingsRef *) getMutableRef {
  return [[SEDocProcessingSettingsRef alloc]
      initFromInternalProcessingSettingsPointer:internal.get()
                             withMutabilityFlag:YES];
}

@end
