/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_OBJECTS_COLLECTIONS_ITERATOR_H_INCLUDED
#define OBJCDOCENGINE_DOC_OBJECTS_COLLECTIONS_ITERATOR_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_forward_declarations.h>

@interface SEDocObjectsCollectionsIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocObjectsCollectionsIterator *)other;
- (BOOL) isEqualToIter:(nonnull SEDocObjectsCollectionsIterator *)other;

- (int) getID;
- (nonnull SEDocObjectsCollectionRef *) getObjectsCollection;
- (nonnull SEDocTagsCollectionRef *) getTags;

- (void) advance;

@end


@interface SEDocObjectsCollectionsMutableIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocObjectsCollectionsMutableIterator *)other;
- (BOOL) isEqualToIter:(nonnull SEDocObjectsCollectionsMutableIterator *)other;

- (int) getID;
- (nonnull SEDocObjectsCollectionRef *) getObjectsCollection;
- (nonnull SEDocObjectsCollectionRef *) getMutableObjectsCollection;
- (nonnull SEDocTagsCollectionRef *) getTags;

- (void) advance;

@end


@interface SEDocObjectsCollectionsSliceIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocObjectsCollectionsSliceIterator *)other;

- (int) getID;
- (nonnull SEDocObjectsCollectionRef *) getObjectsCollection;
- (nonnull SEDocTagsCollectionRef *) getTags;

- (void) advance;
- (BOOL) finished;

@end


@interface SEDocObjectsCollectionsMutableSliceIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocObjectsCollectionsMutableSliceIterator *)other;

- (int) getID;
- (nonnull SEDocObjectsCollectionRef *) getObjectsCollection;
- (nonnull SEDocObjectsCollectionRef *) getMutableObjectsCollection;
- (nonnull SEDocTagsCollectionRef *) getTags;

- (void) advance;
- (BOOL) finished;

@end

#endif // OBJCDOCENGINE_DOC_OBJECTS_COLLECTIONS_ITERATOR_H_INCLUDED