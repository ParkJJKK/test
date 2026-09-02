#include <stdio.h> 
#include <string.h> // 문자열 처리 함수가 선언된 헤더파일

int main (void)
{
  char fruit[20] = "strawberry"; // char형 배열 선언과 문자열 초기화

  printf("%s\n", fruit); 
  strcpy(fruit, "banana"); // 문자열 복사 함수 strcpy()를 이용하여 fruit에 "banana" 복사
  printf("%s\n", fruit);  //fruit에 저장된 문자열 출력

  return 0;
}