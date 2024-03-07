
#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesPrimariasA.h"
#include "ListasLigadasSimples.h"
#include "ListasExerciciosA.h"


int main(){
  PNodo Lista;
  int TAM, Num, quantP;
  float somaPag, Pag, maior;
  
  // A1.1
  TAM = gerarNumeroInteiro(0, 15);//alterar
  printf("TAM = %d\n", TAM);
  Lista = criarListaAleatoria(TAM);
  
  // A.2
  printf("listar inicio para fim:\n");
  mostrarListaInicio(Lista);
  /*printf("listar fim para inicio:\n");
  mostrarListaFimRec(Lista);*/

  // A.3
  /*
  printf("Insira um NIF:");
  scanf("%d", &Num);
  somaPag = somaPagamentos(Lista, Num);
  printf("soma pagamentos = %f\n", somaPag);
*/
  // A.4
  /*
  se der 400 de input, devolve a soma dos pagamentos de mais
de 400 euros
*/
/*  printf("Insira um valor de Pagamentos: ");
  scanf("%f", &Pag);
  quantP = quantPagamentos(Lista, Pag);
  printf("Quant pagamentos=%d\n", quantP);
*/
  // A.5

  //A.6
  

  /*Lista = inserirListaInicio(inicio,Lista);
  mostrarListaInicio(Lista);
  float menor = menorPagamentoRec(Lista);
  printf("%f\n", menor);*/
  //A7
  //A8
  /*float minimo = maiorPagamentoRec(Lista);
  TAM = gerarNumeroInteiro(0, 45);
  printf("TAM = %d\n", TAM);
  PNodo Lista2 = criarListaAleatoria(TAM);
  mostrarListaInicio(Lista2);
  Lista2 =removerTodosPequenos(Lista2,minimo);
  mostrarListaInicio(Lista2);*/
  //A9
  /*
  int teste;
  printf("Numero:\nNIF:");
  scanf(" %d",&teste);
  removerTodosComNum(Lista,teste);
  mostrarListaInicio(Lista);
  */
 //A10
 /*
  int teste;
  printf("Numero:\nSaltos:");
  scanf(" %d",&teste);
  Lista= removerNElementos(Lista,teste);
  mostrarListaInicio(Lista);
*/
//A11
/*  int teste;
  printf("Numero:\nNovo:");
  scanf(" %d",&teste);
  PNodo NovaL= divideEmDois(Lista,teste);
  mostrarListaInicio(Lista);
  printf("-----------------------------\n");
  mostrarListaInicio(NovaL);
  	*/
//A12
  //Lista = ordenaIter(Lista);
  //Lista= inserirListaInicio(Novo,Lista);
  //mostrarListaInicio(Lista);
//A13 A14
  /*int teste ;
  printf("NIFs maiores que x a remover :\n");
  printf("X:");
  scanf(" %d",&teste);
  Lista=removerMaiorQue(Lista,teste); //verificar no remover igual se da
                                      //com uma lista maior que um de um so
                                      //NIF
  mostrarListaInicio(Lista);*/
//A15 
 /*float menorPag , maiorPag;
  printf("No minimo:");
  scanf(" %f",&menorPag);
  printf("No maximo:");
  scanf(" %f",&maiorPag);
  printf("Há %d pagamentos nesse intervalo\n",pagamentoEntre(Lista,menorPag,maiorPag));*/
//A16
  /*float cima , baixo;
  printf("Acrescentar a primeira metade:");
  scanf(" %f",&cima);
  printf("Acrescentar a segunda metade:");
  scanf(" %f",&baixo);
  Lista = pagamentoInflacionado(Lista,cima,baixo);
  mostrarListaInicio(Lista);*/
//A17  
  /*float extremos , meio;
  int porcao;
  printf("Acrescentar nos extremos:");
  scanf(" %f",&extremos);
  printf("Acrescentar no meio se der espaço:");
  scanf(" %f",&meio);
  printf("Numero de elementos em cada extremo a aumentar:");
  scanf(" %d",&porcao);
  Lista = inflacionarExtremos(Lista,extremos,meio,porcao);
  mostrarListaInicio(Lista);*/
 //A18
 /* float maximo;
  printf("O valor que não pode ser ultrapassado:");
  scanf(" %f",&maximo);
  PNodo ListaSenhor = pobreMaisRico(Lista,maximo);
  mostrarListaInicio(ListaSenhor);
  */
  //A19
  /*PNodo segundoMaisRico = segundoMaior(Lista);
  mostrarListaInicio(segundoMaisRico);
  */
  //A20
  //Lista = removePrimeiroEUltimo(Lista);
  //A21
  //Lista = removeTodosMenosOsExtremos(Lista);
  //A22
  //Lista= ultimoParaSegundo(Lista);
  //A23
  //Lista = apagaLista(Lista);
  //A24 inverte ver copiar 5x amanhã
  //Lista= inverteLista(Lista);
  //A25 
  //Lista =apagaNesimo(Lista, 4);
  //A26
  PNodo ListaExtra = criarListaAleatoria(gerarNumeroInteiro(0,15));
  mostrarListaInicio(ListaExtra);
  Lista = concatenarListasEOrdenarNFat(Lista, ListaExtra);
  mostrarListaInicio(Lista);
}