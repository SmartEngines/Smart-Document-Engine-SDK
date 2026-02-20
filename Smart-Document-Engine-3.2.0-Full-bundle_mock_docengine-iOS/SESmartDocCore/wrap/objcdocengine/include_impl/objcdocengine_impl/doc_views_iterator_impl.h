/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_VIEWS_ITERATOR_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_VIEWS_ITERATOR_H_INCLUDED

#import <objcdocengine/doc_views_iterator.h>

#include <docengine/doc_views_iterator.h>

@interface SEDocViewsIterator (Internal)

- (instancetype) initFromInternalViewsIterator:(const se::doc::DocViewsIterator &)iter;
- (const se::doc::DocViewsIterator &) getInternalViewsIterator;

@end


@interface SEDocViewsMutableIterator (Internal)

- (instancetype) initFromInternalViewsMutableIterator:(const se::doc::DocViewsMutableIterator &)iter;
- (const se::doc::DocViewsMutableIterator &) getInternalViewsMutableIterator;

@end


@interface SEDocViewsSliceIterator (Internal)

- (instancetype) initFromInternalViewsSliceIterator:(const se::doc::DocViewsSliceIterator &)iter;
- (const se::doc::DocViewsSliceIterator &) getInternalViewsSliceIterator;

@end


@interface SEDocViewsMutableSliceIterator (Internal)

- (instancetype) initFromInternalViewsMutableSliceIterator:(const se::doc::DocViewsMutableSliceIterator &)iter;
- (const se::doc::DocViewsMutableSliceIterator &) getInternalViewsMutableSliceIterator;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_VIEWS_ITERATOR_H_INCLUDED