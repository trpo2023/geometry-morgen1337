#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int main() {
  FILE *myfile;
  myfile = fopen("figures.txt", "r");
  char *type;
  char line[100];
  char line1[100];

  struct circle c1;
  while ((fgets(line, 100, myfile)) != 0) {
    strcpy(line1, line);
    type = strtok(line1, "(");
    printf("%s ", type);
    for (int i = 0; i < 10; i++){
      type[i] = tolower(type[i]);
    }
    printf("%s ", type);
    if (strcmp(type, "circle") == 0) {
      if ((sscanf(line, "circle(%f %f, %f)", &c1.point.x, &c1.point.y,
                  &c1.number)) == 3)
        printf("circle(%f %f  %f) \n", c1.point.x, c1.point.y, c1.number);
      else
        printf("incorrect data of points of circle. Expected NUM NUM, NUM \n");
    } else
            printf("Incorrect type of figure format. Expected: \"Circle\" \n");
  }
  return 0;
}
