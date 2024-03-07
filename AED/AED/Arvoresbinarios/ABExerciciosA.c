PNodoAB criarABAleatoria (int N){

    int k;

    INFOAB X;
    PNodoAB T;

    T = criarAB ();

    k = 1;

    while (k <= N)
    {
        X = criarElementoAB ();
        if(pesquisarAB (X,T) == NULL){

            T = inserirPorAlturaAB(X,T);
            k = k + 1;
        }
    }
    
    return T;
}


