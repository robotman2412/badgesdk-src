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

#ifdef __cplusplus
extern "C" int __errno;
#define errno __errno
#elif !defined(__ASSEMBLER__)
extern int __errno;
#define errno __errno
#endif

// Operation not permitted
#define	EPERM	1	
// No such file or directory
#define	ENOENT	2	
// No such process
#define	ESRCH	3	
// Interrupted system call
#define	EINTR	4	
// Input/output error
#define	EIO		5	
// No such device or address
#define	ENXIO	6	
// Argument list too long
#define	E2BIG	7	
// Exec format error
#define	ENOEXEC	8	
// Bad file number
#define	EBADF	9	
// No child processes
#define	ECHILD	10	
// Try again
#define	EAGAIN	11	
// Out of memory
#define	ENOMEM	12	
// Permission denied
#define	EACCES	13	
// Bad address
#define	EFAULT	14	
// Block device required
#define	ENOTBLK	15	
// Device or resource busy
#define	EBUSY	16	
// File exists
#define	EEXIST	17	
// Cross-device link
#define	EXDEV	18	
// No such device
#define	ENODEV	19	
// Not a directory
#define	ENOTDIR	20	
// Is a directory
#define	EISDIR	21	
// Invalid argument
#define	EINVAL	22	
// File table overflow
#define	ENFILE	23	
// Too many open files
#define	EMFILE	24	
// Not a typewriter
#define	ENOTTY	25	
// Text file busy
#define	ETXTBSY	26	
// File too large
#define	EFBIG	27	
// No space left on device
#define	ENOSPC	28	
// Illegal seek
#define	ESPIPE	29	
// Read-only file system
#define	EROFS	30	
// Too many links
#define	EMLINK	31	
// Broken pipe
#define	EPIPE	32	
// Argument out of math function domain
#define	EDOM	33	
// Math result out of range
#define	ERANGE	34	

