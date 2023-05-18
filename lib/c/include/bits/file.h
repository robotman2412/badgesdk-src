/*
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
*/

#pragma once

#include "stddef.h"

#ifndef _LCS_REST
# ifdef __cplusplus
#  define _LCS_REST
# else
#  define _LCS_REST restrict
# endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

// __FILE flag: Read allowed.
#define __FILE_FLAG_READ	0x00000001
// __FILE flag: Write allowed.
#define __FILE_FLAG_WRITE	0x00000002
// __FILE flag: Has file descriptor number.
#define __FILE_FLAG_FILENO	0x00000004
// __FILE flag: EOF indicator.
#define __FILE_FLAG_EOF		0x00000008
// __FILE flag: Error indicator.
#define __FILE_FLAG_ERROR	0x00000010
// __FILE flag: Do line ending conversion.
#define __FILE_FLAG_LFCONV	0x00000020

struct __FILE;
typedef struct __FILE FILE;

// __FILE read function.
typedef int (*__FILE_read_t )(FILE *_LCS_REST __fd, void *_LCS_REST __mem, size_t __nmemb, void *_LCS_REST __cookie);
// __FILE write function.
typedef int (*__FILE_write_t)(FILE *_LCS_REST __fd, const void *_LCS_REST __mem, size_t __nmemb, void *_LCS_REST __cookie);
// __FILE seek function.
typedef long(*__FILE_seek_t )(FILE *_LCS_REST __fd, long __off, int __whence, void *_LCS_REST __cookie);
// __FILE close function.
typedef int (*__FILE_close_t)(FILE *_LCS_REST __fd, void *_LCS_REST __cookie);
// __FILE flush function.
typedef int (*__FILE_flush_t)(FILE *_LCS_REST __fd, void *_LCS_REST __cookie);

struct __FILE {
	// Cookie for accessor functions.
	void *__cookie;
	// Read callback.
	__FILE_read_t  __read;
	// Write callback.
	__FILE_write_t __write;
	// Seek / tell callback.
	__FILE_seek_t  __seek;
	// Close callback.
	__FILE_close_t __close;
	// Flush callback.
	__FILE_flush_t __flush;
	
	// Size of ungetc buffer (0-4).
	int  __ungetlen;
	// Ungetc buffer.
	char __unget[4];
	
	// File descriptor number.
	int  __fileno;
	// Flags bitfield.
	int  __flags;
};

#ifdef __cplusplus
} // extern "C"
#endif
