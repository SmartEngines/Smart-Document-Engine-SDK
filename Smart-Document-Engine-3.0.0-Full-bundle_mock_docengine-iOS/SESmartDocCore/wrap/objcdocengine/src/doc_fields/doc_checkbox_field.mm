/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_fields_impl.h>

#import <objcsecommon_impl/se_serialization_impl.h>
#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocCheckboxFieldRef {
  se::doc::DocCheckboxField* ptr;
  bool is_mutable;
}

- (instancetype) initFromInternalCheckboxFieldPointer:(se::doc::DocCheckboxField *)fieldptr
                               withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = fieldptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocCheckboxField *) getInternalCheckboxFieldPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (SEDocBaseFieldInfoRef *) getBaseFieldInfo {
  return [[SEDocBaseFieldInfoRef alloc]
      initFromInternalBaseFieldInfoPointer:const_cast<se::doc::DocBaseFieldInfo*>(&ptr->GetBaseFieldInfo())
                        withMutabilityFlag:NO];
}

- (SEDocBaseFieldInfoRef *) getMutableBaseFieldInfo {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    return [[SEDocBaseFieldInfoRef alloc]
        initFromInternalBaseFieldInfoPointer:&ptr->GetMutableBaseFieldInfo()
                          withMutabilityFlag:YES];
  }
  return nil;
}

- (BOOL) getTickStatus {
  return ptr->GetTickStatus()? YES : NO;
}

- (void) setTickStatusTo:(BOOL)tick_status {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    ptr->SetTickStatus(YES == tick_status);
  }
}

- (void) serialize:(SECommonSerializer *)serializer {
  ptr->Serialize([serializer getInternalSerializer]);
}

@end
