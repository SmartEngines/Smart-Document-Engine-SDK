/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJDOCENGINE_DOC_DOCUMENTS_ITERATOR_H_INCLUDED
#define OBJDOCENGINE_DOC_DOCUMENTS_ITERATOR_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_forward_declarations.h>

@interface SEDocumentsIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocumentsIterator *)other;
- (BOOL) isEqualToIter:(nonnull SEDocumentsIterator *)other;

- (int) getID;
- (nonnull SEDocumentRef *) getDocument;
- (nonnull SEDocTagsCollectionRef *) getTags;

- (void) advance;

@end


@interface SEDocumentsMutableIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocumentsMutableIterator *)other;
- (BOOL) isEqualToIter:(nonnull SEDocumentsMutableIterator *)other;

- (int) getID;
- (nonnull SEDocumentRef *) getDocument;
- (nonnull SEDocumentRef *) getMutableDocument;
- (nonnull SEDocTagsCollectionRef *) getTags;

- (void) advance;

@end


@interface SEDocumentsSliceIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocumentsSliceIterator *)other;

- (int) getID;
- (nonnull SEDocumentRef *) getDocument;
- (nonnull SEDocTagsCollectionRef *) getTags;

- (void) advance;
- (BOOL) finished;

@end


@interface SEDocumentsMutableSliceIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocumentsMutableSliceIterator *)other;

- (int) getID;
- (nonnull SEDocumentRef *) getDocument;
- (nonnull SEDocumentRef *) getMutableDocument;
- (nonnull SEDocTagsCollectionRef *) getTags;

- (void) advance;
- (BOOL) finished;

@end

#endif // OBJDOCENGINE_DOC_DOCUMENTS_ITERATOR_H_INCLUDED