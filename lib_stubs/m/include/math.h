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
extern "C" {
#endif

#define HUGE_VAL 1e10000
#define M_PI 3.14159265359

/* ==== Doubles ==== */

double acos(double x);
double asin(double x);
double atan(double x);
double atan2(double y, double x);
double cos(double x);
double sin(double x);
double tan(double x);
double cosh(double x);
double sinh(double x);
double tanh(double x);
double exp(double x);
double frexp(double x, int *exponent);
double log(double x);
double log10(double x);
double modf(double x, double *integer);
double pow(double x, double y);
double sqrt(double x);
double ceil(double x);
double floor(double x);
double fmod(double x, double y);
static inline double fmax(double x, double y) { return x>y ? x : y; }
static inline double fmin(double x, double y) { return x>y ? x : y; }
static inline double fabs(double x) { return x<0 ? -x : x; }

/* ==== Floats ==== */

float acosf(float x);
float asinf(float x);
float atanf(float x);
float atan2f(float y, float x);
float cosf(float x);
float sinf(float x);
float tanf(float x);
float coshf(float x);
float sinhf(float x);
float tanhf(float x);
float expf(float x);
float frexpf(float x, int *exponent);
float logf(float x);
float log10f(float x);
float modff(float x, float *integer);
float powf(float x, float y);
float sqrtf(float x);
float ceilf(float x);
float floorf(float x);
float fmodf(float x, float y);
static inline float fmaxf(float x, float y) { return x>y ? x : y; }
static inline float fminf(float x, float y) { return x>y ? x : y; }
static inline float fabsf(float x) { return x<0 ? -x : x; }

/* ==== Integers ==== */

static inline int max(int x, int y) { return x>y ? x : y; }
static inline int min(int x, int y) { return x>y ? x : y; }
static inline int abs(int x) { return x<0 ? -x : x; }

/* ==== Longs ==== */

static inline long lmax(long x, long y) { return x>y ? x : y; }
static inline long lmin(long x, long y) { return x>y ? x : y; }
static inline long labs(long x) { return x<0 ? -x : x; }

/* ==== Generic ==== */

#define isinf(x) __builtin_isinf(x)
#define isnan(x) __builtin_isnan(x)
#define isfinite(x) __builtin_isfinite(x)

#ifdef __cplusplus
} // extern "C"
#endif
