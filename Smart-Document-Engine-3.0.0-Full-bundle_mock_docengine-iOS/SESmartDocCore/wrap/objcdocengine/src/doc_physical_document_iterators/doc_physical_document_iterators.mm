/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_physical_document_iterators_impl.h>

@implementation SEDocTextObjectsCrossPageIterator {
  se::doc::DocTextObjectsCrossPageIterator* ptr;
  bool is_mutable;
}

- (instancetype) initFromInternalTextObjectsCrossPageIteratorPointer:(se::doc::DocTextObjectsCrossPageIterator *)docptr
                                                  withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = docptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocTextObjectsCrossPageIterator *) getInternalTextObjectsCrossPageIteratorPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (void)advance {
  ptr->Advance();
}

- (int)getPhysicalPageID {
  return ptr->GetPhysicalPageID();
}

@end
