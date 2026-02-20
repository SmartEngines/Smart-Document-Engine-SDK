/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_RESULT_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_RESULT_H_INCLUDED

#import <objcdocengine/doc_result.h>

#include <docengine/doc_result.h>

@interface SEDocResultRef (Internal)

- (instancetype) initFromInternalResultPointer:(se::doc::DocResult *)resptr
                            withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocResult *) getInternalResultPointer;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_RESULT_H_INCLUDED