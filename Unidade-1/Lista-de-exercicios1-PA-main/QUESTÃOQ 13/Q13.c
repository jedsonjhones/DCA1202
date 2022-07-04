#include <stdio.h>
#include <stdlib.h>

void ordenaValues(float *values, int n){
    int i=0 , j=0;
    float aux=0;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(values[i] < values[j]){
                aux = values[j];
                values[j] = values[i];
                values[i] = aux;
            }
        }
    }
}
void preencheaArray(float *valores, int n){
    float x=0;
    for(int i=0;i<n;i++){
        printf("\nInsira o %d valor: ", i+1);
        scanf("%f", &x);
        valores[i] = x;
    }
}

int main()
{
    int n;
    float *values;

    printf("Quantos valores deseja inserir: ");
    scanf("%d",&n);
    values = malloc(n*sizeof(float));
//Preenche os valores e em seguida os mostra na tela
    preencheaArray(values,n);
    printf("Valores inseridos: ");
    for(int i=0;i<n;i++){
        printf("%0.2f ",values[i]);
    }
//Ordena os valores e em seguida os mostra na tela
    ordenaValues(values,n);
    printf("\nValores ordenados: ");
    for(int i=0;i<n;i++){
        printf("%0.2f ",values[i]);
    }

    printf("\n\n");
    free(values);
    return 0;
}
