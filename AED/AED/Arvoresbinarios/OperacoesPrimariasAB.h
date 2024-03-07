
typedef struct{
  int   NFatura;
  int   NIF;
  int   Data[3];
  float Pagamento;
}INFOAB;


void mostrarElementoAB (INFOAB);

INFOAB criarElementoAB ();

// comparação de 2 elementos do tipo INFO, segundo o campo NFatura (chave)
//   devolve -1 se primeiro < segundo, 0 se primeiro = segundo, 1 se primeiro > segundo
int compararElementosAB (INFOAB, INFOAB);


#include "OperacoesPrimariasAB.c"

