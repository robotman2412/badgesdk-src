cmake_minimum_required(VERSION 3.10)

# Create output file and add sources.
add_library(c STATIC
	src/bits/list_malloc.c
	src/malloc.c
	src/stdio.c
	src/string.c
)
target_link_libraries(c abi)

# Add ABI files into include path.
target_include_directories(c PUBLIC
	${CMAKE_CURRENT_LIST_DIR}/include
)

# Compiler options.
target_compile_options(c BEFORE PRIVATE
	-fdata-sections -ffunction-sections
)

# Export files.
# export_lib(c libc.a)
# export_include(c include .)
