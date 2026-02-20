/**
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

// https://web.dev/module-workers/

const video = document.querySelector('#video');
const canvas = document.querySelector('#canvas');
const overlayCanvas = document.querySelector('#overlayCanvas');
const fileSelector = document.querySelector('#select_file');
const selectButton = document.querySelector("#button_select");
const buttons = document.querySelector('#buttons');

const wasm = document.querySelector('.wasm');

const log = (e) => {
  wasm.innerHTML = e;
};

log("⏳ Loading and compiling wasm...");

const SEWorker = new Worker('./worker.js');


fileSelector.addEventListener("change", async (event) => {

  const file = event.target.files[0];
  if (!file?.type?.startsWith("image/")) return;

  const canv = await getImageBuffer(file)
  const imageData = new ImageData( new Uint8ClampedArray(canv.buffer), canv.width, canv.height);

  canvas.width = overlayCanvas.width = canv.width;
  canvas.height = overlayCanvas.height = canv.height;

  canvas.getContext("2d").putImageData(imageData, 0, 0);


  SEWorker.postMessage({
    requestType: "file",
    buffer: canv.buffer,
    width: canv.width,
    height: canv.height
  }, [canv.buffer]);// transferable to worker without coping

});

function fillSelectOption(list) {
  for (let el of list) selectButton.options.add(new Option(el, el));

  SEWorker.postMessage({
    requestType: "setDocument",
    docData: selectButton.value,
  });

  selectButton.addEventListener("change", function () {
    console.log("You selected: ", this.value);
    SEWorker.postMessage({ requestType: "setDocument", docData: this.value });
  });
}

SEWorker.onmessage = function (msg) {
  switch (msg.data.requestType) {
    // events from wasm worker
    case "eventChannel":
      wasmEmitter(msg.data.data);
      break;

    // processing result
    case "result":
      let result = msg.data;

      // empty result object means timeout event
      if (Object.keys(result.documents).length === 0) {
        console.log("😕 Document Not found");
        log("😕 Document Not found");
        return;
      }

      console.log("👍 Document Ready");
      log("👍 Document Ready " + result.time + " s");

      console.log(result);
      printResult(result);
      canvasHandler.draw(msg.data, overlayCanvas);

      break;
    // no default
  }
};

// Wasm events handler
function wasmEmitter(eventType) {
  switch (eventType.type) {
    case "ready":
      console.log("🟢 v." + eventType.version + " Ready");
      log("🟢 v." + eventType.version + " Ready");
      buttons.style.display = "block";
      fillSelectOption(eventType.doclist);
      break;

    case "log":
      log(eventType.message);
      console.log(eventType.message);
      break;

    case "error":
      // reset file input value
      fileSelector.value = null;
      log(eventType.message);
      break;
    // no default
  }
};

const canvasHandler = {
  clear(overlayCanvas) {
    overlayCanvas.getContext('2d').clearRect(0, 0, overlayCanvas.width, overlayCanvas.height);
  },
  draw(result, overlayCanvas) {
    this.clear(overlayCanvas);
    if (result?.geometry) {
      for (let i = 0; i < result.geometry.length; i++) {
        const p = result.geometry[i].points;
        let colour = 'red';
        if (result.geometry[i].accepted) colour = 'green';

        const path = new Path2D();
        path.moveTo(p[0].x, p[0].y);

        if (p.length == 2) {
          path.lineTo(p[1].x, p[1].y);
        }

        if (p.length == 4) {
          path.lineTo(p[1].x, p[1].y);
          path.lineTo(p[2].x, p[2].y);
          path.lineTo(p[3].x, p[3].y);
          path.lineTo(p[0].x, p[0].y);
        }

        overlayCanvas.getContext('2d').lineWidth = 2;
        overlayCanvas.getContext('2d').strokeStyle = colour;
        overlayCanvas.getContext('2d').stroke(path);
      }
    }

    // debug drawing
    console.log('%c ', `line-height:8rem;padding-right:25%;background:url(${overlayCanvas.toDataURL('image/jpeg', 1.0)}) top left / contain no-repeat`);
  },
};

function printResult(r) {

  const output = document.querySelector("#output");
  const outputDoctypeTemplate = document.querySelector('#output-doctype-template');
  const outputFieldTemplate = document.querySelector('#output-field-template');
  const outputImageTemplate = document.querySelector('#output-image-template');

  // reset
  output.innerHTML = '';

  // field iterator
  for (const doc in r.documents) {
      //doctype
      const clone = outputDoctypeTemplate.content.cloneNode(true);
      clone.querySelector("b").innerText = r.documents[doc]?.docType;
      output.appendChild(clone);

    for (const prop in r.documents[doc].text) {
      const clone = outputFieldTemplate.content.cloneNode(true);
      clone.querySelector("b").innerText = prop;
      clone.querySelector("span").innerText = r.documents[doc].text[prop].value;
      output.appendChild(clone);
    }

    for (const prop in r.documents[doc].fullText) {
      const clone = outputFieldTemplate.content.cloneNode(true);
      const item = r.documents[doc].fullText[prop];

      const geo = item.geometry;
      const geoString = geo.map(p => `[${p.x}, ${p.y}]`).join(' ');

      console.log(`Text: "${item.text}" | Conf: ${item.confidence} | Geo: ${geoString}`);

      clone.querySelector("b").innerText = item.text;
      
      const extraSpan = clone.querySelector("span");
      if (extraSpan) extraSpan.remove();

      output.appendChild(clone);
    }
    // add separator
    output.appendChild(document.createElement('hr'));
  }
  // add separator
  output.appendChild(document.createElement('hr'));

  // image iterator
  for (const el in r.images) {
    const clone = outputImageTemplate.content.cloneNode(true);
    clone.querySelector("b").innerText = el;
    clone.querySelector("img").src = r.images[el];
    output.appendChild(clone);

  }

}

async function getImageBuffer(fileOrBlob) {
  const bitmap = await createImageBitmap(fileOrBlob);

  const canvas = document.createElement("canvas");
  canvas.width = bitmap.width;
  canvas.height = bitmap.height;
  const ctx = canvas.getContext("2d");
  ctx.drawImage(bitmap, 0, 0);

  const imageData = ctx.getImageData(0, 0, canvas.width, canvas.height);
  return {
    buffer: imageData.data.buffer,  // ArrayBuffer RGBA
    width: bitmap.width,
    height: bitmap.height
  };
}
