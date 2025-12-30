/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_graphical_structure_impl.h>

#import <objcdocengine_impl/doc_objects_collection_impl.h>
#import <objcdocengine_impl/doc_objects_collections_iterator_impl.h>
#import <objcdocengine_impl/doc_tags_collection_impl.h>
#import <objcdocengine_impl/doc_views_collection_impl.h>

#import <objcsecommon_impl/se_serialization_impl.h>
#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocGraphicalStructureRef {
  se::doc::DocGraphicalStructure* ptr;
  bool is_mutable;
}

- (instancetype) initFromInternalGraphicalStructurePointer:(se::doc::DocGraphicalStructure *)gsptr
                                        withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = gsptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocGraphicalStructure *) getInternalGraphicalStructurePointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (int) getCollectionsCount {
  return ptr->GetCollectionsCount();
}

- (BOOL) hasCollectionWithID:(int)c_id {
  return ptr->HasCollection(c_id)? YES : NO;
}

- (SEDocObjectsCollectionRef *) getCollectionWithID:(int)c_id {
  try {
    return [[SEDocObjectsCollectionRef alloc]
        initFromInternalObjectsCollectionPointer:const_cast<se::doc::DocObjectsCollection*>(&ptr->GetCollection(c_id))
                              withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SEDocObjectsCollectionRef *) getMutableCollectionWithID:(int)c_id {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocObjectsCollectionRef alloc]
          initFromInternalObjectsCollectionPointer:&ptr->GetMutableCollection(c_id)
                                withMutabilityFlag:YES];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (SEDocTagsCollectionRef *) getCollectionTagsWithID:(int)c_id {
  try {
    return [[SEDocTagsCollectionRef alloc]
        initFromInternalTagsCollectionPointer:const_cast<se::doc::DocTagsCollection*>(&ptr->GetCollectionTags(c_id))
                              withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SEDocObjectsCollectionsMutableIterator *) addCollection:(SEDocObjectsCollection *)collection {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocObjectsCollectionsMutableIterator alloc]
          initFromInternalObjectsCollectionsMutableIterator:ptr->AddCollection(
              [collection getInternalObjectsCollection])];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (SEDocObjectsCollectionsMutableIterator *) addCollection:(SEDocObjectsCollection *)collection
                                                  withTags:(SEDocTagsCollection *)tags {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocObjectsCollectionsMutableIterator alloc]
          initFromInternalObjectsCollectionsMutableIterator:ptr->AddCollection(
              [collection getInternalObjectsCollection],
              [tags getInternalTagsCollection])];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}


- (void) setCollectionWithID:(int)c_id
                          to:(SEDocObjectsCollection *)collection {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->SetCollection(c_id, [collection getInternalObjectsCollection]);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (void) removeCollectionWithID:(int)c_id {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->RemoveCollection(c_id);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (SEDocObjectsCollectionsIterator *) objectsCollectionsBegin {
  return [[SEDocObjectsCollectionsIterator alloc]
      initFromInternalObjectsCollectionsIterator:ptr->ObjectsCollectionsBegin()];
}

- (SEDocObjectsCollectionsIterator *) objectsCollectionsEnd {
  return [[SEDocObjectsCollectionsIterator alloc]
      initFromInternalObjectsCollectionsIterator:ptr->ObjectsCollectionsEnd()];
}

- (SEDocObjectsCollectionsMutableIterator *) mutableObjectsCollectionsBegin {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    return [[SEDocObjectsCollectionsMutableIterator alloc]
        initFromInternalObjectsCollectionsMutableIterator:ptr->MutableObjectsCollectionsBegin()];
  }
  return nil;
}

- (SEDocObjectsCollectionsMutableIterator *) mutableObjectsCollectionsEnd {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    return [[SEDocObjectsCollectionsMutableIterator alloc]
        initFromInternalObjectsCollectionsMutableIterator:ptr->MutableObjectsCollectionsEnd()];
  }
  return nil;
}

- (SEDocObjectsCollectionsSliceIterator *) objectsCollectionsSliceForTag:(NSString *)tag {
  try {
    return [[SEDocObjectsCollectionsSliceIterator alloc]
        initFromInternalObjectsCollectionsSliceIterator:ptr->ObjectsCollectionsSlice([tag UTF8String])];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SEDocObjectsCollectionsMutableSliceIterator *) mutableObjectsCollectionsSliceForTag:(NSString *)tag {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocObjectsCollectionsMutableSliceIterator alloc]
          initFromInternalObjectsCollectionsMutableSliceIterator:ptr->MutableObjectsCollectionsSlice([tag UTF8String])];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (SEDocViewsCollectionRef *) getViewsCollection {
  return [[SEDocViewsCollectionRef alloc]
      initFromInternalViewsCollectionPointer:const_cast<se::doc::DocViewsCollection*>(&ptr->GetViewsCollection())
                          withMutabilityFlag:NO];
}

- (SEDocViewsCollectionRef *) getMutableViewsCollection {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    return [[SEDocViewsCollectionRef alloc]
        initFromInternalViewsCollectionPointer:&ptr->GetMutableViewsCollection()
                            withMutabilityFlag:YES];
  }
  return nil;
}

- (void) serialize:(SECommonSerializer *)serializer {
  ptr->Serialize([serializer getInternalSerializer]);
}

@end
