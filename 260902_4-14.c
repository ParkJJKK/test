#include <stdio.h> 

int main (void)
{
  int a = 10, b=5;
  int res;

  res = a / b * 2;
  printf("res = %d\n", res); // 10/5*2 = 4
  res = ++a * 3;
  printf("res = %d\n", res);  // 전위연산자 ++a로인해 int a의 값이 11로 증가 후 11*3 = 33
  res = a > b && a != 5;
  printf("res = %d\n", res); // a가 b보다 클경우 참(1) 11>5임으로 참(1) 
    //a가 5가 아닐경우 참(1) 11!=5임으로 참(1) 따라서 and게이트 1&&1 = 1
  res = a % 3 == 0;
  printf("res = %d\n", res);  
  // 11을 3으로 나눈 뒤 남은 나머지가 0과 같을경우 참(1),나머지 2임으로 거짓(0)
    
  return 0;
}