
#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesPrimariasAB.h"
#include "EADArvoreBinaria.h"
#include "ABExerciciosA.h"

int main(){
  PNodoAB T;
  int N, numNodos ,Altura , Nivel, niveis, numEsq , numDir;
  
  // Ex. 1
  N = gerarNumeroInteiro(0, 15);
  printf("N = %d\n",N);

  T = criarABAleatoria(N);
  printf("Mostrar raiz:");
  mostrarElementoAB(T->Elemento);
  //printf("Mostrar em ordem\n");
  //mostrarEmOrdemAB(T);
  printf("Mostrar pre ordem\n");
  mostrarPreOrdemAB(T);
  //printf("Mostrar pos ordem\n");
  //mostrarPosOrdemAB(T);
    //A.2
    numNodos = numeroNodosAB(T);
    printf("Numero de nodos = %d\n",numNodos);
    Altura = alturaAB(T);
    printf("Altura = %d\n",Altura);
    niveis = Altura +1;
    printf("Numero de niveis = %d\n", niveis);
    //A.3
    numNodoFilhos(T, &numEsq, &numDir);
    printf("Numero de nodos esquerda = %d\n", numEsq);
    printf("Numero de nodos direita = %d\n",numDir);      
    //A.4
    printf("Numero de iguais a raiz: %d\n",quantosIguais(T,T->Elemento.NIF));
}