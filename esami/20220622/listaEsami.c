#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaEsami.h"

void nuovaLista(Lista* pl) {
  *pl = NULL;
}

void insTesta(Lista* pl, Esame d) {
  Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
  aux->dato = d;
  aux->next = *pl;
  *pl = aux;
}

int diffDate(Data d1, Data d2) {
  if (d1.anno != d2.anno)
    return d1.anno - d2.anno;
  if (d1.mese != d2.mese)
    return d1.mese - d2.mese;
  return d1.giorno - d2.giorno;
}

void aggiorna(Lista* pl, Esame r) {
  while (*pl && strcmp((*pl)->dato.insegnamento, r.insegnamento) != 0)
    pl = &(*pl)->next;

  if (*pl == NULL)
    insTesta(pl, r);
  else {
    Data d1 = {(*pl)->dato.giorno, (*pl)->dato.mese, (*pl)->dato.anno},
    d2 = {r.giorno, r.mese, r.anno};
    if (diffDate(d1,d2) < 0){
      (*pl)->dato.giorno = r.giorno;
      (*pl)->dato.mese = r.mese;
      (*pl)->dato.anno = r.anno;
      (*pl)->dato.voto = r.voto;
    }
  }
}

void stampa(Lista l) {
  int n_esami = 0, somma = 0;

  while (l) {
    n_esami++;
    somma += l->dato.voto;
    printf("%s %d/%d/%d %d\n", l->dato.insegnamento, l->dato.giorno, l->dato.mese,
           l->dato.anno, l->dato.voto);
    l = l->next;
  }
  printf("\nMedia: %.2f\n", (float)somma / n_esami);
}