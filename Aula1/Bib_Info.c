
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

void guardarAlunos(ALUNO *v, int n)
{
    int k;
    FILE *f;
    f = fopen("AlunosFinal.txt", "w");

    for ( k = 0; k < n; k++)
    {
        fprintf(f, "%d %d %d %d %d %d\n", v[k].numAluno, v[k].notas[0], v[k].notas[1], v[k].notas[2], v[k].notas[3], v[k].notaFinal);
    }
    fclose(f);
}

int guardarVetor(ALUNO *v , int n)
{
    int k;
    FILE *f;
    f= fopen("AlunosFinalReduzido.txt", "w");

    if(f==NULL)
        return 0;

    for(k=0; k < n; k++)
    {
        fprintf(f,"%d %d\n", v[k].numAluno, v[k].notaFinal);
    }
    fclose(f);
    return 1;
}

int melhorAluno(ALUNO *v, int tam){
    int max= 0;
    int num =0;
    for(int i = 0 ; i< tam ;i++){
        if(v[i].notaFinal > max){
            max = v[i].notaFinal;
            num = v[i].numAluno;
        }
    }

    return num;
}

int maiorNota(const ALUNO *v, int n){
    int m;
    if(n== 1)
    {
        return v[0].notaFinal;
    }
    m= maiorNota(v,n-1);
    if(v[n-1].notaFinal> m){
        return v[n-1].notaFinal;
    }
    else{
        return m;
    }

}

int quantNotasMaiorK (ALUNO V[], int N, int K){
    if(N==1){
        if(V[0].notaFinal >= K){
            return 1 ;
        }
        else
            return 0;
    }
    else{
        if(V[N-1].notaFinal >= K){
            return 1 + quantNotasMaiorK(V,N-1,K) ;
        }
        else{
            return 0 + quantNotasMaiorK(V,N-1,K);
        }
    }
}

int  vetorNotasFinais (ALUNO *A, int N, int **V){///criar vetor com nom
    int k , tamV;
    tamV= N;
    *V = (int *) malloc(tamV *sizeof(int));
    for(k=0;k<N;k++)
        (*V)[k] =A[k].notaFinal;

    return tamV;
}