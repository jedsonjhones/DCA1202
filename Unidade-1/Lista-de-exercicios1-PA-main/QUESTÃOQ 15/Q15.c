#include <stdio.h>
#include <stdlib.h>

// q fun��o realizar compara��o entre 2 valores
int compare (float a, float b){
  if(a < b){
    return -1;
  }else if(a > b){
    return 1;
  }else{
    return 0;
  }
}

// realiza troca caso a > b
void troca(float *a, float *b){
  float aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

//fun��o qsort()
void meusort(float *vetor,int n, int(*compare)(float, float)){
  for(int i = 0; i < n-1; i++){
    for(int j = i+1; j<n; j++){
      if(compare(vetor[i], vetor[j]) == 1){
        troca(&vetor[i], &vetor[j]);
      }
    }
  }
}

int main ()
{
  int n;
  scanf("%d", &n);
  float *vetor;
  vetor = malloc(n*sizeof(float)); //aloca��o de mem�ria din�mica para o ponteiro vetor
  for(int i = 0; i < n; i++){
    scanf("%f", &vetor[i]); //leitura dos valores do vetor
  }
  meusort(vetor, n, compare); //uso da fun��o qsort para ordena��o
  for(int i = 0; i<n; i++){
    printf ("%f ",vetor[i]);
  }
  free(vetor); //libera��o da memoria
  return 0;
}
