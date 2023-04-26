CFLAGS = -fPIE -Isrc -Ithirdparty -Wall -Wextra -Werror

bin/main: obj/src/geometry/main.o obj/src/libgeometry/libmain.a
	gcc $(CFLAGS) obj/src/libgeometry/figmath.o obj/src/libgeometry/check.o obj/src/geometry/main.o -lm -o bin/main

test: obj/src/test1/main.o obj/src/test1/libmain.a
	gcc $(CFLAGS) obj/src/libgeometry/figmath.o obj/src/libgeometry/check.o obj/src/test1/main.o -lm -o bin/test

obj/src/geometry/main.o: src/geometry/main.c
	gcc $(CFLAGS) -MMD -c src/geometry/main.c -o $@

obj/src/libgeometry/libmain.a: obj/src/libgeometry/check.o obj/src/libgeometry/figmath.o
	ar rcs $@ $^

obj/src/test1/libmain.a: obj/src/libgeometry/check.o obj/src/libgeometry/figmath.o obj/src/geometry/main.o
	ar rcs $@ $^
	
obj/src/libgeometry/check.o: src/libgeometry/check.c
	gcc $(CFLAGS) -MMD -c src/libgeometry/check.c  -o obj/src/libgeometry/check.o

obj/src/libgeometry/figmath.o: src/libgeometry/figmath.c
	gcc $(CFLAGS) -MMD -c src/libgeometry/figmath.c -o obj/src/libgeometry/figmath.o

obj/src/test1/main.o: src/test1/main.c
	gcc $(CFLAGS) -MMD -c src/test1/main.c -o obj/src/test1/main.o

.PHONY: clean

-include obj/src/geometry/main.d obj/src/libgeometry/check.d obj/src/libgeometry/figmath.d obj/src/test1/main.d

clean:
	rm obj/src/geometry/main.o obj/src/libgeometry/check.o obj/src/libgeometry/figmath.o obj/src/test1/main.o obj/src/geometry/main.d obj/src/libgeometry/check.d obj/src/libgeometry/figmath.d obj/src/test1/main.d
