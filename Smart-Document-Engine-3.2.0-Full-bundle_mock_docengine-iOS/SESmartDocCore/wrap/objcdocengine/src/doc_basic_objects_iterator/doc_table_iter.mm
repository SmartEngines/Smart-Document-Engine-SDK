/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_basic_objects_iterator_impl.h>
#import <objcdocengine_impl/doc_objects_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocTableObjectsIterator {
  std::unique_ptr<se::doc::DocTableObjectsIterator> internal;
}

- (instancetype) initFromInternalTableObjectsIterator:(const se::doc::DocTableObjectsIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocTableObjectsIterator(iter));
  }
  return self;
}

- (const se::doc::DocTableObjectsIterator &) getInternalTableObjectsIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocTableObjectsIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocTableObjectsIterator([other getInternalTableObjectsIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocTableObjectsIterator *)other {
  return internal->Equals([other getInternalTableObjectsIterator])? YES : NO;
}

- (SEDocTableObjectRef *) getTableObject {
  return [[SEDocTableObjectRef alloc]
      initFromInternalTableObjectPointer:const_cast<se::doc::DocTableObject*>(&internal->GetTableObject())
                      withMutabilityFlag:NO];
}

- (void) advance {
  internal->Advance();
}

@end

