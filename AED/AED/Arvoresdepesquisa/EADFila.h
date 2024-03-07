// tipos de dados

struct NodoFila {
  INFOF   Elemento;
  struct NodoFila *Prox;
};

typedef struct NodoFila *PNodoFila;

// Operações sobre o NodoFila

PNodoFila criarNodoFila (INFOF);

PNodoFila libertarNodoFila (PNodoFila);

// Operações sobre a Fila

PNodoFila criarFila ();

int filaVazia (PNodoFila);

PNodoFila juntar (INFOF, PNodoFila);

PNodoFila remover (PNodoFila);

INFOF frente (PNodoFila);


#include "EADFila.c"
