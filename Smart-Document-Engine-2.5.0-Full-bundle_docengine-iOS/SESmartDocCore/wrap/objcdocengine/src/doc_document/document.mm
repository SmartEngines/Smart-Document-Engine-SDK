/*
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

#import <objcdocengine_impl/doc_document_impl.h>

#import <objcdocengine_impl/doc_fields_impl.h>
#import <objcdocengine_impl/doc_fields_iterators_impl.h>

#import <objcsecommon_impl/se_strings_iterator_impl.h>
#import <objcsecommon_impl/se_serialization_impl.h>
#import <objcsecommon_impl/se_common_proxy_impl.h>

@implementation SEDocumentRef {
  se::doc::Document* ptr;
  bool is_mutable;
}

+ (NSString *) baseClassNameStatic {
  return [NSString stringWithUTF8String:se::doc::Document::BaseClassNameStatic()];
}

- (instancetype) initFromInternalDocumentPointer:(se::doc::Document *)docptr
                              withMutabilityFlag:(BOOL)mutabilityFlag {
  if (self = [super init]) {
    ptr = docptr;
    is_mutable = (YES == mutabilityFlag);
  }
  return self;
}

- (se::doc::Document *) getInternalDocumentPointer {
  return ptr;
}

- (BOOL) isMutable {
  return is_mutable? YES : NO;
}

- (int) getTextFieldsCount {
  return ptr->GetTextFieldsCount();
}

- (BOOL) hasTextFieldWithName:(NSString *)name {
  return ptr->HasTextField([name UTF8String])? YES : NO;
}

- (SEDocTextFieldRef *) getTextFieldWithName:(NSString *)name {
  try {
    return [[SEDocTextFieldRef alloc]
        initFromInternalTextFieldPointer:const_cast<se::doc::DocTextField*>(&ptr->GetTextField([name UTF8String]))
                      withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SEDocTextFieldRef *) getMutableTextFieldWithName:(NSString *)name {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocTextFieldRef alloc]
          initFromInternalTextFieldPointer:&ptr->GetMutableTextField([name UTF8String])
                        withMutabilityFlag:YES];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (void) removeTextFieldWithName:(NSString *)name {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->RemoveTextField([name UTF8String]);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (SEDocTextFieldsIterator *) textFieldsBegin {
  return [[SEDocTextFieldsIterator alloc]
      initFromInternalTextFieldsIterator:ptr->TextFieldsBegin()];
}

- (SEDocTextFieldsIterator *) textFieldsEnd {
  return [[SEDocTextFieldsIterator alloc]
      initFromInternalTextFieldsIterator:ptr->TextFieldsEnd()];
}


- (int) getImageFieldsCount {
  return ptr->GetImageFieldsCount();
}

- (BOOL) hasImageFieldWithName:(NSString *)name {
  return ptr->HasImageField([name UTF8String])? YES : NO;
}

- (SEDocImageFieldRef *) getImageFieldWithName:(NSString *)name {
  try {
    return [[SEDocImageFieldRef alloc]
        initFromInternalImageFieldPointer:const_cast<se::doc::DocImageField*>(&ptr->GetImageField([name UTF8String]))
                       withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SEDocImageFieldRef *) getMutableImageFieldWithName:(NSString *)name {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocImageFieldRef alloc]
          initFromInternalImageFieldPointer:&ptr->GetMutableImageField([name UTF8String])
                         withMutabilityFlag:YES];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (void) removeImageFieldWithName:(NSString *)name {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->RemoveImageField([name UTF8String]);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (SEDocImageFieldsIterator *) imageFieldsBegin {
  return [[SEDocImageFieldsIterator alloc]
      initFromInternalImageFieldsIterator:ptr->ImageFieldsBegin()];
}

- (SEDocImageFieldsIterator *) imageFieldsEnd {
  return [[SEDocImageFieldsIterator alloc]
      initFromInternalImageFieldsIterator:ptr->ImageFieldsEnd()];
}


- (int) getCheckboxFieldsCount {
  return ptr->GetCheckboxFieldsCount();
}

- (BOOL) hasCheckboxFieldWithName:(NSString *)name {
  return ptr->HasCheckboxField([name UTF8String])? YES : NO;
}

- (SEDocCheckboxFieldRef *) getCheckboxFieldWithName:(NSString *)name {
  try {
    return [[SEDocCheckboxFieldRef alloc]
        initFromInternalCheckboxFieldPointer:const_cast<se::doc::DocCheckboxField*>(&ptr->GetCheckboxField([name UTF8String]))
                       withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SEDocCheckboxFieldRef *) getMutableCheckboxFieldWithName:(NSString *)name {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocCheckboxFieldRef alloc]
          initFromInternalCheckboxFieldPointer:&ptr->GetMutableCheckboxField([name UTF8String])
                         withMutabilityFlag:YES];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (void) removeCheckboxFieldWithName:(NSString *)name {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->RemoveCheckboxField([name UTF8String]);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (SEDocCheckboxFieldsIterator *) checkboxFieldsBegin {
  return [[SEDocCheckboxFieldsIterator alloc]
      initFromInternalCheckboxFieldsIterator:ptr->CheckboxFieldsBegin()];
}

- (SEDocCheckboxFieldsIterator *) checkboxFieldsEnd {
  return [[SEDocCheckboxFieldsIterator alloc]
      initFromInternalCheckboxFieldsIterator:ptr->CheckboxFieldsEnd()];
}


- (int) getForensicFieldsCount {
  return ptr->GetForensicFieldsCount();
}

- (BOOL) hasForensicFieldWithName:(NSString *)name {
  return ptr->HasForensicField([name UTF8String])? YES : NO;
}

- (SEDocForensicFieldRef *) getForensicFieldWithName:(NSString *)name {
  try {
    return [[SEDocForensicFieldRef alloc]
        initFromInternalForensicFieldPointer:const_cast<se::doc::DocForensicField*>(&ptr->GetForensicField([name UTF8String]))
                       withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SEDocForensicFieldRef *) getMutableForensicFieldWithName:(NSString *)name {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocForensicFieldRef alloc]
          initFromInternalForensicFieldPointer:&ptr->GetMutableForensicField([name UTF8String])
                         withMutabilityFlag:YES];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (void) removeForensicFieldWithName:(NSString *)name {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->RemoveForensicField([name UTF8String]);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (SEDocForensicFieldsIterator *) forensicFieldsBegin {
  return [[SEDocForensicFieldsIterator alloc]
      initFromInternalForensicFieldsIterator:ptr->ForensicFieldsBegin()];
}

- (SEDocForensicFieldsIterator *) forensicFieldsEnd {
  return [[SEDocForensicFieldsIterator alloc]
      initFromInternalForensicFieldsIterator:ptr->ForensicFieldsEnd()];
}


- (int) getTableFieldsCount {
  return ptr->GetTableFieldsCount();
}

- (BOOL) hasTableFieldWithName:(NSString *)name {
  return ptr->HasTableField([name UTF8String])? YES : NO;
}

- (SEDocTableFieldRef *) getTableFieldWithName:(NSString *)name {
  try {
    return [[SEDocTableFieldRef alloc]
        initFromInternalTableFieldPointer:const_cast<se::doc::DocTableField*>(&ptr->GetTableField([name UTF8String]))
                       withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SEDocTableFieldRef *) getMutableTableFieldWithName:(NSString *)name {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocTableFieldRef alloc]
          initFromInternalTableFieldPointer:&ptr->GetMutableTableField([name UTF8String])
                         withMutabilityFlag:YES];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (void) removeTableFieldWithName:(NSString *)name {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->RemoveTableField([name UTF8String]);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (SEDocTableFieldsIterator *) tableFieldsBegin {
  return [[SEDocTableFieldsIterator alloc]
      initFromInternalTableFieldsIterator:ptr->TableFieldsBegin()];
}

- (SEDocTableFieldsIterator *) tableFieldsEnd {
  return [[SEDocTableFieldsIterator alloc]
      initFromInternalTableFieldsIterator:ptr->TableFieldsEnd()];
}

- (int) getBarcodeFieldsCount {
  return ptr->GetBarcodeFieldsCount();
}

- (BOOL) hasBarcodeField:(NSString *)name {
  return ptr->HasBarcodeField([name UTF8String])? YES : NO;
}

- (SEDocBarcodeFieldRef *) getBarcodeFieldWithName:(NSString *)name {
  try {
    return [[SEDocBarcodeFieldRef alloc]
        initFromInternalBarcodeFieldPointer:const_cast<se::doc::DocBarcodeField*>(&ptr->GetBarcodeField([name UTF8String]))
                       withMutabilityFlag:NO];
  } catch (const se::common::BaseException& e) {
    throwFromException(e);
  }
  return nil;
}

- (SEDocBarcodeFieldRef *) getMutableBarcodeFieldWithName:(NSString *)name {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      return [[SEDocBarcodeFieldRef alloc]
          initFromInternalBarcodeFieldPointer:&ptr->GetMutableBarcodeField([name UTF8String])
                         withMutabilityFlag:YES];
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
  return nil;
}

- (void) removeBarcodeFieldWithName:(NSString *)name {
  if (!is_mutable) {
    throwNonMutableRefException();
  } else {
    try {
      ptr->RemoveBarcodeField([name UTF8String]);
    } catch (const se::common::BaseException& e) {
      throwFromException(e);
    }
  }
}

- (SEDocBarcodeFieldsIterator *) barcodeFieldsBegin {
  return [[SEDocBarcodeFieldsIterator alloc]
      initFromInternalBarcodeFieldsIterator:ptr->BarcodeFieldsBegin()];
}

- (SEDocBarcodeFieldsIterator *) barcodeFieldsEnd {
  return [[SEDocBarcodeFieldsIterator alloc]
      initFromInternalBarcodeFieldsIterator:ptr->BarcodeFieldsEnd()];
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

- (int) getPhysicalDocIdx {
  return ptr->GetPhysicalDocIdx();
}

@end
