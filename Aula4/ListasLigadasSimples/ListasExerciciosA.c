
PNodo criarListaAleatoria(int N){
    int k=1;
    PNodo L; INFO X;
    L = criarLista(); // cria lista vazia (L=Null)
    while(k<=N) {
        X = criarElemento();
        if(pesquisarLista(X,L)==0) {
            L=inserirListaInicio(X, L);
            k+=1;
        }
    }

    return L;
}

