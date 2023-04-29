#include <math.h>
#include <stdio.h>

struct Point {
    float x;
    float y;
};

struct circle {
    struct Point point;
    float number;
};

struct triangle {
    struct Point point1;
    struct Point point2;
    struct Point point3;
    struct Point point4;
};

float trper(struct triangle tr)
{
    float dx12 = tr.point1.x - tr.point2.x;
    float dy12 = tr.point1.y - tr.point2.y;
    float dx13 = tr.point1.x - tr.point3.x;
    float dy13 = tr.point1.y - tr.point3.y;
    float dx23 = tr.point2.x - tr.point3.x;
    float dy23 = tr.point2.x - tr.point3.x;
    return sqrtf((dx12 * dx12) + (dy12 * dy12))
            + sqrtf((dx13 * dx13) + (dy13 * dy13))
            + sqrtf((dx23 * dx23) + (dy23 * dy23));
}

float trarea(struct triangle tr)
{
    float dx12 = tr.point1.x - tr.point2.x;
    float dy12 = tr.point1.y - tr.point2.y;
    float dx13 = tr.point1.x - tr.point3.x;
    float dy13 = tr.point1.y - tr.point3.y;
    float dx23 = tr.point2.x - tr.point3.x;
    float dy23 = tr.point2.y - tr.point3.y;
    float a = sqrtf((dx12 * dx12) + (dy12 * dy12));
    float b = sqrtf((dx13 * dx13) + (dy13 * dy13));
    float c = sqrtf((dx23 * dx23) + (dy23 * dy23));
    float p = (a + b + c) / 2;
    return sqrtf(p * (p - a) * (p - b) * (p - c));
}

int intersects(struct circle* c1, int index, int successci, int* b)
{
    int distance, x, y;
    int count = 0;

    for (int i = 0; i < successci; i++) {
        if (i != index) {
            x = c1[index].point.x - c1[i].point.x;
            y = c1[index].point.y - c1[i].point.y;
            distance = sqrtf((x * x) + (y * y));
            if (c1[i].number + c1[index].number >= distance) {
                b[i] = 1;
                count++;
            }
        }
    }
    return count;
}