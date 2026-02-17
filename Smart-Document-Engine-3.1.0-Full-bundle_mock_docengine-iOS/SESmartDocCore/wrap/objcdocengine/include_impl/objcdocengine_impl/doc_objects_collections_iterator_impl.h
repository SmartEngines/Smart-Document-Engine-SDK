/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_OBJECTS_COLLECTIONS_ITERATOR_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_OBJECTS_COLLECTIONS_ITERATOR_H_INCLUDED

#import <objcdocengine/doc_objects_collections_iterator.h>

#include <docengine/doc_objects_collections_iterator.h>

@interface SEDocObjectsCollectionsIterator (Internal)

- (instancetype) initFromInternalObjectsCollectionsIterator:(const se::doc::DocObjectsCollectionsIterator &)iter;
- (const se::doc::DocObjectsCollectionsIterator &) getInternalObjectsCollectionsIterator;

@end


@interface SEDocObjectsCollectionsMutableIterator (Internal)

- (instancetype) initFromInternalObjectsCollectionsMutableIterator:(const se::doc::DocObjectsCollectionsMutableIterator &)iter;
- (const se::doc::DocObjectsCollectionsMutableIterator &) getInternalObjectsCollectionsMutableIterator;

@end


@interface SEDocObjectsCollectionsSliceIterator (Internal)

- (instancetype) initFromInternalObjectsCollectionsSliceIterator:(const se::doc::DocObjectsCollectionsSliceIterator &)iter;
- (const se::doc::DocObjectsCollectionsSliceIterator &) getInternalObjectsCollectionsSliceIterator;

@end


@interface SEDocObjectsCollectionsMutableSliceIterator (Internal)

- (instancetype) initFromInternalObjectsCollectionsMutableSliceIterator:(const se::doc::DocObjectsCollectionsMutableSliceIterator &)iter;
- (const se::doc::DocObjectsCollectionsMutableSliceIterator &) getInternalObjectsCollectionsMutableSliceIterator;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_OBJECTS_COLLECTIONS_ITERATOR_H_INCLUDED