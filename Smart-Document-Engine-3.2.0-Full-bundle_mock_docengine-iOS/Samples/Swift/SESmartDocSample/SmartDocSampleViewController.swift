/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

import UIKit

protocol SampleViewControllerProtocol : class {
  func setModeAndDocumentTypeMask(mode: String, docTypeMask: String)
}

enum ResultSection {
  case documentInfo(index: Int, fields: [(fieldName: String, value: String, isAccepted: Bool, confidence: Double, attributes: [String: String])])
  case documentImages(index: Int, images: [(fieldName: String, value: UIImage, isAccepted: Bool, confidence: Double, attributes: [String: String])])
  case documentTables(index: Int, tables: [(fieldName: String, rows: [String], isAccepted: Bool, confidence: Double, attributes: [String: String])])
  case message(String)
}

class SampleViewController: UIViewController,
                            UIImagePickerControllerDelegate,
                            UINavigationControllerDelegate,
                            SmartDocumentEngineDelegate,
                            SmartDocumentEngineInitializationDelegate,
                            SampleViewControllerProtocol {
  var currentDocumenttypeMask : String?
  private var resultSections: [ResultSection] = []
  
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

  func setMessage(_ message: String) {
    resultSections.removeAll()
    resultSections.append(.message(message))
    resultTableView.reloadData()
  }
  
  func setResult(result: SEDocResultRef) {
    resultSections.removeAll()
    
    if result.getDocumentsCount() == 0 {
      setMessage("Document not found")
      return
    }
    
    let docIter = result.documentsBegin()
    let docEnd = result.documentsEnd()
    var documentIndex = 0
    
    while !docIter.isEqual(toIter: docEnd) {
      let doc = docIter.getDocument()
      
      let type = doc.getAttributeWithName("type")
      
      var documentFields: [(String, String, Bool, Double, [String: String])] = []
      documentFields.append(("Document Type", type, true, 1.0, [:]))
      
      if type == "untypified" {
        if doc.getPhysicalDocIdx() != -1 {
          let physDoc = result.getPhysicalDocument(doc.getPhysicalDocIdx())
          for i in 0..<physDoc.getPagesCount() {
            let physPage = physDoc.getPhysicalPage(i)
            let full_text_it = physPage.getFulltextBasicObjectsBegin()
            while !full_text_it.isEqual(toIter: physPage.getFulltextBasicObjectsEnd()) {
              let textObject = full_text_it.getTextObject()
              let isAccepted = textObject.getBaseObjectInfo().getAcceptFlag()
              let confidence = textObject.getBaseObjectInfo().getConfidence()
              
              var attributes: [String: String] = [:]
              let attrIter = textObject.getBaseObjectInfo().attributesBegin()
              let attrEnd = textObject.getBaseObjectInfo().attributesEnd()
              while !attrIter.isEqual(toIter: attrEnd) {
                attributes[attrIter.getKey()] = attrIter.getValue()
                attrIter.advance()
              }
              
              documentFields.append(
                ("Text Line",
                 textObject.getOcrString().getFirstString(),
                 isAccepted,
                 confidence,
                 attributes)
              )
              full_text_it.advance()
            }
          }
        }
      } else {
        let textFieldsIter = doc.textFieldsBegin()
        let textFieldsEnd = doc.textFieldsEnd()
        while !textFieldsIter.isEqual(toIter: textFieldsEnd) {
          let field = textFieldsIter.getField()
          let isAccepted = field.getBaseFieldInfo().getAcceptFlag()
          let confidence = field.getBaseFieldInfo().getConfidence()

          var attributes: [String: String] = [:]
          let attrIter = field.getBaseFieldInfo().attributesBegin()
          let attrEnd = field.getBaseFieldInfo().attributesEnd()
          while !attrIter.isEqual(toIter: attrEnd) {
            attributes[attrIter.getKey()] = attrIter.getValue()
            attrIter.advance()
          }
          
          documentFields.append(
            (textFieldsIter.getKey(),
             field.getOcrString().getFirstString(),
             isAccepted,
             confidence,
             attributes)
          )
          textFieldsIter.advance()
        }
        
        if !documentFields.isEmpty {
          resultSections.append(.documentInfo(index: documentIndex, fields: documentFields))
        }
        
        var imageFields: [(String, UIImage, Bool, Double, [String: String])] = []
        let imageFieldsIter = doc.imageFieldsBegin()
        let imageFieldsEnd = doc.imageFieldsEnd()
        while !imageFieldsIter.isEqual(toIter: imageFieldsEnd) {
          let field = imageFieldsIter.getField()
          if !field.getBaseFieldInfo().isFictive() {
            let isAccepted = field.getBaseFieldInfo().getAcceptFlag()
            let confidence = field.getBaseFieldInfo().getConfidence()
            
            var attributes: [String: String] = [:]
            let attrIter = field.getBaseFieldInfo().attributesBegin()
            let attrEnd = field.getBaseFieldInfo().attributesEnd()
            while !attrIter.isEqual(toIter: attrEnd) {
              attributes[attrIter.getKey()] = attrIter.getValue()
              attrIter.advance()
            }
            
            imageFields.append(
              (imageFieldsIter.getKey(),
               field.getImage().convertToUIImage(),
               isAccepted,
               confidence,
               attributes)
            )
          }
          imageFieldsIter.advance()
        }
        
        if !imageFields.isEmpty {
          resultSections.append(.documentImages(index: documentIndex, images: imageFields))
        }
        
        var tableFields: [(String, [String], Bool, Double, [String: String])] = []
        let tableFieldsIter = doc.tableFieldsBegin()
        let tableFieldsEnd = doc.tableFieldsEnd()
        while !tableFieldsIter.isEqual(toIter: tableFieldsEnd) {
          let table = tableFieldsIter.getField()
          let isAccepted = table.getBaseFieldInfo().getAcceptFlag()
          let confidence = table.getBaseFieldInfo().getConfidence()
          
          var attributes: [String: String] = [:]
          let attrIter = table.getBaseFieldInfo().attributesBegin()
          let attrEnd = table.getBaseFieldInfo().attributesEnd()
          while !attrIter.isEqual(toIter: attrEnd) {
            attributes[attrIter.getKey()] = attrIter.getValue()
            attrIter.advance()
          }
          
          var rows: [String] = []
          for i in 0..<table.getRowsCount() {
            var rowFields = ""
            for j in 0..<table.getColsCount() {
              let cell = table.getCellAtRow(i, atCol: j)
              if j > 0 {
                rowFields += "; "
              }
              rowFields += cell.getOcrString().getFirstString()
            }
            rows.append(rowFields)
          }
          
          tableFields.append((tableFieldsIter.getKey(), rows, isAccepted, confidence, attributes))
          tableFieldsIter.advance()
        }
        
        if !tableFields.isEmpty {
          resultSections.append(.documentTables(index: documentIndex, tables: tableFields))
        }
      }
      
      docIter.advance()
      documentIndex += 1
    }
    
    resultTableView.reloadData()
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
//    engineInstance.sessionSettings!
//      .setOptionWithName("common.rgbPixelFormat", to: "RGBA")
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
    
    resultTableView.register(TextFieldCell.self, forCellReuseIdentifier: "TextCell")
        resultTableView.register(ImageViewCell.self, forCellReuseIdentifier: "ImageCell")
    
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
      } else {
        self.setMessage("One bundle is required in the data folder")
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
  func numberOfSections(in tableView: UITableView) -> Int {
      return resultSections.count
  }
  
  func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
      switch resultSections[section] {
      case .documentInfo(_, let fields):
          return fields.count
      case .documentImages(_, let images):
          return images.count
      case .documentTables(_, let tables):
          return tables.reduce(0) { $0 + $1.rows.count }
      case .message:
          return 1
      }
  }
  
  func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
    switch resultSections[indexPath.section] {
    case .documentInfo(let docIndex, let fields):
      let cell = tableView.dequeueReusableCell(withIdentifier: "TextCell", for: indexPath) as! TextFieldCell
      let field = fields[indexPath.row]
      cell.configure(with: field.fieldName, value: field.value, isAccepted: field.isAccepted, confidence: field.confidence, attributes: field.attributes)
      return cell
      
    case .documentImages(let docIndex, let images):
      let cell = tableView.dequeueReusableCell(withIdentifier: "ImageCell", for: indexPath) as! ImageViewCell
      let image = images[indexPath.row]
      cell.configure(with: image.fieldName, image: image.value, isAccepted: image.isAccepted, confidence: image.confidence, attributes: image.attributes)
      return cell
      
    case .documentTables(let docIndex, let tables):
      var currentRow = 0
      for table in tables {
        if indexPath.row < currentRow + table.rows.count {
          let rowIndex = indexPath.row - currentRow
          let cell = tableView.dequeueReusableCell(withIdentifier: "TextCell", for: indexPath) as! TextFieldCell
          cell.configure(with: "\(table.fieldName) - Row \(rowIndex + 1)",
                         value: table.rows[rowIndex],
                         isAccepted: table.isAccepted,
                         confidence: table.confidence,
                         attributes: table.attributes)
          return cell
        }
        currentRow += table.rows.count
      }
      let fallbackCell = tableView.dequeueReusableCell(withIdentifier: "TextCell", for: indexPath) as! TextFieldCell
      fallbackCell.configure(with: "Error", value: "Row not found", isAccepted: false, confidence: 0.0, attributes: [:])
      return fallbackCell
      
    case .message(let message):
      let cell = tableView.dequeueReusableCell(withIdentifier: "TextCell", for: indexPath) as! TextFieldCell
      cell.configure(with: "Message", value: message, isAccepted: true, confidence: 1.0, attributes: [:])
      return cell
    }
  }
  
  func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
      let header = UIView()
      let label = UILabel()
      label.font = UIFont.boldSystemFont(ofSize: 16)
      label.textColor = .systemBlue
      
      switch resultSections[section] {
      case .documentInfo(let docIndex, _):
          label.text = "DOCUMENT \(docIndex + 1) - FIELDS"
      case .documentImages(let docIndex, _):
          label.text = "DOCUMENT \(docIndex + 1) - IMAGES"
      case .documentTables(let docIndex, _):
          label.text = "DOCUMENT \(docIndex + 1) - TABLES"
      case .message(let message):
          label.text = "RESULT"
      }
      
      header.addSubview(label)
      label.translatesAutoresizingMaskIntoConstraints = false
      NSLayoutConstraint.activate([
          label.leadingAnchor.constraint(equalTo: header.leadingAnchor, constant: 16),
          label.trailingAnchor.constraint(equalTo: header.trailingAnchor, constant: -16),
          label.topAnchor.constraint(equalTo: header.topAnchor, constant: 8),
          label.bottomAnchor.constraint(equalTo: header.bottomAnchor, constant: -8)
      ])
      
      return header
  }
  
  func tableView(_ tableView: UITableView, heightForHeaderInSection section: Int) -> CGFloat {
      return 40
  }
  
  func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
    return UITableView.automaticDimension
  }
}

extension SampleViewController {
  
  func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [UIImagePickerController.InfoKey : Any]) {
    self.setMessage("... processing image ...")
    self.resultTableView.reloadData()
    picker.dismiss(animated: true, completion: {
      DispatchQueue.main.async { [weak self] in
        let image = info[.originalImage] as! UIImage
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
