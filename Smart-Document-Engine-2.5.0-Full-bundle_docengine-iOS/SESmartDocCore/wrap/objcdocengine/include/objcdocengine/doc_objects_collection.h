/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_OBJECTS_COLLECTION_H_INCLUDED
#define OBJCDOCENGINE_DOC_OBJECTS_COLLECTION_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_forward_declarations.h>
#import <objcdocengine/doc_basic_objects_iterator.h>

@interface SEDocObjectsCollectionRef : NSObject

+ (nonnull NSString *) baseClassNameStatic;

- (BOOL) isMutable;

- (nonnull SEDocBasicObject *) createObject;

- (nonnull SEDocObjectsCollection *) clone;

- (nonnull NSString *) objectType;

- (int) getFrameID;
- (void) setFrameIDTo:(int)frame_id;

- (int) getObjectsCount;
- (BOOL) hasObjectWithID:(int)obj_id;
- (nonnull SEDocBasicObjectRef *) getObjectWithID:(int)obj_id;
- (nonnull SEDocBasicObjectRef *) getMutableObjectWithID:(int)obj_id;
- (nonnull SEDocTagsCollectionRef *) getObjectTagsWithID:(int)obj_id;
- (nonnull SEDocBasicObjectsMutableIterator *) addObject:(nonnull SEDocBasicObject *)obj;
- (void) setObjectWithID:(int)obj_id
                      to:(nonnull SEDocBasicObject *)obj;
- (void) removeObjectWithID:(int)obj_id;
- (void) removeObjectDeepWithID:(int)obj_id
            withViewsCollection:(nonnull SEDocViewsCollectionRef *)views_collection;

- (nonnull SEDocBasicObjectsIterator *) basicObjectsBegin;
- (nonnull SEDocBasicObjectsIterator *) basicObjectsEnd;

- (nonnull SEDocBasicObjectsMutableIterator *) mutableBasicObjectsBegin;
- (nonnull SEDocBasicObjectsMutableIterator *) mutableBasicObjectsEnd;

- (nonnull SEDocBasicObjectsSliceIterator *) basicObjectsSliceForTag:(nonnull NSString *)tag;
- (nonnull SEDocBasicObjectsMutableSliceIterator *) mutableBasicObjectsSliceForTag:(nonnull NSString *)tag;

- (void) serialize:(nonnull SECommonSerializer *)serializer;

@end


@interface SEDocObjectsCollection : NSObject 

+ (nonnull NSString *) baseClassNameStatic;

- (nonnull instancetype) initForObjectType:(nonnull NSString *)object_type;

- (nonnull SEDocObjectsCollectionRef *) getRef;
- (nonnull SEDocObjectsCollectionRef *) getMutableRef;

@end

#endif // OBJCDOCENGINE_DOC_OBJECTS_COLLECTION_H_INCLUDED