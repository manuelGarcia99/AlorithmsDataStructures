
#include <stdio.h>
#include <stdlib.h>


#include "Aleatorio.h"
#include "OperacoesPrimariasAB.h"
#include "EADArvoreBinariaPesquisa.h"
#include "ABPorNiveis.h"
#include "ABPExerciciosA.h"




int main(){
  PNodoAB T;
  int N;
  
  N = gerarNumeroInteiro(1, 15);
  printf("N = %d\n", N);
  
  // A.1

  T = criarABPAleatoria(N);
  printf("Raiz:\n");
  mostrarElementoAB(T->Elemento);
  printf("\nMostrar ABP em ordem:\n");
  mostrarEmOrdemAB(T);
  printf("\nNumero de Nodos: %d\nAltura: %d\nNumero de Niveis: %d\n",numeroNodosAB(T),alturaAB(T),alturaAB(T) +1 );
  mostrarPorNiveisAB(T, alturaAB(T) + 1);
  puts("");
  mostrarElementoAB(elementoComMaiorNFatura(T)->Elemento);
  //A4
  mostrarElementoAB(elementoComMenorNFatura(T)->Elemento);
  //A5
  printf("Numero de maiores que 1500 : %d\n",numeroDeMaiores(T,1500));
  //A6 esta nos exercicios nodoComNFatura e também a aplicação iterativa
  //A7
  //A8
  printf("Numero de elementos fora do intervalo : %d\n",numDeElementosForaDoIntervalo(T,1400, 1600));
  //A9
  int qual;
  scanf("%d",&qual);
  T = removerLol(T ,T , qual);///perguyntar
  //puts("DebugMain");
  mostrarPorNiveisAB(T, alturaAB(T)+ 1);
  puts("");
  //A10
  INFOAB * vetor  = (INFOAB *) malloc(sizeof(INFOAB) * numeroNodosAB(T));
  printf("Numero de nodos : %d \n",numeroNodosAB(T));
  
  vetor = criaVetor(T,vetor, numeroNodosAB(T));
  for(int i = 0; i< numeroNodosAB(T) ; i++){
    printf("Nodo %d : NF : %d\n",i,vetor[i].NFatura);
  }
  //A11
  printf("Nivel da folha mais alta: %d\n",folhaMaisAlta(T));
  printf("Nivel da folha mais baixa: %d\n",folhaMaisBaixa(T));
  //A12 e 13 para depois
  //A14
  T= expand(T);
  printf("Numero de nodos : %d \n",numeroNodosAB(T));
  mostrarPorNiveisAB(T, alturaAB(T) + 1);
  puts("");
}