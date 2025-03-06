/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_basic_object_impl.h>

#import <objcdocengine_impl/doc_objects_impl.h>
#import <objcdocengine_impl/doc_objects_collection_impl.h>

#import <objcsecommon_impl/se_serialization_impl.h>
#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocBasicObjectRef {
  se::doc::DocBasicObject* ptr;
  bool is_mutable;
}

+ (NSString *) baseClassNameStatic {
  return [NSString stringWithUTF8String:se::doc::DocBasicObject::BaseClassNameStatic()];
}

- (instancetype) initFromInternalBasicObjectPointer:(se::doc::DocBasicObject *)objptr
                                 withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = objptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocBasicObject *) getInternalBasicObjectPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (NSString *) objectType {
  return [NSString stringWithUTF8String:ptr->ObjectType()];
}

- (SEDocBaseObjectInfoRef *) getBaseObjectInfo {
  return [[SEDocBaseObjectInfoRef alloc] 
      initFromInternalBaseObjectInfoPointer:const_cast<se::doc::DocBaseObjectInfo*>(&ptr->GetBaseObjectInfo())
                         withMutabilityFlag:NO];
}

- (SEDocBaseObjectInfoRef *) getMutableBaseObjectInfo {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    return [[SEDocBaseObjectInfoRef alloc]
        initFromInternalBaseObjectInfoPointer:&ptr->GetMutableBaseObjectInfo()
                           withMutabilityFlag:YES];
  }
  return nil;
}

- (SEDocTextObjectRef *) getTextObjectRef {
  se::doc::DocTextObject* casted = dynamic_cast<se::doc::DocTextObject*>(ptr);
  if (!casted) {
    NSException* exc = [NSException
        exceptionWithName:@"InvalidCast"
        reason:@"Cannot cast basic object to Text object"
        userInfo:nil];
    @throw exc;
    return nil;
  } else {
    return [[SEDocTextObjectRef alloc]
        initFromInternalTextObjectPointer:casted
                       withMutabilityFlag:(is_mutable? YES : NO)];
  }
}

- (SEDocCheckboxObjectRef *) getCheckboxObjectRef {
  se::doc::DocCheckboxObject* casted = dynamic_cast<se::doc::DocCheckboxObject*>(ptr);
  if (!casted) {
    NSException* exc = [NSException
        exceptionWithName:@"InvalidCast"
        reason:@"Cannot cast basic object to Checkbox object"
        userInfo:nil];
    @throw exc;
    return nil;
  } else {
    return [[SEDocCheckboxObjectRef alloc]
        initFromInternalCheckboxObjectPointer:casted
                       withMutabilityFlag:(is_mutable? YES : NO)];
  }
}

- (SEDocTemplateObjectRef *) getTemplateObjectRef {
  se::doc::DocTemplateObject* casted = dynamic_cast<se::doc::DocTemplateObject*>(ptr);
  if (!casted) {
    NSException* exc = [NSException
        exceptionWithName:@"InvalidCast"
        reason:@"Cannot cast basic object to Template object"
        userInfo:nil];
    @throw exc;
    return nil;
  } else {
    return [[SEDocTemplateObjectRef alloc]
        initFromInternalTemplateObjectPointer:casted
                       withMutabilityFlag:(is_mutable? YES : NO)];
  }
}

- (SEDocLineObjectRef *) getLineObjectRef {
  se::doc::DocLineObject* casted = dynamic_cast<se::doc::DocLineObject*>(ptr);
  if (!casted) {
    NSException* exc = [NSException
        exceptionWithName:@"InvalidCast"
        reason:@"Cannot cast basic object to Line object"
        userInfo:nil];
    @throw exc;
    return nil;
  } else {
    return [[SEDocLineObjectRef alloc]
        initFromInternalLineObjectPointer:casted
                       withMutabilityFlag:(is_mutable? YES : NO)];
  }
}

- (SEDocZoneObjectRef *) getZoneObjectRef {
  se::doc::DocZoneObject* casted = dynamic_cast<se::doc::DocZoneObject*>(ptr);
  if (!casted) {
    NSException* exc = [NSException
        exceptionWithName:@"InvalidCast"
        reason:@"Cannot cast basic object to Zone object"
        userInfo:nil];
    @throw exc;
    return nil;
  } else {
    return [[SEDocZoneObjectRef alloc]
        initFromInternalZoneObjectPointer:casted
                       withMutabilityFlag:(is_mutable? YES : NO)];
  }
}

- (SEDocMultiStringTextObjectRef *) getMultiStringTextObjectRef {
  se::doc::DocMultiStringTextObject* casted = dynamic_cast<se::doc::DocMultiStringTextObject*>(ptr);
  if (!casted) {
    NSException* exc = [NSException
        exceptionWithName:@"InvalidCast"
        reason:@"Cannot cast basic object to MultiStringText object"
        userInfo:nil];
    @throw exc;
    return nil;
  } else {
    return [[SEDocMultiStringTextObjectRef alloc]
        initFromInternalMultiStringTextObjectPointer:casted
                       withMutabilityFlag:(is_mutable? YES : NO)];
  }
}

- (SEDocMetaObjectRef *) getMetaObjectRef {
  se::doc::DocMetaObject* casted = dynamic_cast<se::doc::DocMetaObject*>(ptr);
  if (!casted) {
    NSException* exc = [NSException
        exceptionWithName:@"InvalidCast"
        reason:@"Cannot cast basic object to Meta object"
        userInfo:nil];
    @throw exc;
    return nil;
  } else {
    return [[SEDocMetaObjectRef alloc]
        initFromInternalMetaObjectPointer:casted
                       withMutabilityFlag:(is_mutable? YES : NO)];
  }
}

- (SEDocTableObjectRef *) getTableObjectRef {
  se::doc::DocTableObject* casted = dynamic_cast<se::doc::DocTableObject*>(ptr);
  if (!casted) {
    NSException* exc = [NSException
        exceptionWithName:@"InvalidCast"
        reason:@"Cannot cast basic object to Table object"
        userInfo:nil];
    @throw exc;
    return nil;
  } else {
    return [[SEDocTableObjectRef alloc]
        initFromInternalTableObjectPointer:casted
                       withMutabilityFlag:(is_mutable? YES : NO)];
  }
}

- (SEDocImageObjectRef *) getImageObjectRef {
  se::doc::DocImageObject* casted = dynamic_cast<se::doc::DocImageObject*>(ptr);
  if (!casted) {
    NSException* exc = [NSException
        exceptionWithName:@"InvalidCast"
        reason:@"Cannot cast basic object to Image object"
        userInfo:nil];
    @throw exc;
    return nil;
  } else {
    return [[SEDocImageObjectRef alloc]
        initFromInternalImageObjectPointer:casted
                       withMutabilityFlag:(is_mutable? YES : NO)];
  }
}

- (SEDocBarcodeObjectRef *) getBarcodeObjectRef {
  se::doc::DocBarcodeObject* casted = dynamic_cast<se::doc::DocBarcodeObject*>(ptr);
  if (!casted) {
    NSException* exc = [NSException
        exceptionWithName:@"InvalidCast"
        reason:@"Cannot cast basic object to Barcode object"
        userInfo:nil];
    @throw exc;
    return nil;
  } else {
    return [[SEDocBarcodeObjectRef alloc]
        initFromInternalBarcodeObjectPointer:casted
                       withMutabilityFlag:(is_mutable? YES : NO)];
  }
}

- (void) serialize:(SECommonSerializer *)serializer {
  ptr->Serialize([serializer getInternalSerializer]);
}

@end

@implementation SEDocBasicObject {
  std::unique_ptr<se::doc::DocBasicObject> internal;
}

+ (NSString *) baseClassNameStatic {
  return [NSString stringWithUTF8String:se::doc::DocBasicObject::BaseClassNameStatic()];
}

- (instancetype) initFromCreatedBasicObject:(se::doc::DocBasicObject *)objptr {
  if (self = [super init]) {
    internal.reset(objptr);
  }
  return self;
}

- (se::doc::DocBasicObject &) getInternalBasicObject {
  return *internal;
}

- (instancetype) initForCollection:(SEDocObjectsCollectionRef *)collection {
  if (self = [super init]) {
    internal.reset([collection getInternalObjectsCollectionPointer]->CreateObject());
  }
  return self;
}

- (SEDocBasicObjectRef *) getRef {
  return [[SEDocBasicObjectRef alloc]
      initFromInternalBasicObjectPointer:internal.get()
                      withMutabilityFlag:NO];
}

- (SEDocBasicObjectRef *) getMutableRef {
  return [[SEDocBasicObjectRef alloc]
      initFromInternalBasicObjectPointer:internal.get()
                      withMutabilityFlag:YES];
}

@end
