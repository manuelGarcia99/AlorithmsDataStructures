#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define IA 16807
#define IM 2147483647
#define AM ((float)1.0/IM)
#define IQ 127773
#define IR 2836
#define MASK 123459876
#define TAM_MAX_NUM 3

struct NodoAB {
int Elemento;
struct NodoAB *Esquerda;
struct NodoAB *Direita;
};
typedef struct NodoAB *PNodoAB;


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

int alturaAB (PNodoAB T) {
	int  altEsq, altDir;
	if (T == NULL)
		return -1;
	altEsq = alturaAB(T->Esquerda);
	altDir = alturaAB(T->Direita);
	if (altEsq > altDir)
		return altEsq + 1;	// altura da esquerda + raiz
	else
		return altDir + 1;	// altura da direita + raiz
}



PNodoAB criarNodoAB(int X){
	PNodoAB P;
	P = (PNodoAB) malloc(sizeof(struct NodoAB));
	if (P == NULL)
		return  NULL;
	P->Elemento = X;
	P->Esquerda = NULL;
	P->Direita = NULL;
	return P;
}


PNodoAB pesquisarAB (int X, PNodoAB T) {
	PNodoAB P;
	if (T == NULL)
		return NULL;
	if (( T->Elemento) == X)  // X = T->Elemento
		return T;
	P = pesquisarAB(X, T->Esquerda);
	if (P != NULL)
		return P;
	return pesquisarAB(X, T->Direita);
}

PNodoAB inserirPorAlturaAB (int X, PNodoAB T) {
	if (T == NULL) {
		T = criarNodoAB(X);
		return T;
	}
	if (alturaAB(T->Esquerda) > alturaAB(T->Direita))
		T->Direita = inserirPorAlturaAB(X, T->Direita);
	else
		T->Esquerda = inserirPorAlturaAB(X, T->Esquerda);
	return T;
}

int criarElementoAB (){
  int X;
  X = gerarNumeroInteiro(0, 100);
  return X;
}

PNodoAB criarAB(){
	PNodoAB T;
	T = NULL;
	return T;
}

PNodoAB criarABAleatoria (int N){
    int k;
    int X;
    PNodoAB T;
    T = criarAB();//T=NULL
    k= 1;
    while(k<=N){
        X= criarElementoAB();
        if(pesquisarAB(X,T) == NULL)
        {
            T = inserirPorAlturaAB(X, T);
            k++;
        }
    }
    return T;
}

void mostrarEmOrdemAB (PNodoAB T) {
	if (T != NULL) {
		mostrarEmOrdemAB(T->Esquerda);
		printf("%d\n",T->Elemento);
		mostrarEmOrdemAB(T->Direita);
	}
}

void GravarArvore(PNodoAB Acacia, char *ficheiro)
{
    char * buffer = malloc(TAM_MAX_NUM +4);
    if(Acacia!= NULL)
    {
        GravarArvore(Acacia->Esquerda, ficheiro);
        sprintf(buffer,"[%d] ",Acacia->Elemento);
        strcat(ficheiro, buffer);
        GravarArvore(Acacia->Direita, ficheiro);
    }
    free(buffer);
    return;
}

int contarImpares(PNodoAB Acacia)
{
    if(Acacia == NULL)
    return 0;
    return ((Acacia->Elemento % 2 == 1) ? 1 : 0) + contarImpares(Acacia->Esquerda) + contarImpares(Acacia->Direita); 
}

int main ()
{
    PNodoAB Acacia = criarABAleatoria(9);
    char ficheiro[100];
    mostrarEmOrdemAB(Acacia);
    GravarArvore(Acacia, ficheiro);
    printf("%s\n", ficheiro);
    printf("%d\n",contarImpares(Acacia));

    return 0;
}