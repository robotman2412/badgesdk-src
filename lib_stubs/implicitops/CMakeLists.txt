cmake_minimum_required(VERSION 3.10)

# Create output file and add sources.
add_library(implicitops SHARED
	src/float.c
	src/int.c
)

# Export files.
export_lib_stub(implicitops libimplicitops.so)
