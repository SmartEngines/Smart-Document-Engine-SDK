/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_GRAPHICAL_STRUCTURE_H_INCLUDED
#define OBJCDOCENGINE_DOC_GRAPHICAL_STRUCTURE_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_forward_declarations.h>
#import <objcdocengine/doc_objects_collections_iterator.h>

@interface SEDocGraphicalStructureRef : NSObject

- (BOOL) isMutable;

- (int) getCollectionsCount;
- (BOOL) hasCollectionWithID:(int)c_id;
- (nonnull SEDocObjectsCollectionRef *) getCollectionWithID:(int)c_id;
- (nonnull SEDocObjectsCollectionRef *) getMutableCollectionWithID:(int)c_id;
- (nonnull SEDocTagsCollectionRef *) getCollectionTagsWithID:(int)c_id;
- (nonnull SEDocObjectsCollectionsMutableIterator *) addCollection:(nonnull SEDocObjectsCollection *)collection;
- (nonnull SEDocObjectsCollectionsMutableIterator *) addCollection:(nonnull SEDocObjectsCollection *)collection
                                                          withTags:(nonnull SEDocTagsCollection *)tags;
- (void) setCollectionWithID:(int)c_id
                          to:(nonnull SEDocObjectsCollection *)collection;
- (void) removeCollectionWithID:(int)c_id;

- (nonnull SEDocObjectsCollectionsIterator *) objectsCollectionsBegin;
- (nonnull SEDocObjectsCollectionsIterator *) objectsCollectionsEnd;

- (nonnull SEDocObjectsCollectionsMutableIterator *) mutableObjectsCollectionsBegin;
- (nonnull SEDocObjectsCollectionsMutableIterator *) mutableObjectsCollectionsEnd;

- (nonnull SEDocObjectsCollectionsSliceIterator *) objectsCollectionsSliceForTag:(nonnull NSString *)tag;
- (nonnull SEDocObjectsCollectionsMutableSliceIterator *) mutableObjectsCollectionsSliceForTag:(nonnull NSString *)tag;

- (nonnull SEDocViewsCollectionRef *) getViewsCollection;
- (nonnull SEDocViewsCollectionRef *) getMutableViewsCollection;

- (void) serialize:(nonnull SECommonSerializer *)serializer;

@end

#endif // OBJCDOCENGINE_DOC_GRAPHICAL_STRUCTURE_H_INCLUDED