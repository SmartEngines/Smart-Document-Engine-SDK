/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_objects_impl.h>
#import <objcdocengine_impl/doc_basic_object_impl.h>

#import <objcsecommon_impl/se_string_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocTextObjectRef {
  se::doc::DocTextObject* ptr;
  bool is_mutable;
}

+ (NSString *) objectTypeStatic {
  return [NSString stringWithUTF8String:se::doc::DocTextObject::ObjectTypeStatic()];
}

- (instancetype) initFromInternalTextObjectPointer:(se::doc::DocTextObject *)objptr
                                withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = objptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocTextObject *) getInternalTextObjectPointer {
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

- (int) getTextLineObjectsCount {
  return ptr->GetTextLineObjectsCount();
}

- (nonnull SEDocTextLineObjectRef *)getTextLineObjectAt:(int)index {
  try {
    return [[SEDocTextLineObjectRef alloc]
            initFromInternalTextLineObjectPointer:const_cast<se::doc::DocTextLineObject*>(&ptr->GetTextLineObject(index))
            withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (nonnull SEDocBaseObjectInfoRef *)getBaseObjectInfo {
  try {
    return [[SEDocBaseObjectInfoRef alloc]
            initFromInternalBaseObjectInfoPointer:const_cast<se::doc::DocBaseObjectInfo*>(&ptr->GetBaseObjectInfo())
            withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

@end
