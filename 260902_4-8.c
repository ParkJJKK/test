#include <stdio.h> 

int main (void)
{
  int a = 20, b= 3; 
  double res,res2;

  res = a/b; 
  res2 = ((double)a)/((double)b); 
  printf("a = %d, b = %d\n", a, b);
  printf("a/b의 결과 : %.3lf\n", res); 
  printf("a/b (double)의 결과 : %.3lf\n", res2); 

  a = (int)res2; // (int)를 사용해 res의 값에서 정수 부분만 추림
  printf("(int) %.3lf의 결과 : %d\n", res2, a);
  
  return 0;
}