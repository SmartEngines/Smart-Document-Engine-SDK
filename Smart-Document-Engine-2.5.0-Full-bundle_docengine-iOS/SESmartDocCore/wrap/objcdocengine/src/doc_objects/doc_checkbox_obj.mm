/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_objects_impl.h>

#import <objcsecommon_impl/se_string_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocCheckboxObjectRef {
  se::doc::DocCheckboxObject* ptr;
  bool is_mutable;
}

+ (NSString *) objectTypeStatic {
  return [NSString stringWithUTF8String:se::doc::DocCheckboxObject::ObjectTypeStatic()];
}

- (instancetype) initFromInternalCheckboxObjectPointer:(se::doc::DocCheckboxObject *)objptr
                                    withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = objptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocCheckboxObject *) getInternalCheckboxObjectPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
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

@end
