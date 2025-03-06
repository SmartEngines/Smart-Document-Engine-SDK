/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_view_impl.h>

#import <objcsecommon_impl/se_image_impl.h>
#import <objcsecommon_impl/se_geometry_impl.h>
#import <objcsecommon_impl/se_serialization_impl.h>
#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocViewRef {
  se::doc::DocView* ptr;
  bool is_mutable;
}

+ (NSString *) baseClassNameStatic {
  return [NSString stringWithUTF8String:se::doc::DocView::BaseClassNameStatic()];
}

- (instancetype) initFromInternalViewPointer:(se::doc::DocView *)viewptr
                          withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = viewptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocView *) getInternalViewPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (SECommonImageRef *) getImage {
  try {
    return [[SECommonImageRef alloc]
        initFromInternalImagePointer:const_cast<se::common::Image*>(&ptr->GetImage())
                  withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SECommonImageRef *) getMutableImage {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SECommonImageRef alloc]
          initFromInternalImagePointer:&ptr->GetMutableImage()
                    withMutabilityFlag:YES];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
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

- (int) getAncestorID {
  return ptr->GetAncestorID();
}

- (void) setAncestorIDTo:(int)anc_id {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->SetAncestorID(anc_id);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (int) getRootAncestorID {
  return ptr->GetRootAncestorID();
}

- (void) setRootAncestorIDTo:(int)root_anc_id {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->SetRootAncestorID(root_anc_id);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (SECommonProjectiveTransform *) getTransform {
  return [[SECommonProjectiveTransform alloc]
      initFromInternalProjectiveTransform:ptr->GetTransform()];
}

- (void) setTransformTo:(SECommonProjectiveTransform *)transform {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->SetTransform([transform getInternalProjectiveTransform]);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (void) serialize:(SECommonSerializer *)serializer {
  ptr->Serialize([serializer getInternalSerializer]);
}

@end
