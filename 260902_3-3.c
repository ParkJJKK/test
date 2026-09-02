#include <stdio.h> 

int main(void)
{
  short sh = 32767; //short형 변수 sh 선언 및 초기화
  int in = 2147483647; //int형 변수 a 선언 및 초기화
  long ln = 2147483647; //long형 변수 ln 선언 및 초기화
  long long lln = 123451234512345; //아주 큰 값 초기화

  printf("short형 변수 sh의 값 : %d\n", sh);
  printf("int형 변수 in의 값 : %d\n", in);
  printf("long형 변수 ln의 값 : %ld\n", ln);
  printf("long long형 변수 lln의 값 : %lld\n", lln);
  //long long형은 lld로 출력
  
  return 0;
}