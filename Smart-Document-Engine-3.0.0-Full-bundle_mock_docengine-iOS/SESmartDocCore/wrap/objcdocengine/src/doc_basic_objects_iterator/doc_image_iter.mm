/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_basic_objects_iterator_impl.h>
#import <objcdocengine_impl/doc_objects_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocImageObjectsIterator {
  std::unique_ptr<se::doc::DocImageObjectsIterator> internal;
}

- (instancetype) initFromInternalImageObjectsIterator:(const se::doc::DocImageObjectsIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocImageObjectsIterator(iter));
  }
  return self;
}

- (const se::doc::DocImageObjectsIterator &) getInternalImageObjectsIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocImageObjectsIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocImageObjectsIterator([other getInternalImageObjectsIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocImageObjectsIterator *)other {
  return internal->Equals([other getInternalImageObjectsIterator])? YES : NO;
}

- (SEDocImageObjectRef *) getImageObject {
  return [[SEDocImageObjectRef alloc]
      initFromInternalImageObjectPointer:const_cast<se::doc::DocImageObject*>(&internal->GetImageObject())
                      withMutabilityFlag:NO];
}

- (void) advance {
  internal->Advance();
}

@end
