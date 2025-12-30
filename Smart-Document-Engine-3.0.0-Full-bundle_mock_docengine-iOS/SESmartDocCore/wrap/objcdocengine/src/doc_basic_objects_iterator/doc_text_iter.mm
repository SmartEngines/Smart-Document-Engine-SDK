/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_basic_objects_iterator_impl.h>
#import <objcdocengine_impl/doc_objects_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

#include <memory>

@implementation SEDocTextObjectsIterator {
  std::unique_ptr<se::doc::DocTextObjectsIterator> internal;
}

- (instancetype) initFromInternalTextObjectsIterator:(const se::doc::DocTextObjectsIterator &)iter {
  if (self = [super init]) {
    internal.reset(new se::doc::DocTextObjectsIterator(iter));
  }
  return self;
}

- (const se::doc::DocTextObjectsIterator &) getInternalTextObjectsIterator {
  return *internal;
}

- (instancetype) initWithOther:(SEDocTextObjectsIterator *)other {
  if (self = [super init]) {
    internal.reset(new se::doc::DocTextObjectsIterator([other getInternalTextObjectsIterator]));
  }
  return self;
}

- (BOOL) isEqualToIter:(SEDocTextObjectsIterator *)other {
  return internal->Equals([other getInternalTextObjectsIterator])? YES : NO;
}

- (SEDocTextObjectRef *) getTextObject {
  return [[SEDocTextObjectRef alloc]
      initFromInternalTextObjectPointer:const_cast<se::doc::DocTextObject*>(&internal->GetTextObject())
                      withMutabilityFlag:NO];
}

- (void) advance {
  internal->Advance();
}

@end
