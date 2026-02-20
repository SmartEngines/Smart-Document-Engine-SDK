/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_DOCUMENT_FIELDS_INFO_ITERATOR_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_DOCUMENT_FIELDS_INFO_ITERATOR_H_INCLUDED

#import <objcdocengine/doc_document_fields_info_iterator.h>

#include <docengine/doc_document_fields_info_iterator.h>

@interface SEDocDocumentFieldsInfoIterator (Internal)

- (instancetype) initFromInternalDocDocumentFieldsInfoIterator:(const se::doc::DocDocumentFieldsInfoIterator &)iter;
- (const se::doc::DocDocumentFieldsInfoIterator &) getInternalDocDocumentFieldsInfoIterator;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_DOCUMENT_FIELDS_INFO_ITERATOR_H_INCLUDED
