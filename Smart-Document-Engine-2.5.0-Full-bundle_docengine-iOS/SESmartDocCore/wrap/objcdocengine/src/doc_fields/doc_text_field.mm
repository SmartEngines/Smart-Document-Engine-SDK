/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_fields_impl.h>

#import <objcsecommon_impl/se_string_impl.h>

#import <objcsecommon_impl/se_serialization_impl.h>
#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocTextFieldRef {
  se::doc::DocTextField* ptr;
  bool is_mutable;
}

- (instancetype) initFromInternalTextFieldPointer:(se::doc::DocTextField *)fieldptr
                               withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = fieldptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocTextField *) getInternalTextFieldPointer {
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

- (SECommonOcrString *) getOcrString {
  return [[SECommonOcrString alloc] initFromInternalOcrString:ptr->GetOcrString()];
}

- (void) setOcrStringTo:(SECommonOcrString *)ocrstring {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    ptr->SetOcrString([ocrstring getInternalOcrString]);
  }
}

- (void) serialize:(SECommonSerializer *)serializer {
  ptr->Serialize([serializer getInternalSerializer]);
}

@end
