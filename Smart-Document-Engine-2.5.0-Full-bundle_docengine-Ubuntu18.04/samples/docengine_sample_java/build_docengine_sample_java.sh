#  Copyright (c) 2016-2024, Smart Engines Service LLC
#  All rights reserved.

javac DocEngineSample.java -cp ../../bindings/java/jnidocenginejar.jar

# How to run
# LD_LIBRARY_PATH=../../bin LC_ALL=en_US.utf-8 java -Djava.library.path=../../bin -cp ../../bindings/java/jnidocenginejar.jar:. DocEngineSample <image> <bundle_path> <document_types>