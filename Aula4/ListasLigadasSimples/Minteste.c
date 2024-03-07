#include<stdio.h>
#include<stdlib.h>
#include"Aleatorio.h"
#include"OperacoesPrimariasA.h"
#include"ListasLigadasSimples.h"
#include"ListasExerciciosA.h"
typedef struct {
    int numAluno;
    float notaFreq;
    float notaPratica;
    int aprovado;
} INFO;

struct Nodo {
    INFO Elemento;
    struct Nodo *Prox;
};

typedef struct Nodo * PNodo;

int numDeElementosGrandeNF(PNodo L, float NF);

PNodo criarListaAleatoria(int N);

int pesquisarLista(INFO X , PNodo L);

PNodo inserirListaInicio(INFO X , PNodo L);

PNodo criarNodo(INFO X);

void main(){
    PNodo L =criarListaAleatoria(15);
    PNodo p;
    p= L;
    while(p != NULL){
        printf("Numero\t NotaFreq\t NotaPratica\t Estado\t\n");
        printf("%d\t %f\t %f\t %s\n",p->Elemento.numAluno,p->Elemento.notaFreq,p->Elemento.notaFreq,
        (p->Elemento.aprovado) ? "Aprovado" : "Reprovado");

        p= p->Prox;
    }

}

PNodo criarNodo(INFO X){
  PNodo P;
  P = (PNodo) malloc(sizeof(struct Nodo));
  if (P == NULL)
    return NULL;
  P->Elemento = X;
  P->Prox = NULL;
  return P;
}

PNodo inserirListaInicio(INFO X , PNodo L){
    PNodo P;
    P = criarNodo(X);
    if (P == NULL)
        return L;
    P->Prox = L;
    L = P;
    return L;
}

int pesquisarLista(INFO X ,PNodo L){
    PNodo p;
    p= L;
    while(p!= NULL)
    {
        if(p->Elemento.numAluno == X.numAluno)
        {
            return 1;
        }
        p=p->Prox;
    }
    return 0;
}

PNodo criarListaAleatoria(int N){
    int k=1;
    PNodo L; INFO X;
    L = criarLista(); // cria lista vazia (L=Null)
    while(k<=N) {
        X.aprovado=gerarNumeroInteiro(0,1);
        X.notaFreq= gerarNumeroReal(0,16);
        X.notaPratica = gerarNumeroReal(0,4);
        X.numAluno = gerarNumeroInteiro(1000, 2000);
        if(pesquisarLista(X,L)==0) {
            L=inserirListaInicio(X, L);
            k+=1;
        }
    }

    return L;
}

int numDeElementosGrandeNF(PNodo L, float NF)
{
    int contador= 0;
    PNodo p;
    p= L;
    while( p != NULL)
    {   
        if(p->Elemento.notaFreq > NF)
        {
            contador++;
        }

        p= p->Prox;
    }

    return contador;
}