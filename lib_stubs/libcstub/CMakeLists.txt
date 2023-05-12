cmake_minimum_required(VERSION 3.10)

# Create output file and add sources.
add_library(c SHARED
	src/string.c
	src/malloc.c
	src/stdlib.c
	src/stdio.c
)

# Add ABI files into include path.
target_include_directories(c PUBLIC
	${CMAKE_CURRENT_LIST_DIR}/include
)

# Export files.
export_lib_stub(c libc.so)
export_include(c include .)
export_include(c include/cstubbits cstubbits)
