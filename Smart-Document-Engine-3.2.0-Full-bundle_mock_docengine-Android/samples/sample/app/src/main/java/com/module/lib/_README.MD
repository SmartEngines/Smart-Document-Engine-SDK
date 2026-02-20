# Lib description

## Engine.java

The `Engine` class is a singleton helper for managing the loading and initialization of the document processing engine in an Android application. It provides asynchronous and synchronous methods for loading the engine, while exposing the loading state as `LiveData`.

- `static void loadAsync(Context context)`: Initiates asynchronous loading of the engine.
- `static void loadSync(Context context)`: Initiates synchronous loading of the engine.
- `static String[] getDocumentsList()`: Returns an array of supported document types.

- `totalTime` - init engine time.

To use the `Engine` class, simply call the `loadAsync` or `loadSync` methods with the application context, and observe the `loadingState` for updates on the engine's status.

Example of usage engine loading events:

```java
Engine.loadingState.observe(this, loadingState -> {
  if (loadingState == Engine.LoadingState.Loading) {
    Label.getInstance().message.set("Engine loading...");
  } else if (loadingState == Engine.LoadingState.Ready) {
    runOnUiThread(this::onInitialized);
  } else if (loadingState == Engine.LoadingState.Error) {
    Label.getInstance().message.set("Engine init error");
  }
});
```

## Image.java

The `Image` class provides utility methods for creating and manipulating images in various formats.

- `static Image.createFromBase64(String imageObject)`: Creates an image from a Base64 encoded string.
- `static Image.createFromUri(String imageObject, Context context)`: Creates an image from a URI, handling different Android versions.
- `static Image.createFromByteArray(@NonNull byte[] bytes)`: Creates an image from a byte array, commonly used in Flutter applications.
- `static Image.createFromBitmap(Bitmap bitmap)`: Creates an image from an Android Bitmap.
- `static Image.createFromImageProxy(ImageProxy imageObject)`: Creates an image from a CameraX `ImageProxy`, supporting YUV and JPEG formats.
- `static Image.imageProxyToBitmap(ImageProxy image)`: Converts a CameraX `ImageProxy` to an Android Bitmap.

## Session.java

The `Session` class serves as a helper for managing image recognition sessions using the Smart Engines document processing engine. It provides methods for creating sessions, activating them, and handling network requests for activation keys.

- `static void createImageSession()`: Creates a new image recognition session by:

## Settings.java

The `Settings` class serves as a storage for configuration settings.

- `static void SetMask(ArrayList<String> mask)`: Sets the current document mask to the provided list of document types.
- `static void SetMode(String mode)`: Updates the current mode of the engine.
- `static void SetSignature(String sign)`: Sets the signature for the engine.
- `static void SetOptions(Map<String, String> map)`: Updates the options map with the provided key-value pairs.

To use the `Settings` class, call the appropriate static methods to configure the engine's settings before starting a session. This allows for dynamic adjustments to the engine's behavior based on the application's requirements.
