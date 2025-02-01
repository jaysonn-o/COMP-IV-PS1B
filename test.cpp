// Copyright 2022
// By Dr. Rykalova
// Edited by Dr. Daly
// test.cpp for PS1a
// updated 5/12/2022

#include <iostream>
#include <string>

#include "FibLFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testStepInstr1) {
    FibLFSR l("1011011000110110");
    BOOST_REQUIRE_EQUAL(l.step(), 0);
    BOOST_REQUIRE_EQUAL(l.step(), 0);
    BOOST_REQUIRE_EQUAL(l.step(), 0);
    BOOST_REQUIRE_EQUAL(l.step(), 1);
    BOOST_REQUIRE_EQUAL(l.step(), 1);
    BOOST_REQUIRE_EQUAL(l.step(), 0);
    BOOST_REQUIRE_EQUAL(l.step(), 0);
    BOOST_REQUIRE_EQUAL(l.step(), 1);
}

BOOST_AUTO_TEST_CASE(testStepInstr2) {
    FibLFSR l2("1011011000110110");
    BOOST_REQUIRE_EQUAL(l2.generate(9), 51);
}

BOOST_AUTO_TEST_CASE(testConstructorInvalidSeed) {
    BOOST_CHECK_THROW(FibLFSR l("10110110001101"), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(testConstructorInvalidInput) {
    BOOST_CHECK_THROW(FibLFSR l("101A011000110110"), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(testGenerateZeroBits) {
    FibLFSR l("1011011000110110");
    BOOST_REQUIRE_EQUAL(l.generate(0), 0);
}

BOOST_AUTO_TEST_CASE(testGenerateMaxBits) {
    FibLFSR l("1011011000110110");
    BOOST_REQUIRE_EQUAL(l.generate(16), 6557);
}
