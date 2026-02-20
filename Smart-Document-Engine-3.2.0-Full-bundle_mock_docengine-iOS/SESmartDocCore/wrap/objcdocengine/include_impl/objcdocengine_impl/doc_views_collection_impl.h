/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_VIEWS_COLLECTION_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_VIEWS_COLLECTION_H_INCLUDED

#import <objcdocengine/doc_views_collection.h>

#include <docengine/doc_views_collection.h>

@interface SEDocViewsCollectionRef (Internal)

- (instancetype) initFromInternalViewsCollectionPointer:(se::doc::DocViewsCollection *)collptr
                                     withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocViewsCollection *) getInternalViewsCollectionPointer;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_VIEWS_COLLECTION_H_INCLUDED