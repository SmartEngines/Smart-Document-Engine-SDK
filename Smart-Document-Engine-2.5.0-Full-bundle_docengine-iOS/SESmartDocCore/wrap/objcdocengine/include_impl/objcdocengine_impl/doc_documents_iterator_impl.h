/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_DOCUMENTS_ITERATOR_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_DOCUMENTS_ITERATOR_H_INCLUDED

#import <objcdocengine/doc_documents_iterator.h>

#include <docengine/doc_documents_iterator.h>

@interface SEDocumentsIterator (Internal)

- (instancetype) initFromInternalDocumentsIterator:(const se::doc::DocumentsIterator &)iter;
- (const se::doc::DocumentsIterator &) getInternalDocumentsIterator;

@end


@interface SEDocumentsMutableIterator (Internal)

- (instancetype) initFromInternalDocumentsMutableIterator:(const se::doc::DocumentsMutableIterator &)iter;
- (const se::doc::DocumentsMutableIterator &) getInternalDocumentsMutableIterator;

@end


@interface SEDocumentsSliceIterator (Internal)

- (instancetype) initFromInternalDocumentsSliceIterator:(const se::doc::DocumentsSliceIterator &)iter;
- (const se::doc::DocumentsSliceIterator &) getInternalDocumentsSliceIterator;

@end


@interface SEDocumentsMutableSliceIterator (Internal)

- (instancetype) initFromInternalDocumentsMutableSliceIterator:(const se::doc::DocumentsMutableSliceIterator &)iter;
- (const se::doc::DocumentsMutableSliceIterator &) getInternalDocumentsMutableSliceIterator;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_DOCUMENTS_ITERATOR_H_INCLUDED