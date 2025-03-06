/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_PHYSICAL_DOCUMENT_H_INCLUDED
#define OBJCDOCENGINE_PHYSICAL_DOCUMENT_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_basic_objects_iterator.h>

@interface SEDocPhysicalPageRef : NSObject

- (BOOL) isMutable;

- (int) getSourceSceneID;

- (nonnull SEDocBasicObjectsIterator *) basicObjectsBegin:(nonnull NSString *)name;
- (nonnull SEDocBasicObjectsIterator *) basicObjectsEnd:(nonnull NSString *)name;

- (int) getBasicObjectsCount:(nonnull NSString *)name;

- (nonnull SECommonQuadrangle *) getPageQuadrangle;
- (nonnull SECommonPolygon *) getPagePolygon;

- (nonnull SEDocBasicObjectsIterator *) getFulltextBasicObjectsBegin;
- (nonnull SEDocBasicObjectsIterator *) getFulltextBasicObjectsEnd;

- (nonnull SECommonImageRef *) getPageImageFromScene:(nonnull SECommonImageRef *)scene_image;

@end

@interface SEDocPhysicalDocumentRef: NSObject

- (BOOL) isMutable;

- (int) getBasicObjectsCount:(nonnull NSString *)name;
- (int) getPagesCount;

- (nonnull SEDocPhysicalPageRef *) getPhysicalPage:(int)idx;

- (nonnull SEDocPhysicalPageRef *) getPhysicalPagePtr:(int)idx;

@end

#endif // OBJCDOCENGINE_PHYSICAL_DOCUMENT_H_INCLUDED




