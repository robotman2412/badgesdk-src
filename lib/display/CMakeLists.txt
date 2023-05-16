cmake_minimum_required(VERSION 3.10)

# Create output file and add sources.
add_library(display SHARED
	src/display.c
)
target_link_libraries(display c badge)

# Add ABI files into include path.
target_include_directories(display PUBLIC
	${CMAKE_CURRENT_LIST_DIR}/include
)

# Compiler options.
target_compile_options(display BEFORE PRIVATE
	-fdata-sections -ffunction-sections
)

# Export files.
export_lib(display libdisplay.so)
export_include(display include .)
