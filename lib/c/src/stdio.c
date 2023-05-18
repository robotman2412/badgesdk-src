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

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <badgeabi.h>

// Defines what to write as a line ending.
#define PLATFORM_LF "\n"
// Defines the length of the line ending.
#define PLATFORM_LF_LEN 1



/* ==== FILE ACCESSORS ==== */

// Regular file read function.
int __regular_read(FILE *_LCS_REST __fd, void *_LCS_REST __mem, size_t __nmemb, void *_LCS_REST __cookie);
// Regular file write function.
int __regular_write(FILE *_LCS_REST __fd, const void *_LCS_REST __mem, size_t __nmemb, void *_LCS_REST __cookie);
// Regular file seek function.
long __regular_seek(FILE *_LCS_REST __fd, long __off, int __whence, void *_LCS_REST __cookie);
// Regular file close function.
int __regular_close(FILE *_LCS_REST __fd, void *_LCS_REST __cookie);
// Regular file flush function.
int __regular_flush(FILE *_LCS_REST __fd, void *_LCS_REST __cookie);


/* ==== FILE MANAGEMENT ==== */

// Delete file at `__path`.
int remove(const char *__path);
// Rename file at `__old` to `__new`.
int rename(const char __old, const char *__new);

// Open a temporary (deleted when `fclose` is called on the return value) file for read/write binary.
FILE *tmpfile();
// Create a filename for a temporary file that does not yet exist.
char *tmpnam(char *s);

// Close `__fd`.
int fclose(FILE *__fd) {
	int res = __fd->__close(__fd, __fd->__cookie);
	free(__fd);
	return res;
}
// Flush `__fd` or all streams if `__fd` is NULL.
int fflush(FILE *__fd) {
	return __fd->__flush(__fd, __fd->__cookie);
}

// Open a file.
FILE *fopen(const char *_LCS_REST __path, const char *_LCS_REST __mode);
// Open a file and replace an existing stream with it.
FILE *freopen(const char *_LCS_REST __path, const char *_LCS_REST __mode, FILE *_LCS_REST __fd);



/* ==== PRINTF VARIANTS ==== */

// Format `__fmt` and write it to `__fd`.
int vfprintf(FILE *_LCS_REST __fd, const char *_LCS_REST __fmt, va_list __vararg);
// Format `__fmt` and write it to `__fd`.
int fprintf(FILE *_LCS_REST __fd, const char *_LCS_REST __fmt, ...)
	__attribute__((format(printf, 2, 3)));
// Format `__fmt` and write it to `stdout`.
int vprintf(const char *_LCS_REST __fmt, va_list __vararg);
// Format `__fmt` and write it to `stdout`.
int printf(const char *_LCS_REST __fmt, ...)
	__attribute__((format(printf, 1, 2)));

// Format `__fmt`, allocate memory and write it to `__ptr`.
int vasprintf(char **_LCS_REST __ptr, const char *_LCS_REST __fmt, va_list __vararg);
// Format `__fmt`, allocate memory and write it to `__ptr`.
int asprintf(char **_LCS_REST __ptr, const char *_LCS_REST __fmt, ...)
	__attribute__((format(printf, 2, 3)));
// Format `__fmt` and write at most `__len` bytes of it to `__buf`.
int vsnprintf(char *_LCS_REST __buf, size_t __len, const char *_LCS_REST __fmt, va_list __vararg);
// Format `__fmt` and write it to `__buf`.
int vsprintf(char *_LCS_REST __buf, const char *_LCS_REST __fmt, va_list __vararg);
// Format `__fmt` and write it to `__buf`.
int snprintf(char *_LCS_REST __buf, size_t __len, const char *_LCS_REST __fmt, ...)
	__attribute__((format(printf, 3, 4)));
// Format `__fmt` and write it to `__buf`.
int sprintf(char *_LCS_REST __buf, const char *_LCS_REST __fmt, ...)
	__attribute__((format(printf, 2, 3)));



/* ==== SCANF VARIANTS ==== */

// Read formatted (`__fmt`) input from stream `__fd`.
int vfscanf(FILE *_LCS_REST __fd, const char *_LCS_REST __fmt, va_list __vararg);
// Read formatted (`__fmt`) input from stream `__fd`.
int fscanf(FILE *_LCS_REST __fd, const char *_LCS_REST __fmt, ...)
	__attribute__((format(scanf, 2, 3)));

// Read formatted (`__fmt`) input from `stdin`.
int vscanf(const char *_LCS_REST __fmt, va_list __vararg);
// Read formatted (`__fmt`) input from `stdin`.
int scanf(const char *_LCS_REST __fmt, ...)
	__attribute__((format(scanf, 1, 2)));

// Read formatted (`__fmt`) input from c-string `__mem`.
int vsscanf(const char *_LCS_REST __mem, const char *_LCS_REST __fmt, va_list __vararg);
// Read formatted (`__fmt`) input from c-string `__mem`.
int sscanf(const char *_LCS_REST __mem, const char *_LCS_REST __fmt, ...)
	__attribute__((format(scanf, 2, 3)));



/* ==== INPUT/OUTPUT ==== */

// Read a c-string `__dst` from an input stream `__fd`.
char *fgets(char *_LCS_REST __dst, int __len, FILE *_LCS_REST __fd);
// Read a character from an input stream `__fd`.
int fgetc(FILE *__fd) {
	unsigned char tmp;
	int count = fread(&tmp, sizeof(char), 1, __fd);
	if (count) return tmp;
	else return EOF;
}
// Read a character from `stdin`.
int getchar() {
	return fgetc(stdin);
}
// Read `__count` elements of `__size` each from stream `__fd` into `__ptr`.
int fread(void *_LCS_REST __ptr, size_t __size, size_t __count, FILE *_LCS_REST __fd);

// Push a character back into an input stream `__fd`.
int ungetc(int __c, FILE *__fd);

// Write a c-string `__buf` to `__fd`.
int fputs(const char *_LCS_REST __buf, FILE *_LCS_REST __fd) {
	fwrite(__buf, 1, strlen(__buf), __fd);
}
// Write a c-string `__buf` followed by a newline to `stdout`.
int puts(const char *_LCS_REST __buf) {
	fwrite(__buf, 1, strlen(__buf), stdout);
	fwrite(PLATFORM_LF, 1, PLATFORM_LF_LEN, stdout);
}
// Write a character `__c` to a stream `__fd`.
int fputc(int __c, FILE *__fd) {
	return fwrite(&__c, sizeof(char), 1, __fd);
}
// Write a character `__c` to `stdout`.
int putchar(int __c) {
	return fputc(__c, stdout);
}
// Write `__count` elements of `__size` each from `__ptr` into stream `__fd`.
int fwrite(const void *_LCS_REST __ptr, size_t __size, size_t __count, FILE *_LCS_REST __fd) {
	
}



/* ==== CONTROL FUNCTIONS ==== */

// Get the current position in stream `__fd`.
int fgetpos(FILE *_LCS_REST __stream, fpos_t *_LCS_REST __pos);
// Seek to an absolute position in stream `__fd`.
int fsetpos(FILE *_LCS_REST __stream, const fpos_t *_LCS_REST __pos);
// Seek to a position `__pos` in stream `__fd`.
int fseek(FILE *__stream, long __off, int __whence) {
	return __stream->__seek(__stream, __off, __whence, __stream->__cookie);
}
// Get the current position in stream `__fd`.
long ftell(FILE *__stream) {
	return __stream->__seek(__stream, 0, SEEK_CUR, __stream->__cookie);
}
// Rewind to the beginning of stream `__fd`.
void rewind(FILE *__stream) {
	__stream->__seek(__stream, 0, SEEK_SET, __stream->__cookie);
}

/* // Set stream `__fd` buffer to `__buf`, size `BUFSIZ`.
void setbuf(FILE *_LCS_REST __fd, char *_LCS_REST __buf);
// Set stream `__fd` buffer to `__buf`, size `__len`.
void setvbuf(FILE *_LCS_REST __fd, char *_LCS_REST __buf, int __modes, size_t __len); */

// Turn off the error indicators of stream `__fd`.
void clearerr(FILE *__stream) {
	__stream->__flags &= ~__FILE_FLAG_ERROR;
}
// Return the EOF indicator for stream `__fd`.
int feof(FILE *__stream) {
	return !!(__stream->__flags & __FILE_FLAG_EOF);
}
// Return the error indicator for stream `__fd`.
int ferror(FILE *__stream) {
	return !!(__stream->__flags & __FILE_FLAG_ERROR);
}

// Print an error message `__msg` according to `errno`.
void perror(const char *__msg) {
	if (__msg && *__msg) {
		fputs(__msg, stderr);
	}
	fputs(": ", stderr);
	fputs(strerror(errno), stderr);
}
