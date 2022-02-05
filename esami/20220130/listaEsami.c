#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaEsami.h"

void nuovaLista(Lista* pl) {
  *pl = NULL;
}

void insTesta(Lista* pl, Studente d) {
  Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
  aux->dato = d;
  aux->next = *pl;
  *pl = aux;
}

Esito esito(int pratico, int teorico) {
  Esito e;
  e.superato = pratico >= 12 && teorico >= 6;
  e.somma = pratico + teorico;
  return e;
}

int confrontoEsiti(Esito e1, Esito e2) {
  // <(=,>) 0 se e1 peggiore (uguale, migliore) rispetto a e2
  // un esito è migliore di un altro se l'uno corrisponde a esame superato e l'altro no
  // o, a parità di superamento, se ha somma dei punteggi maggiore
  if (e1.superato != e2.superato)
    return e1.superato - e2.superato;
  else
    return e1.somma - e2.somma;
}

int confrontoStudenti(Studente s1, Studente s2) {
  // se l'esito è diverso riporta il confronto fra gli esiti
  int ce = confrontoEsiti(esito(s1.pratico, s1.teorico),
                          esito(s2.pratico, s2.teorico));
  if (ce != 0)
    return ce;
  else
  // altrimenti la differenza fra le matricole
    return s1.matricola - s2.matricola;
}

void aggiorna(Lista* pl, Record v) {
  while (*pl != NULL && (*pl)->dato.matricola != v.matricola)
    pl = &(*pl)->next;
  if (*pl == NULL) {
    Studente d;
    d.matricola = v.matricola;
    d.pratico = -1;
    d.teorico = -1;
    insTesta(pl, d);
  }
  switch (v.prova) {
    case 'P':
      (*pl)->dato.pratico = v.punteggio;
      break;
    case 'T':
      (*pl)->dato.teorico = v.punteggio;
      break;
  }
}

void insOrd(Lista* pl, Studente s) {
  while (*pl && confrontoStudenti((*pl)->dato, s) > 0)
    pl = &(*pl)->next;
  insTesta(pl, s);
}

void elimTesta(Lista* pl) {
  Nodo* aux = *pl;
  (*pl) = (*pl)->next;
  free(aux);
}

void insertionSort(Lista* pl) {
  Lista lOrd;
  nuovaLista(&lOrd);
  while (*pl) {
    insOrd(&lOrd, (*pl)->dato);
    elimTesta(pl);
  }
  *pl = lOrd;
}

void stampa(Lista l) {
  while (l != NULL) {
    Esito e = esito(l->dato.pratico, l->dato.teorico);
    printf("%d ", l->dato.matricola);

    if (e.superato) {
      if (e.somma > 30)
        printf("30 e lode\n");
      else
        printf("%d\n", e.somma);
    } else
      printf("non superato\n");
    l = l->next;
  }
}