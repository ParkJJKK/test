#include <stdio.h> // stdio : standard input
  //output(표준입출력)의 줄임말

int main(void)
{
  printf("%.1lf\n", 1e6); 
  printf("%.7lf\n", 3.14e-5); 
  printf("%le\n", 0.0000314); //소수점 형태의 실수를 지수형태로 출력
  printf("%.2le\n", 0.0000314); //지수형태로 소수점 이하 두 자리까지 출력
  
  return 0;
}