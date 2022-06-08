#define LUNGHEZZA 21

typedef struct
{
  char nome[LUNGHEZZA];
  int ori;
  int argenti;
  int bronzi;
} Nazione;

typedef struct nodo
{
  Nazione dato;
  struct nodo *next;
} Nodo;

typedef Nodo *Lista;

typedef enum
{
  Oro,
  Argento,
  Bronzo
} Medaglia;

void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, char nome[], Medaglia medaglia);
void stampa(Lista l);
