@REM Copyright (c) 2016-2025, Smart Engines Service LLC
@REM All rights reserved.

javac DocEngineSample.java -cp .;..\..\bindings\java\jnidocenginejar.jar

@REM  How to run
@REM  java -Djava.library.path=..\..\bin -cp .;..\..\bindings\java\jnidocenginejar.jar DocEngineSample <image_path> <bundle_path> <document_type>