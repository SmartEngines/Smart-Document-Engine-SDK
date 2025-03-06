/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_PHYSICAL_DOCUMENT_ITERATORS_H_INCLUDED
#define OBJCDOCENGINE_IMPL_PHYSICAL_DOCUMENT_ITERATORS_H_INCLUDED

#import <objcdocengine/doc_physical_document_iterators.h>

#include <docengine/doc_physical_document_iterators.h>

@interface SEDocTextObjectsCrossPageIterator (Internal)

- (instancetype) initFromInternalTextObjectsCrossPageIteratorPointer:(se::doc::DocTextObjectsCrossPageIterator *)docptr
                                withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocTextObjectsCrossPageIterator *) getInternalTextObjectsCrossPageIteratorPointer;

@end

#endif // OBJCDOCENGINE_IMPL_PHYSICAL_DOCUMENT_ITERATORS_H_INCLUDED
