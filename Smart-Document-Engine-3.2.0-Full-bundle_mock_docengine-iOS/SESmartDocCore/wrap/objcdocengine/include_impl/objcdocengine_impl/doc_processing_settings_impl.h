/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_PROCESSING_SETTINGS_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_PROCESSING_SETTINGS_H_INCLUDED

#import <objcdocengine/doc_processing_settings.h>

#include <docengine/doc_processing_settings.h>

@interface SEDocProcessingSettingsRef (Internal)

- (instancetype) initFromInternalProcessingSettingsPointer:(se::doc::DocProcessingSettings *)settingsptr
                                        withMutabilityFlag:(BOOL)mutabilityFlag;
- (se::doc::DocProcessingSettings *) getInternalProcessingSettingsPointer;

@end


@interface SEDocProcessingSettings (Internal)

- (instancetype) initFromCreatedProcessingSettings:(se::doc::DocProcessingSettings *)settingsptr;
- (se::doc::DocProcessingSettings &) getInternalProcessingSettings;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_PROCESSING_SETTINGS_H_INCLUDED