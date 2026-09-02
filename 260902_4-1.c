#include <stdio.h> 

int main (void)
{
  int a,b;
  int sum, sub, mul, inv;

  printf("두 개의 정수를 입력하세요 : ");
  scanf("%d %d", &a, &b);

  sum = a + b;
  sub = a - b;
  mul = a * b;
  inv = -a;

  printf("덧셈 : %d\n", sum);
  printf("뺄셈 : %d\n", sub);
  printf("곱셈 : %d\n", mul);
  printf("마이너스 : %d\n", inv);

  return 0;
}