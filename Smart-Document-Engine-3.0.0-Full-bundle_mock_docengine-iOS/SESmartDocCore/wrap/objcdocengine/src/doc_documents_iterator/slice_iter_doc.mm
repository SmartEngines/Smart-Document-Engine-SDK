/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_documents_iterator_impl.h>

#import <objcdocengine_impl/doc_document_impl.h>
#import <objcdocengine_impl/doc_tags_collection_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocumentsSliceIterator {
  std::unique_ptr<se::doc::DocumentsSliceIterator> internal;
}

- (instancetype) initFromInternalDocumentsSliceIterator:(const se::doc::DocumentsSliceIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocumentsSliceIterator(iter));
  }
  return self;
}

- (const se::doc::DocumentsSliceIterator &) getInternalDocumentsSliceIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocumentsSliceIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocumentsSliceIterator([other getInternalDocumentsSliceIterator]));
  }
  return self;
}

- (int) getID {
  return internal->GetID();
}

- (SEDocumentRef *) getDocument {
  return [[SEDocumentRef alloc]
      initFromInternalDocumentPointer:const_cast<se::doc::Document*>(&internal->GetDocument())
                   withMutabilityFlag:NO];
}

- (SEDocTagsCollectionRef *) getTags {
  return [[SEDocTagsCollectionRef alloc]
      initFromInternalTagsCollectionPointer:const_cast<se::doc::DocTagsCollection*>(&internal->GetTags())
                         withMutabilityFlag:NO];
}

- (void) advance {
  internal->Advance();
}

- (BOOL) finished {
  return internal->Finished()? YES : NO;
}

@end


@implementation SEDocumentsMutableSliceIterator {
  std::unique_ptr<se::doc::DocumentsMutableSliceIterator> internal;
}

- (instancetype) initFromInternalDocumentsMutableSliceIterator:(const se::doc::DocumentsMutableSliceIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocumentsMutableSliceIterator(iter));
  }
  return self;
}

- (const se::doc::DocumentsMutableSliceIterator &) getInternalDocumentsMutableSliceIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocumentsMutableSliceIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocumentsMutableSliceIterator([other getInternalDocumentsMutableSliceIterator]));
  }
  return self;
}

- (int) getID {
  return internal->GetID();
}

- (SEDocumentRef *) getDocument {
  return [[SEDocumentRef alloc]
      initFromInternalDocumentPointer:const_cast<se::doc::Document*>(&internal->GetDocument())
                   withMutabilityFlag:NO];
}

- (SEDocumentRef *) getMutableDocument {
  return [[SEDocumentRef alloc]
      initFromInternalDocumentPointer:&internal->GetMutableDocument()
                   withMutabilityFlag:YES];
}

- (SEDocTagsCollectionRef *) getTags {
  return [[SEDocTagsCollectionRef alloc]
      initFromInternalTagsCollectionPointer:const_cast<se::doc::DocTagsCollection*>(&internal->GetTags())
                         withMutabilityFlag:NO];
}

- (void) advance {
  internal->Advance();
}

- (BOOL) finished {
  return internal->Finished()? YES : NO;
}

@end
