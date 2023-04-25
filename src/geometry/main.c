#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <libgeometry/check.h>

int main() {
  FILE *myfile;
  myfile = fopen("figures.txt", "r");
  if (myfile == NULL){
    printf("A file named \"figures.txt\" was not found \n");
    return -1;
  }
  char *type;
  char line[SIZE];
  char line1[SIZE];
  char *estr;
  struct circle c1[SIZE] = {0};
  struct triangle t[SIZE] = {0};
  int columns = 0;
  int typecode;
  int successtr = 0;
  int successci = 0;


  while (1) {
    estr = fgets(line, SIZE, myfile);
     if (estr == NULL)
      {
         if ( feof (myfile) != 0)
         {  
            printf ("\nЧтение файла закончено, %d кругов и %d треугольников записано\n", successci , successtr);
            break;
         }
         else
         {
            printf ("\nОшибка чтения из файла\n");
            break;
         }
      }

    columns++;
    strcpy(line1, line);

    type = strtok(line1, "(");

    string_tolower(line);
    string_tolower(type);
    typecode = detecttype(line, columns);
    if (typecode) {
      if (!strcmptype(line, typecode, columns)){
      if (bracketscheck(line, type, columns)){
       num_check(line, columns, typecode, &(t[successtr]), &(c1[successci]), &successtr, &successci);}
    }
}

}
printfigures(c1, t, successci, successtr);
  return 0;
}
