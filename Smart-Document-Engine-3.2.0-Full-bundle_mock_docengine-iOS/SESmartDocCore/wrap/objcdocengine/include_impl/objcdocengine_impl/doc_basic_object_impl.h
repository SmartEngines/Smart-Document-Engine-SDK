/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_BASIC_OBJECT_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_BASIC_OBJECT_H_INCLUDED

#import <objcdocengine/doc_basic_object.h>

#include <docengine/doc_basic_object.h>

@interface SEDocBaseObjectInfoRef (Internal)

- (instancetype) initFromInternalBaseObjectInfoPointer:(se::doc::DocBaseObjectInfo *)infoptr
                                    withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocBaseObjectInfo *) getInternalBaseObjectInfoPointer;

@end


@interface SEDocBasicObjectRef (Internal)

- (instancetype) initFromInternalBasicObjectPointer:(se::doc::DocBasicObject *)objptr
                                 withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocBasicObject *) getInternalBasicObjectPointer;

@end

@interface SEDocBasicObject (Internal)

- (instancetype) initFromCreatedBasicObject:(se::doc::DocBasicObject *)objptr;
- (se::doc::DocBasicObject &) getInternalBasicObject;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_BASIC_OBJECT_H_INCLUDED