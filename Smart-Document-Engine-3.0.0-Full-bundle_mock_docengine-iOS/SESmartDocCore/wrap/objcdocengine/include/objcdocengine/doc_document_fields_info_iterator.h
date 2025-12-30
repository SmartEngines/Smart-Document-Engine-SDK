/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_DOCUMENT_FIELDS_INFO_ITERATOR_H_INCLUDED
#define OBJCDOCENGINE_DOC_DOCUMENT_FIELDS_INFO_ITERATOR_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_forward_declarations.h>
#import <objcdocengine/doc_document_field_info.h>

@interface SEDocDocumentFieldsInfoIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocDocumentFieldsInfoIterator *)other;
- (BOOL) isEqualToIter:(nonnull SEDocDocumentFieldsInfoIterator *)other;
- (nonnull NSString *) getKey;
- (void) advance;
- (nonnull SEDocDocumentFieldsInfoRef *) getDocumentFieldInfo;

@end

#endif // OBJCDOCENGINE_DOC_DOCUMENT_FIELDS_INFO_ITERATOR_H_INCLUDED
