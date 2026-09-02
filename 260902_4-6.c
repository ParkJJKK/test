#include <stdio.h> 

int main (void)
{
  int a = 30;
  int res;

  res = (a>10) && (a<20); // a가 10보다 크고 20보다 작은지 확인
  printf("(a>10) && (a<20) : %d\n", res);
  res = (a<10) || (a>20); // a가 10보다 작거나 20보다 큰지 확인
  printf("(a<10) || (a>20) : %d\n", res);
  res = !(a>10); // a가 10보다 크지 않은지 확인
  printf("!(a>10) : %d\n", res);  

  return 0;
}