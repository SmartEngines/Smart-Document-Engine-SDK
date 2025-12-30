/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_OBJECTS_H_INCLUDED
#define OBJCDOCENGINE_DOC_OBJECTS_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_forward_declarations.h>
#import <objcdocengine/doc_basic_object.h>


@interface SEDocTextLineObjectRef : NSObject

+ (nonnull NSString *) objectTypeStatic;

- (BOOL) isMutable;

- (nonnull SECommonOcrString *) getOcrString;

- (nonnull SEDocBaseObjectInfoRef*) getBaseObjectInfo;

@end


@interface SEDocTextObjectRef : NSObject

+ (nonnull NSString *) objectTypeStatic;

- (BOOL) isMutable;

- (nonnull SECommonOcrString *) getOcrString;
- (void) setOcrStringTo:(nonnull SECommonOcrString *)ocrstring;

- (int) getTextLineObjectsCount;
- (nonnull SEDocTextLineObjectRef *) getTextLineObjectAt:(int)index;

- (nonnull SEDocBaseObjectInfoRef*) getBaseObjectInfo;

@end


@interface SEDocForensicCheckObjectRef : NSObject

+ (nonnull NSString *) objectTypeStatic;

- (BOOL) isMutable;

- (nonnull SECommonOcrString *) getOcrString;

- (nonnull SEDocBaseObjectInfoRef*) getBaseObjectInfo;

@end


@interface SEDocCheckboxObjectRef : NSObject

+ (nonnull NSString *) objectTypeStatic;

- (BOOL) isMutable;

- (nonnull SECommonOcrString *) getOcrString;
- (void) setOcrStringTo:(nonnull SECommonOcrString *)ocrstring;

- (nonnull SEDocBaseObjectInfoRef*) getBaseObjectInfo;

@end


@interface SEDocTemplateObjectRef : NSObject

+ (nonnull NSString *) objectTypeStatic;

- (BOOL) isMutable;

- (nonnull SEDocBaseObjectInfoRef*) getBaseObjectInfo;

@end


@interface SEDocLineObjectRef : NSObject

+ (nonnull NSString *) objectTypeStatic;

- (BOOL) isMutable;

- (nonnull SEDocBaseObjectInfoRef*) getBaseObjectInfo;

@end


@interface SEDocZoneObjectRef : NSObject

+ (nonnull NSString *) objectTypeStatic;

- (BOOL) isMutable;

- (nonnull SECommonSize *) getSize;
- (void) setSizeTo:(nonnull SECommonSize *)size;

- (nonnull SEDocBaseObjectInfoRef*) getBaseObjectInfo;

@end


@interface SEDocMultiStringTextObjectRef : NSObject

+ (nonnull NSString *) objectTypeStatic;

- (BOOL) isMutable;

- (int) getStringsCount;
- (void) setStringsCountTo:(int)count;

- (nonnull SEDocTextObjectRef *) getStringObjectAt:(int)index;
- (nonnull SEDocTextObjectRef *) getMutableStringObjectAt:(int)index;

- (nonnull SEDocBaseObjectInfoRef*) getBaseObjectInfo;

@end


@interface SEDocMetaObjectRef : NSObject

+ (nonnull NSString *) objectTypeStatic;

- (BOOL) isMutable;

- (nonnull SECommonOcrString *) getOcrString;
- (void) setOcrStringTo:(nonnull SECommonOcrString *)ocrstring;

- (nonnull SEDocBaseObjectInfoRef*) getBaseObjectInfo;

@end


@interface SEDocTableObjectRef : NSObject

+ (nonnull NSString *) objectTypeStatic;

- (BOOL) isMutable;

- (int) getRowsCount;
- (int) getColsCountForRow:(int)row;

- (nonnull SEDocMultiStringTextObjectRef *) getCellAtRow:(int)row
                                                   atCol:(int)col;
- (nonnull SEDocMultiStringTextObjectRef *) getMutableCellAtRow:(int)row
                                                          atCol:(int)col;

- (void) resizeRowsTo:(int)rows;
- (void) resizeColsAtRow:(int)row
                      to:(int)cols;

- (nonnull NSString *) getColNameForCol:(int)col
                                 forRow:(int)row;
- (void) setColNameForCol:(int)col
             withFirstRow:(int)first_row
                       to:(nonnull NSString *)col_name;

- (nonnull SEDocBaseObjectInfoRef*) getBaseObjectInfo;

@end


@interface SEDocImageObjectRef : NSObject

+ (nonnull NSString *) objectTypeStatic;

- (BOOL) isMutable;

- (nonnull SEDocBaseObjectInfoRef*) getBaseObjectInfo;

@end


@interface SEDocBarcodeObjectRef : NSObject

+ (nonnull NSString *) objectTypeStatic;

- (BOOL) isMutable;

- (nonnull NSString *) getDecodedString;
- (nonnull NSString *) getMutableDecodedString;
- (void) setDecodedString:(nonnull NSString *)decstring;

- (nonnull SEDocBaseObjectInfoRef*) getBaseObjectInfo;

@end


@interface SEDocMarkObjectRef : NSObject

+ (nonnull NSString *) objectTypeStatic;

- (BOOL) isMutable;

- (nonnull SEDocBaseObjectInfoRef*) getBaseObjectInfo;

@end


#endif // OBJCDOCENGINE_DOC_OBJECTS_H_INCLUDED
