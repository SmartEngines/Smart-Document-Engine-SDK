/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_basic_objects_iterator_impl.h>
#import <objcdocengine_impl/doc_objects_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocMetaObjectsIterator {
  std::unique_ptr<se::doc::DocMetaObjectsIterator> internal;
}

- (instancetype) initFromInternalMetaObjectsIterator:(const se::doc::DocMetaObjectsIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocMetaObjectsIterator(iter));
  }
  return self;
}

- (const se::doc::DocMetaObjectsIterator &) getInternalMetaObjectsIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocMetaObjectsIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocMetaObjectsIterator([other getInternalMetaObjectsIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocMetaObjectsIterator *)other {
  return internal->Equals([other getInternalMetaObjectsIterator])? YES : NO;
}

- (SEDocMetaObjectRef *) getMetaObject {
  return [[SEDocMetaObjectRef alloc]
      initFromInternalMetaObjectPointer:const_cast<se::doc::DocMetaObject*>(&internal->GetMetaObject())
                      withMutabilityFlag:NO];
}

- (void) advance {
  internal->Advance();
}

@end

