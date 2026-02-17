/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_IMPL_DOC_VIDEO_SESSION_H_INCLUDED
#define OBJCDOCENGINE_IMPL_DOC_VIDEO_SESSION_H_INCLUDED

#import <objcdocengine/doc_video_session.h>
#import <objcdocengine_impl/doc_proxy_impl.h>

#include <docengine/doc_video_session.h>

@interface SEDocVideoSession (Internal)

- (instancetype) initFromCreatedVideoSession:(se::doc::DocVideoSession *)sessionptr
                    withCreatedProxyFeedback:(ProxyFeedback *)feedback_reporter;
- (se::doc::DocVideoSession &) getInternalVideoSession;

@end

#endif // OBJCDOCENGINE_IMPL_DOC_VIDEO_SESSION_H_INCLUDED
