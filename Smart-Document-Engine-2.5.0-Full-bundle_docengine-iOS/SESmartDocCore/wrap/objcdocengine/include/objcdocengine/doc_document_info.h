/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#ifndef OBJCDOCENGINE_DOC_DOCUMENT_INFO_H_INCLUDED
#define OBJCDOCENGINE_DOC_DOCUMENT_INFO_H_INCLUDED

#import <Foundation/Foundation.h>

@interface SEDocDocumentInfoRef : NSObject 

- (nonnull NSString *) getDocumentName;
- (nonnull NSString *) getDocumentNameLocal;
- (nonnull NSString *) getDocumentShortNameLocal;
- (BOOL) getDocumentMultipageInfo;

@end

#endif // OBJCDOCENGINE_DOC_DOCUMENT_INFO_H_INCLUDED