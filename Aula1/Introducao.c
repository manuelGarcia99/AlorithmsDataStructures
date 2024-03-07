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
    int tam;
    v = lenvetor(&tam); // 100100
    for (int k = 0; k < tam; k++)
    {
        v[k].notaFinal = maiorElemento(v[k].notas, 4);
        printf("%d\n", v[k].notaFinal);
    }
    guardarAlunos(v, tam);
    printf("Numero mais ou = que 10 : %d\n" , quantNotasMaiorK(v,tam,10));
    printf("Numero mais ou = que 20 : %d\n" , quantNotasMaiorK(v,tam,17));
    printf("Numero mais ou = que 21 : %d\n" , quantNotasMaiorK(v,tam,21));
    

    tam = vetorNotasFinais(v,tam,v);
}
