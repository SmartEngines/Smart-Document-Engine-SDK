/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
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

- (nonnull SEDocTextObjectsIterator *) rawTextObjectsBegin;
- (nonnull SEDocTextObjectsIterator *) rawTextObjectsEnd;

- (nonnull SEDocTextObjectsIterator *) textObjectsBegin:(nonnull NSString *)name;
- (nonnull SEDocTextObjectsIterator *) textObjectsEnd:(nonnull NSString *)name;

- (nonnull SEDocImageObjectsIterator *) imageObjectsBegin:(nonnull NSString *)name;
- (nonnull SEDocImageObjectsIterator *) imageObjectsEnd:(nonnull NSString *)name;

- (nonnull SEDocTableObjectsIterator *) tableObjectsBegin:(nonnull NSString *)name;
- (nonnull SEDocTableObjectsIterator *) tableObjectsEnd:(nonnull NSString *)name;

- (nonnull SEDocBarcodeObjectsIterator *) barcodeObjectsBegin:(nonnull NSString *)name;
- (nonnull SEDocBarcodeObjectsIterator *) barcodeObjectsEnd:(nonnull NSString *)name;

- (nonnull SEDocCheckboxObjectsIterator *) checkboxObjectsBegin:(nonnull NSString *)name;
- (nonnull SEDocCheckboxObjectsIterator *) checkboxObjectsEnd:(nonnull NSString *)name;

- (nonnull SEDocMetaObjectsIterator *) forensicObjectsBegin:(nonnull NSString *)name;
- (nonnull SEDocMetaObjectsIterator *) forensicObjectsEnd:(nonnull NSString *)name;

- (nonnull SEDocForensicCheckObjectsIterator *) forensicCheckObjectsBegin:(nonnull NSString *)name;
- (nonnull SEDocForensicCheckObjectsIterator *) forensicCheckObjectsEnd:(nonnull NSString *)name;

- (int) getRawTextObjectsCount;
- (int) getTextObjectsCount:(nonnull NSString *)name;
- (int) getImageObjectsCount:(nonnull NSString *)name;
- (int) getTableObjectsCount:(nonnull NSString *)name;
- (int) getBarcodeObjectsCount:(nonnull NSString *)name;
- (int) getCheckboxObjectsCount:(nonnull NSString *)name;
- (int) getForensicObjectsCount:(nonnull NSString *)name;
- (int) getForensicCheckObjectsCount:(nonnull NSString *)name;

- (nonnull SECommonQuadrangle *) getPageQuadrangle;
- (nonnull SECommonPolygon *) getPagePolygon;

- (nonnull SEDocTextObjectsIterator *) getFulltextBasicObjectsBegin;
- (nonnull SEDocTextObjectsIterator *) getFulltextBasicObjectsEnd;

- (nonnull SECommonImageRef *) getPageImageFromScene:(nonnull SECommonImageRef *)scene_image;

@end

@interface SEDocPhysicalDocumentRef: NSObject

- (BOOL) isMutable;

- (int) getBasicObjectsCount:(nonnull NSString *)name;
- (int) getPagesCount;

- (int) getTextObjectsCount:(nonnull NSString *)name;

- (nonnull SEDocPhysicalPageRef *) getPhysicalPage:(int)idx;

- (nonnull SEDocPhysicalPageRef *) getPhysicalPagePtr:(int)idx;

@end

#endif // OBJCDOCENGINE_PHYSICAL_DOCUMENT_H_INCLUDED




