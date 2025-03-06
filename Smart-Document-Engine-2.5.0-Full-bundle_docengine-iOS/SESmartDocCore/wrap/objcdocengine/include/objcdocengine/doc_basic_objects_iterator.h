/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_BASIC_OBJECTS_ITERATOR_H_INCLUDED
#define OBJCDOCENGINE_DOC_BASIC_OBJECTS_ITERATOR_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_forward_declarations.h>

@interface SEDocBasicObjectsIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocBasicObjectsIterator *)other;
- (BOOL) isEqualToIter:(nonnull SEDocBasicObjectsIterator *)other;

- (int) getID;
- (nonnull SEDocBasicObjectRef *) getBasicObject;
- (nonnull SEDocTagsCollectionRef *) getTags;

- (void) advance;

@end


@interface SEDocBasicObjectsMutableIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocBasicObjectsMutableIterator *)other;
- (BOOL) isEqualToIter:(nonnull SEDocBasicObjectsMutableIterator *)other;

- (int) getID;
- (nonnull SEDocBasicObjectRef *) getBasicObject;
- (nonnull SEDocBasicObjectRef *) getMutableBasicObject;
- (nonnull SEDocTagsCollectionRef *) getTags;

- (void) advance;

@end


@interface SEDocBasicObjectsSliceIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocBasicObjectsSliceIterator *)other;

- (int) getID;
- (nonnull SEDocBasicObjectRef *) getBasicObject;
- (nonnull SEDocTagsCollectionRef *) getTags;

- (void) advance;
- (BOOL) finished;

@end


@interface SEDocBasicObjectsMutableSliceIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocBasicObjectsMutableSliceIterator *)other;

- (int) getID;
- (nonnull SEDocBasicObjectRef *) getBasicObject;
- (nonnull SEDocBasicObjectRef *) getMutableBasicObject;
- (nonnull SEDocTagsCollectionRef *) getTags;

- (void) advance;
- (BOOL) finished;

@end


@interface SEDocBasicObjectsCrossSliceIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocBasicObjectsCrossSliceIterator *)other;

- (int) getCollectionID;
- (int) getObjectID;
- (nonnull SEDocBasicObjectRef *) getBasicObject;
- (nonnull SEDocTagsCollectionRef *) getTags;

- (void) advance;

@end


@interface SEDocBasicObjectsMutableCrossSliceIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocBasicObjectsMutableCrossSliceIterator *)other;

- (int) getCollectionID;
- (int) getObjectID;
- (nonnull SEDocBasicObjectRef *) getBasicObject;
- (nonnull SEDocBasicObjectRef *) getMutableBasicObject;
- (nonnull SEDocTagsCollectionRef *) getTags;

- (void) advance;

@end

@interface SEDocTextObjectsIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocTextObjectsIterator *)other;
- (BOOL) isEqualToIter:(nonnull SEDocTextObjectsIterator *)other;

- (nonnull SEDocTextObjectRef *) getTextObject;

- (void) advance;

@end

#endif // OBJCDOCENGINE_DOC_BASIC_OBJECTS_ITERATOR_H_INCLUDED
