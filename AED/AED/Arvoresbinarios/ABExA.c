
#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesPrimariasAB.h"
#include "EADArvoreBinaria.h"
#include "ABExerciciosA.h"

int main(){
    PNodoAB T;
    int N;
    
    // Ex. 1
    N = gerarNumeroInteiro(1, 15);
    printf("N = %d\n", N);

    T = criarABAleatoria(N);

    printf("Mostrar el arbol en orden: \n");
    mostrarEmOrdemAB(T);
    printf("-------------\n");
    mostrarPreOrdemAB(T);
    printf("-------------\n");
    mostrarPosOrdemAB(T);
}