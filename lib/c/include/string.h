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

#ifndef _LCS_PURE
# define _LCS_PURE __attribute__((pure))
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ==== RAW MEMORY FUNCTIONS ==== */

// Finds the first occurrance of `__c` in `__mem`, searching `__len` bytes.
// Returns a pointer to the first occurrance, or NULL if not found.
void  *memchr    (const void *__mem, int __c, size_t __len) _LCS_PURE;
// Finds the last occurrance of `__c` in `__mem`, searching `__len` bytes.
// Returns a pointer to the last occurrance, or NULL if not found.
void  *memrchr   (const void *__mem, int __c, size_t __len) _LCS_PURE;
// Compare byte arrays `__a` and `__b`, searching `__len` bytes.
// Returns difference <0 or >0 for first different byte, or 0 if `__a` and `__b` are equal.
int    memcmp    (const void *__a, const void *__b, size_t __len) _LCS_PURE;
// Copies data from `__src` to `__dst`, copying at most `__len` bytes, stopping when a byte equal to `__c` has been copied.
// Does not gaurantee correct behaviour for overlapping `__src` and `__dst`.
// Returns a pointer to `__dst` pas the end of the copied `__c` or NULL if `__c` was not found.
void  *memccpy   (void *_LCS_REST __dst, const void *_LCS_REST __src, int __c, size_t __len) _LCS_PURE;
// Copies data from `__src` to `__dst`, copying `__len` bytes.
// Does not gaurantee correct behaviour for overlapping `__src` and `__dst`.
// Returns a pointer to `__dst`.
void  *memcpy    (void *_LCS_REST __dst, const void *_LCS_REST __src, size_t __len) _LCS_PURE;
// Copies data from `__src` to `__dst`, copying `__len` bytes.
// Gaurantees correct copying behaviour for overlapping `__src` and `__dst`.
// Returns a pointer to `__dst`.
void  *memmove   (void *__dst, const void *__src, size_t __len) _LCS_PURE;
// Sets `__len` bytes of `__dst` to `__c`.
// Returns a pointer to `__dst`.
void  *memset    (void *__dst, int __c, size_t __len) _LCS_PURE;



/* ==== STRING FUNCTIONS ==== */

// Find the first occurrance of `__c` in the c-string `__mem`.
// Returns a pointer to the first occurrance, or NULL if not found.
char  *strchr    (const char *__mem, int __c) _LCS_PURE;
// Find the last occurrance of `__c` in the c-string `__mem`.
// Returns a pointer to the last occurrance, or NULL if not found.
char  *strrchr   (const char *__mem, int __c) _LCS_PURE;
// Compare c-strings `__a` and `__b`.
// Returns difference <0 or >0 for first different byte, or 0 if `__a` and `__b` are equal.
int    strcmp    (const char *__a, const char *__b) _LCS_PURE;
// Compare c-strings `__a` and `__b`, searching at most `__len` bytes.
// Returns difference <0 or >0 for first different byte, or 0 if `__a` and `__b` are equal.
int    strncmp   (const char *__a, const char *__b, size_t __len) _LCS_PURE;
// Concatenate the c-string `__src` onto the c-string `__dst`.
// Returns a pointer to `__dst`.
char  *strcat    (char *__dst, const char *__src) _LCS_PURE;
// Concatenate at most `__len` bytes of the c-string `__src` onto the c-string `__dst`.
// This means that if `__len <= strlen (__src)`, `__dst` will have no NULL terminator.
// Returns a pointer to `__dst`.
char  *strncat   (char *__dst, const char *__src, size_t __len) _LCS_PURE;
// Copy the c-string `__src` over the c-string `__dst`.
// Returns a pointer to `__dst`.
char  *strcpy    (char *__dst, const char *__src) _LCS_PURE;
// Copy the c-string `__src` over the c-string `__dst` such that exactly `__len` bytes are written.
// This means that if `__len <= strlen (__src)`, `__dst` will have no NULL terminator.
// Returns a pointer to `__dst`.
char  *strncpy   (char *__dst, const char *__src, size_t __len) _LCS_PURE;
// Determines the number of initial bytes of the c-string `__mem` that consist only of bytes in the c-string `__accept`.
size_t strspn    (const char *__mem, const char *__accept) _LCS_PURE;
// Determines the number of initial bytes of the c-string `__mem` that consist only of bytes not in the c-string `__reject`.
size_t strcspn   (const char *__mem, const char *__reject) _LCS_PURE;
// Finds the first occurrance of the c-string `__substr` in the c-string `__mem`.
// Returns a pointer to the substring if found, NULL if not found.
char  *strstr    (const char *__mem, const char *__substr) _LCS_PURE;
// Finds the first occurrance of the c-string `__substr` (case-insensitive) in the c-string `__mem`.
// Returns a pointer to the substring if found, NULL if not found.
char  *strcasestr(const char *__mem, const char *__substr) _LCS_PURE;
// Determines the length of the c-string `__mem`.
// Returns the index of the byte 0 in the c-string `__mem`.
size_t strlen    (const char *__mem) _LCS_PURE;
// Determines the length of the c-string `__mem`, searching `__len` bytes.
// Returns the index of the byte 0 in the c-string `__mem`, or `__len` if there was no 0 byte.
size_t strnlen   (const char *__mem, size_t __len) _LCS_PURE;
// Allocates memory and duplicates the c-string `__mem`.
char *strdup     (const char *__mem) _LCS_PURE;
// Allocates memory and duplicates the c-string `__mem`.
// Copies at most `__len` characters from the input before adding a NULL terminator.
char *strndup    (const char *__mem, size_t __len) _LCS_PURE;



/* ==== GETTER FUNCTIONS ==== */

// Returns the name of an error code `__code` as in `errno`.
// This string may change on subsequent calls to `strerror`.
// This string must not be changed by the application (despite being non-const).
char  *strerror  (int __code) _LCS_PURE;

#ifdef __cplusplus
} // extern "C"
#endif
