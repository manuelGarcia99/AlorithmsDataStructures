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


//1

int maisqueNUm(PNodoAB T, int num){
  if(T == NULL){return 0;}


  if(T->Elemento.numAluno < num){
    return maisqueNUm(T->Direita, num);
  }

  if(T->Elemento.numAluno > num ){
    if(T->Elemento.aprovado == 1) return 1 + maisqueNUm(T->Esquerda, num)+ maisqueNUm(T->Direita, num);
    else{return maisqueNUm(T->Esquerda, num)+ maisqueNUm(T->Direita, num);}
    
  }
  if(T->Elemento.numAluno == num && T->Elemento.aprovado == 1){
    if(T->Elemento.aprovado == 1) return 1 + maisqueNUm(T->Direita, num);
    else{return maisqueNUm(T->Direita, num);}
  }

  

  
}


int main(){
  PNodoAB T;
  
  // 2.a)
  T = criarABPAleatoria(25);
  
  
  // 2.b)

  mostrarEmOrdemAB(T);
  
  
  // 2.c)

  printf("\nSub-árvore esquerda de T: ");

  if(T->Esquerda == NULL){
    printf("No element");
  }
  else{
    mostrarElementoAB(T->Esquerda->Elemento);
  }
  
  
  
  // 2.d)

  int q = maisqueNUm(T, 4050);

  
  // 2.e)

  printf("\nQuantidade de alunos: %d\n", q);

  
}