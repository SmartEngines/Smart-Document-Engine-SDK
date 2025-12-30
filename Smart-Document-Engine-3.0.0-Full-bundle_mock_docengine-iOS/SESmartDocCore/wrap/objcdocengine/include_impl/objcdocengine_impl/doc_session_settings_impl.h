/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_SESSION_SETTINGS_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_SESSION_SETTINGS_H_INCLUDED

#import <objcdocengine/doc_session_settings.h>

#include <docengine/doc_session_settings.h>

@interface SEDocSessionSettings (Internal)

- (instancetype) initFromCreatedSessionSettings:(se::doc::DocSessionSettings *)settingsptr;
- (const se::doc::DocSessionSettings &) getInternalSessionSettings;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_SESSION_SETTINGS_H_INCLUDED