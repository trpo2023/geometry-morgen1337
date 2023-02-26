#include <stdio.h>

struct Point{
    int x;
    int y;
};

struct WKTcircle {
    struct Point point;
    int number;
};

int main(){
    FILE *myfile;
    myfile = fopen("sas.txt", "r");
    int a,b;
    struct WKTcircle c1;
    fscanf(myfile, "circle(%d %d, %d)", &c1.point.x, &c1.point.y, &c1.number);
    printf("%d %d  %d", c1.point.x, c1.point.y, c1.number);
    return 0;
}