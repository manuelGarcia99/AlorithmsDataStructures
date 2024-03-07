// A. 1
PNodoAB criarABPAleatoria (int N){
    int k;
    INFOAB X;
    PNodoAB T;
    T = criarAB();
    k = 1;
    while(k <= N)
    {
        X= criarElementoAB();
        if(pesquisarABP(X, T) == 0)
        {
            T = inserirABP(X,T) ;
            k = k+1;
        }
    }

    return T;
}

PNodoAB elementoComMaiorNFatura(PNodoAB T)
{
    if(T->Direita == NULL)
    {
        return T;
    }
    PNodoAB pos = T;

    while(pos->Direita != NULL)
    {
        pos = pos->Direita;
    }

    return pos;
}

PNodoAB elementoComMenorNFatura(PNodoAB T)
{
    if(T->Esquerda == NULL)
    {
        return T;
    }
    PNodoAB pos = T;

    while(pos->Esquerda != NULL)
    {
        pos = pos->Esquerda;
    }

    return pos;
}

int numeroDeMaiores( PNodoAB T, int A)
{
    
    if(T== NULL ) return 0;
    if(T->Elemento.NFatura <= A && T!=NULL)
    {
        return 0 +  numeroDeMaiores(T->Direita, A);
    }
    else if(T->Elemento.NFatura > A  && T!= NULL)
    {
        return 1 + numeroDeMaiores(T->Direita, A) + numeroDeMaiores(T->Esquerda, A ) ;
    }

}

PNodoAB nodoComNFatura(PNodoAB T , int A){
    if(T== NULL)
    {
        return NULL;
    }
    if(A == T->Elemento.NFatura)
    {
        return T;
    }
    if(A < T->Elemento.NFatura)
    {
        return nodoComNFatura(T->Esquerda, A);
    }
    else
    {
        return nodoComNFatura(T->Direita, A);
    }
}

PNodoAB nodoComNFaturaI(PNodoAB T, int A)
{
    while(T!= NULL && T->Elemento.NFatura != A)
    {
        if(A<T->Elemento.NFatura)
        {
            T=T->Esquerda;
        }
        else{
            T= T->Direita;
        }
    } 

    return T;
}

int nodoComNFaturaEntre(PNodoAB T, int A, int B){
    if(T == NULL)
    {
        return 0;
    }
    if(T->Elemento.NFatura < A ){
        return nodoComNFaturaEntre(T->Direita,A,B) + 0;
    }
    if(T->Elemento.NFatura > B){
        return nodoComNFaturaEntre(T->Esquerda,A,B) + 0;
    }
    
        return 1 + nodoComNFaturaEntre(T->Esquerda, A, B) + nodoComNFaturaEntre(T->Direita,A,B);
     
}

int nivelMaisAlto(PNodoAB T, int nivel){//Fazer antes da segunda prática
    if(T != NULL)
    {
        nivelMaisAlto(T->Esquerda,nivel +1) + nivelMaisAlto(T->Direita, nivel+1);
    }
}

int numDeElementosForaDoIntervalo(PNodoAB T , int A , int B){
    if(T==NULL){
        
        return 0; 
    }
    else if(T->Direita == NULL && T-> Esquerda == NULL  ){
        
        return (T->Elemento.NFatura < A || T->Elemento.NFatura > B) ? 1 :0;
    }
    else if(T->Direita == NULL){
        
        return ((T->Elemento.NFatura < A || T->Elemento.NFatura > B) ? 1 :0) + (numDeElementosForaDoIntervalo(T->Esquerda,A,B));
    }
    else if(T->Esquerda == NULL){
        
        return ((T->Elemento.NFatura < A || T->Elemento.NFatura > B) ? 1 :0) + (numDeElementosForaDoIntervalo(T->Direita,A,B));
    }
   else {
    
    return ((T->Elemento.NFatura < A || T->Elemento.NFatura > B) ? 1 : 0) + (numDeElementosForaDoIntervalo(T->Esquerda, A, B)) + (numDeElementosForaDoIntervalo(T->Direita, A, B));
}

}

PNodoAB encontraPai(PNodoAB nodo , INFOAB X){
   
    if(compararElementosAB(X,nodo->Elemento) == 0){
        
        return NULL;
    }
    if(nodo->Esquerda == NULL && nodo ->Direita == NULL){
        
        return NULL;
    }
    else if(nodo->Esquerda == NULL ){
        if(compararElementosAB(X , nodo->Direita->Elemento) == 0){
            
            mostrarElementoAB(nodo->Elemento);
            return nodo;
        }
        else{
        
        return encontraPai(nodo->Direita,X);
        
        }
    }
    else if(nodo->Direita == NULL){
        if(compararElementosAB(X , nodo->Esquerda->Elemento) == 0){
            
            
            return nodo;
        }
        else{
            
        return encontraPai(nodo->Esquerda,X);
        }
    }
    else if(compararElementosAB(X , nodo->Esquerda->Elemento) == 0){
        
        return nodo;
    }
    else if(compararElementosAB(X , nodo->Direita->Elemento) == 0){
        
        
        return nodo;
    }
    else{
        if(compararElementosAB(X,nodo->Elemento) == 1){
            
        return  encontraPai(nodo->Direita , X);
        }
        else if(compararElementosAB(X,nodo->Elemento) == -1)
        {
        
        return encontraPai(nodo->Esquerda , X);
        }
        
        return NULL;
    }
}

PNodoAB encontraNovaRaiz(PNodoAB raizARemover , PNodoAB aux){
    if(compararElementosAB(aux->Elemento,raizARemover->Elemento) == 0){
        if(aux->Direita == NULL && aux->Esquerda == NULL){
            return NULL;
        }
        else if(raizARemover->Direita == NULL){
            return encontraNovaRaiz(raizARemover , aux->Esquerda);
        }
        else if(raizARemover->Esquerda == NULL){
            return encontraNovaRaiz(raizARemover , aux->Direita);
        }
        return (alturaAB(aux->Esquerda) > alturaAB(aux->Direita)) ? encontraNovaRaiz(raizARemover , aux->Esquerda) : encontraNovaRaiz(raizARemover,aux->Direita);  

    }
    //em baixo no case de não ser o primeiro
    else if(compararElementosAB (aux->Elemento, raizARemover->Elemento) == 1){
        if(aux->Esquerda != NULL)
        return encontraNovaRaiz(raizARemover,aux->Esquerda);
        PNodoAB pai = encontraPai(raizARemover,aux->Elemento);
        if(compararElementosAB(pai->Elemento,raizARemover->Elemento) == 0){

            aux->Esquerda = raizARemover->Esquerda;
            raizARemover->Esquerda = NULL;
            raizARemover->Direita = NULL;
        }
        else{
            pai->Esquerda = aux->Direita;///Esta aqui o erro D
            puts("");
            mostrarElementoAB(pai->Elemento);
            
            puts("");
            aux->Direita = raizARemover->Direita;
            aux->Esquerda = raizARemover->Esquerda;
            puts("");
            mostrarElementoAB(aux->Elemento);
            
            puts("");
            
        }
        raizARemover = removerNodoABP(raizARemover);
        return aux;
    }
    if(aux->Direita != NULL)
        return encontraNovaRaiz(raizARemover,aux->Direita);
    PNodoAB pai = encontraPai(raizARemover,aux->Elemento);
        if(compararElementosAB(pai->Elemento,raizARemover->Elemento) == 0){

            aux->Direita = raizARemover->Direita;
            raizARemover->Esquerda = NULL;
            raizARemover->Direita  = NULL;
        }
        else{
            pai->Direita = aux->Esquerda;
            aux->Direita = raizARemover->Direita;
            aux->Esquerda = raizARemover->Esquerda;
            
        }
   raizARemover = removerNodoABP(raizARemover);
    return aux;
}

PNodoAB removerLol(PNodoAB node,PNodoAB original , int qual){
    if(node == NULL){
        return original;
    }
    if(node->Elemento.NFatura < qual){
        return removerLol(node->Direita, original , qual);
    }
    else if(node ->Elemento.NFatura > qual){
        return removerLol(node->Esquerda, original, qual);
    }
    else
    {   
        if(compararElementosAB(node->Elemento,original->Elemento) == 0){
            ///Caso de ser a raiz de tudo
            
            
            original = encontraNovaRaiz(original,original);
            
            
            
           
            
            
            return original;
        }
        PNodoAB pai = encontraPai(original, node->Elemento);
        //puts("Chega");
        if(compararElementosAB(pai->Elemento, node->Elemento) == 1){
            pai->Esquerda = removerNodoABP(node);
        }
        else 
        pai->Direita =removerNodoABP(node);
        //encontrar o pai antes disto
        return original;
    }
}

INFOAB * criaVetor(PNodoAB T ,  INFOAB * vetor ,int size){
    
    if(T != NULL){
        criaVetor(T->Esquerda,  vetor ,size);
         int i =0;
    while( vetor[i].NIF  != 0 && i <size){
        i++;
    }
        vetor[i] = T->Elemento;

        criaVetor(T->Direita, vetor ,size);
    }
    return vetor;
}

int folhaMaisAlta(PNodoAB T){
    if(T==NULL){
        return -1;
    }
    if(T->Direita == NULL && T->Esquerda == NULL){
        return 0;
    }
    else if(T->Direita == NULL ){
        return 1 + folhaMaisAlta(T->Esquerda);
    }
    else if(T->Esquerda == NULL){
        return 1 + folhaMaisAlta(T->Direita);
    }
    else{
        return(1+folhaMaisAlta(T->Esquerda) > 1+ folhaMaisAlta(T->Direita) ) ? 1+ folhaMaisAlta(T->Esquerda) : 1+ folhaMaisAlta(T->Direita);
    }
}

int folhaMaisBaixa(PNodoAB T){
    if(T==NULL){
        return -1;
    }
    if(T->Direita == NULL && T->Esquerda == NULL){
        return 0;
    }
    else if(T->Direita == NULL ){
        return 1 + folhaMaisBaixa(T->Esquerda);
    }
    else if(T->Esquerda == NULL){
        return 1 + folhaMaisBaixa(T->Direita);
    }
    else{
        return(1+folhaMaisBaixa(T->Esquerda) < 1+ folhaMaisBaixa(T->Direita) ) ? 1+ folhaMaisBaixa(T->Esquerda) : 1+ folhaMaisBaixa(T->Direita);
    }
}

PNodoAB add(PNodoAB T ,PNodoAB raiz, INFOAB X){
    if(compararElementosAB(X,T->Elemento) == 0){
        return raiz;
    }
    else if(compararElementosAB(X,T->Elemento) == 1){
        if(T->Direita == NULL){
            T->Direita= criarNodoAB(X);
            return raiz;
        }
        else{
            return add(T->Direita,raiz,X);
        }
    }
    else{//no caso de X ter NFatura menor
        if(T->Esquerda == NULL){
            T->Esquerda= criarNodoAB(X);
            return raiz;
        }
        else{
            return add(T->Esquerda,raiz,X);
        }
    }
}

PNodoAB expand(PNodoAB T){
    INFOAB X =  criarElementoAB();
    T = add(T,T,X);
    return T;
}