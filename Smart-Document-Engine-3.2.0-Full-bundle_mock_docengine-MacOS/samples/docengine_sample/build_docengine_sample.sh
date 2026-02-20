#  Copyright (c) 2016-2025, Smart Engines Service LLC
#  All rights reserved.

g++ docengine_sample.cpp -O2 -std=c++11 -I ../../include -L ../../bin -l docengine -o docengine_sample

# How to run
# DYLD_LIBRARY_PATH=../../bin ./docengine_sample <image> <bundle_path> <document_types>
