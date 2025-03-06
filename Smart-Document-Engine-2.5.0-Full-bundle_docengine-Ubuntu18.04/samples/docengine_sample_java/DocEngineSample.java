/**
  Copyright (c) 2016-2024, Smart Engines Service LLC
  All rights reserved.
*/

import com.smartengines.common.*;
import com.smartengines.doc.*;

public class DocEngineSample {
  static {
    System.loadLibrary("jnidocengine");
  }

  // Here we simply output the recognized fields
  public static void OutputRecognitionResult(DocResult recog_result, DocSessionSettings session_settings) {
    DocGraphicalStructure graphical = recog_result.GetGraphicalStructure();
    System.out.printf("Graphical objects:\n");
    System.out.printf("    %d object collections\n", graphical.GetCollectionsCount());
    System.out.printf("    %d views\n", graphical.GetViewsCollection().GetViewsCount());

    System.out.printf("Documents: (%d in total)\n", recog_result.GetDocumentsCount());
    for (DocumentsIterator doc_it = recog_result.DocumentsBegin();
         !doc_it.Equals(recog_result.DocumentsEnd());
         doc_it.Advance()) {   
      Document doc = doc_it.GetDocument();

      if (!doc.GetAttribute("type").isEmpty()) { 
        DocDocumentInfo doc_info =
        session_settings.GetDocumentInfo(doc.GetAttribute("type"));

        System.out.printf("Name: %s\n", doc_info.GetDocumentName());
        System.out.printf("Local Name: %s\n", doc_info.GetDocumentNameLocal());
        System.out.printf("Local Name Short: %s\n", doc_info.GetDocumentShortNameLocal());
        System.out.printf("IsMultipage: %s\n", doc_info.GetDocumentMultipageInfo() ? "true" : "false");


        System.out.printf("    ID %d\n", doc_it.GetID());
        System.out.printf("    Attributes: [ ");
        for (StringsMapIterator attr_it = doc.AttributesBegin();
            !attr_it.Equals(doc.AttributesEnd());
            attr_it.Advance()) {
          System.out.printf("%s:%s ", attr_it.GetKey(), attr_it.GetValue());
        }
        System.out.printf("]\n");
        

        System.out.printf("    Text fields (%d in total):\n", doc.GetTextFieldsCount());
        for (DocTextFieldsIterator f_it = doc.TextFieldsBegin();
            !f_it.Equals(doc.TextFieldsEnd());
            f_it.Advance()) {
          System.out.printf("        %-25s : %s\n", f_it.GetKey(),
                f_it.GetField().GetOcrString().GetFirstString().GetCStr());
        }

        System.out.printf("    Image fields (%d in total):\n", doc.GetImageFieldsCount());
        for (DocImageFieldsIterator f_it = doc.ImageFieldsBegin();
            !f_it.Equals(doc.ImageFieldsEnd());
            f_it.Advance()) {
          System.out.printf("        %-25s : %dx%d\n", f_it.GetKey(),
                f_it.GetField().GetImage().GetWidth(),
                f_it.GetField().GetImage().GetHeight());
        }

        System.out.printf("    Checkbox fields (%d in total):\n", doc.GetCheckboxFieldsCount());
        for (DocCheckboxFieldsIterator f_it = doc.CheckboxFieldsBegin();
            !f_it.Equals(doc.CheckboxFieldsEnd());
            f_it.Advance()) {
          System.out.printf("        %-25s : %s\n", f_it.GetKey(),
                f_it.GetField().GetTickStatus() ? "checked" : "unchecked");
        }

        System.out.printf("    Forensic fields (%d in total):\n", doc.GetForensicFieldsCount());
        for (DocForensicFieldsIterator f_it = doc.ForensicFieldsBegin();
            !f_it.Equals(doc.ForensicFieldsEnd());
            f_it.Advance()) {
          System.out.printf("        %-25s : %s\n", f_it.GetKey(),
                f_it.GetField().GetStatus());
        }

        System.out.printf("    Table fields (%d in total):\n", doc.GetTableFieldsCount());
        for (DocTableFieldsIterator f_it = doc.TableFieldsBegin();
            !f_it.Equals(doc.TableFieldsEnd());
            f_it.Advance()) {
          System.out.printf("        %-25s :\n", f_it.GetKey());
          for (int i_row = 0; i_row < f_it.GetField().GetRowsCount(); i_row++) {
            System.out.printf("            ");
            for (int i_col = 0; i_col < f_it.GetField().GetColsCount(); i_col++) {
              if (i_col > 0) {
                System.out.printf(";");
              }
              System.out.printf("\"%s\"", f_it.GetField()
                                  .GetCell(i_row, i_col)
                                  .GetOcrString()
                                  .GetFirstString()
                                  .GetCStr());
            }
            System.out.printf("\n");
          }
        }
      }
    }
    System.out.flush();
  }

  public static void main(String[] args) {
    // 1st argument - path to the image to be recognized
    // 2nd argument - path to the configuration bundle
    // 3rd argument - document types mask, "*" by default
    if (args.length != 2 && args.length != 3) {
      System.out.printf("Version %s. Usage: docengine_sample_java " +
                        "<image_path> <bundle_se_path> [document_types]\n", 
          DocEngine.GetVersion());
      System.exit(-1);
    }

    String image_path = args[0];
    String config_path = args[1];
    String document_types = args.length >= 3 ? args[2] : "*";

    System.out.printf("Smart Document Engine version %s\n", 
                      DocEngine.GetVersion());
    System.out.printf("image_path = %s\n", image_path);
    System.out.printf("config_path = %s\n", config_path);
    System.out.printf("document_types = %s\n", document_types);
    System.out.println();
    System.out.flush();

    try {
      // Creating the recognition engine object - initializes all internal
      //     configuration structure. Second parameter to the factory method
      //     is the lazy initialization flag (true by default). If set to
      //     false, all internal objects will be initialized here, instead of
      //     waiting until some session needs them.
      DocEngine engine = DocEngine.Create(config_path, true);

      // Before creating the session we need to have a session settings
      //     object. Such object can be created only by acquiring a
      //     default session settings object from the configured engine.
      DocSessionSettings session_settings = engine.CreateSessionSettings();

      // Printing available modes, internal engines, document types
      System.out.printf("Supported modes for this configuration: [ ");
      for (StringsVectorIterator it = session_settings.SupportedModesBegin();
           !it.Equals(session_settings.SupportedModesEnd());
           it.Advance()) {
        System.out.printf("%s ", it.GetValue());
      }
      System.out.printf("]\n");
      System.out.printf("Current mode: %s\n", session_settings.GetCurrentMode());
      System.out.printf("Number of internal engines for this mode: %d\n",
             session_settings.GetInternalEnginesCount());
      System.out.printf("Supported document types for the available internal engines:\n");
      for (int i_engine = 0; i_engine < session_settings.GetInternalEnginesCount(); i_engine++) {
        System.out.printf("    %02d: [ ", i_engine);
        for (int i_doc = 0; i_doc < session_settings.GetSupportedDocumentTypesCount(i_engine); i_doc++) {
          System.out.printf("%s ",
                 session_settings.GetSupportedDocumentType(i_engine, i_doc));
        }
        System.out.printf("]\n");
      }
      System.out.flush();

      // For starting the session we need to set up the mask of document types
      //     which will be recognized.
      session_settings.AddEnabledDocumentTypes(document_types);

      // Printing enabled documents
      System.out.printf("Enabled document types: [ ");
      for (int i_doc = 0; i_doc < session_settings.GetEnabledDocumentTypesCount(); i_doc++) {
        System.out.printf("%s ", session_settings.GetEnabledDocumentType(i_doc));
      }
      System.out.printf("]\n");
      System.out.flush();

      // Creating a session object - a main handle for performing recognition.
      DocSession session = engine.SpawnSession(session_settings, ${put_yor_personalized_signature_from_doc_README.html});

      // Creating default image processing settings - needs to be created before
      //     passing an image for processing. This specifies how the session
      //     should process the updated source.
      DocProcessingSettings proc_settings = session.CreateProcessingSettings();

      // Creating an image object which will be used as an input for the session
      Image image = Image.FromFile(image_path);

      // Registering input image in the session,
      //     setting it up as the current source and processing the image
      int image_id = session.RegisterImage(image);
      proc_settings.SetCurrentSourceID(image_id);
      session.Process(proc_settings);

      // Obtaining the recognition result
      DocResult result = session.GetCurrentResult();

      // Printing the contents of the recognition result
      OutputRecognitionResult(result, session_settings);

      // After the objects are no longer needed it is important to use the 
      // .delete() methods on them. It will force the associated native heap memory 
      // to be deallocated. Note that Java's GC does not care too much about the 
      // native heap and thus can delay the actual freeing of the associated memory, 
      // thus it is better to manage the internal native heap deallocation manually
      image.delete();
      proc_settings.delete();
      session.delete();
      session_settings.delete();
      engine.delete();

    } catch (java.lang.Exception e) {
      System.out.printf("Exception thrown: %s\n", e.toString());
      System.out.flush();
      System.exit(-2);
    }
  }
}