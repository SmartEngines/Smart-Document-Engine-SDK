/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_basic_objects_iterator_impl.h>
#import <objcdocengine_impl/doc_objects_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocCheckboxObjectsIterator {
  std::unique_ptr<se::doc::DocCheckboxObjectsIterator> internal;
}

- (instancetype) initFromInternalCheckboxObjectsIterator:(const se::doc::DocCheckboxObjectsIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocCheckboxObjectsIterator(iter));
  }
  return self;
}

- (const se::doc::DocCheckboxObjectsIterator &) getInternalCheckboxObjectsIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocCheckboxObjectsIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocCheckboxObjectsIterator([other getInternalCheckboxObjectsIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocCheckboxObjectsIterator *)other {
  return internal->Equals([other getInternalCheckboxObjectsIterator])? YES : NO;
}

- (SEDocCheckboxObjectRef *) getCheckboxObject {
  return [[SEDocCheckboxObjectRef alloc]
      initFromInternalCheckboxObjectPointer:const_cast<se::doc::DocCheckboxObject*>(&internal->GetCheckboxObject())
                      withMutabilityFlag:NO];
}

- (void) advance {
  internal->Advance();
}

@end

