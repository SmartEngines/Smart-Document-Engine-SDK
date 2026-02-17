/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
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
- (const se::doc::DocTextObjectsIterator &) getInternalTextObjectsIterator;

@end

@interface SEDocForensicCheckObjectsIterator (Internal)

- (instancetype) initFromInternalForensicCheckObjectsIterator:(const se::doc::DocForensicCheckObjectsIterator &)iter;
- (const se::doc::DocForensicCheckObjectsIterator &) getInternalForensicCheckObjectsIterator;

@end

@interface SEDocImageObjectsIterator (Internal)

- (instancetype) initFromInternalImageObjectsIterator:(const se::doc::DocImageObjectsIterator &)iter;
- (const se::doc::DocImageObjectsIterator &) getInternalImageObjectsIterator;

@end

@interface SEDocTableObjectsIterator (Internal)

- (instancetype) initFromInternalTableObjectsIterator:(const se::doc::DocTableObjectsIterator &)iter;
- (const se::doc::DocTableObjectsIterator &) getInternalTableObjectsIterator;

@end

@interface SEDocBarcodeObjectsIterator (Internal)

- (instancetype) initFromInternalBarcodeObjectsIterator:(const se::doc::DocBarcodeObjectsIterator &)iter;
- (const se::doc::DocBarcodeObjectsIterator &) getInternalBarcodeObjectsIterator;

@end

@interface SEDocCheckboxObjectsIterator (Internal)

- (instancetype) initFromInternalCheckboxObjectsIterator:(const se::doc::DocCheckboxObjectsIterator &)iter;
- (const se::doc::DocCheckboxObjectsIterator &) getInternalCheckboxObjectsIterator;

@end

@interface SEDocMetaObjectsIterator (Internal)

- (instancetype) initFromInternalMetaObjectsIterator:(const se::doc::DocMetaObjectsIterator &)iter;
- (const se::doc::DocMetaObjectsIterator &) getInternalMetaObjectsIterator;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_BASIC_OBJECTS_ITERATOR_H_INCLUDED
