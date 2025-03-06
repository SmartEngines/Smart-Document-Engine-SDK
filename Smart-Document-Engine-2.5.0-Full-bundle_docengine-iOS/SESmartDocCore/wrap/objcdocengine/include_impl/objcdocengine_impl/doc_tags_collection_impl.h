/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_TAGS_COLLECTION_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_TAGS_COLLECTION_H_INCLUDED

#import <objcdocengine/doc_tags_collection.h>

#include <docengine/doc_tags_collection.h>

@interface SEDocTagsCollectionRef (Internal)

- (instancetype) initFromInternalTagsCollectionPointer:(se::doc::DocTagsCollection *)collptr
                                    withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocTagsCollection *) getInternalTagsCollectionPointer;

@end


@interface SEDocTagsCollection (Internal)

- (instancetype) initFromCreatedTagsCollection:(se::doc::DocTagsCollection *)collptr;
- (se::doc::DocTagsCollection &) getInternalTagsCollection;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_TAGS_COLLECTION_H_INCLUDED