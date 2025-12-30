/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_VIEWS_ITERATOR_H_INCLUDED
#define OBJCDOCENGINE_DOC_VIEWS_ITERATOR_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_forward_declarations.h>

@interface SEDocViewsIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocViewsIterator *)other;
- (BOOL) isEqualToIter:(nonnull SEDocViewsIterator *)other;

- (int) getID;
- (nonnull SEDocViewRef *) getView;
- (nonnull SEDocTagsCollectionRef *) getTags;

- (void) advance;

@end


@interface SEDocViewsMutableIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocViewsMutableIterator *)other;
- (BOOL) isEqualToIter:(nonnull SEDocViewsMutableIterator *)other;

- (int) getID;
- (nonnull SEDocViewRef *) getView;
- (nonnull SEDocViewRef *) getMutableView;
- (nonnull SEDocTagsCollectionRef *) getTags;

- (void) advance;

@end


@interface SEDocViewsSliceIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocViewsSliceIterator *)other;

- (int) getID;
- (nonnull SEDocViewRef *) getView;
- (nonnull SEDocTagsCollectionRef *) getTags;

- (void) advance;
- (BOOL) finished;

@end


@interface SEDocViewsMutableSliceIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocViewsMutableSliceIterator *)other;

- (int) getID;
- (nonnull SEDocViewRef *) getView;
- (nonnull SEDocViewRef *) getMutableView;
- (nonnull SEDocTagsCollectionRef *) getTags;

- (void) advance;
- (BOOL) finished;

@end

#endif // OBJCDOCENGINE_DOC_VIEWS_ITERATOR_H_INCLUDED