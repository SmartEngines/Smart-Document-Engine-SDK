/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_fields_iterators_impl.h>

#import <objcdocengine_impl/doc_fields_impl.h>

#include <memory>

@implementation SEDocTableFieldsIterator {
  std::unique_ptr<se::doc::DocTableFieldsIterator> internal;
}

- (instancetype) initFromInternalTableFieldsIterator:(const se::doc::DocTableFieldsIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocTableFieldsIterator(iter));
  }
  return self;
}

- (const se::doc::DocTableFieldsIterator &) getInternalTableFieldsIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocTableFieldsIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocTableFieldsIterator([other getInternalTableFieldsIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocTableFieldsIterator *)other {
  return internal->Equals([other getInternalTableFieldsIterator])? YES : NO;
}

- (NSString *) getKey {
  return [NSString stringWithUTF8String:internal->GetKey()];
}

- (SEDocTableFieldRef *) getField {
  return [[SEDocTableFieldRef alloc]
      initFromInternalTableFieldPointer:const_cast<se::doc::DocTableField*>(&internal->GetField())
                    withMutabilityFlag:NO];
}

- (void) advance {
  internal->Advance();
}

@end
