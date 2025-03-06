/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
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

- (int) getBasicObjectsCount:(nonnull NSString *)name {
    return ptr->GetBasicObjectsCount([name UTF8String]);
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

- (SECommonPolygon *) getPagePolygon {
    return [[SECommonPolygon alloc] initFromInternalPolygon:ptr->GetPagePolygon()];
}

- (nonnull SECommonQuadrangle *)getPageQuadrangle {
    return [[SECommonQuadrangle alloc] initFromInternalQuadrangle:ptr->GetPageQuadrangle()];
}

- (int)getSourceSceneID {
    return ptr->GetSourceSceneID();
}

- (SEDocBasicObjectsIterator *)basicObjectsBegin:(nonnull NSString *)name {
    return [[SEDocBasicObjectsIterator alloc]
            initFromInternalBasicObjectsIterator:ptr->BasicObjectsBegin([name UTF8String])];
}

- (SEDocBasicObjectsIterator *) basicObjectsEnd:(nonnull NSString *)name {
    return [[SEDocBasicObjectsIterator alloc]
            initFromInternalBasicObjectsIterator:ptr->BasicObjectsEnd([name UTF8String])];
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

@end

