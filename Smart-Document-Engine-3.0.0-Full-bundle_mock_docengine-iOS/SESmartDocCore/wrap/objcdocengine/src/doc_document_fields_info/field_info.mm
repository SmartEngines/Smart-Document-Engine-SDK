/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_document_fields_info_impl.h>

@implementation SEDocDocumentFieldsInfoRef {
  se::doc::DocDocumentFieldInfo* ptr;
  bool is_mutable;
}

- (instancetype) initFromInternalDocumentFieldInfoPointer:(se::doc::DocDocumentFieldInfo *)infoptr
                                           withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = infoptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocDocumentFieldInfo *) getInternalDocumentInfoPointer {
  return ptr;
}
- (NSString *) getDocumentFieldName {
  return [NSString stringWithUTF8String:ptr->GetDocumentFieldName()];
}

- (nonnull NSString *)getDocumentFieldNameLocal {
  return [NSString stringWithUTF8String:ptr->GetDocumentFieldNameLocal()];
}

- (nonnull NSString *)getDocumentFieldShortNameLocal {
  return [NSString stringWithUTF8String:ptr->GetDocumentFieldShortNameLocal()];
}

@end
