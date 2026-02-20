/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_objects_collections_iterator_impl.h>

#import <objcdocengine_impl/doc_objects_collection_impl.h>
#import <objcdocengine_impl/doc_tags_collection_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocObjectsCollectionsIterator {
  std::unique_ptr<se::doc::DocObjectsCollectionsIterator> internal;
}

- (instancetype) initFromInternalObjectsCollectionsIterator:(const se::doc::DocObjectsCollectionsIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocObjectsCollectionsIterator(iter));
  }
  return self;
}

- (const se::doc::DocObjectsCollectionsIterator &) getInternalObjectsCollectionsIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocObjectsCollectionsIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocObjectsCollectionsIterator(
        [other getInternalObjectsCollectionsIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocObjectsCollectionsIterator *)other {
  return internal->Equals([other getInternalObjectsCollectionsIterator])? YES : NO;
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

@end


@implementation SEDocObjectsCollectionsMutableIterator {
  std::unique_ptr<se::doc::DocObjectsCollectionsMutableIterator> internal;
}

- (instancetype) initFromInternalObjectsCollectionsMutableIterator:(const se::doc::DocObjectsCollectionsMutableIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocObjectsCollectionsMutableIterator(iter));
  }
  return self;
}

- (const se::doc::DocObjectsCollectionsMutableIterator &) getInternalObjectsCollectionsMutableIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocObjectsCollectionsMutableIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocObjectsCollectionsMutableIterator(
        [other getInternalObjectsCollectionsMutableIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocObjectsCollectionsMutableIterator *)other {
  return internal->Equals([other getInternalObjectsCollectionsMutableIterator])? YES : NO;
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

@end
