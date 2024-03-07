
// A. 1
PNodoAB criarABPAleatoria (int N){
    INFOAB a;
    PNodoAB T = criarAB();

    int k = 1;

    while (k<=N)
    {   
        a = criarElementoAB();
        
        if (pesquisarAB(a,T) == 0)
        {
            T = inserirABP(a,T);
            k+=1;
        }
        
    }
    
    return T;

    
}

PNodoAB majorNfatura(PNodoAB T){

    if(T->Direita ==NULL){

        return T;

    }
    return majorNfatura(T->Direita);
    
}

PNodoAB menorNfatura(PNodoAB T){

    if(T->Esquerda == NULL){
        return T;
    }
    return menorNfatura(T->Esquerda);


}

int Majoresque(PNodoAB T, int A){

    if (T == NULL)
    {
        return 0;
    }
    

    if (A >= T->Elemento.NFatura)
    {
        return Majoresque(T->Direita, A);
    }
    else  
    {
        return 1 + Majoresque(T->Esquerda, A) + Majoresque(T->Esquerda, A);
    }
    
    
}

PNodoAB encontrarelemento(PNodoAB  T, int A){

    if (T == NULL)
    {
        return NULL;
    }

    if (T->Elemento.NFatura == A)
    {
        return T;
    }
    
    else {

        if (A > T->Elemento.NFatura)
        {
            return encontrarelemento(T->Direita,A);
        }
        else
            return encontrarelemento(T->Esquerda,A);
    }

    return NULL;

}

PNodoAB encontrarelementoIterativo(PNodoAB  T, int A){

    while (T != NULL && T->Elemento.NFatura != A)
    {
        if (A < T->Elemento.NFatura)
        {
            T = T->Esquerda;
        }
        else
            T = T->Direita;   
    }
    return T;

}


int numerodointervalo(PNodoAB T, int A, int B){

    if (T == NULL)
    {
        return 0;
    }
    if (A > T->Elemento.NFatura)
    {
        return numerodointervalo(T->Direita, A, B);
    }
    if (T->Elemento.NFatura > B)
    {
        return numerodointervalo(T->Esquerda, A, B);
    }

    return 1 + numerodointervalo(T->Direita, A, B) + numerodointervalo(T->Esquerda, A, B);
    


}

int numerointervaloinvertido(PNodoAB T, int A, int B){

    if (T == NULL)
    {
        return 0;
    }

    if (A > T->Elemento.NFatura || T->Elemento.NFatura > B)
    {
        return 1 + numerodointervalo(T->Esquerda, A, B) + numerodointervalo(T->Direita, A, B);
    }
    
    else
        return numerodointervalo(T->Direita, A, B) + numerodointervalo(T->Esquerda, A, B);


}

