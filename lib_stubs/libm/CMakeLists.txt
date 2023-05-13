cmake_minimum_required(VERSION 3.10)

# Create output file and add sources.
add_library(m SHARED
	src/math.c
)
target_link_libraries(m c)

# Add ABI files into include path.
target_include_directories(m PUBLIC
	${CMAKE_CURRENT_LIST_DIR}/include
)

# Export files.
export_lib_stub(m libm.so)
export_include(m include .)
