<?php
//  Copyright (c) 2016-2025, Smart Engines Service LLC
//  All rights reserved.

function OutputRecognitionResult($recog_result, $session_settings) {
  printf("Documents: (%d in total)\n", $recog_result->GetDocumentsCount());

  if ($recog_result->GetDocumentsCount() > 0) {
    $doc_it = $recog_result->DocumentsBegin();
    while(!$doc_it->Equals($recog_result->DocumentsEnd())){
      $doc = $doc_it->GetDocument();        
      $phys_id = $doc->GetPhysicalDocIdx();
      $phys_doc = $recog_result->GetPhysicalDocument($phys_id);
      if ($doc->GetAttribute("type") != "untypified") {
        if (!empty($doc->GetAttribute("type"))) {
          $type = $doc->GetAttribute("type");
          $doc_info = $session_settings->GetDocumentInfo($type);
          printf("Name: %s\n", $doc_info->GetDocumentName());
          printf("Local Name: %s\n", $doc_info->GetDocumentNameLocal());
          printf("Local Name Short: %s\n", $doc_info->GetDocumentShortNameLocal());
          printf("IsMultipage: %s\n", $doc_info->GetDocumentMultipageInfo() ? "true" : "false");

          printf("    Attributes: [ ");
          for ($attr_it = $doc->AttributesBegin();
              !$attr_it->Equals($doc->AttributesEnd());
              $attr_it->Advance()) {
            printf("%s:%s ", $attr_it->GetKey(), $attr_it->GetValue());
          }
          printf("]\n");
          
          $SortedTextFields = [];
          $f_it = $doc->TextFieldsBegin();
          while(!$f_it->Equals($doc->TextFieldsEnd())) {
            $SortedTextFields[] = $f_it->GetField();
            $f_it->Advance();
          }
          if (count($SortedTextFields) > 0 && $SortedTextFields[0]->GetBaseFieldInfo()->HasAttribute("order")) {
            usort($SortedTextFields, function($a, $b) {
              return (int)$a->GetBaseFieldInfo()->GetAttribute("order") <=> (int)$b->GetBaseFieldInfo()->GetAttribute("order");
            });
          }
          printf("    Text fields (%d in total):\n", $doc->GetTextFieldsCount());
          foreach ($SortedTextFields as $TextField) {
            printf("        %-25s : %s\n", $TextField->GetBaseFieldInfo()->GetName(),
            $TextField->GetOcrString()->GetFirstString()->GetCStr());
            printf("            Connected objects:\n");
            for ($c_it = $TextField->GetBaseFieldInfo()->ConnectedTextObjectsBegin($phys_doc);
                        !$c_it->Equals($TextField->GetBaseFieldInfo()->ConnectedTextObjectsEnd($phys_doc));
                        $c_it->Advance()) {
              $conn_geometry = $c_it->GetTextObject()->GetBaseObjectInfo()->GetGeometryOnScene();
              printf("            [");
              for ($idx = 0; $idx < $conn_geometry->GetPointsCount(); $idx++) {
                printf(" (%lf, %f) ", $conn_geometry->GetPoint($idx)->x, $conn_geometry->GetPoint($idx)->y);
              }
              printf("]\n");
            }
            $f_it->Advance();
          }

          printf("    Image fields (%d in total):\n", $doc->GetImageFieldsCount());
          $i_it = $doc->ImageFieldsBegin();
          for ($f_it = $doc->ImageFieldsBegin();
              !$f_it->Equals($doc->ImageFieldsEnd());
              $f_it->Advance()) {
            printf("        %-25s : %dx%d\n", $f_it->GetKey(),
                    $f_it->GetField()->GetImage()->GetWidth(),
                    $f_it->GetField()->GetImage()->GetHeight());
          }

          printf("    Checkbox fields (%d in total):\n", $doc->GetCheckboxFieldsCount());
          for ($f_it = $doc->CheckboxFieldsBegin();
              !$f_it->Equals($doc->CheckboxFieldsEnd());
              $f_it->Advance()) {
            printf("        %-25s : %s\n", $f_it->GetKey(),
                    $f_it->GetField()->GetTickStatus() ? "checked" : "unchecked");
          }

          printf("    Forensic fields (%d in total):\n", $doc->GetForensicFieldsCount());
          for ($f_it = $doc->ForensicFieldsBegin();
              !$f_it->Equals($doc->ForensicFieldsEnd());
              $f_it->Advance()) {
            printf("        %-25s : %s\n", $f_it->GetKey(),
                    $f_it->GetField()->GetStatus());
          }

          printf("    Table fields (%d in total):\n", $doc->GetTableFieldsCount());
          for ($f_it = $doc->TableFieldsBegin();
              !$f_it->Equals($doc->TableFieldsEnd());
              $f_it->Advance()) {
            printf("        %-25s :\n", $f_it->GetKey());
            for ($i_row = 0; $i_row < $f_it->GetField()->GetRowsCount(); $i_row++) {
              printf("            ");
              for ($i_col = 0; $i_col < $f_it->GetField()->GetColsCount(); $i_col++) {
                if ($i_col > 0) {
                  printf(";");
                }
                printf("\"%s\"", $f_it->GetField()
                                    ->GetCell($i_row, $i_col)
                                    ->GetOcrString()
                                    ->GetFirstString()
                                    ->GetCStr());
              }
              printf("\n");
            }
          }
        }
      } else { // document type == "untypified"
        for ($i = 0; $i < $phys_doc->GetPagesCount(); $i++) {
          $page = $phys_doc->GetPhysicalPage($i);
          for ($obj_it = $page->GetFulltextBasicObjectsBegin(); !$obj_it->Equals($page->GetFulltextBasicObjectsEnd()); $obj_it->Advance()) {
            $data = $obj_it->GetTextObject()->GetOcrString()->GetFirstString()->GetCStr();
            $confidence = $obj_it->GetTextObject()->GetBaseObjectInfo()->GetConfidence();
            $conn_geometry = $obj_it->GetTextObject()->GetBaseObjectInfo()->GetGeometryOnPage();
            printf("%s [%f]\n", $data, $confidence);
            printf("[");
            for ($idx = 0; $idx < $conn_geometry->GetPointsCount(); $idx++) {
              printf("        (%f, %f) ", $conn_geometry->GetPoint($idx)->x, $conn_geometry->GetPoint($idx)->y);
            }
            printf("]\n");
          }
        }
      }

      $doc_it->Advance();
    }
  }
}



function main($argc, $argv) {
  if ($argc != 4 and $argc != 3) {
    printf("Usage: %s %s <image_path> <bundle_se_path> <document_type>\n", PHP_BINARY, $argv[0]);
    exit(-1);
  }

  $image_path = $argv[1];
  $config_path = $argv[2];
  $document_types = ($argc >= 4 ? $argv[3] : "*");

  printf("Smart Document Engine version: %s\n", DocEngine::GetVersion());
  printf("image_path = %s\n", $image_path);
  printf("config_path = %s\n", $config_path);
  printf("document_types = %s\n", $document_types);

  try {
    $engine = DocEngine::Create($config_path);

    $session_settings = $engine->CreateSessionSettings();
    $session_settings->SetCurrentMode("default");
      // Printing available modes, internal engines, document types
    printf("Supported modes for this configuration: [ ");
    for ($it = $session_settings->SupportedModesBegin();
           !$it->Equals($session_settings->SupportedModesEnd());
           $it->Advance()) {
       printf("%s ", $it->GetValue());
    }
    printf("]\n");
    printf("Current mode: %s\n", $session_settings->GetCurrentMode());
    printf("Number of internal engines for this mode: %d\n",
            $session_settings->GetInternalEnginesCount());
    printf("Supported document types for the available internal engines:\n");
    for ($i_engine = 0; $i_engine < $session_settings->GetInternalEnginesCount(); $i_engine++) {
      printf("    %02d: [ ", $i_engine);
      for ($i_doc = 0; $i_doc < $session_settings->GetSupportedDocumentTypesCount($i_engine); $i_doc++) {
        printf("%s ",
                $session_settings->GetSupportedDocumentType($i_engine, $i_doc));
      }
      printf("]\n");
    }

    // For starting the session we need to set up the mask of document types
    //     which will be recognized->
    $session_settings->AddEnabledDocumentTypes($document_types);

    // Printing enabled documents
    printf("Enabled document types: [ ");
    for ($i_doc = 0; $i_doc < $session_settings->GetEnabledDocumentTypesCount(); $i_doc++) {
      printf("%s ", $session_settings->GetEnabledDocumentType($i_doc));
    }
    printf("]\n");

    // Creating a session object - a main handle for performing recognition->
    $session = $engine->SpawnSession($session_settings, @put_yor_personalized_signature_from_doc_README.html@);

    // Creating default image processing settings - needs to be created before
    //     passing an image for processing-> This specifies how the session
    //     should process the updated source->
    $proc_settings = $session->CreateProcessingSettings();

    // Creating an image object which will be used as an input for the session
    $image = Image::FromFile($image_path);

    $session->ProcessImage($image, $proc_settings);
    $result = $session->GetCurrentResult();

    OutputRecognitionResult($result, $session_settings);


  } catch (Exception $e) {
    printf("Exception caught: %s\n", $e->getMessage());
     }
}

main($argc, $argv);

?>