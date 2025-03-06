/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_objects_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocBarcodeObjectRef {
  se::doc::DocBarcodeObject* ptr;
  bool is_mutable;
}

+ (NSString *) objectTypeStatic {
  return [NSString stringWithUTF8String:se::doc::DocBarcodeObject::ObjectTypeStatic()];
}

- (instancetype) initFromInternalBarcodeObjectPointer:(se::doc::DocBarcodeObject *)objptr
                                 withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = objptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocBarcodeObject *) getInternalBarcodeObjectPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (NSString *) getDecodedString {
  try {
    return [NSString stringWithUTF8String:ptr->GetDecodedString().GetCStr()];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (NSString *) getMutableDecodedString {
  try {
    return [NSString stringWithUTF8String:ptr->GetMutableDecodedString().GetCStr()];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (void) setDecodedString:(NSString *)decstring {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    ptr->SetDecodedString(se::common::MutableString([decstring UTF8String]));
  }
}

@end
