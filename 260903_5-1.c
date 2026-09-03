#include <stdio.h> 

int main (void)
{
  int a = 20;
  int b = 0;

  if (a > 10)
  {
    b = a;
  }
  
  printf("a:%d, b:%d\n", a, b); // a가 10보다 크므로 b에 a의 값이 대입되어 b=20
    
  return 0;
}