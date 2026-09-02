#include <stdio.h> 

int main (void)
{
  int a = 10;
  int b = 20;

  printf("a&b : %d\n", a&b); // a와 b의 비트 AND 연산
  printf("a|b : %d\n", a|b); // a와 b의 비트 OR 연산
  printf("a^b : %d\n", a^b); // a와 b의 비트 XOR 연산
  printf("~a : %d\n", ~a); // a의 비트 NOT 연산
  printf("a << 1 : %d\n", a << 1); // a의 비트 왼쪽 시프트 연산
  printf("a >> 2 : %d\n", a >> 2); // a의 비트 오른쪽 시프트 연산
    
  return 0;
}