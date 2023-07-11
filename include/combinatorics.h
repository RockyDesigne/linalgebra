//
// Created by HORIA on 25.02.2023.
//

#ifndef LINALGEBRA_COMBINATORICS_H
#define LINALGEBRA_COMBINATORICS_H

/* recursive function that calculates factorial of a number n
 * @param n an unsigned int, the number we take the factorial of
 * @param accumulator stores the factorial
 * @return the value of accumulator when base cas is reached
 */
unsigned long long factTR(unsigned int n, unsigned long long int accumulator);

/* wrapper for factorial function
 * @param n, the factorial
 */
unsigned long long factorial(unsigned int n);

// the number of n arrangements taken n times
unsigned long long arrangements(unsigned int n, unsigned int k);

// the number of n combinations take k times
unsigned long long combinations(unsigned int n, unsigned int k);

// computes (a + b) to the n power using newton's binomial theorem
unsigned long long newton(unsigned int a, unsigned int b, unsigned int n);
/*
 * prints the binomial expansion of (a+b) to the n power
 * @param n the power we raise (a+b) to
 */
void newt(unsigned int n);

#endif //LINALGEBRA_COMBINATORICS_H
