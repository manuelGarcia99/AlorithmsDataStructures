
PNodo criarListaAleatoria(int N){

    PNodo L;
    int i= 1;
    INFO X;
    L = criarLista(); //2 = NULL

    while(i<=N){

        X = criarElemento();
        if(pesquisarLista(X,L) == 0){
            L = inserirListaInicio(X,L);
            i += 1;    
        }
    }

    return L;

}

int cantidadLista(PNodo L, float NF){

    int soma = 0;

    if(L == NULL){
        return 0;
    }

    while (L != NULL)
    {
        if ((L->Elemento).notaFreq >= NF)
        {
            soma++;
        }
        L = L->Prox;
    }
    
    return soma;

}

