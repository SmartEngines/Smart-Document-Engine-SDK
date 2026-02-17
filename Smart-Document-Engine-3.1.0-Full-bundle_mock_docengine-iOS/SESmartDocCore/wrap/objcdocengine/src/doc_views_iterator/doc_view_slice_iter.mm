/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_views_iterator_impl.h>

#import <objcdocengine_impl/doc_view_impl.h>
#import <objcdocengine_impl/doc_tags_collection_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocViewsSliceIterator {
  std::unique_ptr<se::doc::DocViewsSliceIterator> internal;
}

- (instancetype) initFromInternalViewsSliceIterator:(const se::doc::DocViewsSliceIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocViewsSliceIterator(iter));
  }
  return self;
}

- (const se::doc::DocViewsSliceIterator &) getInternalViewsSliceIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocViewsSliceIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocViewsSliceIterator([other getInternalViewsSliceIterator]));
  }
  return self;
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

- (BOOL) finished {
  return internal->Finished()? YES : NO;
}

@end


@implementation SEDocViewsMutableSliceIterator {
  std::unique_ptr<se::doc::DocViewsMutableSliceIterator> internal;
}

- (instancetype) initFromInternalViewsMutableSliceIterator:(const se::doc::DocViewsMutableSliceIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocViewsMutableSliceIterator(iter));
  }
  return self;
}

- (const se::doc::DocViewsMutableSliceIterator &) getInternalViewsMutableSliceIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocViewsMutableSliceIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocViewsMutableSliceIterator([other getInternalViewsMutableSliceIterator]));
  }
  return self;
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

- (BOOL) finished {
  return internal->Finished()? YES : NO;
}

@end
