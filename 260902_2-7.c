#include <stdio.h> // stdio : standard input
  //output(표준입출력)의 줄임말

int main(void)
{
  printf("%c\n", 'A'); // 문자상수 출력
  printf("%s\n", "AB"); // 문자열상수 출력
  printf("%c은 %s입니다.\n", '1', "first"); // 문자(%c)와 문자열(%s) 출력

  return 0;
}