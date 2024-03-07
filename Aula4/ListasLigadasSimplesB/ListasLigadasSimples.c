PNodo criarListaAleatoria( int tam){
    PNodo L;
    for(int i = 0; i< tam ; i++){
        L->Elemento.altura = gerarNumeroReal(1.50 , 2.10);
        L->Elemento.genero = gerarNumeroInteiro(0,1);
        L->Elemento.NCC = gerarNumeroInteiro(100000,900000);
        L->Elemento.dataNasc[2] = gerarNumeroInteiro(1920,2022);
        L->Elemento.dataNasc[1] = gerarNumeroInteiro(1,12);
        if(L->Elemento.dataNasc[1] == 2 )//30 dias Novembro Abril Junho e Setembro
        {

        }
        else if(L->Elemento.dataNasc[1] == 6 || L->Elemento.dataNasc[1] == 4 || L->Elemento.dataNasc[1] == 11)
}