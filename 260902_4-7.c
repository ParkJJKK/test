#include <stdio.h> 

int main (void)
{
  int a = 10, b=20, res;

  a+b; // 연산결과 버려짐
  printf("%d+%d=%d\n",a,b,a+b); // 연산결과를 바로 출력

  res = a+b; // 연산결과 변수 저장
  printf("%d+%d=%d\n",a,b,res); // 저장된값 사용
  
  return 0; 
}