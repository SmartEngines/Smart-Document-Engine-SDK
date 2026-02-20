/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_DOCUMENT_INFO_H_INCLUDED
#define OBJCDOCENGINE_DOC_DOCUMENT_INFO_H_INCLUDED

#import <Foundation/Foundation.h>
#import <objcdocengine/doc_document_fields_info_iterator.h>

@interface SEDocDocumentInfoRef : NSObject 

- (nonnull NSString *) getDocumentName;
- (nonnull NSString *) getDocumentNameLocal;
- (nonnull NSString *) getDocumentShortNameLocal;
- (BOOL) getDocumentMultipageInfo;
- (nonnull SEDocDocumentFieldsInfoIterator *) documentFieldsInfoBegin;
- (nonnull SEDocDocumentFieldsInfoIterator *) documentFieldsInfoEnd;

@end

#endif // OBJCDOCENGINE_DOC_DOCUMENT_INFO_H_INCLUDED
