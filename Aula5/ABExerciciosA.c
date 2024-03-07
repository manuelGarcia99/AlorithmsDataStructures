
PNodoAB criarABAleatoria (int N){
    int k;
    INFOAB X;
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

void numNodoFilhos(PNodoAB T , int *nEsq, int *nDir)
{
    if(T == NULL)
    {
        *nEsq = 0;
        *nDir = 0;
    }
    else{
    *nEsq = numeroNodosAB(T->Esquerda);

    *nDir = numeroNodosAB(T->Direita);
    }

}

int quantosIguais(PNodoAB T , int k )
{
    if(T == NULL){
        return 0;
    }
    else{
        return ((T->Elemento.NIF == k) ? 1 : 0 ) + quantosIguais(T->Esquerda, k) + quantosIguais(T->Direita, k); 
    }
}
