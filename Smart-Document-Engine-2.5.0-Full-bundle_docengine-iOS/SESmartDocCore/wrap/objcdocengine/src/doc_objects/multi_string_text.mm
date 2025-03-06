/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_objects_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocMultiStringTextObjectRef {
  se::doc::DocMultiStringTextObject* ptr;
  bool is_mutable;
}

+ (NSString *) objectTypeStatic {
  return [NSString stringWithUTF8String:se::doc::DocMultiStringTextObject::ObjectTypeStatic()];
}

- (instancetype) initFromInternalMultiStringTextObjectPointer:(se::doc::DocMultiStringTextObject *)objptr
                                           withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = objptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocMultiStringTextObject *) getInternalMultiStringTextObjectPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (int) getStringsCount {
  return ptr->GetStringsCount();
}

- (void) setStringsCountTo:(int)count {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->SetStringsCount(count);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (SEDocTextObjectRef *) getStringObjectAt:(int)index {
  try {
    return [[SEDocTextObjectRef alloc]
        initFromInternalTextObjectPointer:const_cast<se::doc::DocTextObject*>(&ptr->GetStringObject(index))
                       withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SEDocTextObjectRef *) getMutableStringObjectAt:(int)index {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocTextObjectRef alloc]
          initFromInternalTextObjectPointer:&ptr->GetMutableStringObject(index)
                         withMutabilityFlag:YES];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

@end
