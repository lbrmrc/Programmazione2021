#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaUtenti.h"

void nuovaLista(Lista* pl) {
  *pl = NULL;
}

void insTesta(Lista* pl, Utente u) {
  Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
  aux->dato = u;
  aux->next = *pl;
  *pl = aux;
}

int aggiorna(Lista* pl, CodiceFiscale c, int attivita) {
  // aggiorna lo stato della tessera
  // restituisce 1 per ingresso consentito, 0 per ingresso negato

  // salto tutti i codici fiscali diversi
  while (*pl && strcmp((*pl)->dato.cf, c) != 0)
    pl = &(*pl)->next;
    // se non ho terminato la lista
  if (*pl) {
    // se la tessera non è stata annullata e ci sono ancora ingressi per l'attività
    if ((*pl)->dato.tesseraValida && (*pl)->dato.ingressi[attivita - 1] > 0) {
      // decremento gli ingressi per l'attività
      (*pl)->dato.ingressi[attivita - 1]--;
      // resetto il contatore degli ingressi negati
      (*pl)->dato.ingressiNegatiCons = 0;
      // dico al chiamante che l'ingresso è consentito
      return 1;
    } else {
      // altrimenti incremento il contatore degli ingressi negati
      (*pl)->dato.ingressiNegatiCons++;
      // se sono almeno tre annullo la tessera
      if ((*pl)->dato.ingressiNegatiCons >= 3)
        (*pl)->dato.tesseraValida = 0;
        // dico al chiamante che l'ingresso è negato
      return 0;
    }
  } else {
    printf("Codice fiscale %s non trovato\n");
    return 0;
  }
}

int stampaResidui(Lista l) {
  while (l) {
    printf("%s: %d %d %d", l->dato.cf, l->dato.ingressi[0], l->dato.ingressi[1],
           l->dato.ingressi[2]);

           // se la tessera è stata annullata lo segnalo
    if (!(l->dato.tesseraValida))
      printf(" (tessera annullata)");
    printf("\n");
    l = l->next;
  }
}