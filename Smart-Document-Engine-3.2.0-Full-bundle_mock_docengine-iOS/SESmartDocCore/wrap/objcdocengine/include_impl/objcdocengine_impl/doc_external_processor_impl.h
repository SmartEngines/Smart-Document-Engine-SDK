/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_EXTERNAL_PROCESSOR_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_EXTERNAL_PROCESSOR_H_INCLUDED

#import <objcdocengine/doc_external_processor.h>

#include <docengine/doc_external_processor.h>

@interface SEDocProcessingArgumentsRef (Internal)

- (instancetype) initFromInternalProcessingArgumentsPointer:(se::doc::DocProcessingArguments *)argsptr
                                         withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocProcessingArguments *) getInternalProcessingArgumentsPointer;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_EXTERNAL_PROCESSOR_H_INCLUDED