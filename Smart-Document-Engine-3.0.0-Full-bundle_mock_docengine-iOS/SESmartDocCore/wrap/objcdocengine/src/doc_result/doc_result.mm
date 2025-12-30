/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_result_impl.h>

#import <objcdocengine_impl/doc_graphical_structure_impl.h>
#import <objcdocengine_impl/doc_document_impl.h>
#import <objcdocengine_impl/doc_tags_collection_impl.h>
#import <objcdocengine_impl/doc_documents_iterator_impl.h>
#import <objcdocengine_impl/doc_physical_document_impl.h>

#import <objcsecommon_impl/se_serialization_impl.h>
#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocResultRef {
  se::doc::DocResult* ptr;
  bool is_mutable;
}

- (instancetype) initFromInternalResultPointer:(se::doc::DocResult *)resptr
                            withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = resptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocResult *) getInternalResultPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (SEDocGraphicalStructureRef *) getGraphicalStructure {
  return [[SEDocGraphicalStructureRef alloc]
      initFromInternalGraphicalStructurePointer:const_cast<se::doc::DocGraphicalStructure*>(&ptr->GetGraphicalStructure())
                             withMutabilityFlag:NO];
}

- (SEDocGraphicalStructureRef *) getMutableGraphicalStructure {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    return [[SEDocGraphicalStructureRef alloc]
        initFromInternalGraphicalStructurePointer:&ptr->GetMutableGraphicalStructure()
                               withMutabilityFlag:YES];
  }
  return nil;
}

- (int) getDocumentsCount {
  return ptr->GetDocumentsCount();
}

- (BOOL) hasDocumentWithID:(int)doc_id {
  return ptr->HasDocument(doc_id)? YES : NO;
}

- (SEDocumentRef *) getDocumentWithID:(int)doc_id {
  try {
    return [[SEDocumentRef alloc]
        initFromInternalDocumentPointer:const_cast<se::doc::Document*>(&ptr->GetDocument(doc_id))
                     withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SEDocumentRef *) getMutableDocumentWithID:(int)doc_id {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocumentRef alloc]
          initFromInternalDocumentPointer:&ptr->GetMutableDocument(doc_id)
                       withMutabilityFlag:YES];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (SEDocTagsCollectionRef *) getDocumentTagsWithID:(int)doc_id {
  try {
    return [[SEDocTagsCollectionRef alloc]
        initFromInternalTagsCollectionPointer:const_cast<se::doc::DocTagsCollection*>(&ptr->GetDocumentTags(doc_id))
                           withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (void) removeDocumentWithID:(int)doc_id {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->RemoveDocument(doc_id);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (SEDocumentsIterator *) documentsBegin {
  return [[SEDocumentsIterator alloc]
      initFromInternalDocumentsIterator:ptr->DocumentsBegin()];
}

- (SEDocumentsIterator *) documentsEnd {
  return [[SEDocumentsIterator alloc]
      initFromInternalDocumentsIterator:ptr->DocumentsEnd()];
}

- (SEDocumentsMutableIterator *) mutableDocumentsBegin {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    return [[SEDocumentsMutableIterator alloc]
        initFromInternalDocumentsMutableIterator:ptr->MutableDocumentsBegin()];
  }
  return nil;
}

- (SEDocumentsMutableIterator *) mutableDocumentsEnd {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    return [[SEDocumentsMutableIterator alloc]
        initFromInternalDocumentsMutableIterator:ptr->MutableDocumentsEnd()];
  }
  return nil;
}

- (SEDocumentsSliceIterator *) documentsSliceForTag:(NSString *)tag {
  try {
    return [[SEDocumentsSliceIterator alloc]
        initFromInternalDocumentsSliceIterator:ptr->DocumentsSlice([tag UTF8String])];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SEDocumentsMutableSliceIterator *) mutableDocumentsSliceForTag:(NSString *)tag {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocumentsMutableSliceIterator alloc]
          initFromInternalDocumentsMutableSliceIterator:ptr->MutableDocumentsSlice([tag UTF8String])];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (void) serialize:(SECommonSerializer *)serializer {
  ptr->Serialize([serializer getInternalSerializer]);
}

- (SEDocPhysicalDocumentRef *) getMutablePhysicalDocument:(int)doc_id {
  try {
    return [[SEDocPhysicalDocumentRef alloc]
            initFromInternalPhysicalDocumentPointer:const_cast<se::doc::DocPhysicalDocument*>(&ptr->GetPhysicalDocument(doc_id))
                     withMutabilityFlag:YES];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SEDocPhysicalDocumentRef *) getPhysicalDocument:(int)doc_id {
  try {
    return [[SEDocPhysicalDocumentRef alloc]
            initFromInternalPhysicalDocumentPointer:const_cast<se::doc::DocPhysicalDocument*>(&ptr->GetPhysicalDocument(doc_id))
                     withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (BOOL) getPDFAColourMode {
  return ptr->GetColourMode()? YES : NO;
}

- (void) setPDFAColourModeTo:(BOOL)with_colour {
  try {
    if (is_mutable) {
      ptr->SetColourMode(YES == with_colour);
    } else {
      throwNonMutableRefException();
    }
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
}

- (NSData *) getPDFABuffer{
  try {
    if (is_mutable) {
      NSLog(@"Result is mutable, starting creating pdf");
      ptr->BuildPDFABuffer();
      int buf_size = ptr->GetPDFABufferSize();
      unsigned char * buf = new unsigned char[ptr->GetPDFABufferSize()];
      ptr->GetPDFABuffer(buf, buf_size);
      NSData* buf_data = [NSData dataWithBytes:buf length:buf_size];
      return buf_data;
    } else {
      NSLog(@"Result is unmutable");
      throwNonMutableRefException();
    }
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (nonnull NSData *) fillPDFABufferDEMO:(nullable int *)size0
                               andSize1:(nullable int *)size1
                               andSize2:(nullable int *)size2 {
  try{
    if (is_mutable) {
      NSLog(@"Result is mutable, starting creating pdf");
      ptr->BuildPDFABuffer();
      int buf_size = ptr->GetPDFABufferSize();
      unsigned char * buf0 = new unsigned char[buf_size];
      ptr->GetPDFABuffer(buf0, buf_size);
      NSData* buf_data = [NSData dataWithBytes:(buf0 + 12) length:buf_size - 12];
      
      *size0 = (int)buf0[0] * 16777216  + (int)buf0[1] * 65536 + (int)buf0[2] * 256 + (int)buf0[3];
      *size1 = (int)buf0[4] * 16777216  + (int)buf0[5] * 65536 + (int)buf0[6] * 256 + (int)buf0[7];
      *size2 = (int)buf0[8] * 16777216  + (int)buf0[9] * 65536 + (int)buf0[10] * 256 + (int)buf0[11];
      return buf_data;
    } else {
      NSLog(@"Result is unmutable");
      throwNonMutableRefException();
    }
  }catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
  
}

- (BOOL) canBuildPDFABuffer{
  return ptr->CanBuildPDFABuffer();
}

@end
