/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_VIEW_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_VIEW_H_INCLUDED

#import <objcdocengine/doc_view.h>

#include <docengine/doc_view.h>

@interface SEDocViewRef (Internal)

- (instancetype) initFromInternalViewPointer:(se::doc::DocView *)viewptr
                          withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocView *) getInternalViewPointer;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_VIEW_H_INCLUDED