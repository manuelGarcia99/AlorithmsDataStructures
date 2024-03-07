#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesPrimariasA.h"
#include "ListasLigadasSimples.h"
#include "ListasExerciciosA.h"


int main(){
  PNodo Lista;
  int TAM;
  
  // A1.1
  TAM = gerarNumeroInteiro(0, 15);
  printf("TAM = %d\n\n", TAM);
  Lista = criarListaAleatoria(TAM);

  
}