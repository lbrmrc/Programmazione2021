typedef char CodiceFiscale[17];

typedef struct {
  CodiceFiscale cf;
  int ingressi[3];  // ogni  elemento dell'array è il contatore degli ingressi
                    // per una attività;
                    // si potevano usare anche tre variabili,
                    // così si semplifica leggermente il codice di aggiornamento
  int ingressiNegatiCons, tesseraValida;  // campi usati nella parte 2
} Utente;

typedef struct nodo {
  Utente dato;
  struct nodo* next;
} Nodo;

typedef Nodo* Lista;

void nuovaLista(Lista* pl);
void insTesta(Lista* pl, Utente u);
int aggiorna(Lista* pl, CodiceFiscale c, int attivita);
int stampaResidui(Lista l);
