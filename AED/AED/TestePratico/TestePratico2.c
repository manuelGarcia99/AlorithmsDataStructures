
/*****************************************************/
// Número de estudante: 47275
// Nome de estudante: Joel Tapia
/****************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesPrimariasAB.h"
#include "EADArvoreBinaria.h"
#include "EADArvoreBinariaPesquisa.h"

// Devolve uma ABP com N elementos 
// do tipo INFOAB gerados aleatoriamente
PNodoAB criarABPAleatoria (int N){
  int k;
  INFOAB X;
  PNodoAB T;
  T = criarAB();
  k = 1;
  while (k <= N){
    X = criarElementoAB();
    if (pesquisarABP(X,T) == 0){
      T = inserirABP(X,T);
      k = k + 1;
    }
  }
  return T;
}
//1...

float maiorFrequencia(PNodoAB T, int x){

float Max = 0;
  while (T != NULL)
  {
    if (x > T->Elemento.numAluno)
    {
      T = T->Esquerda;
    }
    if (x < T->Elemento.numAluno)
    {      
      if (Max < T->Elemento.notaFreq)
      {
        Max = T->Elemento.notaFreq;
      }      
      T = T->Direita;
    }
    return Max;
  }

}

int main(){
  PNodoAB T,Aux;

  int numA = 4200;
  //maiorFrequencia(T,3);
  
  // 2.a)
  T = criarABPAleatoria(22);
  
  // 2.b)
  
  mostrarEmOrdemAB(T);
  
  // 2.c)
  
  if (T->Direita == NULL)
  {
    printf("Nao existe");
  }
  else
    mostrarEmOrdemAB(T->Direita);
  
  // 2.d)
  float max = maiorFrequencia(T,numA);
  
  // 2.e)
  printf("Valor maximo:%f\n",max);
  
}
