/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_basic_objects_iterator_impl.h>

#import <objcdocengine_impl/doc_basic_object_impl.h>
#import <objcdocengine_impl/doc_tags_collection_impl.h>
#import <objcdocengine_impl/doc_objects_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocBasicObjectsIterator {
  std::unique_ptr<se::doc::DocBasicObjectsIterator> internal;
}

- (instancetype) initFromInternalBasicObjectsIterator:(const se::doc::DocBasicObjectsIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocBasicObjectsIterator(iter));
  }
  return self;
}

- (const se::doc::DocBasicObjectsIterator &) getInternalBasicObjectsIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocBasicObjectsIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocBasicObjectsIterator([other getInternalBasicObjectsIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocBasicObjectsIterator *)other {
  return internal->Equals([other getInternalBasicObjectsIterator])? YES : NO;
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

@end

@implementation SEDocBasicObjectsMutableIterator {
  std::unique_ptr<se::doc::DocBasicObjectsMutableIterator> internal;
}

- (instancetype) initFromInternalBasicObjectsMutableIterator:(const se::doc::DocBasicObjectsMutableIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocBasicObjectsMutableIterator(iter));
  }
  return self;
}

- (const se::doc::DocBasicObjectsMutableIterator &) getInternalBasicObjectsMutableIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocBasicObjectsMutableIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocBasicObjectsMutableIterator([other getInternalBasicObjectsMutableIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocBasicObjectsMutableIterator *)other {
  return internal->Equals([other getInternalBasicObjectsMutableIterator])? YES : NO;
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

@end


@implementation SEDocTextObjectsIterator {
  std::unique_ptr<se::doc::DocTextObjectsIterator> internal;
}

- (instancetype) initFromInternalTextObjectsIterator:(const se::doc::DocTextObjectsIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocTextObjectsIterator(iter));
  }
  return self;
}

- (const se::doc::DocTextObjectsIterator &) getInternalTextObjectsIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocTextObjectsIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocTextObjectsIterator([other getInternalTextObjectsIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocTextObjectsIterator *)other {
  return internal->Equals([other getInternalTextObjectsIterator])? YES : NO;
}

- (SEDocTextObjectRef *) getTextObject {
  return [[SEDocTextObjectRef alloc]
      initFromInternalTextObjectPointer:const_cast<se::doc::DocTextObject*>(&internal->GetTextObject())
                      withMutabilityFlag:NO];
}

- (void) advance {
  internal->Advance();
}

@end
