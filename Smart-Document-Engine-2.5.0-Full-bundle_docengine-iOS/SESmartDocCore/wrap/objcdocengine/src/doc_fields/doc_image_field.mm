/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_fields_impl.h>

#import <objcsecommon_impl/se_image_impl.h>

#import <objcsecommon_impl/se_serialization_impl.h>
#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocImageFieldRef {
  se::doc::DocImageField* ptr;
  bool is_mutable;
}

- (instancetype) initFromInternalImageFieldPointer:(se::doc::DocImageField *)fieldptr
                               withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = fieldptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocImageField *) getInternalImageFieldPointer {
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

- (SECommonImageRef *) getImage {
  return [[SECommonImageRef alloc]
      initFromInternalImagePointer:const_cast<se::common::Image*>(&ptr->GetImage())
                withMutabilityFlag:NO];
}

- (SECommonImageRef *) getMutableImage {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    return [[SECommonImageRef alloc]
        initFromInternalImagePointer:&ptr->GetMutableImage()
                  withMutabilityFlag:YES];
  }
  return nil;
}

- (void) setImageTo:(SECommonImageRef *)image {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->SetImage(*[image getInternalImagePointer]);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (void) serialize:(SECommonSerializer *)serializer {
  ptr->Serialize([serializer getInternalSerializer]);
}

@end
