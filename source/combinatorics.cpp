//
// Created by HORIA on 25.02.2023.
//
#include "combinatorics.h"

#include <iostream>
#include <cmath>

unsigned long long factTR(unsigned int n, unsigned long long int accumulator) {
    if (n < 2)
        return accumulator;
    return factTR(n - 1, n * accumulator);
}

// wrapper for factTR
unsigned long long factorial(unsigned int n) {return factTR(n, 1);}

unsigned long long arrangements(unsigned int n, unsigned int k) {
    return factorial(n) / factorial(n-k);
}

unsigned long long combinations(unsigned int n, unsigned int k) {
    return factorial(n) / factorial(n-k) * (1.0 / factorial(k));
}

unsigned long long newton(unsigned int a, unsigned int b, unsigned int n) {
    unsigned long long res {};
    for (int k {0}; k <= n; ++k) {
        res += combinations(n, k) * std::pow(a, n - k) * std::pow(b, k);
    }

    return res;
}

void newt(unsigned int n) {

    if (n == 0) {
        std::cout << "0" << '\n';
        return;
    }

    std::cout << "a^" << n << " + ";

    for (int k {1}; k <= n; ++k) {

        if (k == n)
            std::cout << "b^" << k;
        else
            std::cout << combinations(n, k) << "a^" << n-k
                      << '*' << "b^" << k << " + ";
    }

    std::cout << '\n';
}