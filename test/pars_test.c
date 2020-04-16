#include "ctest.h"
#include "pars.h"

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
    ASSERT_EQUAL(-1, k);
    k = pars_test_name("Circle(1 0, 2)");
    ASSERT_EQUAL(-1, k);
    k = pars_test_name("");
    ASSERT_EQUAL(-1, k);
    k = pars_test_name("c ircle(1 0, 2)");
    ASSERT_EQUAL(-1, k);
}

CTEST(parsNumber, Isnumber)
{
    float a[3];
    char name_one[] = "circle(1 4, 2)";
    pars(name_one, a);
    ASSERT_EQUAL(1, a[0]);
    ASSERT_EQUAL(4, a[1]);
    ASSERT_EQUAL(2, a[2]);
    char name_two[] = "circle(1 0, 2.2)";
    pars(name_two, a);
    ASSERT_EQUAL(1, a[0]);
    ASSERT_EQUAL(0, a[1]);
    ASSERT_DBL_NEAR(2.2, a[2]);
    char name_three[] = "circle(1.2 0.5, 2.64)";
    pars(name_three, a);
    ASSERT_DBL_NEAR(1.2, a[0]);
    ASSERT_DBL_NEAR(0.5, a[1]);
    ASSERT_DBL_NEAR(2.64, a[2]);
    char name_four[] = "circle(-1.2 -0.5, 2.64)";
    pars(name_four, a);
    ASSERT_DBL_NEAR(-1.2, a[0]);
    ASSERT_DBL_NEAR(-0.5, a[1]);
    ASSERT_DBL_NEAR(2.64, a[2]);
}

CTEST(parsNumber, IsNotnumber)
{
    float a[3] = {0, 0, 0};
    char name_one[] = "circle(1 4, a)";
    pars(name_one, a);
    ASSERT_EQUAL(1, a[0]);
    ASSERT_EQUAL(4, a[1]);
    ASSERT_EQUAL(0, a[2]);
    a[0] = 0, a[1] = 0, a[2] = 0;
    char name_two[] = "circle(! g, 2.2)";
    pars(name_two, a);
    ASSERT_DBL_NEAR(2.2, a[0]);
    ASSERT_EQUAL(0, a[1]);
    ASSERT_EQUAL(0, a[2]);
    a[0] = 0, a[1] = 0, a[2] = 0;
    char name_three[] = "circle(///////)";
    pars(name_three, a);
    ASSERT_EQUAL(0, a[0]);
    ASSERT_EQUAL(0, a[1]);
    ASSERT_EQUAL(0, a[2]);
    char name_four[] = "circle()";
    pars(name_four, a);
    ASSERT_EQUAL(0, a[0]);
    ASSERT_EQUAL(0, a[1]);
    ASSERT_EQUAL(0, a[2]);
    char name_five[] = "circle";
    pars(name_five, a);
    ASSERT_EQUAL(0, a[0]);
    ASSERT_EQUAL(0, a[1]);
    ASSERT_EQUAL(0, a[2]);
}
