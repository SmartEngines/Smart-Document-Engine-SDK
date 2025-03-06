/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_fields_iterators_impl.h>

#import <objcdocengine_impl/doc_fields_impl.h>

#include <memory>

@implementation SEDocTextFieldsIterator {
  std::unique_ptr<se::doc::DocTextFieldsIterator> internal;
}

- (instancetype) initFromInternalTextFieldsIterator:(const se::doc::DocTextFieldsIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocTextFieldsIterator(iter));
  }
  return self;
}

- (const se::doc::DocTextFieldsIterator &) getInternalTextFieldsIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocTextFieldsIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocTextFieldsIterator([other getInternalTextFieldsIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocTextFieldsIterator *)other {
  return internal->Equals([other getInternalTextFieldsIterator])? YES : NO;
}

- (NSString *) getKey {
  return [NSString stringWithUTF8String:internal->GetKey()];
}

- (SEDocTextFieldRef *) getField {
  return [[SEDocTextFieldRef alloc]
      initFromInternalTextFieldPointer:const_cast<se::doc::DocTextField*>(&internal->GetField())
                    withMutabilityFlag:NO];
}

- (void) advance {
  internal->Advance();
}

@end
