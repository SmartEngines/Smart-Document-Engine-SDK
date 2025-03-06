/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_DOCUMENT_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_DOCUMENT_H_INCLUDED

#import <objcdocengine/doc_document.h>

#include <docengine/doc_document.h>

@interface SEDocumentRef (Internal)

- (instancetype) initFromInternalDocumentPointer:(se::doc::Document *)docptr
                              withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::Document *) getInternalDocumentPointer;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_DOCUMENT_H_INCLUDED