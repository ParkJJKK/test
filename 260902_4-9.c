#include <stdio.h> 

int main (void)
{
  int a = 10;
  double b = 3.4;

  printf("int형 변수의 크기 : %d\n", sizeof(a)); // int형 변수의 크기 출력
  printf("double형 변수의 크기 : %d\n", sizeof(b)); // double형 변수의 크기 출력
  printf("정수형 상수의 크기 : %d\n", sizeof(10)); // 정수형 상수의 크기 출력
  printf("수식의 결괏값의 크기 : %d\n", sizeof(1.5+3.4)); // 수식의 결괏값의 크기 출력
  printf("char 자료형의 크기 : %d\n", sizeof(char)); // char 자료형의 크기 출력
  
  return 0;
}