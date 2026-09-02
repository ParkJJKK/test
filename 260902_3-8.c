#include <stdio.h> 

int main (void)
{
  int income = 0; // 소득(income) 초기화
  double tax; //세금
  const double tax_rate = 0.12; //세율 초기화

  income = 456; //소득 저장
  //tax_rate = 0.2; // 세율 변경 안됨
  tax = income * tax_rate; //세금 계산
  printf("세금 : %.1lf\n", tax);

  return 0;
}