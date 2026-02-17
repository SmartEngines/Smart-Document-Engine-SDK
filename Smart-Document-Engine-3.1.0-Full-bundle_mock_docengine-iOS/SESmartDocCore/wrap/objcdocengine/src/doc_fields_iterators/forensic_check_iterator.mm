/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_fields_iterators_impl.h>

#import <objcdocengine_impl/doc_fields_impl.h>

#include <memory>

@implementation SEDocForensicCheckFieldsIterator {
  std::unique_ptr<se::doc::DocForensicCheckFieldsIterator> internal;
}

- (instancetype) initFromInternalForensicCheckFieldsIterator:(const se::doc::DocForensicCheckFieldsIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocForensicCheckFieldsIterator(iter));
  }
  return self;
}

- (const se::doc::DocForensicCheckFieldsIterator &) getInternalForensicCheckFieldsIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocForensicCheckFieldsIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocForensicCheckFieldsIterator([other getInternalForensicCheckFieldsIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocForensicCheckFieldsIterator *)other {
  return internal->Equals([other getInternalForensicCheckFieldsIterator])? YES : NO;
}

- (NSString *) getKey {
  return [NSString stringWithUTF8String:internal->GetKey()];
}

- (SEDocForensicCheckFieldRef *) getField {
  return [[SEDocForensicCheckFieldRef alloc]
      initFromInternalForensicCheckFieldPointer:const_cast<se::doc::DocForensicCheckField*>(&internal->GetField())
                    withMutabilityFlag:NO];
}

- (void) advance {
  internal->Advance();
}

@end
