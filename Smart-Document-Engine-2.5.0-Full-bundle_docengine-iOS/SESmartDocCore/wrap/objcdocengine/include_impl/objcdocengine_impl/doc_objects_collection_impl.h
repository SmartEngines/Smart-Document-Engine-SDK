/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_OBJECTS_COLLECTION_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_OBJECTS_COLLECTION_H_INCLUDED

#import <objcdocengine/doc_objects_collection.h>

#include <docengine/doc_objects_collection.h>

@interface SEDocObjectsCollectionRef (Internal)

- (instancetype) initFromInternalObjectsCollectionPointer:(se::doc::DocObjectsCollection *)collptr
                                       withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocObjectsCollection *) getInternalObjectsCollectionPointer;

@end


@interface SEDocObjectsCollection (Internal)

- (instancetype) initFromCreatedObjectsCollection:(se::doc::DocObjectsCollection *)collptr;
- (se::doc::DocObjectsCollection &) getInternalObjectsCollection;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_OBJECTS_COLLECTION_H_INCLUDED