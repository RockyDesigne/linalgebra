//
// Created by HORIA on 26.03.2023.
//
#include "Fraction.h"

Fraction::Fraction(int64_t numerator, int64_t denominator)
    : m_numerator {numerator}, m_denominator {denominator} {

    if (m_denominator == 0) {
        throw std::invalid_argument("Denominator cannot be 0");
    }

    simplify();

}

auto Fraction::simplify() -> void {

    auto gcd {std::gcd(m_numerator, m_denominator)};

    m_numerator /= gcd;
    m_denominator /= gcd;

    if (m_numerator < 0 && m_denominator < 0) {
        m_numerator = -m_numerator;
        m_denominator = -m_denominator;
    }

}

auto operator>>(std::ifstream &file, Fraction &fraction) -> std::ifstream & {

    file >> fraction.m_numerator;

    return file;
}

auto operator<<(std::ostream &out, const Fraction &fraction) -> std::ostream & {

    if (!fraction.m_numerator)
        out << 0;

    else if (fraction.m_denominator == 1)
        out << fraction.m_numerator;

    else if (fraction.m_denominator == -1)
        out << -fraction.m_numerator;

    else
        out << fraction.m_numerator << '/' << fraction.m_denominator;

    return out;
}

auto Fraction::get_numerator() const -> int64_t {

    return m_numerator;

}

auto Fraction::get_denominator() const -> int64_t {

    return m_denominator;

}

auto Fraction::set_numerator(int64_t numerator) -> void {

    m_numerator = numerator;

}

auto Fraction::set_denominator(int64_t denominator) -> void {

    m_denominator = denominator;

}

auto Fraction::is_null() const -> bool {

    return !m_numerator;

}

auto operator*(const Fraction& fraction1, const Fraction& fraction2) -> Fraction {

    return Fraction {fraction1.get_numerator() * fraction2.get_numerator(),
                     fraction1.get_denominator() * fraction2.get_denominator()};

}

auto operator/(const Fraction& fraction1, const Fraction& fraction2) -> Fraction {
    return Fraction {fraction1.get_numerator() * fraction2.get_denominator(),
                     fraction1.get_denominator() * fraction2.get_numerator()};
}

auto operator+(const Fraction& fraction1, const Fraction& fraction2) -> Fraction {
    return Fraction {fraction1.get_numerator() * fraction2.get_denominator()
    + fraction2.get_numerator() * fraction1.get_denominator(), fraction1.get_denominator() *
    fraction2.get_denominator()};
}

auto operator-(const Fraction& fraction1, const Fraction& fraction2) -> Fraction {
    return Fraction {fraction1.get_numerator() * fraction2.get_denominator() -
    fraction2.get_numerator() * fraction1.get_denominator(),
    fraction1.get_denominator() * fraction2.get_denominator()};
}

auto Fraction::operator=(const Fraction &other) -> Fraction & {
    if (this != &other) { // avoid self-assignment
        m_numerator = other.m_numerator;
        m_denominator = other.m_denominator;
    }
    return *this;
}
