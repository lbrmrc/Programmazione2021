#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaEsami.h"

int main(int argc, char* argv[]) {
  FILE* fb;
  Esame r;
  Lista l = NULL;
  int n_piani;
  char numero[11];
  int durata;

  if (argc != 2) {
    printf("Uso: %s fileEsami\n", argv[0]);
    exit(1);
  }

  if ((fb = fopen(argv[1], "rb")) == 0) {
    printf("Errore apertura %s\n", argv[1]);
    exit(2);
  }
  while (fread(&r, sizeof(Esame), 1, fb) == 1) {
    if (r.voto >= 18)
      aggiorna(&l, r);
  }
  fclose(fb);

  stampa(l);
  return 0;
}