/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_documents_iterator_impl.h>

#import <objcdocengine_impl/doc_document_impl.h>
#import <objcdocengine_impl/doc_tags_collection_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocumentsIterator {
  std::unique_ptr<se::doc::DocumentsIterator> internal;
}

- (instancetype) initFromInternalDocumentsIterator:(const se::doc::DocumentsIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocumentsIterator(iter));
  }
  return self;
}

- (const se::doc::DocumentsIterator &) getInternalDocumentsIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocumentsIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocumentsIterator([other getInternalDocumentsIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocumentsIterator *)other {
  return internal->Equals([other getInternalDocumentsIterator])? YES : NO;
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

@end


@implementation SEDocumentsMutableIterator {
  std::unique_ptr<se::doc::DocumentsMutableIterator> internal;
}

- (instancetype) initFromInternalDocumentsMutableIterator:(const se::doc::DocumentsMutableIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocumentsMutableIterator(iter));
  }
  return self;
}

- (const se::doc::DocumentsMutableIterator &) getInternalDocumentsMutableIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocumentsMutableIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocumentsMutableIterator([other getInternalDocumentsMutableIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocumentsMutableIterator *)other {
  return internal->Equals([other getInternalDocumentsMutableIterator])? YES : NO;
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

@end
