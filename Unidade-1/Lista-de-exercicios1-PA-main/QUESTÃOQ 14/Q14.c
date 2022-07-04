//ordena valores com a função qsort
#include <stdio.h>
#include <stdlib.h>
void preencheArray(float *valores, int n){              // linhas 4-9: Função para inserir valores em um array qualquer
    for(int i=0;i<n;i++){
        printf("Insira o %d valor :", i+1);
        scanf("%f", &valores[i]);
    }
}
void imprimeArray(float *valores, int n){               // linhas 10-14: Função para mostrar na tela os valores de um array qualquer
    for(int i=0;i<n;i++){
        printf("%0.2f ", valores[i]);
    }
}
int funcaoComparacao(const void *a, const void *b){     // linhas 15-17: função de comparação a ser passada para a função de ordenamento "qsort"
    return (*(int*)a - *(int*)b);                       // atenção para a linha 17 onde acontece a conversão de const void para int.
}
int main()
{
    int n;                                              // declaração da variavel int "n"
    float *values;                                      // declaração do ponteiro para float "values"
    printf("Quantos valores deseja inserir? ");         // Mensagem para preencher "n"
    scanf("%d",&n);                                     // solicita um valor para "n"
    values = malloc(n*sizeof(float));                   // faz a alocação de "n" espaços na memoria para o array "values"

    printf("\nPreencha o array: \n");                   // mensagem para iniciar o preenchimento do array "values" com valores aleatorios
    preencheArray(values,n);                            // invoca a função para inserir cada valor
    printf("\nValores inseridos: ");                    // mensagem informando que será mostrado todos os valores inserido
    imprimeArray(values,n);                             // invoca a função para mostrar cada valor

    qsort(values,n,sizeof(float),funcaoComparacao);     // invoca a função de ordenamento
    printf("\nValores ordenados: ");                    // mensagem informando que será mostrado todos os valores, porém ordenados
    imprimeArray(values,n);                             // invoca a função para imprimir o novo array ordenado


    printf("\n\n");                                     // quebra de linha
    free(values);                                       // libera os espaços de memoria alocado anteriormente
    return 0;
}
