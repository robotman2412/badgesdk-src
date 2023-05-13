cmake_minimum_required(VERSION 3.10)

# Create output file and add sources.
add_library(float SHARED
	src/float.c
)

# Export files.
export_lib_stub(float libfloat.so)
