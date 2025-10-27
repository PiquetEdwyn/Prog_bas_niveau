jury : jury.o moyennes.o moyennes.o
		gcc -o jury jury.o moyennes.o moyennes.o

jury.o : jury.c moyennes.h
		gcc -c jury.c -Wall

moyennes.o : moyennes.c moyennes.h
		gcc -c moyennes.c -Wall

clean :
		del jury.exe jury.o moyennes.o moyennes.o