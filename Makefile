CFLAGS = -Isrc -Ithirdparty -Wall -Werror

main: obj/src/libgeometry/figmath.o obj/src/libgeometry/check.o obj/src/geometry/main.o
	gcc $(CFLAGS) obj/src/libgeometry/figmath.o obj/src/libgeometry/check.o obj/src/geometry/main.o -lm -o main

test: src/libgeometry/figmath.c src/libgeometry/figmath.h src/libgeometry/check.c src/libgeometry/check.h obj/src/test1/main.o
	gcc $(CFLAGS) obj/src/libgeometry/figmath.o obj/src/libgeometry/check.o obj/src/test1/main.o -lm -o test

obj/src/geometry/main.o: src/libgeometry/figmath.c src/libgeometry/figmath.h src/libgeometry/check.c src/libgeometry/check.h src/geometry/main.c
	gcc $(CFLAGS) -c src/geometry/main.c -lm -o obj/src/geometry/main.o

obj/src/libgeometry/check.o: src/libgeometry/figmath.c src/libgeometry/figmath.h src/libgeometry/check.c src/libgeometry/check.h
	gcc $(CFLAGS) -c src/libgeometry/check.c -lm -o obj/src/libgeometry/check.o

obj/src/libgeometry/figmath.o: src/libgeometry/figmath.c src/libgeometry/figmath.h
	gcc $(CFLAGS) -c src/libgeometry/figmath.c -lm -o obj/src/libgeometry/figmath.o

obj/src/test1/main.o: thirdparty/ctest.h test1/main.c
	gcc $(CFLAGS) -c test1/main.c -o obj/src/test1/main.o