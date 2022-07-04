#include <stdio.h>
#include <stdlib.h>

// realizar a soma entre 2 vetores
void soma(int *v1, int *v2, int *v3, int n){
  for(int i = 0; i < n; i++){
    v3[i] = v1[i] + v2[i];
  }
  for(int i = 0; i < n; i++){
    printf("%d ", v3[i]);
  }
  free(v1); //liberação de memória
  free(v2);
  free(v3);
}

int main(void) {
  int n;
  int *v1, *v2, *v3;
  scanf("%d", &n);
  v1 = malloc(n*sizeof(int)); //alocação dinâmica para os ponteiros
  v2 = malloc(n*sizeof(int));
  v3 = malloc(n*sizeof(int));
  for(int i = 0; i < n; i++){
    scanf("%d", &v1[i]);
  }
  for(int i = 0; i < n; i++){
    scanf("%d", &v2[i]);
  }
  soma(v1, v2, v3, n);
  return 0;
}
