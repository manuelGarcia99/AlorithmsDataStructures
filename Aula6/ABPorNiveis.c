
void mostrarPorNiveisAB (PNodoAB T, int niveis){
  PNodoFila Q;
  PNodoAB  P;
  int k = 0;
  
  if (ABVazia(T))
    return;
  Q = criarFila();
  Q = juntar(T, Q);
  Q = juntar(NULL, Q);
  printf("Nivel %1d: %2d\n", k, T->Elemento.NFatura);
  k++;
  printf("Nivel %1d: ", k);
  while (!filaVazia(Q)){
    P = frente(Q);
    Q = remover(Q);
    if (P == NULL){
      k++;
      if (k == niveis)
        return;
      printf("\nNivel %1d: ", k);
      if (!filaVazia(Q))
        Q = juntar(NULL, Q);
    }
    else{
      if (P->Esquerda != NULL)
        printf("%4d[%4d] # ", P->Esquerda->Elemento.NFatura, P->Elemento.NFatura);
      else
        printf("    [%4d] # ", P->Elemento.NFatura);
      if (P->Direita != NULL)
        printf("%4d[%4d] # ", P->Direita->Elemento.NFatura, P->Elemento.NFatura);
      else
        printf("    [%4d] # ", P->Elemento.NFatura);
      if (P->Esquerda != NULL)
        Q = juntar(P->Esquerda, Q);
      if (P->Direita != NULL)
        Q = juntar(P->Direita, Q);
    } // else
  } // while

}
