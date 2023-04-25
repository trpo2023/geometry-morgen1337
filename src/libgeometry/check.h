#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <libgeometry/figmath.h>
#define SIZE 100
#define CIRCLECODE 7
#define TRIANGLECODE 9


int bracketscheck(char *line, char *type, int columns);

void string_tolower(char *string);

int num_check(char *line, int columns, int typecode, struct triangle *t, struct circle *c1, int *successtr, int *successci);

int strcmptype(char *mainline, int typecode, int columns);

int detecttype(char *mainline, int columns);

void printfigures(struct circle *c1, struct triangle *t, int successci, int successtr);