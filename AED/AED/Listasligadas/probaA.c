#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesPrimariasA.h"
#include "ListasLigadasSimples.h"
#include "ListasExerciciosA.h"
#define N 15


int main(){

    PNodo Lista,CL;
    int Mes, diferenca;
    
    Lista = criarListaAleatoria(N);
    mostrarListaInicio(Lista);

    CL = Lista->Prox;

    Mes = (CL->Elemento).Data[1];

    diferenca = N - maiorPagamentoMes(Lista,Mes);

    printf("resultado: %i \n", diferenca);


    /*PNodo Lista,CL;
    Lista = criarListaAleatoria(N);
    int A;
    float resultado;
    mostrarListaFimRec(Lista);

    CL = Lista->Prox;

    A= (CL->Elemento).Data[2];

    resultado = maiorPagamentodoAno(Lista, A);

    printf("Valor maximo: %f\n", resultado);*/


}