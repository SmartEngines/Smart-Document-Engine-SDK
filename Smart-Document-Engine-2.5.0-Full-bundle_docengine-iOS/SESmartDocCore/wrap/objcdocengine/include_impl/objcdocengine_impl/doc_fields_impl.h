/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_FIELDS_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_FIELDS_H_INCLUDED

#import <objcdocengine/doc_fields.h>

#include <docengine/doc_fields.h>

@interface SEDocBaseFieldInfoRef (Internal)

- (instancetype) initFromInternalBaseFieldInfoPointer:(se::doc::DocBaseFieldInfo *)infoptr
                                   withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocBaseFieldInfo *) getInternalBaseFieldInfoPointer;

@end


@interface SEDocTextFieldRef (Internal)

- (instancetype) initFromInternalTextFieldPointer:(se::doc::DocTextField *)fieldptr
                               withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocTextField *) getInternalTextFieldPointer;

@end


@interface SEDocImageFieldRef (Internal)

- (instancetype) initFromInternalImageFieldPointer:(se::doc::DocImageField *)fieldptr
                                withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocImageField *) getInternalImageFieldPointer;

@end


@interface SEDocCheckboxFieldRef (Internal)

- (instancetype) initFromInternalCheckboxFieldPointer:(se::doc::DocCheckboxField *)fieldptr
                                   withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocCheckboxField *) getInternalCheckboxFieldPointer;

@end


@interface SEDocForensicFieldRef (Internal)

- (instancetype) initFromInternalForensicFieldPointer:(se::doc::DocForensicField *)fieldptr
                                   withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocForensicField *) getInternalForensicFieldPointer;

@end


@interface SEDocTableFieldRef (Internal)

- (instancetype) initFromInternalTableFieldPointer:(se::doc::DocTableField *)fieldptr
                                withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocTableField *) getInternalTableFieldPointer;

@end

@interface SEDocBarcodeFieldRef (Internal)

- (instancetype) initFromInternalBarcodeFieldPointer:(se::doc::DocBarcodeField *)fieldptr
                                withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocBarcodeField *) getInternalBarcodeFieldPointer;

@end


#endif // OBJCDOCENGINE_IMPL_DOC_FIELDS_H_INCLUDED