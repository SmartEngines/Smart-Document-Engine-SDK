/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_basic_objects_iterator_impl.h>
#import <objcdocengine_impl/doc_objects_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocBarcodeObjectsIterator {
  std::unique_ptr<se::doc::DocBarcodeObjectsIterator> internal;
}

- (instancetype) initFromInternalBarcodeObjectsIterator:(const se::doc::DocBarcodeObjectsIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocBarcodeObjectsIterator(iter));
  }
  return self;
}

- (const se::doc::DocBarcodeObjectsIterator &) getInternalBarcodeObjectsIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocBarcodeObjectsIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocBarcodeObjectsIterator([other getInternalBarcodeObjectsIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocBarcodeObjectsIterator *)other {
  return internal->Equals([other getInternalBarcodeObjectsIterator])? YES : NO;
}

- (SEDocBarcodeObjectRef *) getBarcodeObject {
  return [[SEDocBarcodeObjectRef alloc]
      initFromInternalBarcodeObjectPointer:const_cast<se::doc::DocBarcodeObject*>(&internal->GetBarcodeObject())
                      withMutabilityFlag:NO];
}

- (void) advance {
  internal->Advance();
}

@end

