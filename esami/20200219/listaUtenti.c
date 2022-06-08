#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaUtenti.h"

float costo(int secondi, Piano p) {
  // restituisce il costo di una chiamata
  // dati durata e piano tariffario
  return p.costoScattoRisposta +
         // in questo modo arrotondo al centesimo inferiore
         (int)(p.durataScatto == 0
                   ? p.costoUnitario * 100 / 60 * secondi
                   : (secondi / p.durataScatto + 1) * p.costoUnitario * 100) /
             100.0;
}

void insTesta(Lista* pl, Utente d) {
  Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
  aux->dato = d;
  aux->next = *pl;
  *pl = aux;
}

void aggiorna(Lista l, char numero[11], int durata) {
  // questa funzione non deve creare o eliminare nodi
  // ma solo modificare il contenuto di quelli esistenti
  // quindi si può usare un argomento lista e non puntatore a lista
  while (l && strcmp(l->dato.numero, numero) != 0)
    l = l->next;
  if (!l)
    printf("Numero %s non trovato\n");
  else 
    l->dato.credito -= costo(durata, l->dato.piano);
}

void stampa(Lista l) {
  while (l) {
    printf("%s %.2f\n", l->dato.numero, l->dato.credito);
    l = l->next;
  }
}