//  Copyright (c) 2016-2025, Smart Engines Service LLC
//  All rights reserved.

using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

using se.doc;
using se.common;



class DocEngineSampleCs
{
  
// Here we simply output the recognized fields
static void OutputRecognitionResult(DocResult recog_result, DocSessionSettings session_settings) {
  Console.OutputEncoding = System.Text.Encoding.UTF8;

  Console.WriteLine("Documents: ({0} in total)\n", recog_result.GetDocumentsCount());

  if (recog_result.GetDocumentsCount() > 0) {
    for (DocumentsIterator doc_it = recog_result.DocumentsBegin();
          !doc_it.Equals(recog_result.DocumentsEnd());
          doc_it.Advance()) {
      Document doc = doc_it.GetDocument();
      int phys_id = doc.GetPhysicalDocIdx();
      DocPhysicalDocument phys_doc = recog_result.GetPhysicalDocument(phys_id);

      if (doc.GetAttribute("type") != "") {
        if (doc.GetAttribute("type") != "untypified") {
          DocDocumentInfo doc_info =
            session_settings.GetDocumentInfo(doc.GetAttribute("type"));
          Console.WriteLine("Name: {0}\n", doc_info.GetDocumentName());
          Console.WriteLine("Local Name: {0}\n", doc_info.GetDocumentNameLocal());
          Console.WriteLine("Local Name Short: {0}\n", doc_info.GetDocumentShortNameLocal());
          Console.WriteLine("IsMultipage:{0}\n", doc_info.GetDocumentMultipageInfo() ? "true" : "false");
          
          Console.WriteLine("    Attributes: [ ");
          for (StringsMapIterator attr_it = doc.AttributesBegin();
                !attr_it.Equals(doc.AttributesEnd());
                attr_it.Advance()) {
            Console.WriteLine("{0}:{1} ", attr_it.GetKey(), attr_it.GetValue());
          }
          Console.WriteLine("]\n"); 

          List<DocTextField> SortedTextFields = new List<DocTextField>();
          for (DocTextFieldsIterator f_it = doc.TextFieldsBegin();
                !f_it.Equals(doc.TextFieldsEnd());
                f_it.Advance()) {
            SortedTextFields.Add(f_it.GetField());
          }
          if (SortedTextFields.Count > 0 && SortedTextFields[0].GetBaseFieldInfo().HasAttribute("order")) {
            SortedTextFields.Sort((a, b) => int.Parse(a.GetBaseFieldInfo().GetAttribute("order")).CompareTo(int.Parse(b.GetBaseFieldInfo().GetAttribute("order"))));
          }
          Console.WriteLine("    Text fields ({0} in total):\n", doc.GetTextFieldsCount());
          foreach (DocTextField TextField in SortedTextFields) {
            Console.WriteLine("        {0,-25} : {1}\n", TextField.GetBaseFieldInfo().GetName(),
                    TextField.GetOcrString().GetFirstString().GetCStr());
            Console.WriteLine("            Connected objects:\n");
            for (se.doc.DocTextObjectsCrossPageIterator c_it = TextField.GetBaseFieldInfo().ConnectedTextObjectsBegin(phys_doc);
                      !c_it.Equals(TextField.GetBaseFieldInfo().ConnectedTextObjectsEnd(phys_doc));
                      c_it.Advance()) {
              Polygon conn_geometry = c_it.GetTextObject().GetBaseObjectInfo().GetGeometryOnScene();
              Console.WriteLine("            [");
              for (int idx = 0; idx < conn_geometry.GetPointsCount(); idx++) {
                Console.WriteLine(" ({0}, {1}) ", conn_geometry.GetPoint(idx).x, conn_geometry.GetPoint(idx).y);
              }
              Console.WriteLine("]\n");
            }      
          }

          Console.WriteLine("    Image fields ({0} in total):\n", doc.GetImageFieldsCount());
          for (DocImageFieldsIterator f_it = doc.ImageFieldsBegin();
                !f_it.Equals(doc.ImageFieldsEnd());
                f_it.Advance()) {
            Console.WriteLine("         {0,-25} : {1}x{2}\n", f_it.GetKey(),
                    f_it.GetField().GetImage().GetWidth(),
                    f_it.GetField().GetImage().GetHeight());
          }

          Console.WriteLine("    Checkbox fields ({0} in total):\n", doc.GetCheckboxFieldsCount());
          for (DocCheckboxFieldsIterator f_it = doc.CheckboxFieldsBegin();
                !f_it.Equals(doc.CheckboxFieldsEnd());
                f_it.Advance()) {
            Console.WriteLine("         {0,-25} : {1}\n", f_it.GetKey(),
                    f_it.GetField().GetTickStatus() ? "checked" : "unchecked");
          }

          Console.WriteLine("    Forensic fields ({0} in total):\n", doc.GetForensicFieldsCount());
          for (DocForensicFieldsIterator f_it = doc.ForensicFieldsBegin();
                !f_it.Equals(doc.ForensicFieldsEnd());
                f_it.Advance()) {
            Console.WriteLine("         {0,-25} : {1}\n", f_it.GetKey(),
                    f_it.GetField().GetStatus());
          }

          Console.WriteLine("    Table fields ({0} in total):\n", doc.GetTableFieldsCount());
          for (DocTableFieldsIterator f_it = doc.TableFieldsBegin();
                !f_it.Equals(doc.TableFieldsEnd());
                f_it.Advance()) {
            Console.WriteLine("         {0,-25} :\n", f_it.GetKey());
            for (int i_row = 0; i_row < f_it.GetField().GetRowsCount(); i_row++) {
              Console.WriteLine("            ");
              for (int i_col = 0; i_col < f_it.GetField().GetColsCount(); i_col++) {
                if (i_col > 0) {
                  Console.WriteLine(";");
                }
                Console.WriteLine("\"{0}\"", f_it.GetField()
                                      .GetCell(i_row, i_col)
                                      .GetOcrString()
                                      .GetFirstString()
                                      .GetCStr());
              }
              Console.WriteLine("\n");
            }
          }
        } else { // document type == "untypified"
          for (int i = 0; i < phys_doc.GetPagesCount(); i++) {
            DocPhysicalPage page = phys_doc.GetPhysicalPage(i);
            for (DocTextObjectsIterator obj_it = page.GetFulltextBasicObjectsBegin(); !obj_it.Equals(page.GetFulltextBasicObjectsEnd()); obj_it.Advance()) {
              String data = obj_it.GetTextObject().GetOcrString().GetFirstString().GetCStr();
              double confidence = obj_it.GetTextObject().GetBaseObjectInfo().GetConfidence();
              Polygon conn_geometry = obj_it.GetTextObject().GetBaseObjectInfo().GetGeometryOnPage();
              Console.WriteLine("{0} [{1}]\n", data,  confidence);
              Console.WriteLine("[");
              for (int idx = 0; idx < conn_geometry.GetPointsCount(); idx++) {
                Console.WriteLine("        ({0} , {1}) ", conn_geometry.GetPoint(idx).x, conn_geometry.GetPoint(idx).y);
              }
              Console.WriteLine("]\n");
            }
          }
        }
      }
    }
  }
}

  static void Main(string[] args)
  {
    if (args.Length < 2)
    {
      Console.WriteLine("Usage: docengine_sample_cs <image_path> <bundle_se_path> [document.types]");
      Console.WriteLine(Environment.NewLine);
      return;
    }

    String image_path = args[0];
    String config_path = args[1];
    String document_types = args.Length >= 3 ? args[2] : "*";

    Console.WriteLine("image_path = {0}", image_path);
    Console.WriteLine("config_path = {0}", config_path);
    Console.WriteLine("document_types = {0}", document_types);

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
    session_settings.SetCurrentMode("default");

    // Printing available modes, internal engines, document types
    Console.WriteLine("Supported modes for this configuration: [ ");
    for (StringsVectorIterator it = session_settings.SupportedModesBegin();
          !it.Equals(session_settings.SupportedModesEnd());
          it.Advance()) {
      Console.WriteLine("{0} ", it.GetValue());
    }
    Console.WriteLine("]\n");
    Console.WriteLine("Current mode: {0}\n", session_settings.GetCurrentMode());
    Console.WriteLine("Number of internal engines for this mode: {0}\n",
            session_settings.GetInternalEnginesCount());
    Console.WriteLine("Supported document types for the available internal engines:\n");
    for (int i_engine = 0; i_engine < session_settings.GetInternalEnginesCount(); i_engine++) {
      Console.WriteLine("    {0:0.0}: [ ", i_engine);
      for (int i_doc = 0; i_doc < session_settings.GetSupportedDocumentTypesCount(i_engine); i_doc++) {
        Console.WriteLine("{0} ",
                session_settings.GetSupportedDocumentType(i_engine, i_doc));
      }
      Console.WriteLine("]\n");
    }

    // For starting the session we need to set up the mask of document types
    //     which will be recognized.
    session_settings.AddEnabledDocumentTypes(document_types);

    // Printing enabled documents
    Console.WriteLine("Enabled document types: [ ");
    for (int i_doc = 0; i_doc < session_settings.GetEnabledDocumentTypesCount(); i_doc++) {
      Console.WriteLine("{0} ", session_settings.GetEnabledDocumentType(i_doc));
    }
    Console.WriteLine("]\n");

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
    session.ProcessImage(image, proc_settings);

    // Obtaining the recognition result
    DocResult result = session.GetCurrentResult();

    // Printing the contents of the recognition result
    OutputRecognitionResult(result, session_settings);

    // After the objects are no longer needed it is important to use the 
    // .delete() methods on them. It will force the associated native heap memory 
    // to be deallocated. Note that Java's GC does not care too much about the 
    // native heap and thus can delay the actual freeing of the associated memory, 
    // thus it is better to manage the internal native heap deallocation manually
    image.Dispose();
    proc_settings.Dispose();
    session.Dispose();
    session_settings.Dispose();
    engine.Dispose();

  } catch (Exception e) {
    Console.WriteLine("Exception thrown: {0}", e);
    }
  }
}

