//
// Created by HORIA on 26.03.2023.
//

#ifndef LINALGEBRA_FRACTION_H
#define LINALGEBRA_FRACTION_H

#include <cstdint>
#include <stdexcept>
#include <numeric>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

class Fraction {
public:

    explicit Fraction(int64_t numerator=1, int64_t denominator=1);

    //getters
    [[nodiscard]] auto get_numerator() const -> int64_t;

    [[nodiscard]] auto get_denominator() const -> int64_t;

    //setters
    auto set_numerator(int64_t numerator) -> void;

    auto set_denominator(int64_t denominator) -> void;

    //funcs
    auto simplify() -> void;

    [[nodiscard]] auto is_null() const -> bool;

    auto operator=(const Fraction& other) -> Fraction&;

    friend auto operator>>(std::ifstream& file, Fraction& fraction) -> std::ifstream&;

    friend auto operator<<(std::ostream& out, const Fraction& fraction) -> std::ostream&;

    friend auto operator*(const Fraction& fraction1, const Fraction& fraction2) -> Fraction;

    friend auto operator/(const Fraction& fraction1, const Fraction& fraction2) -> Fraction;

    friend auto operator+(const Fraction& fraction1, const Fraction& fraction2) -> Fraction;

    friend auto operator-(const Fraction& fraction1, const Fraction& fraction2) -> Fraction;

private:
    int64_t m_numerator {};
    int64_t m_denominator {};
};


#endif //LINALGEBRA_FRACTION_H
