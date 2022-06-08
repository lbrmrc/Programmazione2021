typedef struct {
  char numero[11];
  char piano;
  float credito;
} Record;

// questa struttura serve per la parte 2
typedef struct {
  float costoScattoRisposta;
  int durataScatto;
  float costoUnitario;
} Piano;

typedef struct {
  char numero[11];
  Piano piano;
  float credito;
} Utente;

typedef struct nodo {
  Utente dato;
  struct nodo* next;
} Nodo;

typedef Nodo* Lista;

float costo(int secondi, Piano p);
void insTesta(Lista* pl, Utente d);
void aggiorna(Lista l, char numero[11], int durata);
void stampa(Lista l);