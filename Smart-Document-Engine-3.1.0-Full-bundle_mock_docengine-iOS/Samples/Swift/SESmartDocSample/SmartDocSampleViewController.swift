/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

import UIKit

protocol SampleSmartDocumentEngineViewControllerProtocol : class {
  func setModeAndDocumentTypeMask(mode: String, docTypeMask: String)
}

class SampleViewController: UIViewController,
                            UIImagePickerControllerDelegate,
                            UINavigationControllerDelegate,
                            SmartDocumentEngineDelegate,
                            SmartDocumentEngineInitializationDelegate,
                            SampleSmartDocumentEngineViewControllerProtocol {
  var currentDocumenttypeMask : String?
  
  func setModeAndDocumentTypeMask(mode: String, docTypeMask: String) {
    engineInstance.sessionSettings!.setCurrentModeTo(mode)
    engineInstance.sessionSettings!.removeEnabledDocumentTypes(withMask: "*")
    engineInstance.sessionSettings!.addEnabledDocumentTypes(withMask: docTypeMask)
    
    self.currentDocumenttypeMask = mode + " : " + docTypeMask
    print("Current mode is \(mode), doc type mask is \(docTypeMask)")
  }

  var docTypeListViewController : DocTypesListController!
    
  var resultTableView : UITableView = {
    var resultTableView = UITableView()
    resultTableView.register(TextFieldCell.self, forCellReuseIdentifier: "TextCell")
    resultTableView.register(ImageViewCell.self, forCellReuseIdentifier: "ImageCell")
    resultTableView.estimatedRowHeight = 100
    resultTableView.translatesAutoresizingMaskIntoConstraints = false
    return resultTableView
  }()
    
  func setTableViewAnchors() {
    if #available(iOS 11.0, *) {
      resultTableView.topAnchor.constraint(equalTo: view.safeAreaLayoutGuide.topAnchor, constant: 0).isActive = true
      resultTableView.leadingAnchor.constraint(equalTo: view.safeAreaLayoutGuide.leadingAnchor, constant: 0).isActive = true
      resultTableView.trailingAnchor.constraint(equalTo: view.safeAreaLayoutGuide.trailingAnchor, constant: 0).isActive = true
      resultTableView.bottomAnchor.constraint(equalTo: view.safeAreaLayoutGuide.bottomAnchor, constant: -50).isActive = true
    } else {
      resultTableView.topAnchor.constraint(equalTo: view.topAnchor, constant: 0).isActive = true
      resultTableView.leadingAnchor.constraint(equalTo: view.leadingAnchor, constant: 0).isActive = true
      resultTableView.trailingAnchor.constraint(equalTo: view.trailingAnchor, constant: 0).isActive = true
      resultTableView.bottomAnchor.constraint(equalTo: view.bottomAnchor, constant: -50).isActive = true
    }
    resultTableView.estimatedRowHeight = 600
    resultTableView.allowsSelection = false
  }
    
  private var resultTextFields = [(fieldName: String, value: String)]()
  private var resultImageFields = [(fieldName: String, value: UIImage)]()
    
  func setMessage(_ message: String) {
    resultTextFields.removeAll()
    resultImageFields.removeAll()
    
    resultTextFields.append((message, ""))
  }
  
  func setResult(result: SEDocResultRef) {
    resultTextFields.removeAll()
    resultImageFields.removeAll()
    
    if result.getDocumentsCount() == 0 {
      self.setMessage("Document not found")
      return
    }
    
    let docIter = result.documentsBegin()
    let docEnd = result.documentsEnd()
    while !docIter.isEqual(toIter: docEnd) {
      let doc = docIter.getDocument()
      
      let type = doc.getAttributeWithName("type")
      resultTextFields.append(("#type", type))
      
      if type == "untypified" {
        if doc.getPhysicalDocIdx() != -1 {
          let physDoc = result.getPhysicalDocument(doc.getPhysicalDocIdx())
          for i in 0..<physDoc.getPagesCount() {
            let physPage = physDoc.getPhysicalPage(i)
            let full_text_it = physPage.getFulltextBasicObjectsBegin()
            while !full_text_it.isEqual(toIter: physPage.getFulltextBasicObjectsEnd()) {
              resultTextFields.append(
                ("__text_line__", full_text_it.getTextObject().getOcrString().getFirstString()))
              full_text_it.advance()
            }
          }
        }
      } else {
        let textFieldsIter = doc.textFieldsBegin()
        let textFieldsEnd = doc.textFieldsEnd()
        while !textFieldsIter.isEqual(toIter: textFieldsEnd) {
          resultTextFields.append(
            (textFieldsIter.getKey(), textFieldsIter.getField().getOcrString().getFirstString()))
          textFieldsIter.advance()
        }
        
        let imageFieldsIter = doc.imageFieldsBegin()
        let imageFieldsEnd = doc.imageFieldsEnd()
        while !imageFieldsIter.isEqual(toIter: imageFieldsEnd) {
          resultImageFields.append(
            (imageFieldsIter.getKey(),
             imageFieldsIter.getField().getImage().convertToUIImage()))
          imageFieldsIter.advance()
        }
        
        let tableFieldsIter = doc.tableFieldsBegin()
        let tableFieldsEnd = doc.tableFieldsEnd()
        while !tableFieldsIter.isEqual(toIter: tableFieldsEnd) {
          let table = tableFieldsIter.getField()
          for i in 0..<table.getRowsCount() {
            var rowFields : String = ""
            for j in 0..<table.getColsCount() {
              let cell = table.getCellAtRow(i, atCol: j)
              if j > 0 {
                rowFields += "; "
              }
              rowFields += cell.getOcrString().getFirstString()
            }
            resultTextFields.append(("\(tableFieldsIter.getKey())_row\(i)", rowFields))
          }
          tableFieldsIter.advance()
        }
      }
      docIter.advance()
    }
    
    resultTextFields.sort(by: {
        return $0.0 < $1.0
    })
    resultImageFields.sort(by: {
        return $0.0 < $1.0
    })
  }
    
  let cameraButton: UIButton = {
    let button = UIButton(type: .roundedRect)
    button.autoresizingMask = .flexibleWidth
    button.setTitle("...", for: .normal)
    button.isEnabled = false
    button.layer.borderColor = UIColor.blue.cgColor
    return button
  }()
    
  let galleryButton: UIButton = {
    let button = UIButton(type: .roundedRect)
    button.autoresizingMask = .flexibleWidth
    button.setTitle("initializing ...", for: .normal)
    button.isEnabled = false
    button.layer.borderColor = UIColor.blue.cgColor
    return button
  }()
    
  let documentListButton: UIButton = {
    let button = UIButton(type: .roundedRect)
    button.autoresizingMask = .flexibleWidth
    button.setTitle("...", for: .normal)
    button.isEnabled = false
    button.layer.borderColor = UIColor.blue.cgColor
    return button
  }()
  
  let photoLibraryImagePicker : UIImagePickerController = {
    let picker = UIImagePickerController()
    if UIImagePickerController.isSourceTypeAvailable(UIImagePickerController.SourceType.photoLibrary) {
      picker.sourceType = .photoLibrary
      picker.modalPresentationStyle = .fullScreen
    }
    return picker
  }()
  
  let photoCameraImagePicker : UIImagePickerController = {
    let picker = UIImagePickerController()
    if UIImagePickerController.isSourceTypeAvailable(UIImagePickerController.SourceType.camera) {
      picker.sourceType = UIImagePickerController.SourceType.camera
      picker.modalPresentationStyle = .fullScreen
      picker.cameraFlashMode = .off
      picker.cameraDevice = .rear
      picker.cameraCaptureMode = .photo
    }
    return picker
  }()
  
  let engineInstance : SmartDocumentEngineInstance = {
    let signature = "Place your signature here (see doc\README.html)"
    return SmartDocumentEngineInstance(signature: signature)
  }()
  
  func smartDocumentEngineInitialized() {
    
    self.galleryButton.setTitle("Gallery", for: .normal)
    self.cameraButton.setTitle("Photo", for: .normal)
    self.documentListButton.setTitle("Select type", for: .normal)
    
    self.galleryButton.isEnabled = true
    self.cameraButton.isEnabled = true
    self.documentListButton.isEnabled = true

    self.photoCameraImagePicker.delegate = self
    self.photoLibraryImagePicker.delegate = self
    
    self.configureSessionOptions() // calling _after_ attaching engine instance
  }
  
  func smartDocumentEngineObtainedSingleImageResult(_ result: SEDocResultRef) {
    self.setResult(result: result)
    resultTableView.reloadData()
  }
    
  override func viewDidLayoutSubviews() {
    let bottomSafeArea: CGFloat
    
    // safe area for phones with notch
    
    if #available(iOS 11.0, *) {
      bottomSafeArea = view.safeAreaInsets.bottom
    } else {
      bottomSafeArea = bottomLayoutGuide.length
    }
    
    let elementSize: CGFloat = 50
    
    cameraButton.frame = CGRect(x: 0,
                                y: view.bounds.size.height - bottomSafeArea - elementSize,
                                width: view.bounds.size.width/3,
                                height: elementSize)
    
    galleryButton.frame = CGRect(x: view.bounds.size.width/3,
                                 y: view.bounds.size.height - bottomSafeArea - elementSize,
                                 width: view.bounds.size.width/3,
                                 height: elementSize)
    
    documentListButton.frame = CGRect(x: view.bounds.size.width*2/3,
                                      y: view.bounds.size.height - bottomSafeArea - elementSize,
                                      width: view.bounds.size.width/3,
                                      height: elementSize)
  }
    
  func configureSessionOptions() {
    // you can set mode and document mask here, if you are not using document types table
    engineInstance.sessionSettings!
      .setOptionWithName("common.rgbPixelFormat", to: "RGBA")
  }
    
  override func viewDidLoad() {
    super.viewDidLoad()
    
    if #available(iOS 13.0, *) {
      self.view.backgroundColor = .systemBackground
    } else {
      self.view.backgroundColor = .white
    }
    
    view.addSubview(resultTableView)
    setTableViewAnchors()
    resultTableView.delegate = self
    resultTableView.dataSource = self
    
    view.addSubview(cameraButton)
    view.addSubview(galleryButton)
    view.addSubview(documentListButton)
    
    cameraButton.addTarget(self, action: #selector(self.processFromCamera), for: .touchUpInside)
    galleryButton.addTarget(self, action: #selector(self.processFromGallery), for: .touchUpInside)
    documentListButton.addTarget(self, action: #selector(self.showTypesList), for: .touchUpInside)
    
    DispatchQueue.main.async {
      
      let bundlePaths = Bundle.main.paths(forResourcesOfType: "se", inDirectory: "data")
      
      if bundlePaths.count == 1 {
        
        self.engineInstance.setInitializationDelegate(self)
        self.engineInstance.initializeEngine(bundlePaths[0])
        self.engineInstance.sessionSettings!.setCurrentModeTo("default")
        self.engineInstance.setEngineDelegate(self)
          
        // getting list of supported document modes and types
        
        var modesList = [String]() // modes are not sorted
        let modesEnd = self.engineInstance.sessionSettings!.supportedModesEnd()
        let modesIt = self.engineInstance.sessionSettings!.supportedModesBegin()
        while !modesIt.isEqual(toIter: modesEnd) {
          modesList.append(modesIt.getValue())
          modesIt.advance()
        }
          
        var docTypesList = [String:[String]]()
        for mode in modesList {
          self.engineInstance.sessionSettings!.setCurrentModeTo(mode)
          
          var masks = [String]()
          
          let masksIter = self.engineInstance.sessionSettings!.permissiblePrefixDocMasksBegin()
          let masksEnd = self.engineInstance.sessionSettings!.permissiblePrefixDocMasksEnd()
          while !masksIter.isEqual(toIter: masksEnd) {
            masks.append(masksIter.getValue())
            masksIter.advance()
          }
          
          docTypesList[mode] = masks
        }
        
        if (modesList.count == 1) && (docTypesList[modesList[0]]!.count) == 1 {
          self.setModeAndDocumentTypeMask(
              mode: modesList[0],
              docTypeMask: docTypesList[modesList[0]]![0])
        }
        
        self.docTypeListViewController = DocTypesListController(docTypesList: docTypesList)
        self.docTypeListViewController.delegateSampSID = self
      }
    }
  }
    
  override func didReceiveMemoryWarning() {
    super.didReceiveMemoryWarning()
  }
  
  override func viewDidAppear(_ animated: Bool) {
    super.viewDidAppear(animated)
  }
    
   
  func showAlert(msg: String) {
    let alert = UIAlertController(title: "Warning", message: msg, preferredStyle: .alert)
    alert.addAction(UIAlertAction(
        title: NSLocalizedString("OK", comment: "Default action"),
        style: .default,
        handler: { _ in
      NSLog("The \"OK\" alert occured.")
    }))
    self.present(alert, animated: true, completion: nil)
  }
    
  @objc func processFromGallery() {
    if currentDocumenttypeMask != nil {
      self.present(self.photoLibraryImagePicker, animated: true, completion: nil)
    } else {
      showAlert(msg: "Select document type")
    }
  }
    
  @objc func processFromCamera() {
    if currentDocumenttypeMask != nil {
      if UIImagePickerController.isSourceTypeAvailable(UIImagePickerController.SourceType.camera) {
        present(photoCameraImagePicker, animated: true, completion: nil)
      }
    } else {
      showAlert(msg: "Select document type")
    }
  }
    
  @objc func showTypesList() {
    present(docTypeListViewController, animated: true, completion: nil)
  }
}

// MARK: SEResultTableView

extension SampleViewController: UITableViewDelegate, UITableViewDataSource {
  func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
    return resultTextFields.count + resultImageFields.count
  }
    
  func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
    if (indexPath.row < resultTextFields.count) {
      let cell = resultTableView.dequeueReusableCell(withIdentifier: "TextCell", for: indexPath) as! TextFieldCell
      cell.fieldName.text = resultTextFields[indexPath.row].fieldName
      cell.resultTextView.text = resultTextFields[indexPath.row].value
      return cell
    } else {
      let cell = resultTableView.dequeueReusableCell(withIdentifier: "ImageCell", for: indexPath) as! ImageViewCell
      cell.fieldName.text = resultImageFields[indexPath.row - resultTextFields.count].fieldName
      cell.imageFieldView.image = resultImageFields[indexPath.row - resultTextFields.count].value
      return cell
    }
  }
    
  func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
    return UITableViewAutomaticDimension
  }
}

extension SampleViewController {
    
  func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [String : Any]) {
    self.setMessage("... processing image ...")
    self.resultTableView.reloadData()
    picker.dismiss(animated: true, completion: {
      DispatchQueue.main.async { [weak self] in
        let image = info[UIImagePickerControllerOriginalImage] as! UIImage
        self?.engineInstance.initSession()
        self?.engineInstance.processImage(from: image)
        self?.engineInstance.dismissSession()
      }
    })
  }
  
  func imagePickerControllerDidCancel(_ picker: UIImagePickerController) {
    self.setMessage("Cancelled by user")
    self.resultTableView.reloadData()
    picker.dismiss(animated: true, completion: nil)
  }
}
