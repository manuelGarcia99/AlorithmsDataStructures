
void mostrarElementoF (INFOF X){
  printf("%d - ", X->Elemento.NFatura);
  printf("%d - ",X->Elemento.NIF);
  printf("%2d%2d%4d - ",X->Elemento.Data[0],X->Elemento.Data[1],X->Elemento.Data[2]);
  printf("%f\n",X->Elemento.Pagamento);
}

INFOF criarElementoF (){
  INFOF X;
  X->Elemento.NFatura = gerarNumeroInteiro(1000,2000);
  X->Elemento.NIF = gerarNumeroInteiro(100780, 100790);
  X->Elemento.Data[2] = gerarNumeroInteiro(2010 , 2022);
  X->Elemento.Data[1] = gerarNumeroInteiro(1,12);
  if(X->Elemento.Data[1] == 2)
    X->Elemento.Data[0] = gerarNumeroInteiro(1,28);
  else 
    if(X->Elemento.Data[1] == 4 || X->Elemento.Data[1] == 6 || X->Elemento.Data[1] == 9 || X->Elemento.Data[1] == 11 )
      X->Elemento.Data[0] = gerarNumeroInteiro(1,30);
    else 
      X->Elemento.Data[0] = gerarNumeroInteiro(1,31);
  X->Elemento.Pagamento = gerarNumeroReal(10.0 , 1000.0);
  return X;
}

// comparação de 2 elementos do tipo INFO, segundo o campo NFatura (chave)
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementosF (INFOF X, INFOF Y){
  if(X->Elemento.NFatura > Y->Elemento.NFatura)
    return 1;
  if(X->Elemento.NFatura < Y->Elemento.NFatura)
    return -1;

  return 0;
}


