/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_objects_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocTemplateObjectRef {
  se::doc::DocTemplateObject* ptr;
  bool is_mutable;
}

+ (NSString *) objectTypeStatic {
  return [NSString stringWithUTF8String:se::doc::DocTemplateObject::ObjectTypeStatic()];
}

- (instancetype) initFromInternalTemplateObjectPointer:(se::doc::DocTemplateObject *)objptr
                                    withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = objptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocTemplateObject *) getInternalTemplateObjectPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

@end
