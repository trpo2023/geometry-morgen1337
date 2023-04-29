#include <math.h>

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

float trper(struct triangle tr);

float trarea(struct triangle tr);

int intersects(struct circle* c1, int index, int successci, int* b);