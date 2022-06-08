palestra: listaUtenti.o main.o
	gcc -g -o palestra listaUtenti.o main.o

main.o: main.c listaUtenti.o
	gcc -g -c main.c

listaUtenti.o: listaUtenti.c listaUtenti.h
	gcc -g -c listaUtenti.c

