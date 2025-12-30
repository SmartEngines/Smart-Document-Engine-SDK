/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_VIEWS_COLLECTION_H_INCLUDED
#define OBJCDOCENGINE_DOC_VIEWS_COLLECTION_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_forward_declarations.h>
#import <objcdocengine/doc_views_iterator.h>

@interface SEDocViewsCollectionRef : NSObject

+ (nonnull NSString *) baseClassNameStatic;

- (BOOL) isMutable;

- (int) getViewsCount;
- (BOOL) hasViewWithID:(int)view_id;
- (nonnull SEDocViewRef *) getViewWithID:(int)view_id;
- (nonnull SEDocViewRef *) getMutableViewWithID:(int)view_id;
- (nonnull SEDocTagsCollectionRef *) getViewTagsWithID:(int)view_id;

- (nonnull SEDocViewsMutableIterator *) registerView:(nonnull SECommonImageRef *)image;
- (nonnull SEDocViewsMutableIterator *) registerDerivedView:(nonnull SECommonImageRef *)image
                                             withAncestorID:(int)ancestor_id
                                              withTransform:(nonnull SECommonProjectiveTransform *)transform;

- (void) deleteOrphans;
- (void) deleteViewWithID:(int)view_id;

- (nonnull SEDocViewsIterator *) viewsBegin;
- (nonnull SEDocViewsIterator *) viewsEnd;

- (nonnull SEDocViewsMutableIterator *) mutableViewsBegin;
- (nonnull SEDocViewsMutableIterator *) mutableViewsEnd;

- (nonnull SEDocViewsSliceIterator *) viewsSliceForTag:(nonnull NSString *)tag;
- (nonnull SEDocViewsMutableSliceIterator *) mutableViewsSliceForTag:(nonnull NSString *)tag;

- (void) serialize:(nonnull SECommonSerializer *)serializer;

@end

#endif // OBJCDOCENGINE_DOC_VIEWS_COLLECTION_H_INCLUDED