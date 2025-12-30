/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_objects_collections_iterator_impl.h>

#import <objcdocengine_impl/doc_objects_collection_impl.h>
#import <objcdocengine_impl/doc_tags_collection_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocObjectsCollectionsSliceIterator {
  std::unique_ptr<se::doc::DocObjectsCollectionsSliceIterator> internal;
}

- (instancetype) initFromInternalObjectsCollectionsSliceIterator:(const se::doc::DocObjectsCollectionsSliceIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocObjectsCollectionsSliceIterator(iter));
  }
  return self;
}

- (const se::doc::DocObjectsCollectionsSliceIterator &) getInternalObjectsCollectionsSliceIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocObjectsCollectionsSliceIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocObjectsCollectionsSliceIterator(
        [other getInternalObjectsCollectionsSliceIterator]));
  }
  return self;
}

- (int) getID {
  return internal->GetID();
}

- (SEDocObjectsCollectionRef *) getObjectsCollection {
  return [[SEDocObjectsCollectionRef alloc]
      initFromInternalObjectsCollectionPointer:const_cast<se::doc::DocObjectsCollection*>(&internal->GetObjectsCollection())
                            withMutabilityFlag:NO];
}

- (SEDocTagsCollectionRef *) getTags {
  return [[SEDocTagsCollectionRef alloc]
      initFromInternalTagsCollectionPointer:const_cast<se::doc::DocTagsCollection*>(&internal->GetTags())
                         withMutabilityFlag:NO];
}

- (void) advance {
  internal->Advance();
}

- (BOOL) finished {
  return internal->Finished()? YES : NO;
}

@end


@implementation SEDocObjectsCollectionsMutableSliceIterator {
  std::unique_ptr<se::doc::DocObjectsCollectionsMutableSliceIterator> internal;
}

- (instancetype) initFromInternalObjectsCollectionsMutableSliceIterator:(const se::doc::DocObjectsCollectionsMutableSliceIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocObjectsCollectionsMutableSliceIterator(iter));
  }
  return self;
}

- (const se::doc::DocObjectsCollectionsMutableSliceIterator &) getInternalObjectsCollectionsMutableSliceIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocObjectsCollectionsMutableSliceIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocObjectsCollectionsMutableSliceIterator(
        [other getInternalObjectsCollectionsMutableSliceIterator]));
  }
  return self;
}

- (int) getID {
  return internal->GetID();
}

- (SEDocObjectsCollectionRef *) getObjectsCollection {
  return [[SEDocObjectsCollectionRef alloc]
      initFromInternalObjectsCollectionPointer:const_cast<se::doc::DocObjectsCollection*>(&internal->GetObjectsCollection())
                            withMutabilityFlag:NO];
}

- (SEDocObjectsCollectionRef *) getMutableObjectsCollection {
  return [[SEDocObjectsCollectionRef alloc]
      initFromInternalObjectsCollectionPointer:&internal->GetMutableObjectsCollection()
                            withMutabilityFlag:YES];
}

- (SEDocTagsCollectionRef *) getTags {
  return [[SEDocTagsCollectionRef alloc]
      initFromInternalTagsCollectionPointer:const_cast<se::doc::DocTagsCollection*>(&internal->GetTags())
                         withMutabilityFlag:NO];
}

- (void) advance {
  internal->Advance();
}

- (BOOL) finished {
  return internal->Finished()? YES : NO;
}

@end
