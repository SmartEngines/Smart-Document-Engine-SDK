/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_objects_impl.h>
#import <objcdocengine_impl/doc_basic_object_impl.h>

#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocTableObjectRef {
  se::doc::DocTableObject* ptr;
  bool is_mutable;
}

+ (NSString *) objectTypeStatic {
  return [NSString stringWithUTF8String:se::doc::DocTableObject::ObjectTypeStatic()];
}

- (instancetype) initFromInternalTableObjectPointer:(se::doc::DocTableObject *)objptr
                                 withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = objptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::DocTableObject *) getInternalTableObjectPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (int) getRowsCount {
  return ptr->GetRowsCount();
}

- (int) getColsCountForRow:(int)row {
  try {
    return ptr->GetColsCount(row);
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return -1;
}

- (SEDocMultiStringTextObjectRef *) getCellAtRow:(int)row
                                           atCol:(int)col {
  try {
    return [[SEDocMultiStringTextObjectRef alloc]
        initFromInternalMultiStringTextObjectPointer:const_cast<se::doc::DocMultiStringTextObject*>(&ptr->GetCell(row, col))
                                  withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SEDocMultiStringTextObjectRef *) getMutableCellAtRow:(int)row
                                                  atCol:(int)col {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocMultiStringTextObjectRef alloc]
          initFromInternalMultiStringTextObjectPointer:&ptr->GetMutableCell(row, col)
                                    withMutabilityFlag:YES];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (void) resizeRowsTo:(int)rows {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->ResizeRows(rows);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (void) resizeColsAtRow:(int)row
                      to:(int)cols {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->ResizeCols(row, cols);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (NSString *) getColNameForCol:(int)col
                         forRow:(int)row {
  try {
    return [NSString stringWithUTF8String:ptr->GetColName(col, row)];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (void) setColNameForCol:(int)col
             withFirstRow:(int)first_row
                       to:(NSString *)col_name {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->SetColName(col, first_row, [col_name UTF8String]);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (nonnull SEDocBaseObjectInfoRef *)getBaseObjectInfo {
  try {
    return [[SEDocBaseObjectInfoRef alloc]
            initFromInternalBaseObjectInfoPointer:const_cast<se::doc::DocBaseObjectInfo*>(&ptr->GetBaseObjectInfo())
            withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

@end
