/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_DOCUMENT_INFO_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_DOCUMENT_INFO_H_INCLUDED

#import <objcdocengine/doc_document_info.h>

#include <docengine/doc_document_info.h>

@interface SEDocDocumentInfoRef (Internal)

- (instancetype) initFromInternalDocumentInfoPointer:(se::doc::DocDocumentInfo *)infoptr 
                                  withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocDocumentInfo *) getInternalDocumentInfoPointer;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_DOCUMENT_INFO_H_INCLUDED