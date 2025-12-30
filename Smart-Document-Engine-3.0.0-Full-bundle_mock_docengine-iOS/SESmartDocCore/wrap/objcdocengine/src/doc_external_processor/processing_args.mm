/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_external_processor_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocProcessingArgumentsRef {
  se::doc::DocProcessingArguments* ptr;
  bool is_mutable;
}

- (instancetype) initFromInternalProcessingArgumentsPointer:(se::doc::DocProcessingArguments *)argsptr
                                         withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = argsptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocProcessingArguments *) getInternalProcessingArgumentsPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (int) getTagArgumentsCount {
  return ptr->GetTagArgumentsCount();
}

- (NSString *) getTagArgumentAt:(int)index {
  try {
    return [NSString stringWithUTF8String:ptr->GetTagArgument(index)];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (void) setTagArgumentAt:(int)index
                       to:(NSString *)argument {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->SetTagArgument(index, [argument UTF8String]);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (void) resizeTo:(int)size {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->Resize(size);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

@end
