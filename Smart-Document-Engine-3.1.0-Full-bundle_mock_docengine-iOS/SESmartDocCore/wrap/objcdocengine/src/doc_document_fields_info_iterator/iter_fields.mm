/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_document_fields_info_iterator_impl.h>

#import <objcdocengine_impl/doc_document_fields_info_impl.h>
#import <objcdocengine_impl/doc_tags_collection_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocDocumentFieldsInfoIterator {
  std::unique_ptr<se::doc::DocDocumentFieldsInfoIterator> internal;
}

- (instancetype) initFromInternalDocDocumentFieldsInfoIterator:(const se::doc::DocDocumentFieldsInfoIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocDocumentFieldsInfoIterator(iter));
  }
  return self;
}

- (const se::doc::DocDocumentFieldsInfoIterator &) getInternalDocumentFieldsInfoIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocDocumentFieldsInfoIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocDocumentFieldsInfoIterator([other getInternalDocumentFieldsInfoIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocDocumentFieldsInfoIterator *)other {
  return internal->Equals([other getInternalDocumentFieldsInfoIterator])? YES : NO;
}

- (NSString *) getKey {
  return [NSString stringWithUTF8String:internal->GetKey()];
}

- (void) advance {
  internal->Advance();
}

- (nonnull SEDocDocumentFieldsInfoRef *) getDocumentFieldInfo {
  return [[SEDocDocumentFieldsInfoRef alloc]
          initFromInternalDocumentFieldInfoPointer:
            const_cast<se::doc::DocDocumentFieldInfo*>(&internal->GetDocumentFieldInfo())
          withMutabilityFlag:NO];
}

@end
