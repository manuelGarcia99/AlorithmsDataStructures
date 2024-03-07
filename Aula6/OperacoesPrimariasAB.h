
typedef struct{
  int   NFatura;
  int   NIF;
  int   Data[3];
  float Pagamento;
}INFOAB;


void mostrarElementoAB (INFOAB);

INFOAB criarElementoAB ();

// comparação de 2 elementos do tipo INFO, segundo o campo NFatura (chave)
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementosAB (INFOAB, INFOAB);


#include "OperacoesPrimariasAB.c"