#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Point {
    float x;
    float y;
};

struct WKTcircle {
    struct Point point;
    float number;
};

int main()
{
    FILE* myfile;
    myfile = fopen("sas.txt", "r");
    char* type;
    char line[100];
    char line1[100];

    struct WKTcircle c1;
    while ((fgets(line, 100, myfile)) != 0) {
        strcpy(line1, line);
        type = strtok(line1, "(");
        if (strcmp(type, "circle") == 0) {
            if ((sscanf(line,
                        "circle(%f %f, %f)",
                        &c1.point.x,
                        &c1.point.y,
                        &c1.number))
                == 3)
                printf("circle(%f %f  %f) \n",
                       c1.point.x,
                       c1.point.y,
                       c1.number);
            else
                printf("incorect data of points of circle \n");
        } else
            printf("incorect type format \n");
    }
    return 0;
}