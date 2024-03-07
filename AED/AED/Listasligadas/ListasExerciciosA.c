
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


float sumaPagamentos(PNodo L, int Num){

    float soma = 0;

    while(L != NULL){

        if((L->Elemento).NIF == Num){
            soma = soma + ((L->Elemento).Pagamento);
        }
        L = L->Prox;
    }

    return soma;
}

int quantPagamanetos(PNodo L, float Pag){

    int p;

    if(L == NULL){
        return 0;
    }

    p = quantPagamanetos(L->Prox, Pag); //apuntador talvez?
    if((L->Elemento).Pagamento >= Pag){
        return p+1;
    }
    else 
        return p;
    
}

float maiorPagamentoRec(PNodo L){

    float n;

    if(L->Prox == NULL)
        return (L->Elemento).Pagamento;
    
    n = maiorPagamentoRec(L->Prox);

    if(n > (L->Elemento).Pagamento)
        return n;
    else
        return (L->Elemento).Pagamento;

}

float menorPagamentoRec(PNodo L){

    float n;

    if(L->Prox == NULL)
        return (L->Elemento).Pagamento;
    
    n = menorPagamentoRec(L->Prox);

    if(n < (L->Elemento).Pagamento){
        return n;
    }
    else
        return (L->Elemento).Pagamento;

}
PNodo removerFatura(PNodo L, int NFatura){
    
    PNodo p;
    p = L;

    while (p != NULL)
    {
        if((p->Elemento).NFatura == NFatura){
            L = removerLista(p->Elemento,L);
            p = L;
        }
        p = p->Prox;
    }

    return L;

}


PNodo removerNIF(PNodo L, int NIF){
    
    PNodo p;
    p = L;

    while (p != NULL)
    {
        if((p->Elemento).NIF == NIF){
            L = removerLista(p->Elemento,L);
            p = L;
        }
        p = p->Prox;
    }

    return L;

}

PNodo removerPagamentosmenores(PNodo L){

    PNodo p;
    p = L;
    int Pagamento = maiorPagamentoRec(L);


    if(L == NULL)
        return L;

    while (p != NULL)
    {
        if((p->Elemento).Pagamento < Pagamento){
            L = removerLista(p->Elemento,L);
            p = L;
        }
        p = p->Prox;
    }
    
    return L;
}

PNodo removerN(PNodo L, int N){

    int n = tamanhoListaRec(L), i = 0;

    if (N>n){
        L = libertarLista(L);
    }

    else{

        while (i < N)
        {
            L = L->Prox;
            i++;
        }

    }

    return L;
}

PNodo dividirlista(PNodo L, int N){

    PNodo CL;

    while (L != NULL)
    {
        if ((L->Elemento).NFatura == N)
        {
            L = L->Prox;
            CL = L;
        }

        L = L->Prox;
    }
    return CL;

}
/*
PNodo OrdenarLista(PNodo L){

    int temp;
    INFO tempI;
    PNodo CL;
    CL = L;

    if(L == NULL){
        return L;
    }

    while(L != NULL)
    {
        temp = (L->Elemento).NIF;
        while(CL != NULL)
        {
            if((CL->Elemento).NIF < temp){
                temp = (CL->Elemento).NIF;
                tempI = CL->Elemento;
            }
            L->Elemento = CL->Elemento
            CL = CL->Prox;
        }
        L = L->Prox;
        CL = L;
        
        
    }

    return FL;

}*/


float maiorPagamentodoAno(PNodo L, int a){

    PNodo CL=NULL;
    INFO d;
    float r = -1;

    if(L == NULL){
        return 0;
    }

    while (L != NULL)
    {
        if((L->Elemento).Data[2] >= a){

            d = L->Elemento;
            CL = inserirListaInicio(d,CL);

        }
        L = L->Prox;

    }
    r = maiorPagamentoRec(CL);
    if(r == -1){
        return 0;
    }
    else
        return r;

}

int maiorPagamentoMes(PNodo L, int N){

    PNodo CL = NULL;
    INFO X;
    
    if(L == NULL){
        return 0;
    }

    while (L != NULL)
    {
        if((L->Elemento).Data[1] == N){
            
            X = L->Elemento;
            CL = inserirListaInicio(X,CL);

        }
        L = L->Prox;
    }
    
    return tamanhoListaRec(CL);


}