#include <stdio.h>

int main(void)
{
   int a=10;
   int *pi;
   int **ppi;
   int ***pppi;

   pi = &a;
   ppi = &pi;
   pppi = &ppi;

   printf("-----------------------------------------------------\n");
   printf("변수  변숫값  &연산  *연산  **연산  ***연산\n");
   printf("-----------------------------------------------------\n");
   printf(" a   %10d%20u\n", a, &a);
   printf("pi   %20u%20u%20d\n", pi, &pi, *pi);
   printf("ppi  %20u%20u%20u%20u\n", ppi, &ppi,*ppi,**ppi);
   printf("pppi %20u%20u%20u%20u%20u\n", pppi, &pppi,*pppi,**pppi,***pppi);
   printf("-----------------------------------------------------\n");


   return 0;


}

