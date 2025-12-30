/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_DOCUMENT_H_INCLUDED
#define OBJCDOCENGINE_DOC_DOCUMENT_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>

#import <objcdocengine/doc_fields.h>
#import <objcdocengine/doc_fields_iterators.h>

@interface SEDocumentRef : NSObject

+ (nonnull NSString *) baseClassNameStatic;

- (BOOL) isMutable;

- (int) getTextFieldsCount;
- (BOOL) hasTextFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocTextFieldRef *) getTextFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocTextFieldRef *) getMutableTextFieldWithName:(nonnull NSString *)name;
- (void) removeTextFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocTextFieldsIterator *) textFieldsBegin;
- (nonnull SEDocTextFieldsIterator *) textFieldsEnd;

- (int) getImageFieldsCount;
- (BOOL) hasImageFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocImageFieldRef *) getImageFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocImageFieldRef *) getMutableImageFieldWithName:(nonnull NSString *)name;
- (void) removeImageFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocImageFieldsIterator *) imageFieldsBegin;
- (nonnull SEDocImageFieldsIterator *) imageFieldsEnd;

- (int) getCheckboxFieldsCount;
- (BOOL) hasCheckboxFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocCheckboxFieldRef *) getCheckboxFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocCheckboxFieldRef *) getMutableCheckboxFieldWithName:(nonnull NSString *)name;
- (void) removeCheckboxFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocCheckboxFieldsIterator *) checkboxFieldsBegin;
- (nonnull SEDocCheckboxFieldsIterator *) checkboxFieldsEnd;

- (int) getForensicFieldsCount;
- (BOOL) hasForensicFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocForensicFieldRef *) getForensicFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocForensicFieldRef *) getMutableForensicFieldWithName:(nonnull NSString *)name;
- (void) removeForensicFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocForensicFieldsIterator *) forensicFieldsBegin;
- (nonnull SEDocForensicFieldsIterator *) forensicFieldsEnd;

- (int) getForensicCheckFieldsCount;
- (BOOL) hasForensicCheckFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocForensicCheckFieldRef *) getForensicCheckFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocForensicCheckFieldRef *) getMutableForensicCheckFieldWithName:(nonnull NSString *)name;
- (void) removeForensicCheckFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocForensicCheckFieldsIterator *) forensicCheckFieldsBegin;
- (nonnull SEDocForensicCheckFieldsIterator *) forensicCheckFieldsEnd;

- (int) getTableFieldsCount;
- (BOOL) hasTableFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocTableFieldRef *) getTableFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocTableFieldRef *) getMutableTableFieldWithName:(nonnull NSString *)name;
- (void) removeTableFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocTableFieldsIterator *) tableFieldsBegin;
- (nonnull SEDocTableFieldsIterator *) tableFieldsEnd;

- (int) getBarcodeFieldsCount;
- (BOOL) hasBarcodeField:(nonnull NSString *)name;
- (nonnull SEDocBarcodeFieldRef *) getBarcodeFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocBarcodeFieldRef *) getMutableBarcodeFieldWithName:(nonnull NSString *)name;
- (void) removeBarcodeFieldWithName:(nonnull NSString *)name;
- (nonnull SEDocBarcodeFieldsIterator *) barcodeFieldsBegin;
- (nonnull SEDocBarcodeFieldsIterator *) barcodeFieldsEnd;

- (int) getAttributesCount;
- (BOOL) hasAttributeWithName:(nonnull NSString *)attr_name;
- (nonnull NSString *) getAttributeWithName:(nonnull NSString *)attr_name;
- (void) setAttributeWithName:(nonnull NSString *)attr_name
                           to:(nonnull NSString *)attr_value;
- (void) removeAttributeWithName:(nonnull NSString *)attr_name;
- (nonnull SECommonStringsMapIterator *) attributesBegin;
- (nonnull SECommonStringsMapIterator *) attributesEnd;

- (void) serialize:(nonnull SECommonSerializer *)serializer;

- (int) getPhysicalDocIdx;
@end

#endif // OBJCDOCENGINE_DOC_DOCUMENT_H_INCLUDED
