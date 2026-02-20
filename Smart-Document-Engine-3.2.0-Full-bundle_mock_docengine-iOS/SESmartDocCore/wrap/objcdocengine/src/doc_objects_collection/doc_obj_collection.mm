/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_objects_collection_impl.h>

#import <objcdocengine_impl/doc_basic_object_impl.h>
#import <objcdocengine_impl/doc_tags_collection_impl.h>
#import <objcdocengine_impl/doc_basic_objects_iterator_impl.h>
#import <objcdocengine_impl/doc_views_collection_impl.h>

#import <objcsecommon_impl/se_serialization_impl.h>
#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocObjectsCollectionRef {
  se::doc::DocObjectsCollection* ptr;
  bool is_mutable;
}

+ (NSString *) baseClassNameStatic {
  return [NSString stringWithUTF8String:se::doc::DocObjectsCollection::BaseClassNameStatic()];
}

- (instancetype) initFromInternalObjectsCollectionPointer:(se::doc::DocObjectsCollection *)collptr
                                       withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = collptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocObjectsCollection *) getInternalObjectsCollectionPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (SEDocBasicObject *) createObject {
  try {
    return [[SEDocBasicObject alloc]
        initFromCreatedBasicObject:ptr->CreateObject()];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SEDocObjectsCollection *) clone {
  try {
    return [[SEDocObjectsCollection alloc]
        initFromCreatedObjectsCollection:ptr->Clone()];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (NSString *) objectType {
  return [NSString stringWithUTF8String:ptr->ObjectType()];
}

- (int) getFrameID {
  return ptr->GetFrameID();
}

- (void) setFrameIDTo:(int)frame_id {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    ptr->SetFrameID(frame_id);
  }
}

- (int) getObjectsCount {
  return ptr->GetObjectsCount();
}

- (BOOL) hasObjectWithID:(int)obj_id {
  return ptr->HasObject(obj_id)? YES : NO;
}

- (SEDocBasicObjectRef *) getObjectWithID:(int)obj_id {
  try {
    return [[SEDocBasicObjectRef alloc]
        initFromInternalBasicObjectPointer:const_cast<se::doc::DocBasicObject*>(&ptr->GetObject(obj_id))
                        withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SEDocBasicObjectRef *) getMutableObjectWithID:(int)obj_id {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocBasicObjectRef alloc]
          initFromInternalBasicObjectPointer:&ptr->GetMutableObject(obj_id)
                          withMutabilityFlag:YES];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (SEDocTagsCollectionRef *) getObjectTagsWithID:(int)obj_id {
  try {
    return [[SEDocTagsCollectionRef alloc]
        initFromInternalTagsCollectionPointer:const_cast<se::doc::DocTagsCollection*>(&ptr->GetObjectTags(obj_id))
                           withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SEDocBasicObjectsMutableIterator *) addObject:(SEDocBasicObject *)obj {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocBasicObjectsMutableIterator alloc]
          initFromInternalBasicObjectsMutableIterator:ptr->AddObject([obj getInternalBasicObject])];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (void) setObjectWithID:(int)obj_id
                      to:(SEDocBasicObject *)obj {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->SetObject(obj_id, [obj getInternalBasicObject]);      
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (void) removeObjectWithID:(int)obj_id {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->RemoveObject(obj_id);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}


- (void) removeObjectDeepWithID:(int)obj_id
            withViewsCollection:(SEDocViewsCollectionRef *)views_collection {
  if (!is_mutable || (NO == [views_collection isMutable])) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->RemoveObjectDeep(obj_id, *[views_collection getInternalViewsCollectionPointer]);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (SEDocBasicObjectsIterator *) basicObjectsBegin {
  return [[SEDocBasicObjectsIterator alloc]
      initFromInternalBasicObjectsIterator:ptr->BasicObjectsBegin()];
}

- (SEDocBasicObjectsIterator *) basicObjectsEnd {
  return [[SEDocBasicObjectsIterator alloc]
      initFromInternalBasicObjectsIterator:ptr->BasicObjectsEnd()];
}

- (SEDocBasicObjectsMutableIterator *) mutableBasicObjectsBegin {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    return [[SEDocBasicObjectsMutableIterator alloc]
        initFromInternalBasicObjectsMutableIterator:ptr->MutableBasicObjectsBegin()];
  }
  return nil;
}

- (SEDocBasicObjectsMutableIterator *) mutableBasicObjectsEnd {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    return [[SEDocBasicObjectsMutableIterator alloc]
        initFromInternalBasicObjectsMutableIterator:ptr->MutableBasicObjectsEnd()];
  }
  return nil;
}

- (SEDocBasicObjectsSliceIterator *) basicObjectsSliceForTag:(NSString *)tag {
  try {
    return [[SEDocBasicObjectsSliceIterator alloc]
        initFromInternalBasicObjectsSliceIterator:ptr->BasicObjectsSlice([tag UTF8String])];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SEDocBasicObjectsMutableSliceIterator *) mutableBasicObjectsSliceForTag:(NSString *)tag {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocBasicObjectsMutableSliceIterator alloc]
          initFromInternalBasicObjectsMutableSliceIterator:ptr->MutableBasicObjectsSlice([tag UTF8String])];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (void) serialize:(SECommonSerializer *)serializer {
  ptr->Serialize([serializer getInternalSerializer]);
}

@end


@implementation SEDocObjectsCollection {
  std::unique_ptr<se::doc::DocObjectsCollection> internal;
}

+ (NSString *) baseClassNameStatic {
  return [NSString stringWithUTF8String:se::doc::DocObjectsCollection::BaseClassNameStatic()];
}

- (instancetype) initFromCreatedObjectsCollection:(se::doc::DocObjectsCollection *)collptr {
  if (self = [super init]) {
    internal.reset(collptr);
  }
  return self;
}

- (se::doc::DocObjectsCollection &) getInternalObjectsCollection {
  return *internal;
}

- (instancetype) initForObjectType:(NSString *)object_type {
  if (self = [super init]) {
    try {
      internal.reset(se::doc::DocObjectsCollection::Create([object_type UTF8String]));
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
    return nil;
  }
  return self;
}

- (SEDocObjectsCollectionRef *) getRef {
  return [[SEDocObjectsCollectionRef alloc]
      initFromInternalObjectsCollectionPointer:internal.get()
                            withMutabilityFlag:NO];
}

- (SEDocObjectsCollectionRef *) getMutableRef {
  return [[SEDocObjectsCollectionRef alloc]
      initFromInternalObjectsCollectionPointer:internal.get()
                            withMutabilityFlag:YES];
}

@end
