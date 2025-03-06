/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_OBJECTS_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_OBJECTS_H_INCLUDED

#import <objcdocengine/doc_objects.h>

#include <docengine/doc_objects.h>

@interface SEDocTextObjectRef (Internal)

- (instancetype) initFromInternalTextObjectPointer:(se::doc::DocTextObject *)objptr
                                withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocTextObject *) getInternalTextObjectPointer;

@end


@interface SEDocCheckboxObjectRef (Internal)

- (instancetype) initFromInternalCheckboxObjectPointer:(se::doc::DocCheckboxObject *)objptr
                                    withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocCheckboxObject *) getInternalCheckboxObjectPointer;

@end


@interface SEDocTemplateObjectRef (Internal)

- (instancetype) initFromInternalTemplateObjectPointer:(se::doc::DocTemplateObject *)objptr
                                    withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocTemplateObject *) getInternalTemplateObjectPointer;

@end


@interface SEDocLineObjectRef (Internal)

- (instancetype) initFromInternalLineObjectPointer:(se::doc::DocLineObject *)objptr
                                withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocLineObject *) getInternalLineObjectPointer;

@end


@interface SEDocZoneObjectRef (Internal)

- (instancetype) initFromInternalZoneObjectPointer:(se::doc::DocZoneObject *)objptr
                                withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocZoneObject *) getInternalZoneObjectPointer;

@end


@interface SEDocMultiStringTextObjectRef (Internal)

- (instancetype) initFromInternalMultiStringTextObjectPointer:(se::doc::DocMultiStringTextObject *)objptr
                                           withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocMultiStringTextObject *) getInternalMultiStringTextObjectPointer;

@end


@interface SEDocMetaObjectRef (Internal)

- (instancetype) initFromInternalMetaObjectPointer:(se::doc::DocMetaObject *)objptr
                                withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocMetaObject *) getInternalMetaObjectPointer;

@end


@interface SEDocTableObjectRef (Internal)

- (instancetype) initFromInternalTableObjectPointer:(se::doc::DocTableObject *)objptr
                                 withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocTableObject *) getInternalTableObjectPointer;

@end


@interface SEDocImageObjectRef (Internal)

- (instancetype) initFromInternalImageObjectPointer:(se::doc::DocImageObject *)objptr
                                 withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocImageObject *) getInternalImageObjectPointer;

@end


@interface SEDocBarcodeObjectRef (Internal)

- (instancetype) initFromInternalBarcodeObjectPointer:(se::doc::DocBarcodeObject *)objptr
                                 withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocBarcodeObject *) getInternalBarcodeObjectPointer;

@end


@interface SEDocMarkObjectRef (Internal)

- (instancetype) initFromInternalMarkObjectPointer:(se::doc::DocMarkObject *)objptr
                                 withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocMarkObject *) getInternalMarkObjectPointer;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_OBJECTS_H_INCLUDED