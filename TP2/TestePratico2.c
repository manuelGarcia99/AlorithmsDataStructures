/*****************************************************/
// Número de estudante:
// Nome de estudante:
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

float comparaFloat(float a , float b){
    if(a >= b)
    return a;
    else 
    return b;
}

float maiorFreq(PNodoAB T, int num){
    if(ABVazia(T)){
        return -1;
    }
    if(T->Elemento.numAluno >= num){
        if(ABVazia(T->Esquerda))
        {
            return -1;
        }
        
            return maiorFreq(T->Esquerda,num);
        

    }
    if(num> T->Elemento.numAluno){
        if(T->Direita==NULL && T->Esquerda==NULL) return T->Elemento.notaFreq;
        if(T->Direita->Elemento.numAluno < num ){
            return ((maiorFreq(T->Esquerda,num) > maiorFreq(T->Direita,num) ?  (T->Elemento.notaFreq > maiorFreq(T->Esquerda,num) ? T->Elemento.notaFreq : maiorFreq(T->Esquerda,num)) : maiorFreq(T->Direita,num)));
        }
        else 
        return (T->Elemento.notaFreq > maiorFreq(T->Esquerda,num) ? T->Elemento.notaFreq : maiorFreq(T->Esquerda,num));
    }
    
}


int main(){

  // 2.a)
    PNodoAB T = criarABPAleatoria(5);
  
  // 2.b)
  mostrarEmOrdemAB(T);
  
  // 2.c)
  mostrarElementoAB(T->Direita->Elemento);
  
  // 2.d)
  float MAX = maiorFreq(T,4200);  
  
  // 2.e)
  printf("\n%f\n",MAX);
  
}


