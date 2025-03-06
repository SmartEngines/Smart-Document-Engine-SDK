/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_VIEW_H_INCLUDED
#define OBJCDOCENGINE_DOC_VIEW_H_INCLUDED

#import <Foundation/Foundation.h>

#import <objcsecommon/se_common.h>
#import <objcdocengine/doc_forward_declarations.h>

@interface SEDocViewRef : NSObject

+ (nonnull NSString *) baseClassNameStatic;

- (BOOL) isMutable;

- (nonnull SECommonImageRef *) getImage;
- (nonnull SECommonImageRef *) getMutableImage;
- (void) setImageTo:(nonnull SECommonImageRef *)image;

- (int) getAncestorID;
- (void) setAncestorIDTo:(int)anc_id;

- (int) getRootAncestorID;
- (void) setRootAncestorIDTo:(int)root_anc_id;

- (nonnull SECommonProjectiveTransform *) getTransform;
- (void) setTransformTo:(nonnull SECommonProjectiveTransform *)transform;

- (void) serialize:(nonnull SECommonSerializer *)serializer;

@end

#endif // OBJCDOCENGINE_DOC_VIEW_H_INCLUDED