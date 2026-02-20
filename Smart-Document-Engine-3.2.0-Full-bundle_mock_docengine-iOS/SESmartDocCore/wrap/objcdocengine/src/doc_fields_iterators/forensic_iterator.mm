/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_fields_iterators_impl.h>

#import <objcdocengine_impl/doc_fields_impl.h>

#include <memory>

@implementation SEDocForensicFieldsIterator {
  std::unique_ptr<se::doc::DocForensicFieldsIterator> internal;
}

- (instancetype) initFromInternalForensicFieldsIterator:(const se::doc::DocForensicFieldsIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocForensicFieldsIterator(iter));
  }
  return self;
}

- (const se::doc::DocForensicFieldsIterator &) getInternalForensicFieldsIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocForensicFieldsIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocForensicFieldsIterator([other getInternalForensicFieldsIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocForensicFieldsIterator *)other {
  return internal->Equals([other getInternalForensicFieldsIterator])? YES : NO;
}

- (NSString *) getKey {
  return [NSString stringWithUTF8String:internal->GetKey()];
}

- (SEDocForensicFieldRef *) getField {
  return [[SEDocForensicFieldRef alloc]
      initFromInternalForensicFieldPointer:const_cast<se::doc::DocForensicField*>(&internal->GetField())
                    withMutabilityFlag:NO];
}

- (void) advance {
  internal->Advance();
}

@end
