#include <stdio.h>

int main(void) 
{
 int ary[3]={10,20,30};
 int *pa = ary;
 int i;

 printf("배열의 값 : ");
 
 for(i=1;i<3;i++)
 {
  printf("%5d",*pa);
  pa++;
 }
 printf("\n");
  
 return 0;
}


