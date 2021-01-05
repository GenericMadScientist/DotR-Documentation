/*! \file */

#ifndef STDLIB_H
#define STDLIB_H

/** @brief Address 28F850
 *
 *  Seed for PRNG.
 */
extern unsigned long long seed;

/** @brief https://en.cppreference.com/w/c/numeric/math/cos */
float cosf(float arg);

/** @brief https://en.cppreference.com/w/c/numeric/math/fabs */
float fabsf(float arg);

/** @brief https://en.cppreference.com/w/c/numeric/math/floor */
float floorf(float arg);

/** @brief https://en.cppreference.com/w/c/string/byte/memcpy */
void* memcpy(void* dest, const void* src, size_t count);

/** @brief https://en.cppreference.com/w/c/string/byte/memset */
void* memset(void* dest, int ch, size_t count);

/** @brief https://en.cppreference.com/w/c/numeric/math/pow */
double pow(double base, double exponent);

/** @brief https://en.cppreference.com/w/c/io/fprintf */
int printf(const char* format, ...);

/** @brief https://en.cppreference.com/w/c/algorithm/qsort */
void qsort(void* ptr, size_t count, size_t size,
    int (*comp)(const void*, const void*));

/** @brief https://en.cppreference.com/w/c/numeric/random/rand */
int rand(void);

/** @brief https://en.cppreference.com/w/c/numeric/math/sin */
float sinf(float arg);

#endif
