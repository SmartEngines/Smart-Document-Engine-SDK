/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_RESULT_H_INCLUDED
#define OBJCDOCENGINE_DOC_RESULT_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_forward_declarations.h>
#import <objcdocengine/doc_documents_iterator.h>

@interface SEDocResultRef : NSObject

- (BOOL) isMutable;

- (nonnull SEDocGraphicalStructureRef *) getGraphicalStructure;
- (nonnull SEDocGraphicalStructureRef *) getMutableGraphicalStructure;

- (int) getDocumentsCount;
- (BOOL) hasDocumentWithID:(int)doc_id;
- (nonnull SEDocumentRef *) getDocumentWithID:(int)doc_id;
- (nonnull SEDocumentRef *) getMutableDocumentWithID:(int)doc_id;
- (nonnull SEDocTagsCollectionRef *) getDocumentTagsWithID:(int)doc_id;
- (void) removeDocumentWithID:(int)doc_id;

- (nonnull SEDocumentsIterator *) documentsBegin;
- (nonnull SEDocumentsIterator *) documentsEnd;

- (nonnull SEDocumentsMutableIterator *) mutableDocumentsBegin;
- (nonnull SEDocumentsMutableIterator *) mutableDocumentsEnd;

- (nonnull SEDocumentsSliceIterator *) documentsSliceForTag:(nonnull NSString *)tag;
- (nonnull SEDocumentsMutableSliceIterator *) mutableDocumentsSliceForTag:(nonnull NSString *)tag;

- (void) serialize:(nonnull SECommonSerializer *)serializer;

- (BOOL) canBuildPDFABuffer;
- (nonnull NSData *) getPDFABuffer;

- (nonnull SEDocPhysicalDocumentRef *) getPhysicalDocument:(int)doc_id;
- (nonnull SEDocPhysicalDocumentRef *) getMutablePhysicalDocument:(int)doc_id;

- (nonnull NSData *) fillPDFABufferDEMO:
               (nullable int *)size0
               andSize1:(nullable int *)size1
               andSize2:(nullable int *)size2;



@end

#endif // OBJCDOCENGINE_DOC_RESULT_H_INCLUDED
