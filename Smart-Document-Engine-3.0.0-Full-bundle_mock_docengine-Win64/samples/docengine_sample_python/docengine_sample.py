#  Copyright (c) 2016-2025, Smart Engines Service LLC
#  All rights reserved.


import sys
import os

sys.path.append(os.path.join(sys.path[0], '../../bindings/python/'))
sys.path.append(os.path.join(sys.path[0],'../../bin/'))

import pydocengine


#  Here we simply output the recognized fields
def OutputRecognitionResult(recog_result, session_settings):
  print('Documents: ({} in total)'.format( recog_result.GetDocumentsCount()))

  if (recog_result.GetDocumentsCount() > 0):
    doc_it = recog_result.DocumentsBegin()
    while(doc_it != recog_result.DocumentsEnd()):
      doc = doc_it.GetDocument()
      phys_id = doc.GetPhysicalDocIdx()
      phys_doc = recog_result.GetPhysicalDocument(phys_id)
      if doc.GetAttribute('type') != "":
        if doc.GetAttribute('type') != "untypified":
          doc_info = session_settings.GetDocumentInfo(doc.GetAttribute('type'))
          print('Name: {}'.format(doc_info.GetDocumentName()))
          print('Local Name: {}'.format(doc_info.GetDocumentNameLocal()))
          print('Local Name Short: {}'.format(doc_info.GetDocumentShortNameLocal()))
          print('IsMultipage: {}'.format(doc_info.GetDocumentMultipageInfo()))
          
          print('    ID {}'.format( doc_it.GetID()))
          print('    Attributes: [ ')
          attr_it = doc.AttributesBegin()

          while(attr_it != doc.AttributesEnd()):
            print('{0}:{1} '.format( attr_it.GetKey(), attr_it.GetValue()))
            attr_it.Advance()

          print(']')
          print('    Text fields ({} in total):'.format( doc.GetTextFieldsCount()))

          f_it = doc.TextFieldsBegin()
          while(f_it != doc.TextFieldsEnd()):
            print('        {0} : {1}'.format( f_it.GetKey(),
                  f_it.GetField().GetOcrString().GetFirstString().GetCStr()))
            print("            Connected objects:\n")
            c_it = f_it.GetField().GetBaseFieldInfo().ConnectedTextObjectsBegin(phys_doc)
            while(c_it != f_it.GetField().GetBaseFieldInfo().ConnectedTextObjectsEnd(phys_doc)):
              conn_geometry = c_it.GetTextObject().GetBaseObjectInfo().GetGeometryOnScene()
              print("            [")
              for idx in range(conn_geometry.GetPointsCount()):
                print(" ({0}, {1}) ".format(conn_geometry.GetPoint(idx).x, conn_geometry.GetPoint(idx).y))
              print("]\n")
              c_it.Advance()
            f_it.Advance()
          print('    Image fields ({} in total):'.format( doc.GetImageFieldsCount()))

          f_it = doc.ImageFieldsBegin()
          while(f_it != doc.ImageFieldsEnd()):
            print('        {0} : {1}x{2}'.format( f_it.GetKey(),
                  f_it.GetField().GetImage().GetWidth(),
                  f_it.GetField().GetImage().GetHeight()))
            f_it.Advance()
          print('    Checkbox fields ({} in total):'.format( doc.GetCheckboxFieldsCount()))
          f_it = doc.CheckboxFieldsBegin()
          while(f_it != doc.CheckboxFieldsEnd()):
            # print('        %-25s : %s', f_it.GetKey(),
            #        f_it.GetField().GetTickStatus()? 'checked' : 'unchecked')
            f_it.Advance()
          print('    Forensic fields ({} in total):'.format( doc.GetForensicFieldsCount()))
          f_it = doc.ForensicFieldsBegin()
          while(f_it != doc.ForensicFieldsEnd()):
            print('        {} : {}'.format( f_it.GetKey(),
                  f_it.GetField().GetStatus()))
            f_it.Advance()
          print('    Table fields ({} in total):'.format( doc.GetTableFieldsCount()))
          f_it = doc.TableFieldsBegin()
          while(f_it != doc.TableFieldsEnd()):
            print('\n{} :'.format( f_it.GetKey()))
            for i_row in range(f_it.GetField().GetRowsCount()):
              for i_col in range(f_it.GetField().GetColsCount()):
                print('{}'.format( f_it.GetField()
                                    .GetCell(i_row, i_col)
                                    .GetOcrString()
                                    .GetFirstString()
                                    .GetCStr()), end='\t')
              print('')

            f_it.Advance()
        else: # document type == "untypified"
          for i in range(0, phys_doc.GetPagesCount()):
            page = phys_doc.GetPhysicalPage(i)
            f_it = page.GetFulltextBasicObjectsBegin()
            while(f_it != page.GetFulltextBasicObjectsEnd()):
              print('        {0}'.format(
                    f_it.GetTextObject().GetOcrString().GetFirstString().GetCStr()))
              print("            Connected objects:\n")
              print("            [")
              conn_geometry = f_it.GetTextObject().GetBaseObjectInfo().GetGeometryOnPage()
              for idx in range(conn_geometry.GetPointsCount()):
                print(" ({0}, {1}) ".format(conn_geometry.GetPoint(idx).x, conn_geometry.GetPoint(idx).y))
              print("]\n")
              f_it.Advance()
      doc_it.Advance()


def main():
  if len(sys.argv) != 4 and len(sys.argv) !=3:
    print('Version {}. Usage: '
            '{} <image_path> <bundle_se_path> [document_types]'.format(
            pydocengine.DocEngine.GetVersion(), sys.argv[0]))
    sys.exit(-1)

  image_path = sys.argv[1]
  config_path = sys.argv[2]
  document_types = sys.argv[3] if len(sys.argv) == 4 else "*"

  print('Smart Document Engine version {}'.format(
         pydocengine.DocEngine.GetVersion()))
  print('image_path = {}'.format( image_path))
  print('config_path = {}'.format( config_path))
  print('document_types = {}'.format( document_types))
  print('')

  try:
    # Creating the recognition engine object - initializes all internal
    #     configuration structure. Second parameter to the factory method
    #     is the lazy initialization flag (true by default). If set to
    #     false, all internal objects will be initialized here, instead of
    #     waiting until some session needs them.
    engine = pydocengine.DocEngine.Create(config_path)

    # Before creating the session we need to have a session settings
    #     object. Such object can be created only by acquiring a
    #     default session settings object from the configured engine.
    session_settings = engine.CreateSessionSettings()

    # Printing available modes, internal engines, document types
    print('Supported modes for this configuration: [ ')
    it = session_settings.SupportedModesBegin()
    while(it != session_settings.SupportedModesEnd()):
      print('{} '.format( it.GetValue()))
      it.Advance()
    
    print(']')
    print('Current mode: {}'.format( session_settings.GetCurrentMode()))
    print('Number of internal engines for this mode: {}'.format(
           session_settings.GetInternalEnginesCount()))
    print('Supported document types for the available internal engines:')
    for i_engine in range(session_settings.GetInternalEnginesCount()):
      print('    {}: [ '.format( i_engine))
      for i_doc in range(session_settings.GetSupportedDocumentTypesCount(i_engine)):
        print('{} '.format(
               session_settings.GetSupportedDocumentType(i_engine, i_doc)))
      print(']')
    

    # For starting the session we need to set up the mask of document types
    #     which will be recognized.
    session_settings.AddEnabledDocumentTypes(document_types)

    # Printing enabled documents
    print('Enabled document types: [ ')
    for i_doc in range(session_settings.GetEnabledDocumentTypesCount()):
      print('{} '.format( session_settings.GetEnabledDocumentType(i_doc)))
    print(']')

    # Creating a session object - a main handle for performing recognition.
    session = engine.SpawnSession(session_settings, @put_yor_personalized_signature_from_doc_README.html@)

    # Creating default image processing settings - needs to be created before
    #     passing an image for processing. This specifies how the session
    #     should process the updated source.
    proc_settings = session.CreateProcessingSettings()

    # Creating an image object which will be used as an input for the session
    image = None
    try:
      image = pydocengine.Image.FromFile(image_path)
    except BaseException as e: 
      print(e.ExceptionName() + ': ' + e.what())
      return 0
  
    session.ProcessImage(image, proc_settings)

    # Obtaining the recognition result
    result = session.GetCurrentResult()

    # Printing the contents of the recognition result
    OutputRecognitionResult(result, session_settings)

  except BaseException as e: 
    print('Exception thrown: {}'.format( e.ExceptionName() + ': ' + e.what()))
    return -1
  

  return 0


if __name__ == '__main__':
    main()
