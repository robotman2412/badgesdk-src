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

#include <string.h>
#include <malloc.h>



char __charcaseequal(char a, char b) {
	char _a = a & 0xdf;
	if (_a >= 'A' && _a <= 'Z') {
		return _a == (b & 0xdf);
	} else {
		return a == b;
	}
}



// Finds the first occurrance of `__c` in `__mem`, searching `__len` bytes.
// Returns a pointer to the first occurrance, or NULL if not found.
void *memchr(const void *__mem, int __c, size_t __len) {
	for (const char *ptr = __mem; ptr != __mem+__len; ++ptr) {
		if (*ptr == __c) return (void *) ptr;
	}
	return NULL;
}

// Finds the last occurrance of `__c` in `__mem`, searching `__len` bytes.
// Returns a pointer to the last occurrance, or NULL if not found.
void *memrchr(const void *__mem, int __c, size_t __len) {
	for (const char *ptr = __mem+__len-1; ptr != __mem; --ptr) {
		if (*ptr == __c) return (void *) ptr;
	}
	return NULL;
}

// Compare byte arrays `__a` and `__b`, searching `__len` bytes.
// Returns difference <0 or >0 for first different byte, or 0 if `__a` and `__b` are equal.
int memcmp(const void *__a, const void *__b, size_t __len) {
	const char *a = __a, *b = __b;
	for (size_t i = 0; i < __len; i++) {
		int d = a[i] - b[i];
		if (d) return d;
	}
	return 0;
}

// Compare byte arrays `__a` and `__b` case-insensitive, searching `__len` bytes.
// Returns difference <0 or >0 for first different byte, or 0 if `__a` and `__b` are equal.
int memcasecmp(const void *__a, const void *__b, size_t __len) {
	const char *a = __a, *b = __b;
	for (size_t i = 0; i < __len; i++) {
		if (!__charcaseequal(a[i], b[i])) return a[i] - b[i];
	}
	return 0;
}

// Copies data from `__src` to `__dst`, copying at most `__len` bytes, stopping when a byte equal to `__c` has been copied.
// Does not gaurantee correct behaviour for overlapping `__src` and `__dst`.
// Returns a pointer to `__dst` past the end of the copied `__c` or NULL if `__c` was not found.
void *memccpy(void *_LCS_REST __dst, const void *_LCS_REST __src, int __c, size_t __len) {
	char *dst = __dst;
	const char *src = __src;
	__c = (int) (char) __c;
	for (size_t i = 0; i < __len; i++) {
		if ((dst[i] = src[i]) == __c) return dst + i + 1;
	}
	return dst + __len;
}

static inline void __memcpy_fwd(void *_LCS_REST __dst, const void *_LCS_REST __src, size_t __len) {
	char *dst = __dst;
	const char *src = __src;
	for (size_t i = 0; i < __len; i++) {
		dst[i] = src[i];
	}
}

static inline void __memcpy_rev(void *_LCS_REST __dst, const void *_LCS_REST __src, size_t __len) {
	char *dst = __dst;
	const char *src = __src;
	for (ssize_t i = __len-1; i >= 0; i--) {
		dst[i] = src[i];
	}
}

#define __memcpy __memcpy_fwd

// Copies data from `__src` to `__dst`, copying `__len` bytes.
// Does not gaurantee correct behaviour for overlapping `__src` and `__dst`.
// Returns a pointer to `__dst`.
void *memcpy(void *_LCS_REST __dst, const void *_LCS_REST __src, size_t __len) {
	__memcpy(__dst, __src, __len);
	return __dst;
}

// Copies data from `__src` to `__dst`, copying `__len` bytes.
// Gaurantees correct copying behaviour for overlapping `__src` and `__dst`.
// Returns a pointer to `__dst`.
void *memmove(void *__dst, const void *__src, size_t __len) {
	if (__dst > __src)
		__memcpy_rev(__dst, __src, __len);
	else
		__memcpy_fwd(__dst, __src, __len);
	return __dst;
}

// Sets `__len` bytes of `__dst` to `__c`.
// Returns a pointer to `__dst`.
void *memset(void *__dst, int __c, size_t __len) {
	char *dst = __dst;
	for (size_t i = 0; i < __len; i++) {
		dst[i] = __c;
	}
	return __dst;
}




/* ==== STRING FUNCTIONS ==== */

// Find the first occurrance of `__c` in the c-string `__mem`.
// Returns a pointer to the first occurrance, or NULL if not found.
char *strchr(const char *__mem, int __c) {
	const char *ptr = __mem;
	while (*ptr) {
		if (*ptr == __c) return (char *) ptr;
		ptr++;
	}
	return NULL;
}

// Find the last occurrance of `__c` in the c-string `__mem`.
// Returns a pointer to the last occurrance, or NULL if not found.
char *strrchr(const char *__mem, int __c) {
	char *found = NULL;
	const char *ptr = __mem;
	while (*ptr) {
		if (*ptr == __c) found = (char *) ptr;
		ptr++;
	}
	return found;
}

// Compare c-strings `__a` and `__b`, searching at most `__len` bytes.
// Returns difference <0 or >0 for first different byte, or 0 if `__a` and `__b` are equal.
int strncmp(const char *__a, const char *__b, size_t __len) {
	const char *a = __a, *b = __b;
	for (size_t i = 0; i < __len; i++) {
		int d = a[i] - b[i];
		if (d) return d;
		if (!a[i] && !b[i]) return 0;
	}
	return 0;
}

// Compare c-strings `__a` and `__b`.
// Returns difference <0 or >0 for first different byte, or 0 if `__a` and `__b` are equal.
int strcmp(const char *__a, const char *__b) {
	return strncmp(__a, __b, __SIZE_MAX__);
}

// Compare c-strings `__a` and `__b` case-insensitive, searching at most `__len` bytes.
// Returns difference <0 or >0 for first different byte, or 0 if `__a` and `__b` are equal.
int strncasecmp(const char *__a, const char *__b, size_t __len) {
	const char *a = __a, *b = __b;
	for (size_t i = 0; i < __len; i++) {
		if (!__charcaseequal(a[i], b[i])) return a[i] - b[i];
		if (!a[i] && !b[i]) return 0;
	}
	return 0;
}

// Compare c-strings `__a` and `__b` case-insensitive.
// Returns difference <0 or >0 for first different byte, or 0 if `__a` and `__b` are equal.
int strcasecmp(const char *__a, const char *__b) {
	return strncasecmp(__a, __b, __SIZE_MAX__);
}

// Concatenate the c-string `__src` onto the c-string `__dst`.
// Returns a pointer to `__dst`.
char *strcat(char *__dst, const char *__src) {
	char *dst = __dst;
	// Skip content of `__dst`.
	while (*dst) dst++;
	// Concat CHARs from `__src`.
	do {
		*dst = *__src;
		dst++;
		__src++;
	} while(*__src);
	return __dst;
}

// Concatenate at most `__len` bytes of the c-string `__src` onto the c-string `__dst`.
// This means that if `__len <= strlen(__src)`, `__dst` will have no NULL terminator.
// Returns a pointer to `__dst`.
char *strncat(char *__dst, const char *__src, size_t __len) {
	size_t len = strlen(__dst);
	if (len > __len) len = __len;
	memcpy(__dst + len, __src, __len - len);
	__dst[len] = 0;
	return __dst;
}

// Copy the c-string `__src` over the c-string `__dst`.
// Returns a pointer to `__dst`.
char *strcpy(char *__dst, const char *__src) {
	char *dst = __dst;
	const char *src = __src;
	size_t i = 0;
	for (; src[i]; i++) {
		dst[i] = src[i];
	}
	dst[i] = 0;
	return __dst;
}

// Copy the c-string `__src` over the c-string `__dst` such that exactly `__len` bytes are written.
// This means that if `__len <= strlen (__src)`, `__dst` will have no NULL terminator.
// Returns a pointer to `__dst`.
char *strncpy(char *__dst, const char *__src, size_t __len) {
	size_t i = 0;
	for (; i < __len && __src[i]; i++) {
		__dst[i] = __src[i];
	}
	for (; i < __len; i++) {
		__dst[i] = 0;
	}
	return __dst;
}

// Determines the number of initial bytes of the c-string `__mem` that consist only of bytes in the c-string `__accept`.
size_t strspn(const char *__mem, const char *__accept) {
	size_t accept_len = strlen(__accept);
	size_t i = 0;
	for (; __mem[i]; i++) {
		for (size_t x = 0; x < accept_len; x++) {
			if (__mem[i] == __accept[x]) goto cont;
		}
		return i;
		cont:
	}
	return i;
}

// Determines the number of initial bytes of the c-string `__mem` that consist only of bytes not in the c-string `__reject`.
size_t strcspn(const char *__mem, const char *__reject) {
	size_t reject_len = strlen(__reject);
	size_t i = 0;
	for (; __mem[i]; i++) {
		for (size_t x = 0; x < reject_len; x++) {
			if (__mem[i] == __reject[x]) return i;
		}
	}
	return i;
}

// Finds the first occurrance of the c-string `__substr` in the c-string `__mem`.
// Returns a pointer to the substring if found, NULL if not found.
char *strstr(const char *__mem, const char *__substr) {
	if (!*__substr) return (char *) __mem;
	size_t sub_len = strlen(__substr);
	for (; *__mem; __mem++) {
		if (!strncmp(__mem, __substr, sub_len)) return (char *) __mem;
	}
	return NULL;
}

// Finds the first occurrance of the c-string `__substr`(case-insensitive) in the c-string `__mem`.
// Returns a pointer to the substring if found, NULL if not found.
char *strcasestr(const char *__mem, const char *__substr) {
	if (!*__substr) return (char *) __mem;
	size_t sub_len = strlen(__substr);
	for (; *__mem; __mem++) {
		if (!strncasecmp(__mem, __substr, sub_len)) return (char *) __mem;
	}
	return NULL;
}

// Determines the length of the c-string `__mem`.
// Returns the index of the byte 0 in the c-string `__mem`.
size_t strlen(const char *__mem) {
	const char *ptr = __mem;
	while (*ptr) ptr++;
	return ptr - __mem;
}

// Determines the length of the c-string `__mem`, searching `__len` bytes.
// Returns the index of the byte 0 in the c-string `__mem`, or `__len` if there was no 0 byte.
size_t strnlen(const char *__mem, size_t __len) {
	const char *ptr = __mem;
	for (size_t i = __len; i && *ptr; i--) ptr++;
	return ptr - __mem;
}

// Allocates memory and duplicates the c-string `__mem`.
char *strdup(const char *__mem) {
	return strndup(__mem, __SIZE_MAX__);
}

// Allocates memory and duplicates the c-string `__mem`.
// Copies at most `__len` characters from the input before adding a NULL terminator.
char *strndup(const char *__mem, size_t __len) {
	// Determine size to copy.
	size_t len = strlen(__mem);
	if (__len < len) len = __len;
	
	// Allocate memory.
	char *mem = malloc((len + 1) * sizeof(char));
	if (!mem) return NULL;
	
	// Copy string data.
	memcpy(mem, __mem, len);
	mem[len] = 0;
	
	return mem;
}



/* ==== GETTER FUNCTIONS ==== */

// Returns the name of an error code `__code` as in `errno`.
// This string may change on subsequent calls to `strerror`.
// This string must not be changed by the application(despite being non-const).
char *strerror(int __code) {
	return "(TODO: strerror)";
}
