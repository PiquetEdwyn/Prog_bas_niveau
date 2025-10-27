# Documentation de GNU Make : https://www.gnu.org/software/make/manual/
# L'option -Wall permet d'indiquer tous les messages d'avertissement

foot : main.o equipe.o equipe_alloc_dyn.o
		gcc -o foot main.o equipe.o equipe_alloc_dyn.o

main.o : main.c equipe.h
		gcc -c main.c -Wall

equipe.o : equipe.c equipe.h
		gcc -c equipe.c -Wall

clean :
		del foot.exe main.o equipe.o equipe_alloc_dyn.o

equipe_alloc_dyn.o : equipe_alloc_dyn.c equipe_alloc_dyn.h
		gcc -c equipe_alloc_dyn.c -Wal