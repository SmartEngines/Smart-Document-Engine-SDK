/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#include <cstring>
#include <string>
#include <memory>
#include <cstdio>
#include <vector>
#include <algorithm>

#ifdef _MSC_VER
#pragma warning( disable : 4290 )
#include <windows.h>
#endif // _MSC_VER

#include <secommon/se_common.h>

#include <docengine/doc_engine.h>
#include <docengine/doc_result.h>
#include <docengine/doc_session_settings.h>
#include <docengine/doc_session.h>
#include <docengine/doc_processing_settings.h>
#include <docengine/doc_document.h>
#include <docengine/doc_fields.h>
#include <docengine/doc_objects.h>

// Here we simply output the recognized fields

void OutputRecognitionResult(const se::doc::DocResult& recog_result,
  const se::doc::DocSessionSettings& session_settings) {
  printf("Documents: (%d in total)\n", recog_result.GetDocumentsCount());
  if (recog_result.GetDocumentsCount() > 0) {
    for (auto doc_it = recog_result.DocumentsBegin();
        doc_it != recog_result.DocumentsEnd();
        ++doc_it) {
      const se::doc::Document& doc = doc_it.GetDocument();
      int phys_id = doc.GetPhysicalDocIdx();
      const se::doc::DocPhysicalDocument& phys_doc = recog_result.GetPhysicalDocument(phys_id);

      if (strlen(doc.GetAttribute("type")) != 0) {
        if (strcmp(doc.GetAttribute("type"), "untypified") != 0) {
          const se::doc::DocDocumentInfo& doc_info =
            session_settings.GetDocumentInfo(doc.GetAttribute("type"));
          printf("Name: %s\n", doc_info.GetDocumentName());
          printf("Local Name: %s\n", doc_info.GetDocumentNameLocal());
          printf("Local Name Short: %s\n", doc_info.GetDocumentShortNameLocal());
          printf("IsMultipage: %s\n", doc_info.GetDocumentMultipageInfo() ? "true" : "false");
          
          
          printf("    Attributes: [ ");
          for (auto attr_it = doc.AttributesBegin();
              attr_it != doc.AttributesEnd();
              ++attr_it) {
            printf("%s:%s ", attr_it.GetKey(), attr_it.GetValue());
          }
          printf("]\n");

          std::vector<const se::doc::DocTextField*> SortedTextFields;
          for (auto f_it = doc.TextFieldsBegin();
              f_it != doc.TextFieldsEnd();
              ++f_it) {
              SortedTextFields.push_back(f_it.GetFieldPtr());
          }
          if (SortedTextFields.size() > 0 && SortedTextFields[0]->GetBaseFieldInfo().HasAttribute("order")) {
            std::sort(SortedTextFields.begin(), SortedTextFields.end(),
            [](const se::doc::DocTextField* a, const se::doc::DocTextField* b) {
              return std::stoi(a->GetBaseFieldInfo().GetAttribute("order")) < std::stoi(b->GetBaseFieldInfo().GetAttribute("order"));
            });
          }
          printf("    Text fields (%d in total):\n", doc.GetTextFieldsCount());
          for (auto* TextFieldPtr : SortedTextFields) {
            printf("        %-25s : %s\n", TextFieldPtr->GetBaseFieldInfo().GetName(),
                  TextFieldPtr->GetOcrString().GetFirstString().GetCStr());

            printf("            Connected objects:\n");
            for (auto c_it = TextFieldPtr->GetBaseFieldInfo().ConnectedTextObjectsBegin(phys_doc);
                      c_it != TextFieldPtr->GetBaseFieldInfo().ConnectedTextObjectsEnd(phys_doc);
                      c_it.Advance()) {
              const auto& conn_geometry = c_it.GetTextObject().GetBaseObjectInfo().GetGeometryOnScene();
              printf("            [");
              for (int idx = 0; idx < conn_geometry.GetPointsCount(); idx++) {
                printf(" (%.3lf, %.3lf) ", conn_geometry.GetPoint(idx).x, conn_geometry.GetPoint(idx).y);
              }
              printf("]\n");
            }
          }
          
          printf("    Image fields (%d in total):\n", doc.GetImageFieldsCount());
          for (auto f_it = doc.ImageFieldsBegin();
              f_it != doc.ImageFieldsEnd();
              ++f_it) {
            printf("        %-25s : %dx%d\n", f_it.GetKey(),
                  f_it.GetField().GetImage().GetWidth(),
                  f_it.GetField().GetImage().GetHeight());
          }
          printf("    Checkbox fields (%d in total):\n", doc.GetCheckboxFieldsCount());
          for (auto f_it = doc.CheckboxFieldsBegin();
              f_it != doc.CheckboxFieldsEnd();
              ++f_it) {
            printf("        %-25s : %s\n", f_it.GetKey(),
                  f_it.GetField().GetTickStatus()? "checked" : "unchecked");
          }
          printf("    Forensic fields (%d in total):\n", doc.GetForensicFieldsCount());
          for (auto f_it = doc.ForensicFieldsBegin();
              f_it != doc.ForensicFieldsEnd();
              ++f_it) {
            printf("        %-25s : %s\n", f_it.GetKey(),
                  f_it.GetField().GetStatus());
          }
          printf("    Table fields (%d in total):\n", doc.GetTableFieldsCount());
          for (auto f_it = doc.TableFieldsBegin();
              f_it != doc.TableFieldsEnd();
              ++f_it) {
            printf("        %-25s :\n", f_it.GetKey());
            for (int i_row = 0; i_row < f_it.GetField().GetRowsCount(); ++i_row) {
              printf("            ");
              for (int i_col = 0; i_col < f_it.GetField().GetColsCount(); ++i_col) {
                if (i_col > 0) {
                  printf(";");
                }
                printf("\"%s\"", f_it.GetField()
                                    .GetCell(i_row, i_col)
                                    .GetOcrString()
                                    .GetFirstString()
                                    .GetCStr());
              }
              printf("\n");
            }
          }
          printf("    Barcode fields (%d in total):\n", doc.GetBarcodeFieldsCount());
          for (auto f_it = doc.BarcodeFieldsBegin();
              f_it != doc.BarcodeFieldsEnd();
              ++f_it) {
            printf("        %-25s : %s\n", f_it.GetKey(),
                  f_it.GetField().GetDecodedString().GetCStr());
          }
        } else { // document type == "untypified"
          for (int i = 0; i < phys_doc.GetPagesCount(); i++) {
            const se::doc::DocPhysicalPage& page = phys_doc.GetPhysicalPage(i);
            for (auto obj_it = page.GetFulltextBasicObjectsBegin(); !obj_it.Equals(page.GetFulltextBasicObjectsEnd()); obj_it.Advance()) {
              std::string data = obj_it.GetTextObject().GetOcrString().GetFirstString().GetCStr();
              double confidence = obj_it.GetTextObject().GetBaseObjectInfo().GetConfidence();
              const se::common::Polygon& conn_geometry = obj_it.GetTextObject().GetBaseObjectInfo().GetGeometryOnPage();
              printf("%s [%f]\n", data.c_str(),  confidence);
              printf("[");
              for (int idx = 0; idx < conn_geometry.GetPointsCount(); idx++) {
                printf("        (%f, %f) ", conn_geometry.GetPoint(idx).x, conn_geometry.GetPoint(idx).y);
              }
              printf("]\n");
            }
          }
        }
      }
    }
  }
}

int main(int argc, char **argv) {
#ifdef _MSC_VER
  SetConsoleOutputCP(65001);
#endif // _MSC_VER

  // 1st argument - path to the image to be recognized
  // 2nd argument - path to the configuration bundle
  // 3rd argument - document types mask, "*" by default
  if (argc != 3 && argc != 4) {
    printf("Version %s. Usage: "
           "%s <image_path> <bundle_se_path> [document_types]\n",
           se::doc::DocEngine::GetVersion(), argv[0]);
    return -1;
  }

  const std::string image_path = argv[1];
  const std::string config_path = argv[2];
  const std::string document_types = (argc >= 4 ? argv[3] : "*");

  printf("Smart Document Engine version %s\n",
         se::doc::DocEngine::GetVersion());
  printf("image_path = %s\n", image_path.c_str());
  printf("config_path = %s\n", config_path.c_str());
  printf("document_types = %s\n", document_types.c_str());
  printf("\n");

  try {
    // Creating the recognition engine object - initializes all internal
    //     configuration structure. Second parameter to the factory method
    //     is the lazy initialization flag (true by default). If set to
    //     false, all internal objects will be initialized here, instead of
    //     waiting until some session needs them.
    std::unique_ptr<se::doc::DocEngine> engine(
        se::doc::DocEngine::Create(config_path.c_str(), true));

    // Before creating the session we need to have a session settings
    //     object. Such object can be created only by acquiring a
    //     default session settings object from the configured engine.
    std::unique_ptr<se::doc::DocSessionSettings> session_settings(
        engine->CreateSessionSettings());
    session_settings->SetCurrentMode("default");

    // Printing available modes, internal engines, document types
    printf("Supported modes for this configuration: [ ");
    for (auto it = session_settings->SupportedModesBegin();
         it != session_settings->SupportedModesEnd();
         ++it) {
      printf("%s ", it.GetValue());
    }
    printf("]\n");
    printf("Current mode: %s\n", session_settings->GetCurrentMode());
    printf("Number of internal engines for this mode: %d\n",
           session_settings->GetInternalEnginesCount());
    printf("Supported document types for the available internal engines:\n");
    for (int i_engine = 0;
         i_engine < session_settings->GetInternalEnginesCount();
         ++i_engine) {
      printf("    %02d: [ ", i_engine);
      for (int i_doc = 0;
           i_doc < session_settings->GetSupportedDocumentTypesCount(i_engine);
           ++i_doc) {
        printf("%s ",
               session_settings->GetSupportedDocumentType(i_engine, i_doc));
      }
      printf("]\n");
    }

    // For starting the session we need to set up the mask of document types
    //     which will be recognized.
    session_settings->AddEnabledDocumentTypes(document_types.c_str());

    // Printing enabled documents
    printf("Enabled document types: [ ");
    for (int i_doc = 0;
         i_doc < session_settings->GetEnabledDocumentTypesCount();
         ++i_doc) {
      printf("%s ", session_settings->GetEnabledDocumentType(i_doc));
    }
    printf("]\n");

    // Creating a session object - a main handle for performing recognition.
    std::unique_ptr<se::doc::DocSession> session(
                engine->SpawnSession(*session_settings, ${put_yor_personalized_signature_from_doc_README.html}));

    // Creating default image processing settings - needs to be created before
    //     passing an image for processing. This specifies how the session
    //     should process the updated source.
    std::unique_ptr<se::doc::DocProcessingSettings> proc_settings(
        session->CreateProcessingSettings());

    // Creating an image object which will be used as an input for the session
    std::unique_ptr<se::common::Image> image(
        se::common::Image::FromFile(image_path.c_str()));

    // Processing the image
    session->ProcessImage(*image, proc_settings.get());

    // Obtaining the recognition result
    const se::doc::DocResult& result = session->GetCurrentResult();

    // Printing the contents of the recognition result
    OutputRecognitionResult(result, *session_settings);

  } catch (const se::common::BaseException& e) {
    printf("Exception thrown: %s\n", e.what());
    return -1;
  }

  return 0;
}
