#include <stdio.h>

int main(void) 
{
 int a = 10, b = 20;
 const int *pa=&a;
 
 printf("변수 a 값: %d\n",*pa);// 10
 pa = &b;
 printf("변수 b 값: %d\n",*pa);// 20
 pa = &a;
 a = 20;
 printf("변수 a 값 : %d\n",*pa);// 20
 
 return 0;
}


