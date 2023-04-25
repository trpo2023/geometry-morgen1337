main: obj/src/libgeometry/figmath.o obj/src/libgeometry/check.o obj/src/geometry/main.o
	gcc -Isrc -Wall -Werror obj/src/libgeometry/figmath.o obj/src/libgeometry/check.o obj/src/geometry/main.o -lm -o main

obj/src/geometry/main.o: src/libgeometry/figmath.c src/libgeometry/figmath.h src/libgeometry/check.c src/libgeometry/check.h src/geometry/main.c
	gcc -Isrc -Wall -Werror -c src/geometry/main.c -lm -o obj/src/geometry/main.o

obj/src/libgeometry/check.o: src/libgeometry/figmath.c src/libgeometry/figmath.h src/libgeometry/check.c src/libgeometry/check.h
	gcc -Isrc -Wall -Werror -c src/libgeometry/check.c -lm -o obj/src/libgeometry/check.o

obj/src/libgeometry/figmath.o: src/libgeometry/figmath.c src/libgeometry/figmath.h
	gcc -Isrc -Wall -Werror -c src/libgeometry/figmath.c -lm -o obj/src/libgeometry/figmath.o
