# Smart Document Engine SDK Overview

This is a collection of DEMO builds of Smart Document Engine SDK developed by Smart Engines. The SDK examples can be used to demonstrate the integration possibilities and understand the basic object recognition workflows.

  * [:warning: Personalized signature :warning:](#warning-personalized-signature-warning)
  * [Troubleshooting and help](#troubleshooting-and-help)
  * [General Usage Workflow](#general-usage-workflow)
  * [Smart Document Engine SDK Overview](#smart-document-engine-sdk-overview)
    - [Header files, namespaces, and modules](#header-files-namespaces-and-modules)
    - [Code documentation](#code-documentation)
    - [Exceptions](#exceptions)
    - [Factory methods and memory ownership](#factory-methods-and-memory-ownership)
  * [Multipage document recognition](#multipage-document-recognition)
  * [Configuration bundles](#configuration-bundles)
  * [Specifying document types for DocSession](#specifying-document-types-for-docsession)
    - [Supported document types](#supported-document-types)
    - [Enabling document types using wildcard expressions](#enabling-document-types-using-wildcard-expressions)
    - [Session modes](#session-modes)
  * [Session options](#session-options)
  * [Java API Specifics](#java-api-specifics)
    - [Object deallocation](#object-deallocation)
  * [FAQ](#faq)


## :warning: Personalized signature :warning:

Starting from Smart Document Engine v1.11.0 users are required to use a personalized signature for starting a session. The signature is validated offline and locks to the copy of the native library, thus ensures that only an authorized client may use it. The signature is a string with 256 characters.

You will need to manually copy the signature string and pass it as an argument for the `SpawnSession()` method ([see item 6 below](#general-usage-workflow)). Do NOT keep the signature in any asset files, only inside code. If possible, clients are encouraged to keep the signature in a controlled server and load it into the application via a secure channel, to ensure that signature and the library are separated.



## Troubleshooting and help

To resolve issue that you might be facing we recommend to do the following:

* Carefully read in-code documentation in API and samples and documentation in .pdf and .html, including this document
* Check out the code details / compilation flags etc. in the sample code and projects
* Read exception messages if exception is thrown - it might contain usable information

But remember:

* You are always welcome to ask for help at `support@smartengines.com` (or your sales manager's email) no matter what

## General Usage Workflow

1. Create `DocEngine` instance:

    ```cpp
    // C++
    std::unique_ptr<se::doc::DocEngine> engine(se::doc::DocEngine::Create(
        configuration_bundle_path));
    ```

    ```java
    // Java
    DocEngine engine = DocEngine.Create(configuration_bundle_path);
    ```

    Configuration process might take a while but it only needs to be performed once during the program lifetime. Configured `DocEngine` is used to spawn sessions which have actual recognition methods.

    The second parameter to the `Create()` method is a boolean flag for enabling lazy configuration (`true` by default). If lazy configuration is enabled, some of the internal structured will be allocated and initialized only when first needed. If you disable the lazy configuration, all the internal structures and components will be initialized in the `Create()` method.

    See more about configuration bundles in [Configuration Bundles](#configuration-bundles).

2. Create `DocSessionSettings` from configured `DocEngine`:

    ```cpp
    // C++
    std::unique_ptr<se::doc::DocSessionSettings> settings(
          engine->CreateSessionSettings());
    ```

    ```java
    // Java
    DocSessionSettings settings = engine.CreateSessionSettings();
    ```

    Note, that `DocEngine::CreateSessionSettings()` is a factory method and returns an allocated pointer. You are responsible for deleting it.

3. Enable desired document types:

    ```cpp
    // C++
    settings->AddEnabledDocumentTypes("rus.2ndfl.*"); // Russian personal tax form (2-NDFL)
    ```

    ```java
    // Java
    settings.AddEnabledDocumentTypes("rus.2ndfl.*"); // Russian personal tax form (2-NDFL)
    ```

    See more about document types in [Specifying document types for DocSession](#specifying-document-types-for-docsession).

4. Spawn DocSession:

    ```cpp
    // C++
    const char* signature = "... YOUR SIGNATURE HERE ...";
    std::unique_ptr<se::doc::DocSession> session(
        engine->SpawnSession(*settings, signature));
    ```

    ```java
    // Java
    String signature = "... YOUR SIGNATURE HERE ...";
    DocSession session = engine.SpawnSession(settings, signature); 
    ```

5. Create a processing settings object

    ```cpp
    // C++
    std::unique_ptr<se::doc::DocProcessingSettings> proc_settings(
        session->CreateProcessingSettings());
    ```

    ```java
    // Java
    DocProcessingSettings proc_settings = session.CreateProcessingSettings();
    ```

6. Create an Image object which will be used for processing:

    ```cpp
    // C++
    std::unique_ptr<se::common::Image> image(
        se::common::Image::FromFile(image_path)); // Loading from file
    ```

    ```java
    // Java
    Image image = Image.FromFile(image_path); // Loading from file
    ```

7. Call `ProcessImage(...)` method for launching the image recognition

    ```cpp
    // C++
    session->ProcessImage(*image, proc_settings.get());
    ```

    ```java
    // Java
    session.ProcessImage(image, proc_settings);
    ```

8. Obtain the current result from the session

    ```cpp
    // C++
    const se::doc::DocResult& result = session->GetCurrentResult();
    ```

    ```java
    // Java
    DocResult result = session.GetCurrentResult();
    ```

9. Use `DocResult` fields to extract recognized information:

    ```cpp
    // C++
    // Going through the found documents
    for (auto doc_it = result.DocumentsBegin();
         doc_it != result.DocumentsEnd();
         ++doc_it) {
        const se::doc::Document& doc = doc_it.GetDocument();
        
        // Going through the text fields
        for (auto it = doc.TextFieldsBegin();
             it != doc.TextFieldsEnd();
             ++it) {

            // Getting text field value (UTF-8 string representation)
            std::string field_value = it.GetField().GetOcrString().GetFirstString().GetCStr();
        }
    }
    ```

    ```java
    // Java
    // Going through the found documents
    for (DocumentsIterator doc_it = result.DocumentsBegin();
         !doc_it.Equals(result.DocumentsEnd());
         doc_it.Advance()) {
        Document doc = doc_it.GetDocument();

        // Going through the text fields
        for (DocTextFieldsIterator it = doc.TextFieldsBegin();
             !it.Equals(doc.TextFieldsEnd());
             it.Advance()) {

            // Getting text field value (UTF-8 string representation)
            String field_value = it.GetField().GetOcrString().GetFirstString().GetCStr();
        }
    }
    ```

## Smart Document Engine SDK Overview

#### Header files, namespaces, and modules

Common classes, such as Point, OcrString, Image, etc. are located within `se::common` namespace and are located within a `secommon` directory:

```cpp
// C++
#include <secommon/se_export_defs.h>      // This header contains export-related definitions of Smart Engines libraries
#include <secommon/se_exceptions.h>       // This header contains the definition of exceptions used in Smart Engines libraries
#include <secommon/se_geometry.h>         // This header contains geometric classes and procedures (Point, Rectangle, etc.)
#include <secommon/se_image.h>            // This header contains the definition of the Image class 
#include <secommon/se_string.h>           // This header contains the string-related classes (MutableString, OcrString, etc.)
#include <secommon/se_strings_iterator.h> // This header contains the definition of string-targeted iterators
#include <secommon/se_serialization.h>    // This header contains auxiliary classes related to object serialization

#include <secommon/se_common.h>           // This is an auxiliary header which simply includes all of the above
```

The same common classes in Java API are located within `com.smartengines.common` module:

```java
// Java
import com.smartengines.common.*; // Import all se::common classes
```

Main Smart Document Engine classes are located within `se::doc` namespaces and are located within an `docengine` directory:

```cpp
// C++

#include <docengine/doc_engine.h>              // Contains DocEngine class definition
#include <docengine/doc_session_settings.h>    // Contains DocSessionSettings class definition
#include <docengine/doc_session.h>             // Contains DocSession class definition
#include <docengine/doc_processing_settings.h> // Contains DocProcessingSettings class definition

#include <docengine/doc_result.h>              // Contains DocResult class definition
#include <docengine/doc_document.h>            // Contains Document class definition
#include <docengine/doc_documents_iterator.h>  // Contains Document-related iterators
#include <docengine/doc_fields.h>              // Contains the definitions of Smart Document Engine fields
#include <docengine/doc_fields_iterators.h>    // Contains fields-related iterators
#include <docengine/doc_feedback.h>            // Contains the DocFeedback interface and associated containers

#include <docengine/doc_document_field_info.h> // Contains DocDocumentFieldInfo class definition
#include <docengine/doc_document_fields_info_iterator.h> // Contains DocDocumentFieldInfo-related iterators

#include <docengine/doc_document_info.h> // Contains DocDocumentInfo class definition

#include <docengine/doc_physical_document.h> // Contains DocPhysicalDocument, DocPhysicalPage, and DocPageInfo class definitions
#include <docengine/doc_physical_document_iterators.h> // Contains DocPhysicalDocument-related iterators
#include <docengine/doc_scene_info.h> // Contains DocSceneInfo class definition

#include <docengine/doc_basic_object.h>                 // Contains DocBasicObject class definition
#include <docengine/doc_basic_objects_iterator.h>       // Contains DocBasicObject-related iterators
#include <docengine/doc_objects.h>                      // Contains definitions of graphical object classes
#include <docengine/doc_objects_collection.h>           // Contains DocObjectsCollection class definition
#include <docengine/doc_objects_collections_iterator.h> // Contains DocObjectsCollection-related iterators

#include <docengine/doc_forward_declarations.h>         // Service header containing forward declarations of all classes

/// Soflty deprecated headers (to be removed in future versions)

#include <docengine/doc_video_session.h>       // Contains DocVideoSession class definition
#include <docengine/doc_external_processor.h>  // Contains the external document processing interface

#include <docengine/doc_graphical_structure.h> // Contains DocGraphicalStructure class definition
#include <docengine/doc_tags_collection.h>     // Contains DocTagsCollection class definition

#include <docengine/doc_view.h>                // Contains DocView class definition
#include <docengine/doc_views_iterator.h>      // Contains DocView-related iterators
#include <docengine/doc_views_collection.h>    // Contains DocViewsCollection class definition
```

The same classes in Java API are located within `com.smartengines.doc` module:

```java
// Java
import com.smartengines.doc.*; // Import all se::doc classes
```

#### Code documentation

All classes and functions have useful Doxygen comments.
Other out-of-code documentation is available at `doc` folder of your delivery.
For complete compilable and runnable sample usage code and build scripts please see `samples` folder.

#### Exceptions

Our C++ API may throw `se::common::BaseException` subclasses when user passes invalid input, makes bad state calls or if something else goes wrong. Most exceptions contain useful human-readable information. Please read `e.what()` message if exception is thrown. Note that `se::common::BaseException` is **not** a subclass of `std::exception`, an Smart Document Engine interface in general do not have any dependency on the STL.

The thrown exceptions are wrapped in general `java.lang.Exception`, so in Java API do catch those.

#### Factory methods and memory ownership

Several Smart Document Engine SDK classes have factory methods which return pointers to heap-allocated objects.  **Caller is responsible for deleting** such objects _(a caller is probably the one who is reading this right now)_.
We recommend using `std::unique_ptr<T>` for simple memory management and avoiding memory leaks.

In Java API for the objects which are no longer needed it is recommended to use `.delete()` method to force the deallocation of the native heap memory.

## Multipage document recognition

Smart Document Engine supports multipage document recognition out-of-box. Run recognition of all the pages of the document in **one** session, sequentially calling `ProcessImage` on them. 

Each image should contain one page of the document and pages should be sorted in reading order (page 1, page 2, etc.) Smart Document Engine will create **one** instance of `Document` for a multipage document to aggregate the recognized fields from all the pages.

Also note that if a page of arbitrary-filled document (or a document not supported by running session) will come, it will be classified as a page of the current multipage document and all the text it contains will be recognized.

## Configuration bundles

Every delivery contains one or several _configuration bundles_ – archives containing everything needed for Smart Document Engine to be created and configured. Usually they are named as `bundle_something.se` and located inside `data-zip` folder.

## Specifying document types for DocSession

Assuming you already created the engine and session settings like this:

```cpp
// C++
// create recognition engine with configuration bundle path
std::unique_ptr<se::doc::DocEngine> engine(
    se::doc::DocEngine::Create(configuration_bundle_path));

// create session settings with se::doc::DocEngine factory method
std::unique_ptr<se::doc::DocSessionSettings> settings(
    engine->CreateSessionSettings());
```

```java
// Java
// create recognition engine with configuration bundle path
DocEngine engine = DocEngine.Create(configuration_bundle_path);

// create session settings with DocEngine factory method
DocSessionSettings settings = engine.CreateSessionSettings();
```

In order to call `engine->SpawnSession(...)` you need to specify enabled document types for session to be spawned using `DocSessionSettings` methods. **By default, all document types are disabled.**

#### Supported document types

A _document type_ is simply a string encoding real world document type you want to recognize. Document types that Smart Document Engine SDK delivered to you can potentially recognize can be obtaining using the following procedure:

```cpp
// C++ 
// Iterating though internal engines
for (int i_engine = 0;
     i_engine < settings->GetInternalEnginesCount();
     ++i_engine) {
    // Iterating though supported document types for this internal engine
    for (int i_doc = 0;
         i_doc < settings->GetSupportedDocumentTypesCount(i_engine);
         ++i_doc) {
        // Getting supported document type name
        std::string doctype = settings->GetSupportedDocumentType(i_engine, i_doc);
    }
}
```

```java
// Java
// Iterating though internal engines
for (int i_engine = 0;
     i_engine < settings.GetInternalEnginesCount();
     i_engine++) {
    // Iterating though supported document types for this internal engine
    for (int i_doc = 0;
         i_doc < settings.GetSupportedDocumentTypesCount(i_engine);
         i_doc++) {
        // Getting supported document type name
        String doctype = settings.GetSupportedDocumentType(i_engine, i_doc);
    }
}
```

**In a single session you can only enable document types that belong to the same internal engine**.

#### Enabling document types using wildcard expressions

Since all documents in settings are disabled by default you need to enable some of them.
In order to do so you may use `AddEnabledDocumentTypes(...)` method of `DocSessionSettings`:

```cpp
// C++
settings->AddEnabledDocumentTypes("rus.2ndfl.type1"); // Enables Russian 2-NDFL document
```

```java
// Java
settings.AddEnabledDocumentTypes("rus.2ndfl.type1"); // Enables Russian 2-NDFL document
```

You may also use `RemoveEnabledDocumentTypes(...)` method to remove already enabled document types.

For convenience it's possible to use **wildcards** (using asterisk symbol) while enabling or disabling document types. When using document types related methods, each passed document type is matched against all supported document types. All matches in supported document types are added to the enabled document types list. 

```cpp
// C++
settings->AddEnabledDocumentTypes("deu.*"); // Enables all supported documents of Germany
```

```java
// Java
settings.AddEnabledDocumentTypes("deu.*"); // Enables all supported documents of Germany
```

As it was mentioned earlier, you can only enable document types that belong to the same internal engine for a single session. If you do otherwise then an exception will be thrown during session spawning.

It's always better to enable the minimum number of document types as possible if you know exactly what are you going to recognize because the system will spend less time deciding which document type out of all enabled ones has been presented to it.

#### Session modes

Based on the list of supported document types in the configuration bundle, and on the document masks provided by the caller, the engine is determining which internal engine to use in the created session. However, what if there have to be multiple engines which support a certain document type? For example, a Russian 2-NDFL document (`rus.2ndfl.type1`) can be recognized both in the internal engine for recognition of all accounting documents, and in the internal engine for recognition of all Russian documents. To sort this out there is a concept of session modes.

To get the list of available session modes in the provided configuration bundle, you can use the corresponding method of the `DocSessionSettings`:

```cpp
// C++
for (auto it = settings->SupportedModesBegin();
     it != settings->SupportedModesEnd();
     ++it) {
    // it.GetValue() is a name of a supported mode
}
```

```java
// Java
for (StringsSetIterator it = settings.SupportedModesBegin();
     !it.Equals(settings.SupportedModesEnd());
     it.Advance()) {
    // it.GetValue() is a name of a supported mode
}
```

There is always a mode called `default` and it is enabled, well, by default. There are methods for getting the currently enabled mode and to set a new one:

```cpp
// C++
std::string current_mode = settings->GetCurrentMode();

settings->SetCurrentMode("primary_accounting"); // Setting a current mode to primary accounting 
settings->AddEnabledDocumentTypes("*");  // Setting a document type mask _within a mode_
```

```java
// Java
String current_mode = settings.GetCurrentMode();

settings.SetCurrentMode("primary_accounting"); // Setting a current mode to primary accounting
settings.AddEnabledDocumentTypes("*"); // Setting a document type mask _within a mode_
```

Within any given configuration bundle there is a strict invariant: there cannot be internal engines which belong to the same mode and for which the subsets of supported documents types intersect.

## Session options

Some configuration bundle options can be overriden in runtime using `DocSessionSettings` methods. You can obtain all currently set option names and their values using the following procedure:


```cpp
// C++
for (auto it = settings->OptionsBegin();
     it != settings->OptionsEnd();
     ++it) {
    // it.GetKey() returns the option name
    // it.GetValue() returns the option value
}
```

```java
// Java
for (StringsMapIterator it = settings.OptionsBegin();
     !it.Equals(settings.OptionsEnd());
     it.Advance()) {
    // it.GetKey() returns the option name
    // it.GetValue() returns the option value
}
```

You can change option values using the `SetOption(...)` method:

```cpp
// C++
settings->SetOption("enableMultiThreading", "true");
```

```java
// Java
settings.SetOption("enableMultiThreading", "true");
```

Option values are always represented as strings, so if you want to pass an integer or boolean it should be converted to string first.

#### Common options

|                                   Option name |                           Value type |                                             Default | Description                                                                                                                                                                            |
|----------------------------------------------:|-------------------------------------:|----------------------------------------------------:|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `enableMultiThreading`                        | `"true"` or `"false"`                | true                                                | Enables parallel execution of internal algorithms                                                                                                                                      |
| `rgbPixelFormat`                              | String of characters R, G, B, and A  | RGB for 3-channel images, BGRA for 4-channel images | Sequence of color channels for session.Process() method image interpretation                                                                                                   |

## Java API Specifics

Smart Document Engine SDK has Java API which is automatically generated from C++ interface by SWIG tool.

Java interface is the same as C++ except minor differences, please see the provided Java sample.

There are several drawbacks related to Java memory management that you need to consider.

#### Object deallocation

Even though garbage collection is present and works, it's strongly advised to manually call `obj.delete()` functions for our API objects because they are wrappers to the heap-allocated memory and their heap size is unknown to the garbage collector.

```java
DocEngine engine = DocEngine.Create(config_path); // or any other object

// ...

engine.delete(); // forces and immediately guarantees wrapped C++ object deallocation
```

This is important because from garbage collector's point of view these objects occupy several bytes of Java memory while their actual heap-allocated size may be up to several dozens of megabytes. GC doesn't know that and decides to keep them in memory – several bytes won't hurt, right?

You don't want such objects to remain in your memory when they are no longer needed so call `obj.delete()` manually.

# FAQ

1.  ### How can I test the system? 

You can install demo apps from Apple Store and Google Play from the links below:

    Google Play: https://play.google.com/store/apps/details?id=com.smartengines.se&showAllReviews=true

    Apple Store: https://apps.apple.com/us/app/smart-engines/id1593408182


2. ### How can I install and test your library? 

We provide the classic SDK as a library and its integration samples, you need to install one of the examples (you can find it in the /samples folder)

3. ### How can I update to the new version?

You need to replace the libraries from /bin, bindings (from /bindings respectively) and configuration bundle (*.se file from /data-zip) You can find it in the provided SDK.

4. ### How can I find out what documents and engines are available to me? 

Inside our library all documents are sorted by engines, and engines sorted by modes, you can find the list of available modes, engines and documents using methods from DocSessionSettings. (see provided samples from /samples)

5. ### I have the SDK version for Windows, but our production system will use any OS from Linux family. How do I run in a Linux-based docker container? 

Our SDK are platform-dependent, so please contact us at sales@smartengines.com or support@smartengines.com and we will provide you with the required SDK.

6. ### I have SDK for Centos 7, I try to run it on Ubuntu/Debian/Alpine. I have a lot of "undefined symbol" errors. 

Please don't run SDK for operating systems not intended for it and contact us at sales@smartengines.com or support@smartengines.com to provide you with the required SDK.

# Oops! Something went wrong. 

## Common Errors:

1. `Failed to verify static auth`: please look at the [1st paragraph of `Readme`](#warning-personalized-signature-warning)

2. `Found no single engine that supports settings-enabled document types`: our recognition engine contains a whole set of tools aimed at recognizing specific groups of documents. 
In order for the library to be able to select the right tool you need to set the document mask. 
To set the document mask please use `AddEnabledDocumentTypes` (document_types) in the session settings. Usually all documents are grouped by country name, so you can use the country name (country code according to ISO 3166-1 alpha-3). 
There are also tools that has all passports (or all driver's license or ID's of different countries): in this case in order to determine the right tool you have to use the `settings.SetCurrentMode` (mode_name) mod.

3. `Failed to initialize DocEngine: mismatching engine version in config`: .se format configuration bundles contain the number of the version with which they work so most likely you just did not replace bundles. Make sure that the bundle and the library are taken from the same SDK, if this does not help please contact the support.

4. `libdocengine.so:cannot open shared object file:no such file or directory`: 
integration for wrappers has in two stages: there is a main library with all the functionality and there is a lightweight wrapper that translates calls from the module to our library. This error occurs when the wrapper library cannot find the main library. You can fix this by setting the `LD_LIBRARY_PATH=</path/to/libdocengine.so>` IMPORTANT! This environment variable must be set before running your program (you cannot set the path to the library when the program is already running by HP or JVM)

- for PYTHON
`libpython3.x.x:cannot open shared object file: No such file or directory`: the module you are using is built for a different version of python, /samples/docengine_sample_*/ contains a script for building the module on your side. Don't forget that you must have the dev packages installed for your language.