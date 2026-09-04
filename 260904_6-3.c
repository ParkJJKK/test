#include <stdio.h> 

int main (void)
{ 
  int a = 1;
  
  do {a=a*2;} //do while 조건문 무조건 한번은 실행 (while 조건문은 실행안할수도있음)
  while (a<10);
  printf("a:%d\n",a);
  
  return 0;
}
