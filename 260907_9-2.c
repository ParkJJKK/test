#include <stdio.h>

int main(void) 
{
 int a;
 int *pa;

 pa= &a;//pa에 a의 주소입력
 *pa=10;//pa에 입력된 주소에 10입력 = a에 10입력
  

 printf("포인터로 a 값 출력: %d\n",*pa);
 printf("변수명으로 a 값 출력: %d\n",a);

 return 0;
}


