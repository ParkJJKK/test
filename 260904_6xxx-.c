#include <stdio.h> 

int main (void) //무한반복에서 연속된고 짝수를 제외한 홀수를 모두 더하면서 결과같이 100이되기전에 멈춰라 
{ 
  int count;
  int i,j;

  count=1;
  while (1)
  { 
   if(j==100) break;
   if(i%2==0)
   {
    continue;
   }
   for(i=0;i<0;i++)
   {
    j=count+i;
    printf("%d+%d=%d\n",count,i,j);
    count++;
   }

  }
return 0;
}
