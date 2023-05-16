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

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Display update callback function.
typedef bool (*display_write_func_t)(const void *buf, size_t len, int x, int y, int width, int height, void *cookie);

// Register a new display.
// The `cookie` parameter is passed to the display's write function.
// Returns an ID on success, 0 on error.
int display_add(display_write_func_t func, void *cookie, int width, int height);
// Remove a display.
// Returns success status.
bool display_remove(int display);
// Get the amount of connected displays.
// May be zero on badges without displays.
int display_count();
// Get the IDs of connected displays.
// Any ID zero means not present.
void display_get_ids(int *out_ids, size_t len);

// Get the width in pixels of a display.
int display_width(int display);
// Get the height in pixels of a display.
int display_height(int display);

// Draw the full area of a display.
bool display_write(int display, const void *buf, size_t len);
// Draw a part of the display.
bool display_write_partial(int display, const void *buf, size_t len, int x, int y, int width, int height);

#ifdef __cplusplus
}
#endif
