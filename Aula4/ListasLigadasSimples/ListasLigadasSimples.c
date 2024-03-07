
PNodo criarNodo(INFO X){
  PNodo P;
  P = (PNodo) malloc(sizeof(struct Nodo));
  if (P == NULL)
    return NULL;
  P->Elemento = X;
  P->Prox = NULL;
  return P;
}

PNodo libertarNodo(PNodo P){
  P->Prox = NULL;
  free(P);
  P = NULL;
  return P;
}

PNodo criarLista(){
  PNodo L;
  L = NULL;
  return L;
}

int listaVazia(PNodo L){
  if (L == NULL)
    return 1;
  else
    return 0;
}

void mostrarListaInicio(PNodo L){
  PNodo P = L;
  while (P != NULL){
    mostrarElemento(P->Elemento);
    P = P->Prox;
  }
  printf("\n\n");
}

void mostrarListaInicioRec(PNodo L){
  if (L != NULL){
    mostrarElemento(L->Elemento);
    mostrarListaInicioRec(L->Prox);
  }
}

void mostrarListaFimRec(PNodo L){
  if (L != NULL){
    mostrarListaFimRec(L->Prox);
    mostrarElemento(L->Elemento);
  }
}

int tamanhoLista(PNodo L){
  int  tam = 0; 
  while (L != NULL){
    tam++;
    L = L->Prox;
  } 
  return tam;
}

int tamanhoListaRec(PNodo L){ 
  if (L == NULL) 
    return 0; 
  else 
    return 1 + tamanhoListaRec(L->Prox);
}

int pesquisarLista(INFO X, PNodo L){ 
  while (L != NULL && compararElementos(L->Elemento, X) != 0)
    L = L->Prox;
  if (L == NULL)
    return 0;
  else
    return 1;
} 

int pesquisarListaRec(INFO X, PNodo L){
  if (L == NULL) 
    return  0;
  if (compararElementos(L->Elemento, X) == 0) 
    return  1; 
  return pesquisarListaRec(X, L->Prox);
}

// X está na lista L
// devolve NULL se X está no inicio da lista
PNodo procurarAntecessor(INFO X, PNodo L){
  PNodo  Ant;
  if (compararElementos(L->Elemento, X) == 0)
    return NULL;
  Ant = L; 
  while (compararElementos(Ant->Prox->Elemento, X) != 0)
    Ant = Ant->Prox;
  return Ant;
}

// X está na lista L
// devolve NULL se X está no inicio da lista
PNodo procurarAntecessorRec(INFO X, PNodo L){ 
  if (compararElementos(L->Elemento, X) == 0) 
    return  NULL;   //  só acontece se X estiver no início de L 
  if (compararElementos(L->Prox->Elemento, X) == 0) 
    return  L; 
  return procurarAntecessorRec(X, L->Prox);
}

PNodo inserirListaInicio(INFO X, PNodo L){
  PNodo P;
  P = criarNodo(X);
  if (P == NULL)
    return L;
  P->Prox = L;
  L = P;
  return L;
}

PNodo inserirListaFim(INFO X, PNodo L){ 
  PNodo Ant, P;
  P = criarNodo(X); 
  if (P == NULL) 
    return L; 
  if (L == NULL) // lista vazia, logo X é o único elemento da lista
    return P;
  Ant = L; 
  while (Ant->Prox != NULL)    // marcar o elemento do fim de L
    Ant = Ant->Prox;
  Ant->Prox = P; // ligar último nodo da lista L ao novo nodo (com o X)
  return  L;
}

// assume-se que a lista está ordenada por ordem crescente
PNodo procurarAntecessorOrdem(INFO X, PNodo L){ 
  PNodo Ant = NULL; 
  while (L != NULL && compararElementos(L->Elemento, X) < 0){
    Ant = L;
    L = L->Prox;
  } 
  return Ant; 
} 

PNodo inserirListaOrdem(INFO X, PNodo L){//ordena
  PNodo P, Ant;
  P = criarNodo(X); 
  if (P == NULL) 
    return  L; 
  if (L == NULL) 
    return  P;    // a lista L inicia-se em P
  Ant = procurarAntecessorOrdem(X, L); 
  if (Ant == NULL){   // inserir no início de L
    P->Prox = L; 
    return  P;
  }   
  P->Prox = Ant->Prox;
  Ant->Prox = P;
  return  L; 
}

// remover X da lista L, em que X está na lista
PNodo removerLista(INFO X, PNodo L){ //ordena
  PNodo P, Ant;
  Ant = procurarAntecessor(X, L); 
  if (Ant == NULL){   // remover elemento do início de L
    P = L;
    L = L->Prox;
  } 
  else{
    P = Ant->Prox;
    Ant->Prox = P->Prox; // ou (= Ant->Prox)->Prox
  } 
  P = libertarNodo(P); 
  return  L;
}

// atualiza os dados do elemento da lista que tem a chave de X
void atualizarLista(INFO X, PNodo L){
  PNodo PAux = L;
  while (PAux != NULL && compararElementos(PAux->Elemento, X) != 0)
    PAux = PAux->Prox;
  if (PAux != NULL)  //  existe um elemento com a chave de X
    PAux->Elemento = X;
}

// liberta todos os nodos da lista, devolvendo-a vazia
PNodo libertarLista(PNodo L){
  PNodo P;
  while (L != NULL){
    P = L;
    L = L->Prox;
    P = libertarNodo(P);
  }
  return  L;
}

float somaPagamentos(PNodo L, int Num) {
  float soma =0;
  while(L!=NULL) {
    if((L->Elemento).NIF==Num) {
      soma+=(L->Elemento).Pagamento;
    }
    L=L->Prox;
  }
  return soma;
}

/*
se der 400 de input, devolve a soma dos pagamentos de mais
de 400 euros*/
int quantPagamentos(PNodo L, float Pag)
{
  int p;
  // caso particular/terminal
  if (L == NULL)
    return 0;
  // caso geral
  p = quantPagamentos(L->Prox, Pag);

  /* grab an individual and put it aside. Check that there
    are x amount of people who have less than 1.7m, than
    the amount of people who have less than 1.7m is
    x, if the individual aside has more or equal than 1.7m, and
    x+1, if the individual has less than 1.7m */
  if ((L->Elemento).Pagamento >= Pag)
  {
    return p + 1;
  }
  else
  {
    return p;
  }
}

float maiorPagamentoRec(PNodo L) {
    float n;
    //caso terminal
    if(L->Prox == NULL) 
        return (L->Elemento).Pagamento;
        //caso geral
    n = maiorPagamentoRec(L->Prox);
    if(n > (L->Elemento).Pagamento) {  
      return n;
    } else {
      return (L->Elemento).Pagamento;
    }
    
}

float menorPagamentoRec(PNodo L){
  float n;
  if(L->Prox == NULL){
    return (L->Elemento).Pagamento;
  }
  n= menorPagamentoRec(L->Prox);
  return ((n < (L->Elemento).Pagamento)) ? n : (L->Elemento).Pagamento;
 
}

PNodo procurarAntecessorNF(PNodo L, int NumF){
  if(L->Prox == NULL) return NULL;
  if(L->Prox->Elemento.NFatura == NumF){
    return L->Prox;
  }
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

PNodo removerTodosPequenos(PNodo L, int minimo){
  PNodo p;
    p = L;

    while (p != NULL)
    {
        if((p->Elemento).Pagamento <= minimo){
            L = removerLista(p->Elemento,L);
            p = L;
        }
        p = p->Prox;
    }

    return L;
}

PNodo removerTodosComNum(PNodo L , int Num){
  PNodo p;
    p = L;

    while (p != NULL)
    {
        if((p->Elemento).NIF == Num){
            L = removerLista(p->Elemento,L);
            p = L;
        }
        p = p->Prox;
    }

    return L;
}

PNodo removerNElementos(PNodo Lista ,int Num){
  PNodo p; 
  int contador= Num;
  p=Lista;
  if(tamanhoLista(Lista) <= Num){
    Lista->Prox = NULL;
    removerLista(Lista->Elemento,Lista);
    return Lista;
  }
  else{
    while (p != NULL && contador>0)
    {
        Lista = removerLista(p->Elemento,Lista);
        p = Lista;
        
        
        contador--;
    }
    return Lista;
  }
}

PNodo divideEmDois(PNodo L , int Num){
  PNodo NovaL;
  if(tamanhoLista(L) == 1){
    return L;
  }
  else{
    int corte =gerarNumeroInteiro(1,tamanhoLista(L) -1);
    PNodo p;
    p= L;
    while(corte > 0){
      if(corte ==1 ){
        NovaL= p->Prox;
        p->Prox = NULL;
        if(tamanhoLista(NovaL) >=2){
          NovaL->Prox->Elemento.NFatura=Num;
          return NovaL;
        }
        else{
          return NovaL;
        }
      }
      else{
        p=p->Prox;
        corte--;
      }
    }
  }
}

int contem(int NFatura, PNodo L){
  if(L==NULL){
    0;
  }
  
  for(int i= 0; i< tamanhoListaRec(L); i++){
    if(NFatura == L->Elemento.NFatura)
      return 1;
    L=L->Prox;
  }
  

  return 0;
}

PNodo ordenaIter(PNodo L){
  PNodo p =L;
  PNodo walker ;
  PNodo marcador = NULL, lindo ,var = L;
  int ultimoNIF = 1;
  PNodo iguais;
  iguais =criarLista();
  

  while(p != NULL){
    walker = p;
    int max= 1100000;
    while(walker != NULL && ((marcador==NULL) ? 1 : (compararElementos(marcador->Elemento,walker->Elemento))) ){
      if( (walker->Elemento.NIF <= max) &&  (walker->Elemento.NIF >= ultimoNIF) && (!contem(walker->Elemento.NFatura,iguais) )){
        max= walker->Elemento.NIF;////duvida
        marcador= criarNodo(walker->Elemento);
      }
      walker= walker->Prox;
    }
    if(max!= 1100000){
      lindo = criarNodo(marcador->Elemento);
      ultimoNIF =marcador->Elemento.NIF; 

      iguais = inserirListaInicio(marcador->Elemento,iguais); 
      
      if(lindo->Elemento.NFatura == p->Elemento.NFatura){
        p = p->Prox;
      }
      L=removerLista(lindo->Elemento,L);
      L= inserirListaFim(marcador->Elemento,L);
      
      
      
      
       }
  if(max== 1100000)
    p=p->Prox;
  
  }
  
    
  return L;//L a seguir
 

}
  PNodo removeSegundoNif(PNodo L, int Num)
  {
    if(L== NULL)
    {
      return NULL;
    }
    if(tamanhoLista(L) == 1 )
      if(L->Elemento.NIF==Num)
        return NULL;
      else
        return L;
    PNodo p ,Ant;
    p= L;
    while(p!= NULL){
      if(p->Elemento.NIF == Num){
        Ant= procurarAntecessor(p->Elemento,L);
        if(Ant == NULL){
          p=L;
          while(L->Elemento.NIF == Num)
          L=L->Prox;
        }
        else{
          Ant->Prox= p->Prox;
        }
        p=libertarNodo(p);

      
         p=L;

      }
      p=p->Prox;
    }

    return L;
    
  }

  PNodo removerMaiorQue(PNodo L , int X){
    if(tamanhoLista(L) == 1){
      if(L->Elemento.NIF>=X){
        return NULL;
      }
      else{
      return L;
    }
    }
    

    PNodo Ant , p;
    p=L;
    while(p!=NULL){
      if(p->Elemento.NIF>=X){
      Ant = procurarAntecessor(p->Elemento,L);
      if(Ant == NULL){//basta devolver NULL
        return NULL;
      }
      else{
        Ant->Prox =p->Prox;
      }
      p=libertarNodo(p);
      p=L;

    }
    p= p->Prox;
    }
    return L;
  }

  int pagamentoEntre(PNodo L , float pagamentoMinimo , float pagamentoMaximo ){
    int contador=0;
    PNodo p ;
    p=  L;
    while(p!=NULL){
      if(p->Elemento.Pagamento >= pagamentoMinimo && p->Elemento.Pagamento<= pagamentoMaximo)
      {
        contador++;
      }
      p=p->Prox;
    }

    return contador;
  }

  PNodo pagamentoInflacionado(PNodo L, float aumentoCima , float aumentoBaixo)
  {
    int metade = tamanhoLista(L)/2;
    int posicao =1 ;
    PNodo p ;
    p= L;
    while( p != NULL)
    {
      if(posicao <= metade)
        p->Elemento.Pagamento += aumentoCima;
      else
        p->Elemento.Pagamento += aumentoBaixo; 
      posicao++;
      p= p->Prox;
    }

    return L;
  }

  PNodo inflacionarExtremos(
    PNodo L , float extremos , float meio , int porcao
  )
  {
    int posicao =1 ;
    int terceiroSegmento = tamanhoLista(L) - porcao;
    PNodo p;
    p=L;
    while(p!= NULL)
    {
      if(posicao <= porcao)
      {
        p->Elemento.Pagamento+=extremos;
      }
      else if(posicao > terceiroSegmento)
      {
        p->Elemento.Pagamento+=extremos;
      }
      else
      {
        p->Elemento.Pagamento+= meio;
      }

      posicao++;
      p= p->Prox;
    }     
    return L;
  }

  PNodo pobreMaisRico(PNodo L , float maximo){
    INFO senhor;
    PNodo p;
    p=L;
    float maiorDosMinimos=-1;
    if(menorPagamentoRec(L) > maximo)
      return NULL;
    while(p!=NULL){
      if(p->Elemento.Pagamento < maximo &&
       p->Elemento.Pagamento > maiorDosMinimos){
        maiorDosMinimos = p->Elemento.Pagamento;
        senhor.NFatura = p->Elemento.NFatura;
        senhor.NIF = p->Elemento.NIF;
        senhor.Pagamento = p->Elemento.Pagamento;
        for(int i=0; i< sizeof(senhor.Data) / sizeof(senhor.Data[0]);i++)
        {
          senhor.Data[i] = p->Elemento.Data[i];
        }
       }


      p=p->Prox;
    }

    return criarNodo(senhor);
  }

  PNodo segundoMaior(PNodo L){
    PNodo p;
    
    p=L;
    INFO atras , frente=criarElemento();
    frente.Pagamento=-1;
    while(p!= NULL){
      if(p->Elemento.Pagamento>frente.Pagamento)
      {
        atras.NFatura = frente.NFatura;
        atras.NIF = frente.NIF;
        atras.Pagamento = frente.Pagamento;
        for(int i=0; i< sizeof(atras.Data) / sizeof(atras.Data[0]);i++)
        {
          atras.Data[i] = frente.Data[i];
        }
        frente.NFatura = p->Elemento.NFatura;
        frente.NIF = p->Elemento.NIF;
        frente.Pagamento = p->Elemento.Pagamento;
        for(int i=0; i< sizeof(frente.Data) / sizeof(frente.Data[0]);i++)
        {
          frente.Data[i] = p->Elemento.Data[i];
        }
      }
      else if(p->Elemento.Pagamento<=frente.Pagamento &&
              p->Elemento.Pagamento>atras.Pagamento)
              {
                atras.NFatura = p->Elemento.NFatura;
                atras.NIF = p->Elemento.NIF;
                atras.Pagamento = p->Elemento.Pagamento;
                for(int i=0; i< sizeof(atras.Data) / sizeof(atras.Data[0]);i++)
                {
                  atras.Data[i] = p->Elemento.Data[i];
                }           
              }
      p= p->Prox;
    }
    if(frente.Pagamento == -1 || atras.Pagamento == -1){
      return NULL;
    }

    return criarNodo(atras);

  }

  PNodo removePrimeiroEUltimo(PNodo L)
  {
    PNodo p, Ant;
    int tam = tamanhoLista(L);
    p=L;
    if(tamanhoLista(L) == 1 || tamanhoLista(L) ==2 || tamanhoLista(L) == 0){
      return NULL;
    }
    while(p != NULL){
      if(procurarAntecessor(p->Elemento,L) == NULL && tam == tamanhoLista(L)){
        p=L;
        L= L->Prox;
        p= libertarNodo(p);
        p=L;
      }
      else if(p->Prox==NULL && tamanhoLista(L)== tam -1){//Acho que so preciso de libertar o Nodo
        Ant= procurarAntecessor(p->Elemento,L);
        Ant->Prox = p->Prox;
        p=libertarNodo(p);
        p=L;
      }

      p= p->Prox;
    }

    return L;    
  }

  PNodo removeTodosMenosOsExtremos(PNodo L){
    PNodo p, Ant;
    p=L;
    while(p!= NULL)
    {
      if(procurarAntecessor(p->Elemento,L) != NULL && p->Prox != NULL)
      {
        Ant= procurarAntecessor(p->Elemento,L);
        Ant->Prox = p->Prox;
        p=libertarNodo(p);
        p= L;
      }

      p= p->Prox;
    }

    return L;
  }

  PNodo ultimoParaSegundo(PNodo L)
  {
    if(tamanhoListaRec(L) < 3){
      return L;
    }
    PNodo p, Ant, novo;
    INFO copia;
    p=L;
    while(p!= NULL)
    {
      if(p->Prox == NULL)
      {
        copia.NFatura = p->Elemento.NFatura;
        copia.NIF = p->Elemento.NIF;
        copia.Pagamento = p->Elemento.Pagamento;
        for(int i=0; i< sizeof(copia.Data) / sizeof(copia.Data[0]);i++)
        {
          copia.Data[i] = p->Elemento.Data[i];
        }
        Ant = procurarAntecessor(p->Elemento,L);
        Ant->Prox = p->Prox;
        p=libertarNodo(p);
        novo =criarNodo(copia);
        novo->Prox= L->Prox;
        L->Prox = novo;
        return L;
      }
      p= p->Prox;
    }

    return L;
  }

  PNodo apagaLista(PNodo L){
    PNodo p,Ant;
    p= L ;
    while(p!=NULL && tamanhoLista(L)>1){
      
      p=L;
      L= L->Prox;
      p->Prox = NULL;
      free(p);
      p= NULL;
      p=L;
      p= p->Prox;
    }
    free(L);
    L = NULL;
    return L;
  }

  PNodo inverteLista(PNodo L){
    PNodo p, Ant=NULL, seguinte=NULL;
    p=L;
    while(p!= NULL)
    {
      seguinte = p->Prox;
      p->Prox = Ant;
      
      Ant = p;
      p= seguinte;
    
    }
    L = Ant;
    return L;
  }

PNodo apagaNesimo(PNodo L , int index){
  int posicao= 1;
  PNodo p,Ant;
  p =L;
  if(index > tamanhoLista(L)){
    return L;
  }
  while(posicao <= index){
    if(posicao == index && posicao == 1){
      p= L;
      L = L->Prox;
      p = libertarNodo(p);
      p= L;
      return L; 
    }
    else if(posicao == index){
      Ant = procurarAntecessor(p->Elemento,L);
      Ant->Prox = p->Prox;
      p = libertarNodo(p);
      p= L;
      return L;
    }

    posicao++;
    p= p->Prox;
  }

  return L;
}

PNodo concatenarListasEOrdenarNFat(PNodo Lista,PNodo ListaExtra){
  PNodo ligacao = Lista;
  while(ligacao->Elemento.NFatura != ListaExtra->Elemento.NFatura){
    if(ligacao->Prox == NULL){
      ligacao->Prox= ListaExtra;
    }
    ligacao= ligacao->Prox;
  }
  PNodo p =Lista;
  PNodo walker ;
  PNodo marcador = NULL, lindo ;
  PNodo iguais;
  iguais =criarLista();
  int ultimoNF=1;
   while(p != NULL){
    
    walker = p;
    int max= 1100000;
    while(walker != NULL ){
      
      if(walker->Elemento.NFatura <= max && (walker->Elemento.NFatura >= ultimoNF) 
      && (!contem(walker->Elemento.NFatura,iguais) ))    {
        max= walker->Elemento.NFatura;////duvida
        marcador= criarNodo(walker->Elemento);
      }
      walker= walker->Prox;
    }
    if(max!= 1100000){
      lindo = criarNodo(marcador->Elemento);
      ultimoNF = marcador->Elemento.NFatura;
      iguais = inserirListaInicio(marcador->Elemento,iguais); 
      if(lindo->Elemento.NFatura == p->Elemento.NFatura){
        p = p->Prox;
      }
      Lista=removerLista(lindo->Elemento,Lista);
      Lista= inserirListaFim(marcador->Elemento,Lista);
    }
  if(max== 1100000){

    p=p->Prox;
  }
  }
  
    
  return Lista;  
}
