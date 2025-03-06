/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_fields_iterators_impl.h>

#import <objcdocengine_impl/doc_fields_impl.h>

#include <memory>

@implementation SEDocBarcodeFieldsIterator {
  std::unique_ptr<se::doc::DocBarcodeFieldsIterator> internal;
}

- (instancetype) initFromInternalBarcodeFieldsIterator:(const se::doc::DocBarcodeFieldsIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocBarcodeFieldsIterator(iter));
  }
  return self;
}

- (const se::doc::DocBarcodeFieldsIterator &) getInternalBarcodeFieldsIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocBarcodeFieldsIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocBarcodeFieldsIterator([other getInternalBarcodeFieldsIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocBarcodeFieldsIterator *)other {
  return internal->Equals([other getInternalBarcodeFieldsIterator])? YES : NO;
}

- (NSString *) getKey {
  return [NSString stringWithUTF8String:internal->GetKey()];
}

- (SEDocBarcodeFieldRef *) getField {
  return [[SEDocBarcodeFieldRef alloc]
      initFromInternalBarcodeFieldPointer:const_cast<se::doc::DocBarcodeField*>(&internal->GetField())
                    withMutabilityFlag:NO];
}

- (void) advance {
  internal->Advance();
}

@end
