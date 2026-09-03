#include <stdio.h> 

int main (void)
{
  int a = 2;
 
  if (a >= 10)
  {
    a = 1;
  }
  else
  {
    a = -1;
  }

  printf("a:%d\n", a); // a가 10보다 크므로 a에 1이 대입되어 a=1
    
  return 0;
}