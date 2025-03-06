/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_BASIC_OBJECTS_ITERATOR_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_BASIC_OBJECTS_ITERATOR_H_INCLUDED

#import <objcdocengine/doc_basic_objects_iterator.h>

#include <docengine/doc_basic_objects_iterator.h>

@interface SEDocBasicObjectsIterator (Internal)

- (instancetype) initFromInternalBasicObjectsIterator:(const se::doc::DocBasicObjectsIterator &)iter;
- (const se::doc::DocBasicObjectsIterator &) getInternalBasicObjectsIterator;

@end


@interface SEDocBasicObjectsMutableIterator (Internal)

- (instancetype) initFromInternalBasicObjectsMutableIterator:(const se::doc::DocBasicObjectsMutableIterator &)iter;
- (const se::doc::DocBasicObjectsMutableIterator &) getInternalBasicObjectsMutableIterator;

@end


@interface SEDocBasicObjectsSliceIterator (Internal)

- (instancetype) initFromInternalBasicObjectsSliceIterator:(const se::doc::DocBasicObjectsSliceIterator &)iter;
- (const se::doc::DocBasicObjectsSliceIterator &) getInternalBasicObjectsSliceIterator;

@end


@interface SEDocBasicObjectsMutableSliceIterator (Internal)

- (instancetype) initFromInternalBasicObjectsMutableSliceIterator:(const se::doc::DocBasicObjectsMutableSliceIterator &)iter;
- (const se::doc::DocBasicObjectsMutableSliceIterator &) getInternalBasicObjectsMutableSliceIterator;

@end


@interface SEDocBasicObjectsCrossSliceIterator (Internal)

- (instancetype) initFromInternalBasicObjectsCrossSliceIterator:(const se::doc::DocBasicObjectsCrossSliceIterator &)iter;
- (const se::doc::DocBasicObjectsCrossSliceIterator &) getInternalBasicObjectsCrossSliceIterator;

@end


@interface SEDocBasicObjectsMutableCrossSliceIterator (Internal)

- (instancetype) initFromInternalBasicObjectsMutableCrossSliceIterator:(const se::doc::DocBasicObjectsMutableCrossSliceIterator &)iter;
- (const se::doc::DocBasicObjectsMutableCrossSliceIterator &) getInternalBasicObjectsMutableCrossSliceIterator;

@end


@interface SEDocTextObjectsIterator (Internal)

- (instancetype) initFromInternalTextObjectsIterator:(const se::doc::DocTextObjectsIterator &)iter;
- (const se::doc::DocTextObjectsIterator &) getInternalBasicObjectsIterator;

@end


#endif // OBJCDOCENGINE_IMPL_DOC_BASIC_OBJECTS_ITERATOR_H_INCLUDED
