/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_basic_object_impl.h>

#import <objcsecommon_impl/se_geometry_impl.h>
#import <objcsecommon_impl/se_serialization_impl.h>
#import <objcsecommon_impl/se_common_proxy_impl.h>
#import <objcsecommon_impl/se_strings_iterator_impl.h>

@implementation SEDocBaseObjectInfoRef {
  se::doc::DocBaseObjectInfo* ptr;
  bool is_mutable;
}

- (instancetype) initFromInternalBaseObjectInfoPointer:(se::doc::DocBaseObjectInfo *)infoptr
                                    withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = infoptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocBaseObjectInfo *) getInternalBaseObjectInfoPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (int) getViewID {
  return ptr->GetViewID();
}

- (void) setViewIDTo:(int)view_id {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    ptr->SetViewID(view_id);
  }
}

- (double) getConfidence {
  return ptr->GetConfidence();
}

- (void) setConfidenceTo:(double)conf {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    ptr->SetConfidence(conf);
  }
}
 
- (BOOL) getAcceptFlag {
  return ptr->GetAcceptFlag()? YES : NO;
}

- (void) setAcceptFlagTo:(BOOL)is_accepted {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    ptr->SetAcceptFlag(YES == is_accepted);
  }
}

- (SECommonPolygon *) getGeometry {
    return [[SECommonPolygon alloc] initFromInternalPolygon:ptr->GetGeometryOnPage()];
}

- (void) setGeometryTo:(SECommonPolygon *)geometry {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    ptr->SetGeometry([geometry getInternalPolygon]);
  }
}

- (int) getAttributesCount {
  return ptr->GetAttributesCount();
}

- (BOOL) hasAttributeWithName:(NSString *)attr_name {
  return ptr->HasAttribute([attr_name UTF8String])? YES : NO;
}

- (NSString *) getAttributeWithName:(NSString *)attr_name {
  try {
    return [NSString stringWithUTF8String:ptr->GetAttribute([attr_name UTF8String])];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (void) setAttributeWithName:(NSString *)attr_name
                           to:(NSString *)attr_value {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->SetAttribute([attr_name UTF8String], [attr_value UTF8String]);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (void) removeAttributeWithName:(NSString *)attr_name {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->RemoveAttribute([attr_name UTF8String]);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (SECommonStringsMapIterator *) attributesBegin {
  return [[SECommonStringsMapIterator alloc]
      initFromInternalStringsMapIterator:ptr->AttributesBegin()];
}

- (SECommonStringsMapIterator *) attributesEnd {
  return [[SECommonStringsMapIterator alloc]
      initFromInternalStringsMapIterator:ptr->AttributesEnd()];
}

- (void) serialize:(SECommonSerializer *)serializer {
  ptr->Serialize([serializer getInternalSerializer]);
}

@end
