/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_views_iterator_impl.h>

#import <objcdocengine_impl/doc_view_impl.h>
#import <objcdocengine_impl/doc_tags_collection_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocViewsIterator {
  std::unique_ptr<se::doc::DocViewsIterator> internal;
}

- (instancetype) initFromInternalViewsIterator:(const se::doc::DocViewsIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocViewsIterator(iter));
  }
  return self;
}

- (const se::doc::DocViewsIterator &) getInternalViewsIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocViewsIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocViewsIterator([other getInternalViewsIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocViewsIterator *)other {
  return internal->Equals([other getInternalViewsIterator])? YES : NO;
}

- (int) getID {
  return internal->GetID();
}

- (SEDocViewRef *) getView {
  return [[SEDocViewRef alloc]
      initFromInternalViewPointer:const_cast<se::doc::DocView*>(&internal->GetView())
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


@implementation SEDocViewsMutableIterator {
  std::unique_ptr<se::doc::DocViewsMutableIterator> internal;
}

- (instancetype) initFromInternalViewsMutableIterator:(const se::doc::DocViewsMutableIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocViewsMutableIterator(iter));
  }
  return self;
}

- (const se::doc::DocViewsMutableIterator &) getInternalViewsMutableIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocViewsMutableIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocViewsMutableIterator([other getInternalViewsMutableIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocViewsMutableIterator *)other {
  return internal->Equals([other getInternalViewsMutableIterator])? YES : NO;
}

- (int) getID {
  return internal->GetID();
}

- (SEDocViewRef *) getView {
  return [[SEDocViewRef alloc]
      initFromInternalViewPointer:const_cast<se::doc::DocView*>(&internal->GetView())
               withMutabilityFlag:NO];
}

- (SEDocViewRef *) getMutableView {
  return [[SEDocViewRef alloc]
      initFromInternalViewPointer:&internal->GetMutableView()
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
