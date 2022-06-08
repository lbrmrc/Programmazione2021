#include <stdio.h>
#include <string.h>

#include "listaUtenti.h"

#define N_PIANI_MAX 10

int main(int argc, char* argv[]) {
  FILE *fb, *ft;
  Record r;
  Lista l = NULL;
  Piano piani[N_PIANI_MAX];
  int n_piani;
  char numero[11];
  int durata;

  // parte 2
  if (argc > 3) {
    // se è fornito il terzo argomento leggo i piani dal file
    fb = fopen(argv[3], "rb");
    n_piani = fread(piani, sizeof(Piano), N_PIANI_MAX, fb);
    fclose(fb);
  } else {
    // se il terzo argomento non è fornito uso i piani tariffari predefiniti
    n_piani = 2;
    piani[0].costoScattoRisposta = 0.15;
    piani[0].durataScatto = 60;
    piani[0].costoUnitario = 0.08;

    piani[1].costoScattoRisposta = 0.0;
    piani[1].durataScatto = 0;
    piani[1].costoUnitario = 0.12;
  }

  fb = fopen(argv[1], "rb");
  // creo la lista degli utenti
  while (fread(&r, sizeof(Record), 1, fb)) {
    Utente u;
    int indice = r.piano - 'A';
    if (indice < n_piani) {
      strcpy(u.numero, r.numero);
      u.piano = piani[indice];
      u.credito = r.credito;
      // l'ordine non è specificato
      insTesta(&l, u);
    }
  }
  fclose(fb);

  ft = fopen(argv[2], "rt");
  // per ogni chiamata
  while (fscanf(ft, "%s%d", numero, &durata) == 2)
    // scalo l'importo dal credito dell'utente chiamante
    aggiorna(l, numero, durata);
  fclose(ft);

  stampa(l);
  return 0;
}