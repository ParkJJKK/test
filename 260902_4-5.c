#include <stdio.h> 

int main (void)
{
  int a = 10, b=20, c=10;
  int res;

  res = (a>b);
  printf("a>b : %d\n", res); // a가 b보다 크면 1, 아니면 0 출력
  res = (a>=b);
  printf("a>=b : %d\n", res); // a가 b보다 크거나 같으면 1, 아니면 0 출력
  res = (a<b);
  printf("a<b : %d\n", res); // a가 b보다 작으면 1, 아니면 0 출력
  res = (a<=b);
  printf("a<=b : %d\n", res); // a가 b보다 작거나 같으면 1, 아니면 0 출력
  res = (a<=c);
  printf("a<=c : %d\n", res); // a가 c보다 작거나 같으면 1, 아니면 0 출력   
  res = (a==b);
  printf("a==b : %d\n", res); // a가 b와 같으면 1, 아니면 0 출력
  res = (a==c);
  printf("a==c : %d\n", res); // a가 c와 같으면 1, 아니면 0 출력  
  res = (a!=c);
  printf("a!=c : %d\n", res); // a가 c와 같지 않으면 1, 아니면 0 출력 
  res = (a!=b);
  printf("a!=b : %d\n", res); // a가 b와 같지 않으면 1, 아니면 0 출력

  return 0;
}