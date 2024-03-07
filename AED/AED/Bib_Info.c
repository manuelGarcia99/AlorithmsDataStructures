
int maiorElemento(int v[], int n)
{
    int k, maior;
    maior = v[0];
    for (int k = 1; k < n; k++)
        if (v[k] > maior)
            maior = v[k];
    return maior;
}

ALUNO *lenvetor(int *n)
{
    ALUNO *A;
    int num;
    FILE *f;
    *n = 0;
    f = fopen("Alunos.txt", "r");
    A = (ALUNO *)malloc(sizeof(ALUNO)); // 24 bytes
    while (fscanf(f, "%d", &num) == 1)
    {
        *n = *n + 1;
        A = (ALUNO *)realloc(A, (*n) * sizeof(ALUNO));
        A[*n - 1].numAluno = num;
        fscanf(f, "%d %d %d %d", &(A[*n - 1].notas[0]), &(A[*n - 1].notas[1]), &(A[*n - 1].notas[2]), &(A[*n - 1].notas[3]));
    }
    fclose(f);
    return A;
}

int guardarAlunos(ALUNO *v, int n) //5 e 3
{
    int k;
    FILE *f;
    f = fopen("AlunosFinal.txt", "w");
    if(f == NULL){
        return 0;
    }   
    
    for (int k = 0; k < n; k++)
    {
        fprintf(f, "%d %d %d %d %d %d\n", v[k].numAluno, v[k].notas[0], v[k].notas[1], v[k].notas[2], v[k].notas[3], v[k].notaFinal);
    }
    fclose(f);
    return 1;
}

int maioNotaFinal(ALUNO *v, int n){ //4

    int maior;

    if(n == 1)
        return v[0].notaFinal;

    maior = maioNotaFinal(v,n-1);

    if(v[n-1].notaFinal > maior)
        return v[n-1].notaFinal;
    else
        return maior;
    
    return maior;
}

int quantNotasMaiorK (ALUNO v[], int N, int K){

        
    if(N==1){
        
        if(v[0].notaFinal >= K)
            return 1;
        else   
            return 0;
    }

    else if(v[N - 1].notaFinal >= K){

        return 1 + quantNotasMaiorK(v,N-1,K);

    }
    else
        return 0 + quantNotasMaiorK(v, N-1,K);

}

int vetorNotasFinais(ALUNO *A,int N, int *(*V)){

    int k, tamV;

    tamV = N;
    
    *V = (int *) malloc(tamV * sizeof(int));
    for (k = 0; k < N; k++)
    {
        (*V)[k] = A[k].notaFinal; 
    }

    return tamV;


}

