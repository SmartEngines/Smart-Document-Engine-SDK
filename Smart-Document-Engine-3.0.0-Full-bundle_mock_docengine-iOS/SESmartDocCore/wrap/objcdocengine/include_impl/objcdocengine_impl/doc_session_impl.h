/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_SESSION_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_SESSION_H_INCLUDED

#import <objcdocengine/doc_session.h>
#import <objcdocengine_impl/doc_proxy_impl.h>

#include <docengine/doc_session.h>

@interface SEDocSession (Internal)

- (instancetype) initFromCreatedSession:(se::doc::DocSession *)sessionptr
               withCreatedProxyFeedback:(ProxyFeedback *)feedback_reporter
      withCreatedProxyExternalProcessor:(ProxyExternalProcessor *)external_processor;
- (se::doc::DocSession &) getInternalSession;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_SESSION_H_INCLUDED
