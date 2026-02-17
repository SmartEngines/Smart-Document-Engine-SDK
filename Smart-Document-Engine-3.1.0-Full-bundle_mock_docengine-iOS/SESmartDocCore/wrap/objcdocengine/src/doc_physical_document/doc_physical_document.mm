/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/
#import <objcdocengine_impl/doc_basic_objects_iterator_impl.h>
#import <objcdocengine_impl/doc_physical_document_impl.h>

#import <objcsecommon_impl/se_geometry_impl.h>
#import <objcsecommon_impl/se_image_impl.h>
#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocPhysicalPageRef {
    se::doc::DocPhysicalPage* ptr;
    bool is_mutable;
}

- (instancetype) initFromInternalPhysicalPagePointer:(se::doc::DocPhysicalPage *)docptr
                                withMutabilityFlag:(BOOL)mutabilityFlag {
    if (self = [super init]) {
        ptr = docptr;
        is_mutable = (YES == mutabilityFlag);
    }
    return self;
}

- (se::doc::DocPhysicalPage *) getInternalPhysicalPagePointer {
    return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (int)getSourceSceneID {
    return ptr->GetSourceSceneID();
}

- (nonnull SEDocTextObjectsIterator *)rawTextObjectsBegin {
  return [[SEDocTextObjectsIterator alloc]
          initFromInternalTextObjectsIterator:ptr->RawTextObjectsBegin()];
}

- (nonnull SEDocTextObjectsIterator *)rawTextObjectsEnd {
  return [[SEDocTextObjectsIterator alloc]
          initFromInternalTextObjectsIterator:ptr->RawTextObjectsEnd()];
}

- (nonnull SEDocTextObjectsIterator *)textObjectsBegin:(nonnull NSString *)name {
  return [[SEDocTextObjectsIterator alloc]
          initFromInternalTextObjectsIterator:ptr->TextObjectsBegin([name UTF8String])];
}

- (nonnull SEDocTextObjectsIterator *)textObjectsEnd:(nonnull NSString *)name {
  return [[SEDocTextObjectsIterator alloc]
          initFromInternalTextObjectsIterator:ptr->TextObjectsEnd([name UTF8String])];
}

- (nonnull SEDocImageObjectsIterator *)imageObjectsBegin:(nonnull NSString *)name {
  return [[SEDocImageObjectsIterator alloc]
          initFromInternalImageObjectsIterator:ptr->ImageObjectsBegin([name UTF8String])];
}

- (nonnull SEDocImageObjectsIterator *)imageObjectsEnd:(nonnull NSString *)name {
  return [[SEDocImageObjectsIterator alloc]
          initFromInternalImageObjectsIterator:ptr->ImageObjectsEnd([name UTF8String])];
}

- (nonnull SEDocTableObjectsIterator *)tableObjectsBegin:(nonnull NSString *)name {
  return [[SEDocTableObjectsIterator alloc]
          initFromInternalTableObjectsIterator:ptr->TableObjectsBegin([name UTF8String])];
}

- (nonnull SEDocTableObjectsIterator *)tableObjectsEnd:(nonnull NSString *)name {
  return [[SEDocTableObjectsIterator alloc]
          initFromInternalTableObjectsIterator:ptr->TableObjectsEnd([name UTF8String])];
}

- (nonnull SEDocBarcodeObjectsIterator *)barcodeObjectsBegin:(nonnull NSString *)name {
  return [[SEDocBarcodeObjectsIterator alloc]
          initFromInternalBarcodeObjectsIterator:ptr->BarcodeObjectsBegin([name UTF8String])];
}

- (nonnull SEDocBarcodeObjectsIterator *)barcodeObjectsEnd:(nonnull NSString *)name {
  return [[SEDocBarcodeObjectsIterator alloc]
          initFromInternalBarcodeObjectsIterator:ptr->BarcodeObjectsEnd([name UTF8String])];
}

- (nonnull SEDocCheckboxObjectsIterator *)checkboxObjectsBegin:(nonnull NSString *)name {
  return [[SEDocCheckboxObjectsIterator alloc]
          initFromInternalCheckboxObjectsIterator:ptr->CheckboxObjectsBegin([name UTF8String])];
}

- (nonnull SEDocCheckboxObjectsIterator *)checkboxObjectsEnd:(nonnull NSString *)name {
  return [[SEDocCheckboxObjectsIterator alloc]
          initFromInternalCheckboxObjectsIterator:ptr->CheckboxObjectsEnd([name UTF8String])];
}

- (nonnull SEDocMetaObjectsIterator *)forensicObjectsBegin:(nonnull NSString *)name {
  return [[SEDocMetaObjectsIterator alloc]
          initFromInternalMetaObjectsIterator:ptr->ForensicObjectsBegin([name UTF8String])];
}

- (nonnull SEDocMetaObjectsIterator *)forensicObjectsEnd:(nonnull NSString *)name {
  return [[SEDocMetaObjectsIterator alloc]
          initFromInternalMetaObjectsIterator:ptr->ForensicObjectsEnd([name UTF8String])];
}

- (nonnull SEDocForensicCheckObjectsIterator *)forensicCheckObjectsBegin:(nonnull NSString *)name {
  return [[SEDocForensicCheckObjectsIterator alloc]
          initFromInternalForensicCheckObjectsIterator:ptr->ForensicCheckObjectsBegin([name UTF8String])];
}

- (nonnull SEDocForensicCheckObjectsIterator *)forensicCheckObjectsEnd:(nonnull NSString *)name {
  return [[SEDocForensicCheckObjectsIterator alloc]
          initFromInternalForensicCheckObjectsIterator:ptr->ForensicCheckObjectsEnd([name UTF8String])];
}


- (int) getRawTextObjectsCount {
  return ptr->GetRawTextObjectsCount();
}

- (int) getTextObjectsCount:(nonnull NSString *)name {
  return ptr->GetTextObjectsCount([name UTF8String]);
}

- (int) getImageObjectsCount:(nonnull NSString *)name {
    return ptr->GetImageObjectsCount([name UTF8String]);
}

- (int) getTableObjectsCount:(nonnull NSString *)name {
    return ptr->GetTableObjectsCount([name UTF8String]);
}

- (int) getBarcodeObjectsCount:(nonnull NSString *)name {
    return ptr->GetBarcodeObjectsCount([name UTF8String]);
}

- (int) getCheckboxObjectsCount:(nonnull NSString *)name {
    return ptr->GetCheckboxObjectsCount([name UTF8String]);
}

- (int) getForensicObjectsCount:(nonnull NSString *)name {
    return ptr->GetForensicObjectsCount([name UTF8String]);
}

- (int) getForensicCheckObjectsCount:(nonnull NSString *)name {
    return ptr->GetForensicCheckObjectsCount([name UTF8String]);
}

- (nonnull SECommonQuadrangle *)getPageQuadrangle {
  return [[SECommonQuadrangle alloc] initFromInternalQuadrangle:ptr->GetPageQuadrangle()];
}

- (SECommonPolygon *) getPagePolygon {
  return [[SECommonPolygon alloc] initFromInternalPolygon:ptr->GetPagePolygon()];
}

- (SEDocTextObjectsIterator *) getFulltextBasicObjectsBegin {
  return [[SEDocTextObjectsIterator alloc]
          initFromInternalTextObjectsIterator:ptr->GetFulltextBasicObjectsBegin()];
}

- (SEDocTextObjectsIterator *) getFulltextBasicObjectsEnd {
  return [[SEDocTextObjectsIterator alloc]
          initFromInternalTextObjectsIterator:ptr->GetFulltextBasicObjectsEnd()];
}

- (SECommonImageRef *) getPageImageFromScene:(const SECommonImageRef *)scene_image {
  return [[SECommonImageRef alloc]
          initFromInternalImagePointer:const_cast<se::common::Image*>(ptr->GetPageImageFromScene(*[scene_image getInternalImagePointer]))
          withMutabilityFlag:NO];
}


@end

@implementation SEDocPhysicalDocumentRef {
    se::doc::DocPhysicalDocument* ptr;
    bool is_mutable;
}

- (instancetype) initFromInternalPhysicalDocumentPointer:(se::doc::DocPhysicalDocument *)docptr
                                withMutabilityFlag:(BOOL)mutabilityFlag {
    if (self = [super init]) {
        ptr = docptr;
        is_mutable = (YES == mutabilityFlag);
    }
    return self;
}

- (se::doc::DocPhysicalDocument *) getInternalPhysicalDocumentPointer {
    return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (int) getPagesCount {
    return ptr->GetPagesCount();
}

- (SEDocPhysicalPageRef *) getPhysicalPage:(int)idx {
    return [[SEDocPhysicalPageRef alloc] 
            initFromInternalPhysicalPagePointer:const_cast<se::doc::DocPhysicalPage*>(&ptr->GetPhysicalPage(idx))
            withMutabilityFlag:NO];
}

- (SEDocPhysicalPageRef *) getPhysicalPagePtr:(int)idx {
    return [[SEDocPhysicalPageRef alloc]
            initFromInternalPhysicalPagePointer:const_cast<se::doc::DocPhysicalPage*>(&ptr->GetPhysicalPage(idx))
            withMutabilityFlag:NO];
}

- (int) getBasicObjectsCount:(nonnull NSString *)name {
    return ptr->GetBasicObjectsCount([name UTF8String]);
}

- (int) getTextObjectsCount:(nonnull NSString *)name {
  return ptr->GetTextObjectsCount([name UTF8String]);
}

@end

