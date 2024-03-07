
#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesPrimariasA.h"
#include "ListasLigadasSimples.h"
#include "ListasExerciciosA.h"


int main(){
    PNodo Lista, Listanova;
    int TAM, NUM, NIF;
    float somap;//,pagamento, maior,menor;
    // A1.1
    TAM = gerarNumeroInteiro(0, 15);
    printf("TAM = %d\n", TAM);
    Lista = criarListaAleatoria(TAM);

    mostrarListaInicio(Lista);
    printf("Lista para fin\n");
    /*mostrarListaFimRec(Lista);
    
    printf("Introduci un NIF\n");
    scanf("%d", &NUM);

    somap = sumaPagamentos(Lista, NUM);
    printf("La soma es: %f\n", somap);

    printf("Coloque su Pagamento: ");
    scanf("%f", &pagamento);

    printf("La cantidad es: %d\n", quantPagamanetos(Lista,pagamento));

    maior = maiorPagamentoRec(Lista);
    printf("%f\n", maior);

    menor = menorPagamentoRec(Lista);
    printf("%f\n", menor);

    scanf("%i",&NIF);
    Lista = removerFatura(Lista, NIF);      
    mostrarListaInicio(Lista);
    Lista = removerPagamentosmenores(Lista);
    mostrarListaInicio(Lista);
    Lista = removerN(Lista, NUM);*/
    
    //scanf("%i",&NUM);                             //quitar el NUM
    
    scanf("%i",&NIF);

    printf("resultado:%i \n",maiorPagamentoMes(Lista, NIF));


}
  