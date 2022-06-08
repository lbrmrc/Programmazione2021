#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaNazioni.h"

void nuovaLista(Lista *pl)
{
  *pl = NULL;
}

void insTesta(Lista *pl, Nazione d)
{
  Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
  aux->dato = d;
  aux->next = *pl;
  *pl = aux;
}

void aggiorna(Lista *pl, char nome[], Medaglia medaglia)
{
  while (*pl && strcmp((*pl)->dato.nome, nome) != 0)
    pl = &(*pl)->next;
  if (*pl == NULL)
  {
    Nazione d;
    strcpy(d.nome, nome);
    d.ori = d.argenti = d.bronzi = 0;
    insTesta(pl, d);
  }
  switch (medaglia)
  {
  case Oro:
    (*pl)->dato.ori++;
    break;
  case Argento:
    (*pl)->dato.argenti++;
    break;
  case Bronzo:
    (*pl)->dato.bronzi++;
    break;
  }
}

void stampa(Lista l)
{
  while (l != NULL)
  {
    printf("%s: %d ori, %d argenti, %d bronzi\n", l->dato.nome, l->dato.ori, l->dato.argenti, l->dato.bronzi);
    l = l->next;
  }
}