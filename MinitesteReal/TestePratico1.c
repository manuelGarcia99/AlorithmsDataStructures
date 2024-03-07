// Numero do estudante:
// Nome do estudante:

#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesPrimarias.h"
#include "ListasLigadasSimples.h"

float media(PNodo L,int num);
// implementar as funções neste local
PNodo criarListaAleatoria (int N){
  int k;
  PNodo L;
  INFO X;
  L = criarLista();
  for (k = 1; k <= N; k++){
    X = criarElemento();
    L = inserirListaInicio(X, L);
  }
  return L;
}

// função da pergunta 1
float media(PNodo L,int num){
  PNodo p;
  p= L;
  float resultado, somatorio= 0;
  int contador=0;
  while(p!= NULL){
    if(p->Elemento.aprovado == num)
    {
      somatorio += p->Elemento.notaPratica;
      contador++;
    }
    p= p->Prox;
  }
  return somatorio / (float) contador;
}
// programa principal
int main()
{
  //A
  PNodo L = criarListaAleatoria(12);
  //B
  mostrarListaInicio(L);
  //C
  int ap = L->Prox->Elemento.aprovado;
  //D
  float mediaPedida = media(L,ap);
  //E
  printf("Media Pedida : %f\n", mediaPedida);

}
