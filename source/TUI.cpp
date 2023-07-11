//
// Created by HORIA on 25.02.2023.
//
#include "TUI.h"
#include "combinatorics.h"

#include <iostream>

// tui for the arrangements function
void arrangementsTUI() {
    std::cout << "Enter n: ";
    unsigned int n {};
    std::cin >> n;
    std::cout << '\n';

    std::cout << "Enter k: ";
    unsigned int k {};
    std::cin >> k;
    std::cout << '\n';

    std::cout << arrangements(n, k) << '\n';
}

// tui for combinations
void combinationsTUI() {
    std::cout << "Enter n: ";
    unsigned int n {};
    std::cin >> n;
    std::cout << '\n';

    std::cout << "Enter k: ";
    unsigned int k {};
    std::cin >> k;
    std::cout << '\n';

    std::cout << combinations(n, k) << '\n';
}

void permutationsTUI() {
    std::cout << "enter n: ";
    unsigned int n {};
    std::cin >> n;
    std::cout << '\n';

    std::cout << factorial(n) << '\n';
}

void binomialTUI() {
    std::cout << "enter n: ";
    unsigned int n {};
    std::cin >> n;
    std::cout << '\n';

    newt(n);
}

void handleTUI() {

    std::cout << "*** Combinatorics *** " << '\n';
    std::cout << "Input the integer one for arrangements." << '\n';
    std::cout << "Input the integer two for combinations." << '\n';
    std::cout << "Input the integer three for permutations." << '\n';
    std::cout << "Input the integer four for binomial expansion of (a+b)." << '\n';
    std::cout << "Input zero to exit." << '\n';

    unsigned int exit {0};
    while (!exit) {

        std::cout << "input choice: ";
        unsigned choice {};
        std::cin >> choice;
        std::cout << '\n';

        switch (choice) {
            case 1:
                arrangementsTUI();
                break;
            case 2:
                combinationsTUI();
                break;
            case 3:
                permutationsTUI();
                break;
            case 4:
                binomialTUI();
                break;
            default:
                exit = 1;
        }
    }

}