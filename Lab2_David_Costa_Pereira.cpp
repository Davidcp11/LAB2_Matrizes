/*  David Costa Pereira                               */
/*  Turma 3                                           */
/*  Exercicio 2: Produto de Matrizes                  */
/*                                                    */
/*  Programa compilado com CodeBlocks 20.03           */
#include<stdio.h>
#include <string.h>
///Declaracoes de variaveis e arquivos.
int L[21], C[21], M[21][21];
int cont, aux, n;
char lixo[72];
FILE *entrada, *saida;
///*---------------------------------------------------------------------------------------*
///Recebe a posicao inicial e final da sequencia de matrizes e retorna a menor quantidade de multiplicacoes possivel.
int Minimo(int i, int j){
    cont++;
    if(i==j)
        return 0;
    int min;
    min = Minimo(i, i) + Minimo(i + 1, j) + L[i] * C[i] * C[j];
    M[i][j]=i;
    for(int k=i+1;k<j;k++){
        aux= Minimo(i, k) + Minimo(k + 1, j) + L[i] * C[k] * C[j];
        if(aux<min) {
            min = aux;
            M[i][j]=k;
        }
    }
    return min;
}
///*------------------------------------------------------------------------------------------------*
///Recebe um intervalo e printa no arquivo a melhor maneira de se multiplicar as matrizes nesse intervalo.
void MelhorCorte(int i, int j){
    if(i!=j) {
        MelhorCorte(i, M[i][j]);
        MelhorCorte(M[i][j] + 1, j);
        if(M[i][j]!=i){
            if(M[i][j]>=10)
                fprintf(saida,"%2d- %d x ",i,M[i][j]);
            else
                fprintf(saida,"%3d- %d x ",i,M[i][j]);
        } else{
            fprintf(saida,"%6d x ", i);
        }
        if(M[i][j]+1!=j){
            fprintf(saida,"%1d- %1d\n",M[i][j]+1, j);
        } else{
            fprintf(saida,"%1d\n", j);
        }
    }

}
int main() {
    ///Abrindo arquivos de saida e de entrada.
    entrada = fopen("entrada2.txt","r");
    saida = fopen("Lab2_David_Costa_Pereira.txt","w");
    for(int i=0; i<5;i++)
        fgets(lixo,72,entrada);
    ///Quantidade de matrizes.
    fscanf(entrada,"%d ",&n);
    fgets(lixo,72,entrada);
    ///Lendo os dados de cada matriz.
    for(int i=1;i<=n;i++){
        fscanf(entrada,"%d %d ", &L[i], &C[i]);
    }
    ///Saida.
    fprintf(saida,"Exemplo de arquivo de saida\n");
    fprintf(saida,"Exercicio 2\n");
    fprintf(saida,"Produto de Matrizes\n\n");
    fprintf(saida,"Total de multiplicacoes escalares = %d\n\n", Minimo(1,n));
    fprintf(saida,"Chamadas aa funcao: %d\n\n", cont);
    fprintf(saida,"Melhor ordem para realizar o produto\n");
    MelhorCorte(1,n);
    ///Fechando arquivos de entrada e saida.
    fclose(entrada);
    fclose(saida);
    return 0;
}
