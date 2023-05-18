#[[
	MIT License

	Copyright    (c) 2023 Julian Scheffers

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files    (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
]]

cmake_minimum_required(VERSION 3.10)

# Compile in release mode by default.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Define project.
set(CMAKE_EXPORT_COMPILE_COMMANDS true)
project(badgesdk)
message(STATUS "Build path: " $ENV{BUILD_PATH})



# Add a library to `lib`.
function(export_lib lib_name lib_file)
	set(out_path $ENV{BUILD_PATH}/gen_lib/${lib_file})
	message(STATUS "Exporting " ${lib_name} " to " ${out_path})
	
	add_custom_command(TARGET ${lib_name} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${lib_name}> ${out_path}
	)
endfunction()

# Add a library to `lib_stubs`.
function(export_lib_stub lib_name lib_file)
	set(out_path $ENV{BUILD_PATH}/gen_lib_stubs/${lib_file})
	message(STATUS "Exporting " ${lib_name} " to " ${out_path})
	
	add_custom_command(TARGET ${lib_name} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${lib_name}> ${out_path}
	)
endfunction()

# Add include directory to `include`.
function(export_include target include_path out_name)
	set(in_path ${CMAKE_CURRENT_LIST_DIR}/${include_path})
	set(out_path $ENV{BUILD_PATH}/gen_include/${out_name})
	message(STATUS "Exporting " ${in_path} " to " ${out_path})
	
	make_directory(${out_path})
	add_custom_command(TARGET ${target} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy ${in_path}/* ${out_path}
	)
endfunction()



# Set the C and C++ compilers to use.
set(CMAKE_C_COMPILER "riscv64-linux-gnu-gcc")
set(CMAKE_CXX_COMPILER "riscv64-linux-gnu-g++")
# These don't pass built-in cmake test, so disable said test.
set(CMAKE_C_COMPILER_FORCED true)
set(CMAKE_CXX_COMPILER_FORCED true)

# Compiler options: PIC, exceptions disabled, no system libraries.
add_compile_options(
	-march=rv32imac -mabi=ilp32
	-nostdinc
	-ffreestanding -fPIC
)
# Linker options: PIC, o system libraries
add_link_options(
	-march=rv32imac -mabi=ilp32
	-nostdlib -nodefaultlibs
	-fPIC
)



# Add libraries.
add_subdirectory(lib/badgert)
add_subdirectory(lib/c)
add_subdirectory(lib/display)

add_subdirectory(lib_stubs/abi)
add_subdirectory(lib_stubs/badge)
add_subdirectory(lib_stubs/cstub)
add_subdirectory(lib_stubs/implicitops)
add_subdirectory(lib_stubs/m)
