/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_FIELDS_ITERATORS_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_FIELDS_ITERATORS_H_INCLUDED

#import <objcdocengine/doc_fields_iterators.h>

#include <docengine/doc_fields_iterators.h>

@interface SEDocTextFieldsIterator (Internal)

- (instancetype) initFromInternalTextFieldsIterator:(const se::doc::DocTextFieldsIterator &)iter;
- (const se::doc::DocTextFieldsIterator &) getInternalTextFieldsIterator;

@end


@interface SEDocImageFieldsIterator (Internal)

- (instancetype) initFromInternalImageFieldsIterator:(const se::doc::DocImageFieldsIterator &)iter;
- (const se::doc::DocImageFieldsIterator &) getInternalImageFieldsIterator;

@end


@interface SEDocCheckboxFieldsIterator (Internal)

- (instancetype) initFromInternalCheckboxFieldsIterator:(const se::doc::DocCheckboxFieldsIterator &)iter;
- (const se::doc::DocCheckboxFieldsIterator &) getInternalCheckboxFieldsIterator;

@end


@interface SEDocForensicFieldsIterator (Internal)

- (instancetype) initFromInternalForensicFieldsIterator:(const se::doc::DocForensicFieldsIterator &)iter;
- (const se::doc::DocForensicFieldsIterator &) getInternalForensicFieldsIterator;

@end


@interface SEDocTableFieldsIterator (Internal)

- (instancetype) initFromInternalTableFieldsIterator:(const se::doc::DocTableFieldsIterator &)iter;
- (const se::doc::DocTableFieldsIterator &) getInternalTableFieldsIterator;

@end


@interface SEDocBarcodeFieldsIterator (Internal)

- (instancetype) initFromInternalBarcodeFieldsIterator:(const se::doc::DocBarcodeFieldsIterator &)iter;
- (const se::doc::DocBarcodeFieldsIterator &) getInternalBarcodeFieldsIterator;

@end


#endif // OBJCDOCENGINE_IMPL_DOC_FIELDS_ITERATORS_H_INCLUDED