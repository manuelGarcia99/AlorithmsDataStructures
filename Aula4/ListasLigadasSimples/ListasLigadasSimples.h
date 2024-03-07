
struct Nodo{
  INFO   Elemento;
  struct Nodo *Prox;
};

typedef struct Nodo *PNodo;


PNodo criarNodo(INFO);

PNodo libertarNodo(PNodo);

PNodo criarLista();

int listaVazia(PNodo);

void mostrarListaInicio(PNodo);

void mostrarListaInicioRec(PNodo);

void mostrarListaFimRec(PNodo);

int tamanhoLista(PNodo);

int tamanhoListaRec(PNodo);

int pesquisarLista(INFO, PNodo);

int pesquisarListaRec(INFO, PNodo);

// X está na lista L
PNodo procurarAntecessor(INFO, PNodo);

// X está na lista L
PNodo procurarAntecessorRec(INFO, PNodo);

PNodo inserirListaInicio(INFO, PNodo);

PNodo inserirListaFim(INFO, PNodo);

// assume-se que a lista está ordenada por ordem crescente
PNodo procurarAntecessorOrdem(INFO, PNodo);

PNodo inserirListaOrdem(INFO, PNodo);

// remover X da lista L, em que X está na lista
PNodo removerLista(INFO, PNodo);

// atualiza os dados do elemento da lista que tem a chave de X
void atualizarLista(INFO, PNodo);

// liberta todos os nodos da lista, devolvendo-a vazia
PNodo libertarLista(PNodo);

float somaPagamentos(PNodo L, int Num);
int quantPagamentos(PNodo L, float Pag);
float menorPagamentoRec(PNodo L);
float maiorPagamentoRec(PNodo L);
PNodo removerNIF(PNodo L, int NIF);
PNodo removerTodosPequenos(PNodo L, int minimo);
PNodo removerTodosComNum(PNodo L , int Num);
PNodo divideEmDois(PNodo L , int Num);

PNodo ordenaIter(PNodo L);

int contem(int NFatura, PNodo L);

PNodo removerMaiorQue(PNodo L , int X);

PNodo removeSegundoNif(PNodo L, int Num);

int pagamentoEntre(PNodo L , float pagamentoMinimo , float pagamentoMaximo );

PNodo pagamentoInflacionado(PNodo L, float aumentoCima , float aumentoBaixo);

PNodo pobreMaisRico(PNodo L , float maximo);

PNodo segundoMaior(PNodo L);

PNodo removePrimeiroEUltimo(PNodo L);

PNodo removeTodosMenosOsExtremos(PNodo L);

PNodo ultimoParaSegundo(PNodo L);

PNodo apagaLista(PNodo L);

PNodo inverteLista(PNodo L);

PNodo apagaNesimo(PNodo L, int index);

PNodo concatenarListasEOrdenarNFat(PNodo,PNodo);

#include "ListasLigadasSimples.c"
