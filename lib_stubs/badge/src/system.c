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

#include "system.h"

// Exit thingy.
void _exit(int ec) __attribute__((weak)) __attribute__((noreturn));
void _exit(int ec) { while(1); }
// Yield to the scheduler.
void yield() __attribute__((weak));
void yield() {}
// Delay for a period of milliseconds.
void delay_ms(int64_t millis) __attribute__((weak));
void delay_ms(int64_t millis) {}
// Delay for a period of microseconds.
void delay_us(int64_t millis) __attribute__((weak));
void delay_us(int64_t millis) {}
// Get the number of milliseconds since system startup.
int64_t uptime_ms() __attribute__((weak));
int64_t uptime_ms() { return 0; }
// Get the number of microseconds since system startup.
int64_t uptime_us() __attribute__((weak));
int64_t uptime_us() { return 0; }
// Request a new range of memory.
void *__mem_map(size_t size, size_t min_align, bool allow_exec) __attribute__((weak));
void *__mem_map(size_t size, size_t min_align, bool allow_exec) { return (void*) 0; }
// Discard a range of memory.
void __mem_unmap(void *addr) __attribute__((weak));
void __mem_unmap(void *addr) {}
