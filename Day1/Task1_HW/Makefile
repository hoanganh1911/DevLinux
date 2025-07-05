all: main_static main_shared
strutils.o: strutils.c strutils.h
	gcc -c strutils.c -o strutils.o
main.o: main.c strutils.h
	gcc -Wall -c main.c -o main.o
libstrutils.so: strutils.o
	gcc -shared -o libstrutils.so strutils.o
libstrutils.a: strutils.o
	ar rcs libstrutils.a strutils.o

main_static: main.o libstrutils.a
	gcc -o main_static main.o -L. -lstrutils -static

main_shared: main.o libstrutils.so
	gcc -o main_shared main.o -L. -lstrutils

clean:
	rm -f *.o *.a *.so main_static main_shared