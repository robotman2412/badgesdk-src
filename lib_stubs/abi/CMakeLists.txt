cmake_minimum_required(VERSION 3.10)

# Create output file and add sources.
add_library(abi SHARED
	src/mem.c
	src/fd.c
)
target_include_directories(abi PUBLIC include)

# Export files.
export_lib_stub(abi libabi.so)
export_include(abi include .)
