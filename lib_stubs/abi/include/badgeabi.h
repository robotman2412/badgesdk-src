/*
	MIT License

	Copyright (c) 2023 Julian Scheffers

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
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
*/

#pragma once

// SIZE TYPE YEAH LETS GOOOO.
typedef unsigned long __abi_size_t;


// System call used by libc's `fopen()`.
int __open(int *__errno_out, const char *__path, int __flags);
// System call used by libc's `fclose()`.
int __close(int *__errno_out, int __fd);
// System call used by libc's `fseek()` and `ftell()`.
int __seek(int *__errno_out, int __fd, long __off, int __whence);
// System call used by libc's `fflush()`.
int __flush(int *__errno_out, int __fd);

// Request a new range of memory.
void *__mem_map(__abi_size_t size, __abi_size_t min_align, _Bool allow_exec);
// Discard a range of memory.
void __mem_unmap(void *addr);

// Exit the current process.
int __exit(int __ec) __attribute__((noreturn));
