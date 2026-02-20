/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_ENGINE_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_ENGINE_H_INCLUDED

#import <objcdocengine/doc_engine.h>

#include <docengine/doc_engine.h>

@interface SEDocEngine (Internal)

- (se::doc::DocEngine &) getInternalEngine;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_ENGINE_H_INCLUDED