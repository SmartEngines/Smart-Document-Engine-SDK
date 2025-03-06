/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_fields_impl.h>

#import <objcsecommon_impl/se_serialization_impl.h>
#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocTableFieldRef {
  se::doc::DocTableField* ptr;
  bool is_mutable;
}

- (instancetype) initFromInternalTableFieldPointer:(se::doc::DocTableField *)fieldptr
                               withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = fieldptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocTableField *) getInternalTableFieldPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (SEDocBaseFieldInfoRef *) getBaseFieldInfo {
  return [[SEDocBaseFieldInfoRef alloc]
      initFromInternalBaseFieldInfoPointer:const_cast<se::doc::DocBaseFieldInfo*>(&ptr->GetBaseFieldInfo())
                        withMutabilityFlag:NO];
}

- (SEDocBaseFieldInfoRef *) getMutableBaseFieldInfo {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    return [[SEDocBaseFieldInfoRef alloc]
        initFromInternalBaseFieldInfoPointer:&ptr->GetMutableBaseFieldInfo()
                          withMutabilityFlag:YES];
  }
  return nil;
}

- (int) getRowsCount {
  return ptr->GetRowsCount();
}

- (int) getColsCount {
  return ptr->GetColsCount();
}

- (SEDocTextFieldRef *) getCellAtRow:(int)row
                               atCol:(int)col {
  try {
    return [[SEDocTextFieldRef alloc]
        initFromInternalTextFieldPointer:const_cast<se::doc::DocTextField*>(&ptr->GetCell(row, col))
                      withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}


- (SEDocTextFieldRef *) getMutableCellAtRow:(int)row
                                      atCol:(int)col {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocTextFieldRef alloc]
          initFromInternalTextFieldPointer:&ptr->GetMutableCell(row, col)
                        withMutabilityFlag:YES];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (NSString *) getColNameFor:(int)col {
  try {
    return [NSString stringWithUTF8String:ptr->GetColName(col)];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (void) setColNameFor:(int)col
                    to:(NSString *)col_name {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->SetColName(col, [col_name UTF8String]);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (void) serialize:(SECommonSerializer *)serializer {
  ptr->Serialize([serializer getInternalSerializer]);
}

@end
