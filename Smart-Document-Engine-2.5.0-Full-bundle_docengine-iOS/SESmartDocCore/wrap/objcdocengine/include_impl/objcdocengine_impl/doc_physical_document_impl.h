/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_PHYSICAL_DOCUMENT_H_INCLUDED
#define OBJCDOCENGINE_IMPL_PHYSICAL_DOCUMENT_H_INCLUDED

#import <objcdocengine/doc_physical_document.h>

#include <docengine/doc_physical_document.h>

@interface SEDocPhysicalPageRef (Internal)

- (instancetype) initFromInternalPhysicalPagePointer:(se::doc::DocPhysicalPage *)docptr
                                withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocPhysicalPage *) getInternalPhysicalPagePointer;

@end

@interface SEDocPhysicalDocumentRef (Internal)

- (instancetype) initFromInternalPhysicalDocumentPointer:(se::doc::DocPhysicalDocument *)docptr
                                withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocPhysicalDocument *) getInternalPhysicalDocumentPointer;

@end

#endif // OBJCDOCENGINE_IMPL_PHYSICAL_DOCUMENT_H_INCLUDED
