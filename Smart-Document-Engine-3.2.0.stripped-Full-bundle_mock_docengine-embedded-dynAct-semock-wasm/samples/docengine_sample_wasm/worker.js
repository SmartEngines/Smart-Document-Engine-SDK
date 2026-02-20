/**
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

"use strict";

(async () => {
  // Main config
  const ENGINE_CONFIG = {
    activationUrl: "http://localhost:8000/client/sign_message",
    mode: "default", // <- set document mode
    docTypes: "*", // <- set document mask. 
    signature: PUT_YOUR_PERSONAL_SIGNATURE_FROM_doc  // <-- set secret key
  };

  // Get root path relative to worker.js
  const pathname = self.location.pathname;
  let ROOT_PATH = pathname.substring(0, pathname.lastIndexOf("/") + 1); // "/dir/dir2/worker.js" return "/dir/dir2/"

  /* importScripts is still the most compatible.
   * Module workers are only supported with iOS15.
   * We don't want to use polyfill for that
   * https://wpt.fyi/results/workers/modules/dedicated-worker-import.any.html?label=master&label=stable&product=chrome&product=firefox&product=safari-14.1.2%20%2815611.3.10.1.7%29
   */

  importScripts(`${ROOT_PATH}se-func.js`);

  // Import getModuleName()
  let MODULE = await getModuleName();

  // For sample demostration we change bin root folder
  if (ROOT_PATH == "/samples/docengine_sample_wasm/") {
    ROOT_PATH = "/"
  }

  // Import the relevant global Engine object
  importScripts(`${ROOT_PATH}bin/${MODULE}/docengine_wasm.js`);

  // *_wasm.js files are auto-generated from emscripten
  let module = {
    mainScriptUrlOrBlob: `${ROOT_PATH}bin/${MODULE}/docengine_wasm.js`,
    locateFile: (file) => `${ROOT_PATH}bin/${MODULE}/` + file,
  };

  // Init WASM module
  const SE = await SmartDocEngine(module);

  // WASM OPTIMIZATION:
  // allocate memory for first Image before recognition
  prepareImageBuffer(SE, 1);

  // Init recognition engine
  let ENGINE = createEngine(SE, MODULE);

  onmessage = async function (msg) {
    switch (msg.data.requestType) {
      case "setDocument":
        const data = msg.data.docData.split(":");
        // console.log(data)
        ENGINE_CONFIG.docTypes = data[1];
        ENGINE_CONFIG.mode = data[0];

        break;

      case 'file':
        const r = await recognize(SE, ENGINE, ENGINE_CONFIG, msg.data)
        postMessage(r);

        break;

      // no default
    }
  };
})();
