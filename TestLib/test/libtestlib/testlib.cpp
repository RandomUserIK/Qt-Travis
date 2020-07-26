#include <catch2/catch.hpp>

#include "testlib.hpp"

TEST_CASE("Addition")
{
    SECTION("Computes addition on two integers")
    {
        auto testLib = TestLib();
        REQUIRE(testLib.addition(3, 2) == 5);
    }
}

