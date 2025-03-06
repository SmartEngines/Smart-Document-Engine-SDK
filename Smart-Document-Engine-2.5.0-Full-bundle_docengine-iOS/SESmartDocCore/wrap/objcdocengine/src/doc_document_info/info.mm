/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_document_info_impl.h>

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

- (BOOL) getDocumentMultipageInfo {
  return ptr->GetDocumentMultipageInfo()? YES : NO;
}




@end
