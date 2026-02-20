/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_views_collection_impl.h>

#import <objcdocengine_impl/doc_view_impl.h>
#import <objcdocengine_impl/doc_tags_collection_impl.h>
#import <objcdocengine_impl/doc_views_iterator_impl.h>

#import <objcsecommon_impl/se_serialization_impl.h>
#import <objcsecommon_impl/se_image_impl.h>
#import <objcsecommon_impl/se_geometry_impl.h>
#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocViewsCollectionRef {
  se::doc::DocViewsCollection* ptr;
  bool is_mutable;
}

+ (NSString *) baseClassNameStatic {
  return [NSString stringWithUTF8String:se::doc::DocViewsCollection::BaseClassNameStatic()];
}

- (instancetype) initFromInternalViewsCollectionPointer:(se::doc::DocViewsCollection *)collptr
                                     withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = collptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocViewsCollection *) getInternalViewsCollectionPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (int) getViewsCount {
  return ptr->GetViewsCount();
}

- (BOOL) hasViewWithID:(int)view_id {
  try {
    return ptr->HasView(view_id)? YES : NO;
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return NO;
}

- (SEDocViewRef *) getViewWithID:(int)view_id {
  try {
    return [[SEDocViewRef alloc]
        initFromInternalViewPointer:const_cast<se::doc::DocView*>(&ptr->GetView(view_id))
                 withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;  
}

- (SEDocViewRef *) getMutableViewWithID:(int)view_id {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocViewRef alloc]
          initFromInternalViewPointer:&ptr->GetMutableView(view_id)
                   withMutabilityFlag:YES];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (SEDocTagsCollectionRef *) getViewTagsWithID:(int)view_id {
  try {
    return [[SEDocTagsCollectionRef alloc]
        initFromInternalTagsCollectionPointer:const_cast<se::doc::DocTagsCollection*>(&ptr->GetViewTags(view_id))
                           withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;  
}

- (SEDocViewsMutableIterator *) registerView:(SECommonImageRef *)image {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocViewsMutableIterator alloc]
          initFromInternalViewsMutableIterator:ptr->RegisterView(*[image getInternalImagePointer])];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (SEDocViewsMutableIterator *) registerDerivedView:(SECommonImageRef *)image
                                     withAncestorID:(int)ancestor_id
                                      withTransform:(SECommonProjectiveTransform *)transform {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocViewsMutableIterator alloc]
          initFromInternalViewsMutableIterator:ptr->RegisterDerivedView(
              *[image getInternalImagePointer],
              ancestor_id,
              [transform getInternalProjectiveTransform])];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (void) deleteOrphans {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->DeleteOrphans();
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (void) deleteViewWithID:(int)view_id {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->DeleteView(view_id);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (SEDocViewsIterator *) viewsBegin {
  return [[SEDocViewsIterator alloc]
      initFromInternalViewsIterator:ptr->ViewsBegin()];
}

- (SEDocViewsIterator *) viewsEnd {
  return [[SEDocViewsIterator alloc]
      initFromInternalViewsIterator:ptr->ViewsEnd()];
}

- (SEDocViewsMutableIterator *) mutableViewsBegin {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    return [[SEDocViewsMutableIterator alloc]
        initFromInternalViewsMutableIterator:ptr->MutableViewsBegin()];
  }
  return nil;
}

- (SEDocViewsMutableIterator *) mutableViewsEnd {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    return [[SEDocViewsMutableIterator alloc]
        initFromInternalViewsMutableIterator:ptr->MutableViewsEnd()];
  }
  return nil;
}

- (SEDocViewsSliceIterator *) viewsSliceForTag:(NSString *)tag {
  try {
    return [[SEDocViewsSliceIterator alloc]
        initFromInternalViewsSliceIterator:ptr->ViewsSlice([tag UTF8String])];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;  
}

- (SEDocViewsMutableSliceIterator *) mutableViewsSliceForTag:(NSString *)tag {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocViewsMutableSliceIterator alloc]
          initFromInternalViewsMutableSliceIterator:ptr->MutableViewsSlice([tag UTF8String])];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (void) serialize:(SECommonSerializer *)serializer {
  ptr->Serialize([serializer getInternalSerializer]);
}

@end
