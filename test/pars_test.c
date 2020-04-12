#include "../src/pars.cpp"
#include "ctest.h"

CTEST(pars_name, circle)
{
    int k = pars_test_name("circle(1 4, 2)");
    ASSERT_EQUAL(1, k);
    k = pars_test_name("circle(1 6, 8)");
    ASSERT_EQUAL(1, k);
}

CTEST(pars_name, notCircle)
{
    int k = pars_test_name("hjfhjfhjfj(1 0, 2)");
    ASSERT_EQUAL(1, k);
    k = pars_test_name("Circle(1 0, 2)");
    ASSERT_EQUAL(1, k);
    k = pars_test_name("");
    ASSERT_EQUAL(1, k);
}