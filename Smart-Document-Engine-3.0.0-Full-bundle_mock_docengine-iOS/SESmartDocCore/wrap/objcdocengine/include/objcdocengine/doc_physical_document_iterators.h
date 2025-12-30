/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_PHYSICAL_DOCUMENT_ITERATORS_H_INCLUDED
#define OBJCDOCENGINE_PHYSICAL_DOCUMENT_ITERATORS_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_basic_object.h>

@interface SEDocTextObjectsCrossPageIterator : NSObject

- (nonnull instancetype) initWithOther:(nonnull SEDocTextObjectsCrossPageIterator *)other;
- (BOOL) isEqualToIter:(nonnull SEDocTextObjectsCrossPageIterator *)other;

- (int) getPhysicalPageID;
- (nonnull SEDocTextObjectRef *) getTextObject;

- (void) advance;

@end

#endif // OBJCDOCENGINE_PHYSICAL_DOCUMENT_ITERATORS_H_INCLUDED


