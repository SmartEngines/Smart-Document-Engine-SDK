/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_GRAPHICAL_STRUCTURE_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_GRAPHICAL_STRUCTURE_H_INCLUDED

#import <objcdocengine/doc_graphical_structure.h>

#include <docengine/doc_graphical_structure.h>

@interface SEDocGraphicalStructureRef (Internal)

- (instancetype) initFromInternalGraphicalStructurePointer:(se::doc::DocGraphicalStructure *)gsptr
                                        withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocGraphicalStructure *) getInternalGraphicalStructurePointer;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_GRAPHICAL_STRUCTURE_H_INCLUDED