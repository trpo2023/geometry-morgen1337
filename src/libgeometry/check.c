#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <libgeometry/figmath.h>
#define SIZE 100
#define CIRCLECODE 7
#define TRIANGLECODE 9



int bracketscheck(char *line, char *type, int columns){
  int i = 0;
  int j = 0;
  for(; type[i] != '\0'; i++){
  }
  for (j = i; line[j] != '\0'; j++){
    if (line[j] == '('){
      if (line[j-1] == ' ' || line[j-1] == type[i-1])
      continue;
      else {printf("COLUMN %d: %s ||  Wrong place for \"(\" ", columns, line);
      return 0;}
    }
  }
  for (; 1; j--){
    if (line[j] != ' '){
      if (line[j] == ')'){
      break;}
      }
      else {printf("COLUMN %d: %s ||  Expected \")\"", columns, line);
      return 0;}
  }
  return 1;
}

void string_tolower(char *string){
  for (int i = 0; string[i] != '\0'; i++){
    string[i] = tolower(string[i]);
  }
}


int num_check(char *line, int columns, int typecode, struct triangle *t, struct circle *c1, int *successtr, int *successci){
  float a,b,c,d,e,f,g,h; //для проверки сколько scanf считывает
  int nums;
  if (typecode == CIRCLECODE) {
  nums = sscanf(line, "circle(%f %f, %f)", &a, &b, &c);
  if (nums == 3){
    
        sscanf(line, "circle(%f %f, %f)", &c1->point.x, &c1->point.y, &c1->number);
        *successci = *successci + 1;
        //printf("\n Сircle X = %f, Y = %f, R = %f, Perimetr = %f, Square = %f) \n", a, b, c, 2 * M_PI * c, M_PI * c * c);
      
        return 1;}

      else if (nums == 2 && sscanf(line, "circle(%f %f %f)", &a, &b, &c ) == 3){
        printf("\nCOLUMN %d: %s || A \",\" was expected before 3rd number. Expected   NUM NUM, NUM \n", columns, line);
        return 0;}

     else if (nums == 2){
            printf("\nCOLUMN %d: %s || Error: Only 2 of 3 numbers were found. Expected   NUM NUM, NUM \n", columns, line);
            return 0;}

      else if (nums == 1 && sscanf(line, "circle(%f, %f %f)", &a, &b, &c ) >= 2){
          printf("\nCOLUMN %d: %s || Error: A \",\" was not expected before 2nd number. Expected   NUM NUM, NUM \n", columns, line);
          return 0;}

      else if (nums == 1){
            printf("\nCOLUMN %d: %s || Only 1 of 3 numbers were found. Expected   NUM NUM, NUM \n", columns, line);
            return 0;}

      else if (nums == 0){
            printf("\nCOLUMN %d: %s || Error: No numbers were found. Expected   NUM NUM, NUM \n", columns, line);
            return 0;}
}
  else if (typecode == TRIANGLECODE){
    nums = sscanf(line, "triangle(%f %f, %f %f, %f %f, %f %f)", &a, &b, &c, &d, &e, &f, &g, &h);
    if (nums == 8){
      if (a == g && b == h){
        
      sscanf(line, "triangle(%f %f, %f %f, %f %f, %f %f)", 
      &t->point1.x, &t->point1.y, &t->point2.x, &t->point2.y, &t->point3.x, &t->point3.y, &t->point4.x, &t->point4.y);
      *successtr = *successtr + 1;
      //printf("\n Triangle X1 = %f Y1 = %f, X2 = %f Y2 = %f, X3 = %f Y3 = %f, Perimeter = %f, Area = %f\n", a,b,c,d,e,f, trper(*t), trarea(*t));
      return 1;}
      else
      printf("\nCOLUMN %d: %s || Error: x4 and y4 is not the same as x1 and y1.\n", columns, line);
    }

  } 
  return -1;
  }

int strcmptype(char *mainline, int typecode, int columns){
  int typesize;
  char *type;
  string_tolower(mainline);

  if (typecode == CIRCLECODE)
    {type = "circle";
    typesize = CIRCLECODE;}

  else if (typecode == TRIANGLECODE)
    {type = "triangle";
    typesize = TRIANGLECODE;}

  for (int i = 0; i<typesize-1; i++){
    if (mainline[i] != type[i]){
      printf("COLUMN %d: %s || Incorrect type of figure format. Did you mean: \"%s\"?\n", columns, mainline, type);
      return 1;}
  }
  if (mainline[typesize-1] != '('){
      if (mainline[typesize-1] == ' ')
    printf("COLUMN %d: %s || Expected \"(\" instead of the gap after %s. Expected: \"%s(NUM NUM, NUM)\"\n", columns, mainline, type, type);

    else if (mainline[typesize-1] > '0' && mainline[typesize-1] < '9') // проверка на цифру
      printf("COLUMN %d: %s || Expected a \"(\" before \"%c\" digit.\n", columns, mainline, mainline[typesize-1]);
    else printf("COLUMN %d: %s || Expected a \"(\" instead of \"%c\" character.\n", columns, mainline, mainline[typesize-1]);
    return -1;
  }
  return 0;

}

int detecttype(char *mainline, int columns){
  if (mainline[0] == ' '){
    printf("COLUMN %d: %s || You have to write WKT - format figure in the begining of the string. Expected: \"Circle\", \"Triangle\" in any case.\n", columns, mainline);
    return 0;}
  if (mainline[0] == 'c')
    return CIRCLECODE;
  else if (mainline[0] == 't')
    return TRIANGLECODE;
  else {
    printf("COLUMN %d: %s || No type of figure was found. Expected: \"Circle\", \"Triangle\" in any case.\n", columns, mainline);
    return 0;}
}



void printfigures(struct circle *c1, struct triangle *t, int successci, int successtr){
  printf("__________________Circles:\n");
  for (int i = 0; i < successci; i++){
    int b[100] = {0};
    intersects(c1, i, successci, b);
    printf("%d. circle(%f %f, %f)\n perimeter = %f \n area = %f \n intersects ="
    , i+1, c1[i].point.x, c1[i].point.y, c1[i].number, 2 * M_PI * c1[i].number, M_PI * c1[i].number * c1[i].number);
    for (int j = 0; j < successci; j++){
      if (b[j]){
        printf(" %d.circle(%f %f, %f)", j+1, c1[j].point.x, c1[j].point.y, c1[j].number);
      }
    }
    printf("\n");
  }
  printf("__________________Triangles:\n");
  for (int i = 0; i < successtr; i++){
    printf("%d. triangle(%f %f, %f %f, %f %f, %f %f)\n perimeter = %f \n area = %f \n intersects = \n",
    i+1,t[i].point1.x, t[i].point1.y, t[i].point2.x, t[i].point2.y, t[i].point3.x,
    t[i].point3.y, t[i].point4.x, t[i].point4.y,trper(t[i]), trarea(t[i]) );
  }

}