<?php
//  Copyright (c) 2016-2024, Smart Engines Service LLC
//  All rights reserved.

function OutputRecognitionResult($recog_result, $session_settings) {
  $graphical = $recog_result->GetGraphicalStructure();
  printf("Graphical objects:\n");
  printf("    %d object collections\n", $graphical->GetCollectionsCount());
  printf("    %d views\n", $graphical->GetViewsCollection()->GetViewsCount());
  unset($graphical);
  printf("Documents: (%d in total)\n", $recog_result->GetDocumentsCount());

  $doc_it = $recog_result->DocumentsBegin();
  while(!$doc_it->Equals($recog_result->DocumentsEnd())){
    $doc = $doc_it->GetDocument();
    if (!empty($doc->GetAttribute("type"))) {
      printf("GetDocument\n");
      printf("GetDocumentInfo\n");
      $type = $doc->GetAttribute("type");
      printf("type: %s\n", $type);
      $doc_info = $session_settings->GetDocumentInfo($type);
      printf("GetDocumentName\n");
      printf("Name: %s\n", $doc_info->GetDocumentName());
      printf("Local Name: %s\n", $doc_info->GetDocumentNameLocal());
      printf("Local Name Short: %s\n", $doc_info->GetDocumentShortNameLocal());
      printf("IsMultipage: %s\n", $doc_info->GetDocumentMultipageInfo() ? "true" : "false");


      printf("    ID %d\n", $doc_it->GetID());
      printf("    Attributes: [ ");
      for ($attr_it = $doc->AttributesBegin();
          !$attr_it->Equals($doc->AttributesEnd());
          $attr_it->Advance()) {
        printf("%s:%s ", $attr_it->GetKey(), $attr_it->GetValue());
      }
      printf("]\n");
      

      printf("    Text fields (%d in total):\n", $doc->GetTextFieldsCount());
      $f_it = $doc->TextFieldsBegin();
      while(!$f_it->Equals($doc->TextFieldsEnd())) {
        printf("        %-25s : %s\n", $f_it->GetKey(),
        $f_it->GetField()->GetOcrString()->GetFirstString()->GetCStr());
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
    $doc_it->Advance();
  }
}



function main($argc, $argv) {
  if ($argc != 4) {
    printf("Usage: %s %s <image_path> <bundle_se_path> <document_type>\n", PHP_BINARY, $argv[0]);
    exit(-1);
  }

  $image_path = $argv[1];
  $config_path = $argv[2];
  $document_types = $argv[3];

  printf("Smart Document Engine version: %s\n", DocEngine::GetVersion());
  printf("image_path = %s\n", $image_path);
  printf("config_path = %s\n", $config_path);
  printf("document_types = %s\n", $document_types);

  try {
    $engine = DocEngine::Create($config_path);

    $session_settings = $engine->CreateSessionSettings();

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

    // Registering input image in the session,
    //     setting it up as the current source and processing the image
    $image_id = $session->RegisterImage($image);
    $proc_settings->SetCurrentSourceID($image_id);

    $session->Process($proc_settings);
    $result = $session->GetCurrentResult();

    OutputRecognitionResult($result, $session_settings);


  } catch (Exception $e) {
    printf("Exception caught: %s\n", $e->getMessage());
     }
}

main($argc, $argv);

?>