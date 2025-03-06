/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_basic_objects_iterator_impl.h>

#import <objcdocengine_impl/doc_basic_object_impl.h>
#import <objcdocengine_impl/doc_tags_collection_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocBasicObjectsCrossSliceIterator {
  std::unique_ptr<se::doc::DocBasicObjectsCrossSliceIterator> internal;
}

- (instancetype) initFromInternalBasicObjectsCrossSliceIterator:(const se::doc::DocBasicObjectsCrossSliceIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocBasicObjectsCrossSliceIterator(iter));
  }
  return self;
}

- (const se::doc::DocBasicObjectsCrossSliceIterator &) getInternalBasicObjectsCrossSliceIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocBasicObjectsCrossSliceIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocBasicObjectsCrossSliceIterator([other getInternalBasicObjectsCrossSliceIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocBasicObjectsCrossSliceIterator *)other {
  return internal->Equals([other getInternalBasicObjectsCrossSliceIterator])? YES : NO;
}

- (int) getCollectionID {
  return internal->GetCollectionID();
}

- (int) getObjectID {
  return internal->GetObjectID();
}

- (SEDocBasicObjectRef *) getBasicObject {
  return [[SEDocBasicObjectRef alloc]
      initFromInternalBasicObjectPointer:const_cast<se::doc::DocBasicObject*>(&internal->GetBasicObject())
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

@implementation SEDocBasicObjectsMutableCrossSliceIterator {
  std::unique_ptr<se::doc::DocBasicObjectsMutableCrossSliceIterator> internal;
}

- (instancetype) initFromInternalBasicObjectsMutableCrossSliceIterator:(const se::doc::DocBasicObjectsMutableCrossSliceIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocBasicObjectsMutableCrossSliceIterator(iter));
  }
  return self;
}

- (const se::doc::DocBasicObjectsMutableCrossSliceIterator &) getInternalBasicObjectsMutableCrossSliceIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocBasicObjectsMutableCrossSliceIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocBasicObjectsMutableCrossSliceIterator([other getInternalBasicObjectsMutableCrossSliceIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocBasicObjectsMutableCrossSliceIterator *)other {
  return internal->Equals([other getInternalBasicObjectsMutableCrossSliceIterator])? YES : NO;
}

- (int) getCollectionID {
  return internal->GetCollectionID();
}

- (int) getObjectID {
  return internal->GetObjectID();
}

- (SEDocBasicObjectRef *) getBasicObject {
  return [[SEDocBasicObjectRef alloc]
      initFromInternalBasicObjectPointer:const_cast<se::doc::DocBasicObject*>(&internal->GetBasicObject())
                      withMutabilityFlag:NO];
}

- (SEDocBasicObjectRef *) getMutableBasicObject {
  return [[SEDocBasicObjectRef alloc]
      initFromInternalBasicObjectPointer:&internal->GetMutableBasicObject()
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
