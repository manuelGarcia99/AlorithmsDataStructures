struct NodoAB {
	INFOAB  Elemento;
	struct NodoAB *Esquerda;
	struct NodoAB *Direita;
};

typedef struct NodoAB *PNodoAB;

// Operações sobre o Nodo


PNodoAB criarNodoAB(INFOAB);


PNodoAB libertarNodoAB(PNodoAB);

// Operações sobre a EAD Árvore Binária

PNodoAB criarAB();

PNodoAB destruirAB(PNodoAB);

int ABVazia(PNodoAB);

int numeroNodosAB (PNodoAB);

int alturaAB (PNodoAB);

void mostrarEmOrdemAB (PNodoAB);

void mostrarPreOrdemAB (PNodoAB);

void mostrarPosOrdemAB (PNodoAB);

PNodoAB pesquisarAB (INFOAB, PNodoAB);

// inserir de forma que fique o mais possível equilibrada
PNodoAB inserirPorAlturaAB (INFOAB, PNodoAB);
		
PNodoAB procurarFolhaAB (PNodoAB, INFOAB *);

PNodoAB removerNodoAB (PNodoAB);


//  X está na árvore binária T
PNodoAB removerAB (INFOAB, PNodoAB);


#include "EADArvoreBinaria.c"

