typedef struct {
  int giorno;
  int mese;
  int anno;
  char insegnamento[50];
  int voto;
} Esame;

typedef struct {
  int giorno;
  int mese;
  int anno;
} Data;

typedef struct nodo {
  Esame dato;
  struct nodo* next;
} Nodo;

typedef Nodo* Lista;

void nuovaLista(Lista* pl);
void aggiorna(Lista *pl, Esame r);
void stampa(Lista l);