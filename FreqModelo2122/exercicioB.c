#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define IA 16807
#define IM 2147483647
#define AM ((float)1.0/IM)
#define IQ 127773
#define IR 2836
#define MASK 123459876

struct Nodo 
{
    int Elemento;
    struct Nodo * Prox;
};

typedef struct Nodo * PNodo;

long semente = 12345L;

float ran0(long *idum){
   long k;
   float ans;
  
   *idum ^= MASK;              // XORing with MASK allows use of zero and other simple bit patterns for idum
   k = (*idum)/IQ; 
   *idum = IA*(*idum-k*IQ)-IR*k; // Compute idum=(IA*idum) % IM without overflows
   if (*idum < 0) 
      *idum += IM;              // by Schragefs method.
   ans = AM*(*idum);           // Convert idum to a floating result.
   *idum ^= MASK;              // Unmask before return.
   return ans;
}


int gerarNumeroInteiro(int a, int b){
   float x;
   time_t  seg;
   int inf, sup, k, cardinal;

   inf = a;
   sup = a;
   if (a > b)
      inf = b;
   else
      sup = b;

   seg = time(NULL);
   semente = semente + seg;
   x = ran0(&semente);
   semente = semente + seg;
   x = ran0(&semente);
  
   cardinal = (sup - inf + 1);
   k = (int) (x * cardinal * 10000);
   return  inf + k % cardinal;

}

PNodo criarNodo(int X){
  PNodo P;
  P = (PNodo) malloc(sizeof(struct Nodo));
  if (P == NULL)
    return NULL;
  X= gerarNumeroInteiro(-50,50);
  P->Elemento = X;
  P->Prox = NULL;
  return P;
}

PNodo inserirListaInicio(int X, PNodo L){
  PNodo P;
  P = criarNodo(X);
  if (P == NULL)
    return L;
  P->Prox = L;
  L = P;
  return L;
}

PNodo criarLista(){
  PNodo L;
  L = NULL;
  return L;
}

PNodo criarListaAleatoria(int N){
    int k=1;
    PNodo L; int X ;
    L = criarLista(); // cria lista vazia (L=Null)
    //puts("What");
    while(k<=N) {
        
            L=inserirListaInicio(X, L);
            
            
            k+=1;
       
    }

    return L;
}

void mostrarLista(PNodo L)
{
    PNodo p;
    p= L;
    while(p!= NULL){
        printf("Elemento : %d -----> \n",p->Elemento);
        p= p->Prox;
    }
}

PNodo libertarNodo(PNodo P){
  P->Prox = NULL;
  free(P);
  P = NULL;
  return P;
}

PNodo removerPrimeiroPositivo(PNodo L)
{
    if(L->Elemento >0){
        PNodo aEliminar;
        aEliminar = L;
        L = L -> Prox;
        aEliminar = libertarNodo(aEliminar);
    
        return L;
    }

    PNodo pos;
    pos = L;
    while(pos != NULL)
    {
        if(pos->Prox->Elemento > 0)
        {
            PNodo temp;
            temp = pos ->Prox;
            pos->Prox = temp->Prox;
            temp = libertarNodo(temp);

            return L;
        }

        pos= pos->Prox;
    }

    return L;
}

PNodo inserePenultimo(PNodo L , int X)
{
    if(L->Prox == NULL)
        return L;
    
    PNodo pos;
    pos= L;
    while(pos->Prox != NULL)
    {
        if(pos->Prox->Prox == NULL)
        {
            PNodo novoNodo = criarNodo(X);
            novoNodo->Elemento = X;
            novoNodo->Prox = pos->Prox;
            pos->Prox = novoNodo;
            return L;
        }

        pos = pos->Prox;
    }

    return L;
}



int main()
{
    PNodo L;
    L =criarListaAleatoria(9);
    //puts("What");
    mostrarLista(L);
    //L =removerPrimeiroPositivo(L);
    L = inserePenultimo(L, 25);
    puts("Resultado:\n");
    mostrarLista(L);

    return 0;

}
