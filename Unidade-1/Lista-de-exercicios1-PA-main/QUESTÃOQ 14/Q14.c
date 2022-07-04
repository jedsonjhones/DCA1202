//ordena valores com a fun��o qsort
#include <stdio.h>
#include <stdlib.h>
void preencheArray(float *valores, int n){              // linhas 4-9: Fun��o para inserir valores em um array qualquer
    for(int i=0;i<n;i++){
        printf("Insira o %d valor :", i+1);
        scanf("%f", &valores[i]);
    }
}
void imprimeArray(float *valores, int n){               // linhas 10-14: Fun��o para mostrar na tela os valores de um array qualquer
    for(int i=0;i<n;i++){
        printf("%0.2f ", valores[i]);
    }
}
int funcaoComparacao(const void *a, const void *b){     // linhas 15-17: fun��o de compara��o a ser passada para a fun��o de ordenamento "qsort"
    return (*(int*)a - *(int*)b);                       // aten��o para a linha 17 onde acontece a convers�o de const void para int.
}
int main()
{
    int n;                                              // declara��o da variavel int "n"
    float *values;                                      // declara��o do ponteiro para float "values"
    printf("Quantos valores deseja inserir? ");         // Mensagem para preencher "n"
    scanf("%d",&n);                                     // solicita um valor para "n"
    values = malloc(n*sizeof(float));                   // faz a aloca��o de "n" espa�os na memoria para o array "values"

    printf("\nPreencha o array: \n");                   // mensagem para iniciar o preenchimento do array "values" com valores aleatorios
    preencheArray(values,n);                            // invoca a fun��o para inserir cada valor
    printf("\nValores inseridos: ");                    // mensagem informando que ser� mostrado todos os valores inserido
    imprimeArray(values,n);                             // invoca a fun��o para mostrar cada valor

    qsort(values,n,sizeof(float),funcaoComparacao);     // invoca a fun��o de ordenamento
    printf("\nValores ordenados: ");                    // mensagem informando que ser� mostrado todos os valores, por�m ordenados
    imprimeArray(values,n);                             // invoca a fun��o para imprimir o novo array ordenado


    printf("\n\n");                                     // quebra de linha
    free(values);                                       // libera os espa�os de memoria alocado anteriormente
    return 0;
}
