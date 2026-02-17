/**
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

// Init recognition engine
function createEngine(SE, MODULE){
  try {
    console.time("Create Engine");
    ENGINE = new SE.DocEngine(true);
    console.timeEnd("Create Engine");

    readyEmitter({ version: SE.DocEngineGetVersion() + " / " + MODULE + " / ", doclist: getAvailableDocList(ENGINE) });
  } catch (e) {
    errorEmitter({ message: e, SE });
  }
  return ENGINE;
}

// Used for runtime calculation
let PERFSTART;

// Check if session is activated, and start recognizing if it is
const checkSession = async (spawnedSession, ENGINE_CONFIG) => {
  // Is session already activated? (In case of images from canvas)
  if (spawnedSession.IsActivated()) {
    logEmitter({ message: "✅ Already activated." });
    return;
  }

  // Send request to activation server
  logEmitter({ message: "⏳ Sending activation request..." });
  // Get dynamic key
  const dynKey = spawnedSession.GetActivationRequest();
  // Get response from activation server
  const response = await fetch(ENGINE_CONFIG.activationUrl, {
    method: "POST",
    //mode: 'no-cors', // no-cors, *cors, same-origin
    headers: { "Content-Type": "text/plain" }, // text/plain requests don't trigger a CORS preflight.
    body: JSON.stringify({ action: "activate_id_session", message: dynKey }), //`{"action": "activate_id_session", "message": "${dynKey}" }`,
    signal: AbortSignal.timeout(3000),
  });

  if (!response.ok) {
    let desc = await response.json();
    throw new Error(desc.message);
  }

  const desc = await response.json();
  // Response is ok, activate session
  spawnedSession.Activate(desc.message);
  // self.PERFSTART = performance.now();

  logEmitter({ message: "✉ Activation done. Waiting for recognition..." });
};

// Used for file
function createRGBSession(engine, ENGINE_CONFIG) {
  let sessionSettings = engine.CreateSessionSettings();
  sessionSettings.SetCurrentMode(ENGINE_CONFIG.mode);
  sessionSettings.AddEnabledDocumentTypes(ENGINE_CONFIG.docTypes);
  sessionSettings.SetOption("common.extractTemplateImages", "true");
  sessionSettings.SetOption("common.sessionTimeout", "5.0");

  let spawnedSession = engine.SpawnSession(sessionSettings, ENGINE_CONFIG.signature);

  return spawnedSession;
}

// Load image from file pre-loaded in a buffer
function ImageFromRGBbytes(imageData, SE) {
  return new SE.seImage(imageData);
}

// Recognize image from file
async function recognizeFile(data, ENGINE, ENGINE_CONFIG, SE) {
  // 1. Create session
  let spawnedSessionRGB = createRGBSession(ENGINE, ENGINE_CONFIG);
  // 2. Activate session
  await checkSession(spawnedSessionRGB, ENGINE_CONFIG);
  self.PERFSTART = performance.now();
  // 3. Create image
  const image = ImageFromRGBbytes(data, SE);
  // 4. Prepare processing settings for recognition
  let proc_settings = spawnedSessionRGB.CreateProcessingSettings();
  // 5. Get recognition result
  spawnedSessionRGB.ProcessImage(image, proc_settings);
  const result = spawnedSessionRGB.GetCurrentResult();

  const resultMessage = resultObject(result);
  // Free the memory!
  image.delete();
  proc_settings.delete();
  spawnedSessionRGB.Reset();
  // console.log(resultMessage);
  return resultMessage;
}

// code from wasm-feature-detect.js
const getModuleName = async () => {
  const a = async (e) => {
    try {
      return "undefined" != typeof MessageChannel && new MessageChannel().port1.postMessage(new SharedArrayBuffer(1)), WebAssembly.validate(e);
    } catch (e) {
      return !1;
    }
  };

  const simd = async () => WebAssembly.validate(new Uint8Array([0, 97, 115, 109, 1, 0, 0, 0, 1, 5, 1, 96, 0, 1, 123, 3, 2, 1, 0, 10, 10, 1, 8, 0, 65, 0, 253, 15, 253, 98, 11]));
  const threads = () => a(new Uint8Array([0, 97, 115, 109, 1, 0, 0, 0, 1, 4, 1, 96, 0, 0, 3, 2, 1, 0, 5, 4, 1, 3, 1, 1, 10, 11, 1, 9, 0, 65, 0, 254, 16, 2, 0, 26, 11]));

  const hasSimd = await simd();
  // const hasThreads = await threads();
  const hasThreads = false;

  let module;

  if (hasSimd === true) {
    hasThreads //hasThreads
      ? (module = "simd.threads")
      : (module = "simd.nothreads");
  } else {
    module = "nosimd.nothreads";
  }

  return module;
};

// postMessages for errors for UI thread
const errorEmitter = (data) => {
  // It doesn't look good, but so far it's the only way to get string exceptions from WASM
  if (typeof data.message === "number") {
    try {
      data.message = "❌ " + data.SE.getExceptionMessage(data.message);
    } catch (e) {
      /* empty */
    }
  }
  console.error(data.message);
  // Some worker objects cannot be cloned to UI thread. Delete it.
  delete data["SE"];
  data.type = "error";
  postMessage({ requestType: "eventChannel", data });
};

// Event for ready state
const readyEmitter = (data) => {
  data.type = "ready";
  postMessage({ requestType: "eventChannel", data });
};

// Event for printing messages in log in UI side
const logEmitter = (data) => {
  data.type = "log";
  postMessage({ requestType: "eventChannel", data });
};

// Process runtime calculation
const timeDiff = () => ((performance.now() - self.PERFSTART) / 1000).toFixed(2);

// Prepare result object for worker response
function resultObject(result) {
  let res = {requestType: 'result',
             documents: [],
             geometry: [],
             time: timeDiff()}
  if (result.GetDocumentsCount() > 0) {
    let doc_iter = result.DocumentsBegin();
    for (; !doc_iter.Equals(result.DocumentsEnd()); doc_iter.Advance()) {
      const document = doc_iter.GetDocument();
      let document_result = {
        docType: document.GetAttribute("type"),
        text: getTextFields(document),
        images: getImageFields(document),
        checkboxes: getCheckBoxFields(document),
        barcodes: getBarcodeFields(document),
        tables: getTableFields(document)
      }
      res.documents.push(document_result);
    }

    res.geometry = [];
  } else {
    console.log("No documents here\n")
  }
  // console.log(res);
  return res;
}

// Get text fields in result
function getTextFields(result) {
  const data = {};
  const tf = result.TextFieldsBegin();
  for (; !tf.Equals(result.TextFieldsEnd()); tf.Advance()) {
    const key = tf.GetKey();
    const field = tf.GetField();
    let value = field.GetOcrString().GetFirstString();
    console.log("value is: " + value);
    data[key] = {
      name: key,
      value: value,
      isAccepted: field.GetBaseFieldInfo().GetAcceptFlag(),
      attr: getFieldAttributes(field),
    };
  }
  return data;
}

// Get images fields in result
function getImageFields(result) {
  let images = {};
  const img_iter = result.ImageFieldsBegin();
  for (; !img_iter.Equals(result.ImageFieldsEnd()); img_iter.Advance()) {
    const key = img_iter.GetKey();
    const field = img_iter.GetField();

    images[key] = {
      name: key,
      value: _base64toBlob(field.GetImage().GetBase64String()),
      isAccepted: field.GetBaseFieldInfo().GetAcceptFlag(),
      attr: getFieldAttributes(field),
    };
  }
  // console.log(images)
  return images;
}

// Get checkbox fields in result
function getCheckBoxFields(result) {
  let checkbox_fields = {};
  const checkbox_iter = result.CheckboxFieldsBegin();
  for (; !checkbox_iter.Equals(result.CheckboxFieldsEnd()); checkbox_iter.Advance()) {
    const key = checkbox_iter.GetKey();
    const field = checkbox_iter.GetField();
    const status = field.GetTickStatus();
    checkbox_fields[key] = {
      name: key,
      value: status,
      isAccepted: field.GetBaseFieldInfo().GetAcceptFlag(),
      attr: getFieldAttributes(field),
    };
  }
  // console.log(checkbox_fields)
  return checkbox_fields;
}

// Get barcode fields in result
function getBarcodeFields(result) {
  let barcode_fields = {};
  const barcode_iter = result.CheckboxFieldsBegin();
  for (; !barcode_iter.Equals(result.CheckboxFieldsEnd()); barcode_iter.Advance()) {
    const key = barcode_iter.GetKey();
    const field = barcode_iter.GetField();
    const barcode_data = field.GetDecodedString();
    barcode_fields[key] = {
      name: key,
      value: barcode_data,
      isAccepted: field.GetBaseFieldInfo().GetAcceptFlag(),
      attr: getFieldAttributes(field),
    };
  }
  // console.log(barcode_fields)
  return barcode_fields;
}

// Get table fields in result
function getTableFields(result) {
  let table_fields = {};
  const table_iter = result.TableFieldsBegin();
  for (; !table_iter.Equals(result.TableFieldsEnd()); table_iter.Advance()) {
    let table = []
    const key = table_iter.GetKey();
    const field = table_iter.GetField();
    const row_count = field.GetRowsCount()
    const col_count = field.GetColsCount()
    for (r=0; r<row_count; ++r){
      row_array = []
      for (c=0; c<col_count; ++c){
        row_array[c] = field.GetCell(r,c).GetOcrString().GetFirstString();
      }
      table[r] = row_array;
    }
  
    table_fields[key] = {
      name: key,
      value: table,
      isAccepted: field.GetBaseFieldInfo().GetAcceptFlag(),
      attr: getFieldAttributes(field),
    };
  }
  // console.log(table_fields)
  return table_fields;
}

// Get field attributes for field
function getFieldAttributes(field) {
  let attributes = {}
  let dataField = field.GetBaseFieldInfo();
  let start = dataField.AttributesBegin();
  let end = dataField.AttributesEnd();
  for (; !start.Equals(end); start.Advance()) {

    let attrKey = start.GetKey();
    let attrValue = start.GetValue();
    attributes[attrKey] = attrValue;

    // console.log("🔸 " + attrKey + ":" + attrValue);
  }
  return attributes
}

// Get object attributes
function getObjectAttributes(object) {
  let attributes = {}
  let dataField = object.GetBaseObjectInfo();
  let start = dataField.AttributesBegin();
  let end = dataField.AttributesEnd();
  for (; !start.Equals(end); start.Advance()) {

    let attrKey = start.GetKey();
    let attrValue = start.GetValue();
    attributes[attrKey] = attrValue;

    // console.log("🔸 " + attrKey + ":" + attrValue);
  }
  return attributes
}

/* Convert base64 images to blob urls for better reuse in UI */
function _base64toBlob(data) {
  const b = atob(data);
  const byteNumbers = new Array(b.length);
  for (let i = 0; i < b.length; i++) {
    byteNumbers[i] = b.charCodeAt(i);
  }
  const byteArray = new Uint8Array(byteNumbers);
  const file = new Blob([byteArray], { type: 'image/jpg' + ';base64' });
  return URL.createObjectURL(file);
}

// Get available document lists in your SDK
function getAvailableDocList(engine) {
  const sessionSettings = engine.CreateSessionSettings();

  let arr = [];
  const ie = sessionSettings.SupportedModesBegin();
  for (; !ie.Equals(sessionSettings.SupportedModesEnd()); ie.Advance()) {
    let mode = ie.GetValue();
    sessionSettings.SetCurrentMode(mode);

    console.log("🔸Mode : " + ie.GetValue());
    const dd = sessionSettings.PermissiblePrefixDocMasksBegin();
    for (; !dd.Equals(sessionSettings.PermissiblePrefixDocMasksEnd()); dd.Advance()) {
      arr.push(mode + ":" + dd.GetValue());
      console.log("▪ " + dd.GetValue());
    }
  }
  return arr;
}

