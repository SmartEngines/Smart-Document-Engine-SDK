/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_objects_impl.h>
#import <objcdocengine_impl/doc_basic_object_impl.h>

#import <objcsecommon_impl/se_geometry_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocZoneObjectRef {
  se::doc::DocZoneObject* ptr;
  bool is_mutable;
}

+ (NSString *) objectTypeStatic {
  return [NSString stringWithUTF8String:se::doc::DocZoneObject::ObjectTypeStatic()];
}

- (instancetype) initFromInternalZoneObjectPointer:(se::doc::DocZoneObject *)objptr
                                withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = objptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocZoneObject *) getInternalZoneObjectPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (SECommonSize *) getSize {
  return [[SECommonSize alloc] initFromInternalSize:ptr->GetSize()];
}

- (void) setSizeTo:(SECommonSize *)size {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    ptr->SetSize([size getInternalSize]);
  }
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
