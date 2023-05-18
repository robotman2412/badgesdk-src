cmake_minimum_required(VERSION 3.10)

# Create output file and add sources.
add_library(cstub SHARED
	src/string.c
	src/malloc.c
	src/stdlib.c
	src/stdio.c
)

# Add ABI files into include path.
target_include_directories(cstub PUBLIC
	${CMAKE_CURRENT_LIST_DIR}/include
)

# Export files.
export_lib_stub(cstub libcstub.so)
export_include(cstub include .)
export_include(cstub include/cstubbits cstubbits)
