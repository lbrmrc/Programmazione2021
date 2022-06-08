#include <stdio.h>
#include <stdlib.h>

#include "listaNazioni.h"

int main(int argc, char* argv[]) {
  FILE* fp;
  Lista l;
  char primo[LUNGHEZZA], secondo[LUNGHEZZA], terzo[LUNGHEZZA];
  if (argc != 2) {
    printf("Uso: %s fileRisultati\n", argv[0]);
    exit(1);
  }
  if ((fp = fopen(argv[1], "rt")) == NULL) {
    printf("Errore apertura %s\n", argv[1]);
    exit(2);
  }
  nuovaLista(&l);
  // solita reduce(aggiorna,[],file)
  while (fscanf(fp, "%s%s%s", primo, secondo, terzo) == 3){
    aggiorna(&l, primo, Oro);
    aggiorna(&l, secondo, Argento);
    aggiorna(&l, terzo, Bronzo);
    }
  fclose(fp);
  stampa(l);
  return 0;
}
