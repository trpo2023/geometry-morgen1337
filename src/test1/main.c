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

CTEST(check_suite, bracket_check){
    char line1[] = "circle(12 43";
    CLOSEout;
    int result = bracketscheck(line1, "circle",  0);
    OPENout;
    ASSERT_EQUAL(0, result);
    CLOSEout;
    char line2[] = "circle(12 15, 54)";
    result = bracketscheck(line2,"circle", 0);
    OPENout;
    ASSERT_EQUAL(1,result);
}

CTEST(check_suite, num_check)
{
    struct triangle t = {0};
    struct circle c1 = {0};
    int successtr = 0;
    int successci = 0;
    char line1[] = "circle(12 14 16)";
    char line2[] = "circle(12, 14 15)";
    char line3[] = "circle(12  14,     15)";
    char line5[] = "triangle(12  14     15)";
    char line4[] = "triangle(12 14, 15 16,16 14, 12 14)";

    CLOSEout;
    int result
            = num_check(line1, 1, CIRCLECODE, &t, &c1, &successtr, &successci);
    OPENout;
    ASSERT_EQUAL(0, result);

    CLOSEout;
    result = num_check(line2, 1, CIRCLECODE, &t, &c1, &successtr, &successci);
    OPENout;
    ASSERT_EQUAL(0, result);

    CLOSEout;
    result = num_check(line3, 1, CIRCLECODE, &t, &c1, &successtr, &successci);
    OPENout;
    ASSERT_EQUAL(1, result);

    CLOSEout;
    result = num_check(line5, 1, CIRCLECODE, &t, &c1, &successtr, &successci);
    OPENout;
    ASSERT_EQUAL(0, result);

    CLOSEout;
    result = num_check(line4, 1, TRIANGLECODE, &t, &c1, &successtr, &successci);
    OPENout;
    ASSERT_EQUAL(1, result);
}

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
    ASSERT_EQUAL(expected, result);
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
    char line3[] = "circle12 16, 25)";
    CLOSEout;
    result = strcmptype(line3, CIRCLECODE, 0);
    OPENout;
    expected = -1;
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

    float expected = 17.07;
    ASSERT_DBL_NEAR_TOL(expected, result, 0.5);

    tr.point1.x = 10;
    tr.point1.y = 4;
    tr.point2.x = 17;
    tr.point2.y = 22;
    tr.point3.x = 6;
    tr.point3.y = 34;

    tr.point4.x = 10;
    tr.point4.y = 4;

    result = trper(tr);

    expected = 65.1;
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

    float expected = 12.5;
    ASSERT_DBL_NEAR_TOL(expected, result, 1);

    tr.point1.x = 10;
    tr.point1.y = 4;
    tr.point2.x = 17;
    tr.point2.y = 22;
    tr.point3.x = 6;
    tr.point3.y = 34;

    tr.point4.x = 10;
    tr.point4.y = 4;

    result = trarea(tr);

    expected = 141;
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
