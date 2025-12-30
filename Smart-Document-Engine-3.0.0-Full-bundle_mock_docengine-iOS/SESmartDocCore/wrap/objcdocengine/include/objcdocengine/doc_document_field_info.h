/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_DOCUMENT_FIELD_INFO_H_INCLUDED
#define OBJCDOCENGINE_DOC_DOCUMENT_FIELD_INFO_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>

@interface SEDocDocumentFieldsInfoRef : NSObject

- (nonnull NSString *) getDocumentFieldName;
- (nonnull NSString *) getDocumentFieldNameLocal;
- (nonnull NSString *) getDocumentFieldShortNameLocal;
//- (nonnull NSString *) getDocumentFieldFormat;
//- (nonnull NSString *) getDocumentFieldExtFormat;
//- (nonnull NSString *) getDocumentFieldType;
@end

#endif // OBJCDOCENGINE_DOC_DOCUMENT_FIELD_INFO_H_INCLUDED
