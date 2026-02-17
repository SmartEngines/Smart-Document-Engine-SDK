/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_document_info_impl.h>
#import <objcdocengine_impl/doc_document_fields_info_iterator_impl.h>

@implementation SEDocDocumentInfoRef {
  se::doc::DocDocumentInfo* ptr;
  bool is_mutable;
}

- (instancetype) initFromInternalDocumentInfoPointer:(se::doc::DocDocumentInfo *)infoptr 
                                  withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = infoptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocDocumentInfo *) getInternalDocumentInfoPointer {
  return ptr;
}

- (NSString *) getDocumentName {
  return [NSString stringWithUTF8String:ptr->GetDocumentName()];
}

- (NSString *) getDocumentNameLocal {
  return [NSString stringWithUTF8String:ptr->GetDocumentNameLocal()];
}

- (NSString *) getDocumentShortNameLocal {
  return [NSString stringWithUTF8String:ptr->GetDocumentShortNameLocal()];
}

- (SEDocDocumentFieldsInfoIterator *) documentFieldsInfoBegin {
  return [[SEDocDocumentFieldsInfoIterator alloc]
          initFromInternalDocDocumentFieldsInfoIterator:ptr->DocumentFieldsInfoBegin()];
}

- (SEDocDocumentFieldsInfoIterator *) documentFieldsInfoEnd {
    return [[SEDocDocumentFieldsInfoIterator alloc]
        initFromInternalDocDocumentFieldsInfoIterator:ptr->DocumentFieldsInfoEnd()];
}

- (BOOL) getDocumentMultipageInfo {
  return ptr->GetDocumentMultipageInfo()? YES : NO;
}

@end
