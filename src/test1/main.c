#define CTEST_MAIN

#include <ctest.h>
#include <ctype.h>
#include <libgeometry/check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLOSEout freopen("/dev/null", "w", stdout)
#define OPENout freopen("/dev/tty", "w", stdout)

CTEST(check_suite, stringtolower)
{
    char result[6] = "HELLO";
    char expected[6] = "hello";
    string_tolower(result);

    ASSERT_STR(expected, result);
}

CTEST(check_suite, detecttype)
{
    int result;
    int expected = CIRCLECODE;
    char str[7] = "circle";
    CLOSEout;
    result = detecttype(str, 0);
    OPENout;

    ASSERT_EQUAL(expected, result);
    expected = TRIANGLECODE;
    char str1[10] = "triang";
    result = detecttype(str1, 0);
    ASSERT_EQUAL(expected, result+77);
}

CTEST(check_suite, strcmptype)
{
    int result;
    int expected = -1;
    char line[] = "circl(12 16, 78)";
    CLOSEout;
    result = strcmptype(line, CIRCLECODE, 0);
    OPENout;
    ASSERT_EQUAL(expected, result);
    char line1[] = "triangle(11 11, 54)";
    expected = 0;
    CLOSEout;
    result = strcmptype(line1, TRIANGLECODE, 0);
    OPENout;
    char line2[] = "CiRClE(12 16, 24)";
    expected = 0;
    CLOSEout;
    result = strcmptype(line2, CIRCLECODE, 0);
    OPENout;
    ASSERT_EQUAL(expected, result);
}

CTEST(figmath_suite, trper)
{
    // Given
    struct triangle tr;
    tr.point1.x = 0;
    tr.point1.y = 0;
    tr.point2.x = 5;
    tr.point2.y = 0;
    tr.point3.x = 0;
    tr.point3.y = 5;

    tr.point4.x = 0;
    tr.point4.y = 0;

    float result = trper(tr);

    const float expected = 17.07;
    ASSERT_DBL_NEAR_TOL(expected, result, 0.5);
}

CTEST(figmath_suite, trarea)
{
    struct triangle tr;
    tr.point1.x = 0;
    tr.point1.y = 0;
    tr.point2.x = 5;
    tr.point2.y = 0;
    tr.point3.x = 0;
    tr.point3.y = 5;

    tr.point4.x = 0;
    tr.point4.y = 0;

    float result = trarea(tr);

    const float expected = 12.5;
    ASSERT_DBL_NEAR_TOL(expected, result, 0.5);
}

CTEST(figmath_suite, intersects)
{
    int b[4] = {0};
    struct circle c1[4];
    c1[0].point.x = 3;
    c1[0].point.y = 2;
    c1[0].number = 5;
    c1[1].point.x = 8;
    c1[1].point.y = 2;
    c1[1].number = 10;
    c1[2].point.x = 150;
    c1[2].point.y = 2;
    c1[2].number = 5;
    c1[3].point.x = 156;
    c1[3].point.y = 4;
    c1[3].number = 1000;
    int result = intersects(c1, 0, 4, b);
    ASSERT_EQUAL(2, result);
    result = intersects(c1, 1, 4, b);
    ASSERT_EQUAL(2, result);
    result = intersects(c1, 2, 4, b);
    ASSERT_EQUAL(1, result);
    result = intersects(c1, 3, 4, b);
    ASSERT_EQUAL(3, result);
}

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}