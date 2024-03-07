
// Numero do estudante:
// Nome do estudante:

#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesPrimarias.h"
#include "ListasLigadasSimples.h"

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

float meiadevalores(PNodo L, int num){

    float resultado = 0;
    if (L == NULL)
    {
        return -1;
    }
    
    while (L != NULL)
    {
        if ((L->Elemento).aprovado == num)
        {
            resultado += (L->Elemento).notaPratica;
        }
        L = L->Prox;
    }
    
    return resultado/2;

}



// programa principal
int main()
{
    PNodo Lista;
    int ap;
    float r;

    Lista = criarListaAleatoria(12);
    
    mostrarListaInicio(Lista);
    
    ap = (Lista->Prox)->Elemento.aprovado;

    r = meiadevalores(Lista, ap);

    printf("Resultado: %f\n", r);
    

}
