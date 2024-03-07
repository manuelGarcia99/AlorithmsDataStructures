#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesPrimariasA.h"
#include "ListasLigadasSimples.h"
#include "ListasExerciciosA.h"
#define N 15

int main(){

    PNodo Lista;
    float nota;
    Lista = criarListaAleatoria(N);

    mostrarListaInicio(Lista);

    nota = (Lista->Elemento).notaFreq;

    printf("%i\n", cantidadLista(Lista, nota));

}