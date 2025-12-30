/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_fields_impl.h>

#import <objcdocengine_impl/doc_basic_objects_iterator_impl.h>
#import <objcdocengine_impl/doc_graphical_structure_impl.h>

#import <objcsecommon_impl/se_strings_iterator_impl.h>
#import <objcsecommon_impl/se_serialization_impl.h>
#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocBaseFieldInfoRef {
  se::doc::DocBaseFieldInfo* ptr;
  bool is_mutable;
}

- (instancetype) initFromInternalBaseFieldInfoPointer:(se::doc::DocBaseFieldInfo *)infoptr
                                   withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = infoptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocBaseFieldInfo *) getInternalBaseFieldInfoPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (NSString *) getName {
  return [NSString stringWithUTF8String:ptr->GetName()];
}

- (void) setNameTo:(NSString *)name {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    ptr->SetName([name UTF8String]);
  }
}

- (double) getConfidence {
  return ptr->GetConfidence();
}

- (void) setConfidenceTo:(double)confidence {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->SetConfidence(confidence);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (BOOL) getAcceptFlag {
  return ptr->GetAcceptFlag()? YES : NO;
}

- (void) setAcceptFlatTo:(BOOL)is_accepted {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    ptr->SetAcceptFlag(YES == is_accepted);
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

- (void) connectBasicObjectWithCollectionID:(int)coll_id
                               withObjectID:(int)obj_id {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->ConnectBasicObject(coll_id, obj_id);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (SEDocBasicObjectsCrossSliceIterator *) connectedBasicObjectsFromGraphicalStructureBegin:(SEDocGraphicalStructureRef *)graphical {
  return [[SEDocBasicObjectsCrossSliceIterator alloc]
      initFromInternalBasicObjectsCrossSliceIterator:ptr->ConnectedBasicObjectsBegin(
          *[graphical getInternalGraphicalStructurePointer])];
}

- (SEDocBasicObjectsCrossSliceIterator *) connectedBasicObjectsFromGraphicalStructureEnd:(SEDocGraphicalStructureRef *)graphical {
  return [[SEDocBasicObjectsCrossSliceIterator alloc]
      initFromInternalBasicObjectsCrossSliceIterator:ptr->ConnectedBasicObjectsEnd(
          *[graphical getInternalGraphicalStructurePointer])];
}

- (SEDocBasicObjectsMutableCrossSliceIterator *) mutableConnectedBasicObjectsFromGraphicalStructureBegin:(SEDocGraphicalStructureRef *)graphical {
  if (!is_mutable || (NO == [graphical isMutable])) {
    throwNonMutableRefException();
  } else {
    return [[SEDocBasicObjectsMutableCrossSliceIterator alloc]
      initFromInternalBasicObjectsMutableCrossSliceIterator:ptr->MutableConnectedBasicObjectsBegin(
          *[graphical getInternalGraphicalStructurePointer])];
  }
  return nil;
}

- (SEDocBasicObjectsMutableCrossSliceIterator *) mutableConnectedBasicObjectsFromGraphicalStructureEnd:(SEDocGraphicalStructureRef *)graphical {
  if (!is_mutable || (NO == [graphical isMutable])) {
    throwNonMutableRefException();
  } else {
    return [[SEDocBasicObjectsMutableCrossSliceIterator alloc]
      initFromInternalBasicObjectsMutableCrossSliceIterator:ptr->MutableConnectedBasicObjectsEnd(
          *[graphical getInternalGraphicalStructurePointer])];
  }
  return nil;
}

- (void) serialize:(SECommonSerializer *)serializer {
  ptr->Serialize([serializer getInternalSerializer]);
}

@end
