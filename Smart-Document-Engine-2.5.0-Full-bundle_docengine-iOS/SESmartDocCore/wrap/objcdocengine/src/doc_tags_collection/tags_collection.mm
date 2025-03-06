/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_tags_collection_impl.h>

#import <objcsecommon_impl/se_strings_iterator_impl.h>
#import <objcsecommon_impl/se_serialization_impl.h>
#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocTagsCollectionRef {
  se::doc::DocTagsCollection* ptr;
  bool is_mutable;
}

- (instancetype) initFromInternalTagsCollectionPointer:(se::doc::DocTagsCollection *)collptr
                                    withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = collptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocTagsCollection *) getInternalTagsCollectionPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (int) getTagsCount {
  return ptr->GetTagsCount();
}

- (BOOL) hasTag:(NSString *)tag {
  return ptr->HasTag([tag UTF8String])? YES : NO;
}

- (void) addTag:(NSString *)tag {
  ptr->AddTag([tag UTF8String]);
}

- (void) removeTag:(NSString *)tag {
  try {
    ptr->RemoveTag([tag UTF8String]);
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
}

- (SECommonStringsSetIterator *) tagsBegin {
  return [[SECommonStringsSetIterator alloc]
      initFromInternalStringsSetIterator:ptr->TagsBegin()];
}

- (SECommonStringsSetIterator *) tagsEnd {
  return [[SECommonStringsSetIterator alloc]
      initFromInternalStringsSetIterator:ptr->TagsEnd()];
}

- (void) serialize:(SECommonSerializer *)serializer {
  ptr->Serialize([serializer getInternalSerializer]);
}

@end


@implementation SEDocTagsCollection {
  std::unique_ptr<se::doc::DocTagsCollection> internal;
}

- (instancetype) initFromCreatedTagsCollection:(se::doc::DocTagsCollection *)collptr {
  if (self = [super init]) {
    internal.reset(collptr);
  }
  return self;
}

- (se::doc::DocTagsCollection &) getInternalTagsCollection {
  return *internal;
}

- (instancetype) init {
  if (self = [super init]) {
    internal.reset(se::doc::DocTagsCollection::Create());
  }
  return self;
}

- (SEDocTagsCollectionRef *) getRef {
  return [[SEDocTagsCollectionRef alloc]
      initFromInternalTagsCollectionPointer:internal.get()
                         withMutabilityFlag:NO];
}

- (SEDocTagsCollectionRef *) getMutableRef {
  return [[SEDocTagsCollectionRef alloc]
      initFromInternalTagsCollectionPointer:internal.get()
                         withMutabilityFlag:YES];
}

@end
