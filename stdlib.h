/*! \file */

#ifndef STDLIB_H
#define STDLIB_H

/** @brief Address 28F850
 *
 *  Seed for PRNG.
 */
extern unsigned long long seed;

/** @brief https://en.cppreference.com/w/c/numeric/math/pow */
double pow(double base, double exponent);

/** @brief https://en.cppreference.com/w/c/numeric/random/rand */
int rand(void);

#endif
