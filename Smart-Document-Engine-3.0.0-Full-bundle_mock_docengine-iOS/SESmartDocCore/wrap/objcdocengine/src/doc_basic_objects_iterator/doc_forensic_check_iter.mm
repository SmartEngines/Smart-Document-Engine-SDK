/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_basic_objects_iterator_impl.h>
#import <objcdocengine_impl/doc_objects_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocForensicCheckObjectsIterator {
  std::unique_ptr<se::doc::DocForensicCheckObjectsIterator> internal;
}

- (instancetype) initFromInternalForensicCheckObjectsIterator:(const se::doc::DocForensicCheckObjectsIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocForensicCheckObjectsIterator(iter));
  }
  return self;
}

- (const se::doc::DocForensicCheckObjectsIterator &) getInternalForensicCheckObjectsIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocForensicCheckObjectsIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocForensicCheckObjectsIterator([other getInternalForensicCheckObjectsIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocForensicCheckObjectsIterator *)other {
  return internal->Equals([other getInternalForensicCheckObjectsIterator])? YES : NO;
}

- (SEDocForensicCheckObjectRef *) getForensicCheckObject {
  return [[SEDocForensicCheckObjectRef alloc]
      initFromInternalForensicCheckObjectPointer:const_cast<se::doc::DocForensicCheckObject*>(&internal->GetForensicCheckObject())
                      withMutabilityFlag:NO];
}

- (void) advance {
  internal->Advance();
}

@end

