#  Copyright (c) 2016-2024, Smart Engines Service LLC
#  All rights reserved.

# You can use this autobuild system instead of prebuilt .py and .so if any troubles occured
#
# DESCRIPTION: 
#   This script is designed to locally build Python integration module for docengine library.
# 
# MOTIVATION:
#   Version of the Python module development libraries has to exactly correspond to the version
#   of the Python runtime libraries. Thus if the Python modules built on external SDK build machines
#   is different from the version used on client's machine, the Python integration module will not
#   be operational. The local build will guarantee that the Python versions match.
#
# REQUIREMENTS:
#   cmake - version 3.0 or higher. Required for building the Python module.
#   gcc/g++ - version 4.8 or higher. These are required for running Smart Document Engine native
#      libraries anyway, and for building the wrapping Python module. 
#      If you are running CentOS 6, the compilers can be installed using devtoolset-2 
#      (see https://gist.github.com/giwa/b1fb1e44dc0a7d270881).
#      Don't forget to switch environments using 'scl enable devtoolset-2 bash'.
#      python-dev: module-development libraries should be available
#
# HOWTO:
#   1. Run this script from its local directory with two parameters - the path to the directory
#      containing libidengine.so installed in your system ("../../bin" if you simply are using 
#      the unpacked SDK) and your Python version (2 or 3 or exact 3.x) 
#      Keep in mind that the built Python module will link to the absolute path
#      to the libidengine.so library.
#   2. When this script is finished, the compiled module will be placed in ../../bin 
#      directory, and the python bindings will be placed in ../../bindings/python directory. 
#   3. Check the sample: $ python docengine_sample.py
#
# OVERVIEW:
#   - First, the script unpacks, configures the sources with a local install prefix, 
#     builds and installs SWIG (not in the system, simply in the local folder).
#     SWIG sources (exact version v4.1.1 is required) is placed here, it also can
#     be downloaded from https://downloads.sourceforge.net/project/swig/swig/swig-4.1.1/swig-4.1.1.tar.gz
#   - Next, a module build directory is created and the module is built according
#     to the CMake script provided. Local SWIG build will be used to generate the 
#     wrapper, and $1-st argument of this script will be used to find the 
#     libidengine.so library to link with.
