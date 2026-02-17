/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_TAGS_COLLECTION_H_INCLUDED
#define OBJCDOCENGINE_DOC_TAGS_COLLECTION_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_fields_iterators.h>

@interface SEDocTagsCollectionRef : NSObject

- (BOOL) isMutable;

- (int) getTagsCount;
- (BOOL) hasTag:(nonnull NSString *)tag;
- (void) addTag:(nonnull NSString *)tag;
- (void) removeTag:(nonnull NSString *)tag;

- (nonnull SECommonStringsSetIterator *) tagsBegin;
- (nonnull SECommonStringsSetIterator *) tagsEnd;

- (void) serialize:(nonnull SECommonSerializer *)serializer;

@end


@interface SEDocTagsCollection : NSObject

- (nonnull instancetype) init;

- (nonnull SEDocTagsCollectionRef *) getRef;
- (nonnull SEDocTagsCollectionRef *) getMutableRef;

@end

#endif // OBJCDOCENGINE_DOC_TAGS_COLLECTION_H_INCLUDED