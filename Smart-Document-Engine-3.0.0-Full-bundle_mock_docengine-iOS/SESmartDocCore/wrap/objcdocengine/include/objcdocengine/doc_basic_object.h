/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_BASIC_OBJECT_H_INCLUDED
#define OBJCDOCENGINE_DOC_BASIC_OBJECT_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcdocengine/doc_forward_declarations.h>

#import <objcsecommon/se_common.h>

@interface SEDocBaseObjectInfoRef : NSObject

- (BOOL) isMutable;

- (int) getViewID;
- (void) setViewIDTo:(int)view_id;

- (double) getConfidence;
- (void) setConfidenceTo:(double)conf;
 
- (BOOL) getAcceptFlag;
- (void) setAcceptFlagTo:(BOOL)is_accepted;

- (nonnull SECommonPolygon *) getGeometry;
- (void) setGeometryTo:(nonnull SECommonPolygon *)geometry;

- (int) getAttributesCount;
- (BOOL) hasAttributeWithName:(nonnull NSString *)attr_name;
- (nonnull NSString *) getAttributeWithName:(nonnull NSString *)attr_name;
- (void) setAttributeWithName:(nonnull NSString *)attr_name
                           to:(nonnull NSString *)attr_value;
- (void) removeAttributeWithName:(nonnull NSString *)attr_name;
- (nonnull SECommonStringsMapIterator *) attributesBegin;
- (nonnull SECommonStringsMapIterator *) attributesEnd;

- (void) serialize:(nonnull SECommonSerializer *)serializer;

@end


@interface SEDocBasicObjectRef : NSObject

+ (nonnull NSString *) baseClassNameStatic;

- (BOOL) isMutable;

- (nonnull NSString *) objectType;

- (nonnull SEDocBaseObjectInfoRef *) getBaseObjectInfo;
- (nonnull SEDocBaseObjectInfoRef *) getMutableBaseObjectInfo;

- (nonnull SEDocTextObjectRef *) getTextObjectRef;
- (nonnull SEDocCheckboxObjectRef *) getCheckboxObjectRef;
- (nonnull SEDocTemplateObjectRef *) getTemplateObjectRef;
- (nonnull SEDocLineObjectRef *) getLineObjectRef;
- (nonnull SEDocZoneObjectRef *) getZoneObjectRef;
- (nonnull SEDocMultiStringTextObjectRef *) getMultiStringTextObjectRef;
- (nonnull SEDocMetaObjectRef *) getMetaObjectRef;
- (nonnull SEDocTableObjectRef *) getTableObjectRef;
- (nonnull SEDocImageObjectRef *) getImageObjectRef;
- (nonnull SEDocBarcodeObjectRef *) getBarcodeObjectRef;

- (void) serialize:(nonnull SECommonSerializer *)serializer;

@end 


@interface SEDocBasicObject : NSObject

+ (nonnull NSString *) baseClassNameStatic;

- (nonnull instancetype) initForCollection:(nonnull SEDocObjectsCollectionRef *)collection;

- (nonnull SEDocBasicObjectRef *) getRef;
- (nonnull SEDocBasicObjectRef *) getMutableRef;

@end

#endif // OBJCDOCENGINE_DOC_BASIC_OBJECT_H_INCLUDED