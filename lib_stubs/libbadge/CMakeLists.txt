cmake_minimum_required(VERSION 3.10)

# Create output file and add sources.
add_library(badge SHARED
	src/gpio.c
	src/system.c
)
target_link_libraries(badge c)

# Add ABI files into include path.
target_include_directories(badge PUBLIC
	${CMAKE_CURRENT_LIST_DIR}/include
)

# Export files.
export_lib_stub(badge libbadge.so)
export_include(badge include .)
