typedef struct {
  int matricola;
  int punteggio;
  char prova;
} Record;

typedef struct {
  int matricola;
  int teorico;
  int pratico;
} Studente;

typedef struct {
  int superato;
  int somma;
} Esito;


typedef struct nodo {
  Studente dato;
  struct nodo* next;
} Nodo;

typedef Nodo* Lista;

void nuovaLista(Lista* pl);
void aggiorna(Lista* pl, Record v);
void insertionSort(Lista* pl);
void stampa(Lista l);
