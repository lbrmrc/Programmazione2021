medagliere: main.o listaNazioni.o
	gcc -g -o medagliere main.o listaNazioni.o

main.o: main.c listaNazioni.h
	gcc -c -g main.c

listaNazioni.o: listaNazioni.c listaNazioni.h
	gcc -c -g listaNazioni.c