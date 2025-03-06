/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_basic_objects_iterator_impl.h>

#import <objcdocengine_impl/doc_basic_object_impl.h>
#import <objcdocengine_impl/doc_tags_collection_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocBasicObjectsSliceIterator {
  std::unique_ptr<se::doc::DocBasicObjectsSliceIterator> internal;
}

- (instancetype) initFromInternalBasicObjectsSliceIterator:(const se::doc::DocBasicObjectsSliceIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocBasicObjectsSliceIterator(iter));
  }
  return self;
}

- (const se::doc::DocBasicObjectsSliceIterator &) getInternalBasicObjectsSliceIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocBasicObjectsSliceIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocBasicObjectsSliceIterator([other getInternalBasicObjectsSliceIterator]));
  }
  return self;
}

- (int) getID {
  return internal->GetID();
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

- (BOOL) finished {
  return internal->Finished()? YES : NO;
}

@end

@implementation SEDocBasicObjectsMutableSliceIterator {
  std::unique_ptr<se::doc::DocBasicObjectsMutableSliceIterator> internal;
}

- (instancetype) initFromInternalBasicObjectsMutableSliceIterator:(const se::doc::DocBasicObjectsMutableSliceIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocBasicObjectsMutableSliceIterator(iter));
  }
  return self;
}

- (const se::doc::DocBasicObjectsMutableSliceIterator &) getInternalBasicObjectsMutableSliceIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocBasicObjectsMutableSliceIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocBasicObjectsMutableSliceIterator([other getInternalBasicObjectsMutableSliceIterator]));
  }
  return self;
}

- (int) getID {
  return internal->GetID();
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

- (BOOL) finished {
  return internal->Finished()? YES : NO;
}

@end
