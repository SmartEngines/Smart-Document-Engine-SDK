/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_FIELDS_ITERATORS_H_INCLUDED
#define OBJCDOCENGINE_DOC_FIELDS_ITERATORS_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_forward_declarations.h>

@interface SEDocTextFieldsIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocTextFieldsIterator *)other;
- (BOOL) isEqualToIter:(nonnull SEDocTextFieldsIterator *)other;

- (nonnull NSString *) getKey;
- (nonnull SEDocTextFieldRef *) getField;

- (void) advance;

@end


@interface SEDocImageFieldsIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocImageFieldsIterator *)other;
- (BOOL) isEqualToIter:(nonnull SEDocImageFieldsIterator *)other;

- (nonnull NSString *) getKey;
- (nonnull SEDocImageFieldRef *) getField;

- (void) advance;

@end


@interface SEDocCheckboxFieldsIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocCheckboxFieldsIterator *)other;
- (BOOL) isEqualToIter:(nonnull SEDocCheckboxFieldsIterator *)other;

- (nonnull NSString *) getKey;
- (nonnull SEDocCheckboxFieldRef *) getField;

- (void) advance;

@end


@interface SEDocForensicFieldsIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocForensicFieldsIterator *)other;
- (BOOL) isEqualToIter:(nonnull SEDocForensicFieldsIterator *)other;

- (nonnull NSString *) getKey;
- (nonnull SEDocForensicFieldRef *) getField;

- (void) advance;

@end


@interface SEDocForensicCheckFieldsIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocForensicCheckFieldsIterator *)other;
- (BOOL) isEqualToIter:(nonnull SEDocForensicCheckFieldsIterator *)other;

- (nonnull NSString *) getKey;
- (nonnull SEDocForensicCheckFieldRef *) getField;

- (void) advance;

@end


@interface SEDocTableFieldsIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocTableFieldsIterator *)other;
- (BOOL) isEqualToIter:(nonnull SEDocTableFieldsIterator *)other;

- (nonnull NSString *) getKey;
- (nonnull SEDocTableFieldRef *) getField;

- (void) advance;

@end


@interface SEDocBarcodeFieldsIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocBarcodeFieldsIterator *)other;
- (BOOL) isEqualToIter:(nonnull SEDocBarcodeFieldsIterator *)other;

- (nonnull NSString *) getKey;
- (nonnull SEDocBarcodeFieldRef *) getField;

- (void) advance;

@end


#endif // OBJCDOCENGINE_DOC_FIELDS_ITERATORS_H_INCLUDED
