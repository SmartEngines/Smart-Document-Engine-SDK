/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_DOCUMENT_FIELD_INFO_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_DOCUMENT_FIELD_INFO_H_INCLUDED

//#import <objcdocengine/doc_document_info.h>
#import <objcdocengine/doc_document_field_info.h>

//#include <docengine/doc_document_info.h>
#include <docengine/doc_document_field_info.h>

@interface SEDocDocumentFieldsInfoRef (Internal)

- (instancetype) initFromInternalDocumentFieldInfoPointer:(se::doc::DocDocumentFieldInfo *)infoptr
                                  withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocDocumentFieldInfo *) getInternalDocumentFieldInfoPointer;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_DOCUMENT_FIELD_INFO_H_INCLUDED
