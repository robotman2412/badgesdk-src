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


# Provide default paths.
set(BADGESDK_INCLUDE_PATH ${CMAKE_CURRENT_LIST_DIR}/include)
set(BADGESDK_LIB_PATH ${CMAKE_CURRENT_LIST_DIR}/lib ${CMAKE_CURRENT_LIST_DIR}/lib_stubs)

# Default linker script.
set(BADGESDK_LINKER_SCRIPT ${CMAKE_CURRENT_LIST_DIR}/link/default.ld)
# System libraries in link order.
set(BADGESDK_SYSTEM_LIBRARIES
	${CMAKE_CURRENT_LIST_DIR}/lib/libbadgert.a
	${CMAKE_CURRENT_LIST_DIR}/lib_stubs/libbadge.so
	${CMAKE_CURRENT_LIST_DIR}/lib_stubs/libc.so
)
# Include path passed to compiler.
set(BADGESDK_INCLUDE_OPTION)
foreach(path ${BADGESDK_INCLUDE_PATH})
	set(BADGESDK_INCLUDE_OPTION ${BADGESDK_INCLUDE_OPTION} -I${path})
endforeach()


# Have `compile_commands.json` generated for IDE users.
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

# Set the C and C++ compilers to use.
set(CMAKE_C_COMPILER "riscv64-linux-gnu-gcc")
set(CMAKE_CXX_COMPILER "riscv64-linux-gnu-g++")
# These don't pass built-in cmake test, so disable said test.
set(CMAKE_C_COMPILER_FORCED true)
set(CMAKE_CXX_COMPILER_FORCED true)


# Sets options for apps.
function(badgesdk_define_app target)
	# Set compile flags for apps.
	target_compile_options(${target} BEFORE PRIVATE
		-march=rv32imac -mabi=ilp32
		-nostdinc
		-ffreestanding -fno-exceptions
		-fPIE
		-fdata-sections -ffunction-sections
		${BADGESDK_INCLUDE_OPTION}
	)
	# Set linker flags for apps.
	target_link_options(${target} BEFORE PRIVATE
		-march=rv32imac -mabi=ilp32
		-nostdlib -nodefaultlibs
		-fPIE
		-Wl,--gc-sections
		-T${BADGESDK_LINKER_SCRIPT}
	)
	# Link system libraries.
	target_link_libraries(${target} PUBLIC
		${BADGESDK_SYSTEM_LIBRARIES}
	)
endfunction()

# Sets options for dynamic libraries.
function(badgesdk_define_shared_lib target)
	# Set compile flags for apps.
	target_compile_options(${target} BEFORE PRIVATE
		-march=rv32imac -mabi=ilp32
		-nostdinc
		-ffreestanding -fno-exceptions
		-fPIE
		${BADGESDK_INCLUDE_OPTION}
	)
	# Set linker flags for apps.
	target_link_options(${target} BEFORE PRIVATE
		-march=rv32imac -mabi=ilp32
		-nostdlib -nodefaultlibs
		-fPIE
	)
	# Link system libraries.
	target_link_libraries(${target} PUBLIC
		${BADGESDK_SYSTEM_LIBRARIES}
	)
endfunction()

# Sets options for static libraries.
function(badgesdk_define_static_lib target)
	# Set compile flags for apps.
	target_compile_options(${target} BEFORE PRIVATE
		-march=rv32imac -mabi=ilp32
		-nostdinc
		-ffreestanding -fno-exceptions
		-fPIE
		-fdata-sections -ffunction-sections
		${BADGESDK_INCLUDE_OPTION}
	)
	# Link system libraries.
	target_link_libraries(${target} PUBLIC
		${BADGESDK_SYSTEM_LIBRARIES}
	)
endfunction()
