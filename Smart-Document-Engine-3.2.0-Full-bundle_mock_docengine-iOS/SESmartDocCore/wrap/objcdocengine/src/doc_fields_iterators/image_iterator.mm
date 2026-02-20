/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_fields_iterators_impl.h>

#import <objcdocengine_impl/doc_fields_impl.h>

#include <memory>

@implementation SEDocImageFieldsIterator {
  std::unique_ptr<se::doc::DocImageFieldsIterator> internal;
}

- (instancetype) initFromInternalImageFieldsIterator:(const se::doc::DocImageFieldsIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocImageFieldsIterator(iter));
  }
  return self;
}

- (const se::doc::DocImageFieldsIterator &) getInternalImageFieldsIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocImageFieldsIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocImageFieldsIterator([other getInternalImageFieldsIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocImageFieldsIterator *)other {
  return internal->Equals([other getInternalImageFieldsIterator])? YES : NO;
}

- (NSString *) getKey {
  return [NSString stringWithUTF8String:internal->GetKey()];
}

- (SEDocImageFieldRef *) getField {
  return [[SEDocImageFieldRef alloc]
      initFromInternalImageFieldPointer:const_cast<se::doc::DocImageField*>(&internal->GetField())
                    withMutabilityFlag:NO];
}

- (void) advance {
  internal->Advance();
}

@end
