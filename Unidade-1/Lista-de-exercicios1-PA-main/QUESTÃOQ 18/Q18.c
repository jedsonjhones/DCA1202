#include <stdio.h>
#include <stdlib.h>
void imprimeMatriz(int **mat, int nL, int nC){
    for(int i=0; i<nL; i++){
        for(int j=0; j<nC;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void produtoMatricial(int **mat1, int **mat2, int **matResul, int nL, int x, int nC){
    for(int i=0; i<nL; i++){
        for(int j=0; j<nC;j++){
            matResul[i][j] = 0;
            for(int k=0; k<x;k++){
                matResul[i][j] = matResul[i][j] + (mat1[i][k]*mat2[k][j]);
            }
        }
    }
}
void preencheMatriz(int **mat, int nL, int nC){
    for(int i=0; i<nL; i++){
        printf("Informe os valores da linha %d : \n", i+1);
        for(int j=0; j<nC;j++){
            scanf("%d",&mat[i][j]);
        }
    }
}

int main()
{
    int **matA, **matB, **matC, numLA = 0, numCA = 0, numCB = 0;
    int i=0;

//Inseri o tamanho das matrizes
    printf("Informe o numero de linhas da matriz A: ");
    scanf("%d",&numLA);
    printf("\nInforme o numero de colunas da matriz A (tambem sera o numero de linhas de B): ");
    scanf("%d",&numCA);
    printf("\nInforme o numero de colunas da matriz B: ");
    scanf("%d",&numCB);

// Alocação das matrizes
    matA = malloc(numLA*sizeof(int*));
    matA[0] = malloc(numLA*numCA*sizeof(int));
    matB = malloc(numCA*sizeof(int*));
    matB[0] = malloc(numCA*numCB*sizeof(int));
    matC = malloc(numLA*sizeof(int*));
    matC[0] = malloc(numLA*numCB*sizeof(int));
    for(i=1;i<numLA;i++){
            matA[i] = matA[i-1]+numCA;
    }
    for(i=1;i<numCA;i++){
            matB[i] = matB[i-1]+numCB;
    }
    for(i=1;i<numLA;i++){
            matC[i] = matC[i-1]+numCB;
    }

//Colocar os valores na matriz
    printf("Preencha a matriz A!\n");
    preencheMatriz(matA,numLA,numCA);
    printf("Preencha a matriz B!\n");
    preencheMatriz(matB,numCA,numCB);

//chamada da operação multiplicação
    produtoMatricial(matA,matB,matC,numLA,numCA,numCB);

//impressão da matrizes A,B e C
    printf("Matriz A\n");
    imprimeMatriz(matA,numLA,numCA);
    printf("Matriz B\n");
    imprimeMatriz(matB,numCA,numCB);
    printf("Matriz C = AB\n");
    imprimeMatriz(matC,numLA,numCB);
    printf("\n\n");

//Liberação de memoria
    free(matA[0]);free(matA);
    free(matB[0]);free(matB);
    free(matC[0]);free(matC);
    return 0;
}
