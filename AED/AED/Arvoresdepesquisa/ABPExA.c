
#include <stdio.h>
#include <stdlib.h>
#include "AInsercaoBalanceada.h"
#include "Aleatorio.h"
#include "OperacoesPrimariasAB.h"
#include "EADArvoreBinariaPesquisa.h"
#include "ABPorNiveis.h"
#include "ABPExerciciosA.h"

int main(){
    PNodoAB T,MNodo;
    int N,niveis,altura,nodos,Num,b, intervalo;

    N = gerarNumeroInteiro(1, 15);
    printf("N = %d\n", N);
  
    T = criarABPAleatoria(N);

    nodos = numeroNodosAB(T);
    altura = alturaAB(T);
    niveis = alturaAB(T)+1;

    printf("La raiz es:");
    mostrarElementoAB(T->Elemento);
    
    printf("El arbol es:\n");
    //mostrarEmOrdemAB(T);
    
    mostrarPorNiveisAB(T,niveis);
    printf("\nEl numero de nodos: %i\nLa altura es: %i\nLos niveles son: %i\n",nodos,altura,niveis);

    /*MNodo = majorNfatura(T);

    mostrarElementoAB(MNodo->Elemento);
    
    MNodo = menorNfatura(T);
    mostrarElementoAB(MNodo->Elemento);

    
    MNodo = encontrarelemento(T,Num);
    mostrarElementoAB(MNodo->Elemento);

    
    intervalo = numerodointervalo(T, Num, b);
*/
    scanf("%i",&Num);
    scanf("%i",&b);

    intervalo = numerointervaloinvertido(T,Num,b);


    printf("La cantidad en este intervalo es: %i \n", intervalo);

    //printf("La cantidad de numeros mayores a %i \n", Majoresque(T,Num));

}