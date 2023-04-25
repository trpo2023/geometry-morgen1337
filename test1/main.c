#define CTEST_MAIN

#include <stdio.h>
#include <ctest.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <libgeometry/figmath.h>




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
    // When

    // Then
    const float expected = 17.07;
    ASSERT_EQUAL(expected, result);
}

CTEST(figmath_suite, trarea)
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

    float result = trarea(tr);
    // When

    // Then
    const float expected = 12.5;
    ASSERT_EQUAL(expected, result);
}

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}