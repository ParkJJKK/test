#include <stdio.h> 

int main (void)
{
  int a = 10, b=20;
  int res = 2;

  a+=20;
  res*=b+10;
  a-=b*res;
  a+=1200;


  printf("a = %d, b = %d, res = %d\n", a, b, res);
  
  return 0;
}