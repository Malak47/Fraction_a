//
// Created by malaklinux on 4/19/23.
//
#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"
#include <sstream>

using namespace ariel;
using namespace std;

TEST_CASE("Constructors") {
    Fraction f1;
    CHECK(f1.getNumerator() == 0);
    CHECK(f1.getDenominator() == 1);
    CHECK(f1 == 0);
    CHECK_THROWS(Fraction {1,0});

    Fraction f2(3, 4);
    CHECK(f2.getNumerator() == 3);
    CHECK(f2.getDenominator() == 4);


    Fraction f3(6, 8);
    CHECK(f3.getNumerator() == 3);
    CHECK(f3.getDenominator() == 4);

    Fraction f4(0.5);
    CHECK(f4.getNumerator() == 1);
    CHECK(f4.getDenominator() == 2);
}

TEST_CASE("Addition") {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    Fraction f3 = f1 + f2;
    CHECK(f3.getNumerator() == 5);
    CHECK(f3.getDenominator() == 6);
}

TEST_CASE("Subtraction") {
    Fraction f1(1, 2);
    Fraction f2(1, 4);
    Fraction f3 = f1 - f2;
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 4);
}

TEST_CASE("Multiplication") {
    Fraction f1(1, 2);
    Fraction f2(2, 3);
    Fraction f3 = f1 * f2;
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 3);
}

TEST_CASE("Division") {
    Fraction f1(1, 2);
    Fraction f2(2, 3);
    Fraction f3 = f1 / f2;
    CHECK(f3.getNumerator() == 3);
    CHECK(f3.getDenominator() == 4);

    // Divide by zero
    REQUIRE_THROWS_AS(f1 / Fraction(0, 1), std::invalid_argument);
}

TEST_CASE("Equality") {
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(3, 6);
    CHECK(f1 == f2);
    CHECK(f1 == f3);
}

TEST_CASE("Inequality") {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    CHECK(f1 != f2);
}

TEST_CASE("Greater than") {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    CHECK(f1 > f2);
}

TEST_CASE("Less than") {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    CHECK(f2 < f1);
}

TEST_CASE("Greater than or equal") {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    Fraction f3(1, 2);
    CHECK(f1 >= f2);
    CHECK(f1 >= f3);
}

TEST_CASE("Less than or equal") {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    Fraction f3(1, 2);
    CHECK(f2 <= f1);
    CHECK(f3 <= f1);
}

TEST_CASE("Increment") {
    Fraction f1(1, 2);
    Fraction f2 = f1++;
    CHECK(f2.getNumerator() == 1);
    CHECK(f2.getDenominator() == 2);
    CHECK(f1.getNumerator() == 3);
    CHECK(f1.getDenominator() == 2);

    Fraction f3 = ++f1;
    CHECK(f3.getNumerator() == 5);
    CHECK(f3.getDenominator() == 2);
    CHECK(f1.getNumerator() == 5);
    CHECK(f1.getDenominator() == 2);
}

TEST_CASE("Decrement") {
    Fraction f1(3, 2);
    Fraction f2 = f1--;
    CHECK(f2.getNumerator() == 3);
    CHECK(f2.getDenominator() == 2);
    CHECK(f1.getNumerator() == 1);
    CHECK(f1.getDenominator() == 2);

    Fraction f3 = --f1;
    CHECK(f3.getNumerator() == -1);
    CHECK(f3.getDenominator() == 2);
    CHECK(f1.getNumerator() == -1);
    CHECK(f1.getDenominator() == 2);
}

TEST_CASE("Input stream") {
    std::istringstream iss("3/4");
    Fraction f;
    iss >> f;
    CHECK(f.getNumerator() == 3);
    CHECK(f.getDenominator() == 4);

    std::istringstream iss2("5/0");
    CHECK_THROWS_AS(iss2 >> f, std::invalid_argument);
}

TEST_CASE("Output stream") {
    Fraction f(3, 4);
    std::ostringstream oss;
    oss << f;
    CHECK(oss.str() == "3/4");
}
