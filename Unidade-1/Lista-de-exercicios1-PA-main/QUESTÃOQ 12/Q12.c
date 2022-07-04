#include <stdio.h>

void inc (int *n)
{
   (*n)++ ;
}
int main ()
{
   void (*fp) (int *) ;
   fp = inc ;

   int a = 0 ;

   printf ("a vale %d\n", a) ;
   inc(&a) ;

   printf ("a vale %d\n", a) ;
   fp(&a) ;

   printf ("a vale %d\n", a) ;

   return (0) ;
}
