#include <stdio.h>
#include <stdlib.h>

struct Point{
    float x;
    float y;
};

struct WKTcircle {
    struct Point point;
    float number;
};

int main(){
    FILE *myfile;
    myfile = fopen("sas.txt", "r");

    char line[100];

    struct WKTcircle c1;
    if ((fgets(line, 100, myfile))){
    sscanf(line, "circle(%f %f, %f)", &c1.point.x, &c1.point.y, &c1.number);
    printf("circle(%f %f  %f) \n", c1.point.x, c1.point.y, c1.number);
    }
    return 0;
}