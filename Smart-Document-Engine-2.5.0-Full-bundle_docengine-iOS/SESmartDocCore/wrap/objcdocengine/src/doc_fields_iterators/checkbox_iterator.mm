/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_fields_iterators_impl.h>

#import <objcdocengine_impl/doc_fields_impl.h>

#include <memory>

@implementation SEDocCheckboxFieldsIterator {
  std::unique_ptr<se::doc::DocCheckboxFieldsIterator> internal;
}

- (instancetype) initFromInternalCheckboxFieldsIterator:(const se::doc::DocCheckboxFieldsIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocCheckboxFieldsIterator(iter));
  }
  return self;
}

- (const se::doc::DocCheckboxFieldsIterator &) getInternalCheckboxFieldsIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocCheckboxFieldsIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocCheckboxFieldsIterator([other getInternalCheckboxFieldsIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocCheckboxFieldsIterator *)other {
  return internal->Equals([other getInternalCheckboxFieldsIterator])? YES : NO;
}

- (NSString *) getKey {
  return [NSString stringWithUTF8String:internal->GetKey()];
}

- (SEDocCheckboxFieldRef *) getField {
  return [[SEDocCheckboxFieldRef alloc]
      initFromInternalCheckboxFieldPointer:const_cast<se::doc::DocCheckboxField*>(&internal->GetField())
                    withMutabilityFlag:NO];
}

- (void) advance {
  internal->Advance();
}

@end
