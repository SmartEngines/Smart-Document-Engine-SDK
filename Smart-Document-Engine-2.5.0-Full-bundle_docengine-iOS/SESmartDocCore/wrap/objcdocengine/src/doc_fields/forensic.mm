/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_fields_impl.h>

#import <objcsecommon_impl/se_serialization_impl.h>
#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocForensicFieldRef {
  se::doc::DocForensicField* ptr;
  bool is_mutable;
}

- (instancetype) initFromInternalForensicFieldPointer:(se::doc::DocForensicField *)fieldptr
                               withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = fieldptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocForensicField *) getInternalForensicFieldPointer {
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

- (NSString *) getStatus {
  return [NSString stringWithUTF8String:ptr->GetStatus()];
}

- (void) setStatusTo:(NSString *)status {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    ptr->SetStatus([status UTF8String]);
  }
}

- (void) serialize:(SECommonSerializer *)serializer {
  ptr->Serialize([serializer getInternalSerializer]);
}

@end
