#include <stdio.h>

int main()
{
    char x[4];
    int y[4];
    float z[4];
    double k[4];
   for(int i=0; i<4; i++){
       printf("Endereco de : Char (x+%d) = %d | Int (y+%d) = %d | Float (z+%d) = %d | Double (k+%d) = %d",i,x+i,i,y+i,i,z+i,i,k+i);
       printf("\n");
   }


    return 0;
}
