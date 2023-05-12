cmake_minimum_required(VERSION 3.10)

# Create output file and add sources.
add_library(badgert STATIC
	src/list_malloc.c
	src/malloc.c
	src/start.c
)
target_link_libraries(badgert c badge)

# Add ABI files into include path.
target_include_directories(badgert PUBLIC
	${CMAKE_CURRENT_LIST_DIR}/include
)

# Compiler options.
target_compile_options(badgert BEFORE PRIVATE
	-fdata-sections -ffunction-sections
)

# Export files.
export_lib(badgert libbadgert.a)
export_include(badgert include .)
