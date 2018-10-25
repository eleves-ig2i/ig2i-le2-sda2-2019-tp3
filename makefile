all : tp3.exe

tp3.exe : tp3.o abr.o testABR.o util.o
	gcc tp3.o abr.o testABR.o util.o -o tp3.exe

tp3.o :	tp3.c
	gcc -c tp3.c -o tp3.o

abr.o : abr.c
	gcc -c abr.c -o abr.o

testABR.o : testABR.c
	gcc -c testABR.c -o testABR.o

util.o : util.c
	gcc -c util.c -o util.o
clean :
	rm -f *.o *.exe
