#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int numAluno;
    int notas[4];
    int notaFinal;
} ALUNO;
#include "Bib_Info.h"
void main()
{
    ALUNO *v;
    int tam, *V, tamV;
    v = lenvetor(&tam); // 100100
    for (int k = 0; k < tam; k++)
    {
        v[k].notaFinal = maiorElemento(v[k].notas, 4);
    }

    if (guardarAlunos(v, tam) == 0)
    {
        printf("Operacion com suceso; Erro na apertura do archivo \n");
    }
    else 
        printf("Operacao com succeso\n");
    
    printf("El valor mayor es: %d\n", maioNotaFinal(v,tam) );
    int notaK = 17;
 
    printf("Numero de alunos com uma nota mais alta do que %d: %d\n",notaK, quantNotasMaiorK(v,tam,notaK));
    
    
    tamV = vetorNotasFinais(v,tam, &V);

    
    for (int i = 0; i < tamV; i++)
    {
        printf("V[%2d] = %d", i, V[i]);
    }
    
}