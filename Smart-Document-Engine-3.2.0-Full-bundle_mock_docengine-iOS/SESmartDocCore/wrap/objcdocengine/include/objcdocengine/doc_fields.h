/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_FIELDS_H_INCLUDED
#define OBJCDOCENGINE_DOC_FIELDS_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>

#import <objcdocengine/doc_forward_declarations.h>
#import <objcdocengine/doc_basic_objects_iterator.h>

@interface SEDocBaseFieldInfoRef : NSObject

- (BOOL) isMutable;

- (nonnull NSString *) getName;
- (void) setNameTo:(nonnull NSString *)name;

- (double) getConfidence;
- (void) setConfidenceTo:(double)confidence;

- (BOOL) getAcceptFlag;
- (void) setAcceptFlatTo:(BOOL)is_accepted;

- (BOOL) isFictive;

- (int) getAttributesCount;
- (BOOL) hasAttributeWithName:(nonnull NSString *)attr_name;
- (nonnull NSString *) getAttributeWithName:(nonnull NSString *)attr_name;
- (void) setAttributeWithName:(nonnull NSString *)attr_name
                           to:(nonnull NSString *)attr_value;
- (void) removeAttributeWithName:(nonnull NSString *)attr_name;
- (nonnull SECommonStringsMapIterator *) attributesBegin;
- (nonnull SECommonStringsMapIterator *) attributesEnd;

- (void) connectBasicObjectWithCollectionID:(int)coll_id
                               withObjectID:(int)obj_id;

- (nonnull SEDocBasicObjectsCrossSliceIterator *) connectedBasicObjectsFromGraphicalStructureBegin:(nonnull SEDocGraphicalStructureRef *)graphical;
- (nonnull SEDocBasicObjectsCrossSliceIterator *) connectedBasicObjectsFromGraphicalStructureEnd:(nonnull SEDocGraphicalStructureRef *)graphical;

- (nonnull SEDocBasicObjectsMutableCrossSliceIterator *) mutableConnectedBasicObjectsFromGraphicalStructureBegin:(nonnull SEDocGraphicalStructureRef *)graphical;
- (nonnull SEDocBasicObjectsMutableCrossSliceIterator *) mutableConnectedBasicObjectsFromGraphicalStructureEnd:(nonnull SEDocGraphicalStructureRef *)graphical;

- (void) serialize:(nonnull SECommonSerializer *)serializer;

@end


@interface SEDocTextFieldRef : NSObject 

- (BOOL) isMutable;

- (nonnull SEDocBaseFieldInfoRef *) getBaseFieldInfo;
- (nonnull SEDocBaseFieldInfoRef *) getMutableBaseFieldInfo;

- (nonnull SECommonOcrString *) getOcrString;
- (void) setOcrStringTo:(nonnull SECommonOcrString *)ocrstring;

- (void) serialize:(nonnull SECommonSerializer *)serializer;

@end


@interface SEDocImageFieldRef : NSObject 

- (BOOL) isMutable;

- (nonnull SEDocBaseFieldInfoRef *) getBaseFieldInfo;
- (nonnull SEDocBaseFieldInfoRef *) getMutableBaseFieldInfo;

- (nonnull SECommonImageRef *) getImage;
- (nonnull SECommonImageRef *) getMutableImage;
- (void) setImageTo:(nonnull SECommonImageRef *)image;

- (void) serialize:(nonnull SECommonSerializer *)serializer;

@end


@interface SEDocCheckboxFieldRef : NSObject 

- (BOOL) isMutable;

- (nonnull SEDocBaseFieldInfoRef *) getBaseFieldInfo;
- (nonnull SEDocBaseFieldInfoRef *) getMutableBaseFieldInfo;

- (BOOL) getTickStatus;
- (void) setTickStatusTo:(BOOL)tick_status;

- (void) serialize:(nonnull SECommonSerializer *)serializer;

@end


@interface SEDocForensicFieldRef : NSObject 

- (BOOL) isMutable;

- (nonnull SEDocBaseFieldInfoRef *) getBaseFieldInfo;
- (nonnull SEDocBaseFieldInfoRef *) getMutableBaseFieldInfo;

- (nonnull NSString *) getStatus;
- (void) setStatusTo:(nonnull NSString *)status;

- (void) serialize:(nonnull SECommonSerializer *)serializer;

@end


@interface SEDocForensicCheckFieldRef : NSObject

- (BOOL) isMutable;

- (nonnull SEDocBaseFieldInfoRef *) getBaseFieldInfo;
- (nonnull SEDocBaseFieldInfoRef *) getMutableBaseFieldInfo;

- (nonnull NSString *) getStatus;
- (void) setStatusTo:(nonnull NSString *)status;

- (void) serialize:(nonnull SECommonSerializer *)serializer;

@end


@interface SEDocTableFieldRef : NSObject

- (BOOL) isMutable;

- (nonnull SEDocBaseFieldInfoRef *) getBaseFieldInfo;
- (nonnull SEDocBaseFieldInfoRef *) getMutableBaseFieldInfo;

- (int) getRowsCount;
- (int) getColsCount;
- (nonnull SEDocTextFieldRef *) getCellAtRow:(int)row
                                       atCol:(int)col;
- (nonnull SEDocTextFieldRef *) getMutableCellAtRow:(int)row
                                              atCol:(int)col;

- (nonnull NSString *) getColNameFor:(int)col;
- (void) setColNameFor:(int)col
                    to:(nonnull NSString *)col_name;

- (void) serialize:(nonnull SECommonSerializer *)serializer;

@end


@interface SEDocBarcodeFieldRef : NSObject

- (BOOL) isMutable;

- (nonnull SEDocBaseFieldInfoRef *) getBaseFieldInfo;
- (nonnull SEDocBaseFieldInfoRef *) getMutableBaseFieldInfo;

- (nonnull NSString *) getDecodedString;
- (nonnull NSString *) getMutableDecodedString;
- (void) setDecodedString:(nonnull NSString *)decstring;

- (void) serialize:(nonnull SECommonSerializer *)serializer;

@end


#endif // OBJCDOCENGINE_DOC_FIELDS_H_INCLUDED
