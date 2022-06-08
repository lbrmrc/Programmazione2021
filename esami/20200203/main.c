#include <stdio.h>
#include <stdlib.h>

#include "listaUtenti.h"

int main(int argc, char* argv[]) {
  Utente u;
  int i;
  CodiceFiscale cf;
  int attivita;
  Lista l;
  if (argc != 3) {
    printf("Uso: %s file_cf file_ingressi\n", argv[0]);
    exit(1);
  }
  for (i = 0; i < 3; i++)
    u.ingressi[i] = 4;
  u.ingressiNegatiCons = 0;
  u.tesseraValida = 1;
  FILE* f;
  nuovaLista(&l);
  f = fopen(argv[1], "rb");
  if (f == NULL){
    printf("Errore apertura file %s\n", argv[1]);
    exit(2);
  }
  // metto nella lista una tessera per ogni codice fiscale
  while (fread(u.cf, 17, 1, f) == 1)
    // gli altri campi sono stati inizializzati prima
    insTesta(&l, u);
  fclose(f);

  f = fopen(argv[2], "rt");
  if (f == NULL){
    printf("Errore apertura file %s\n", argv[2]);
    exit(3);
  }
  // gestisco ogni tentativo di ingresso
  while (fscanf(f, "%s%d", cf, &attivita) == 2) {
    if (!aggiorna(&l, cf, attivita))
      printf("Codice Fiscale %s, attivita` %d: Accesso negato\n", cf, attivita);
  }
  // stampo le tessere con il numero di ingressi residui per ogni attività
  stampaResidui(l);
  return 0;
}