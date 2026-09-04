#include <stdio.h> 

int get_num(void);

int main(void)
{ 
  int a,b,c,d,e;

  a = get_num();
  b = get_num();
  c = get_num();
  d = get_num();
  e = get_num();

  printf("반환값 ABCDE : %d%d%d%d%d\n",a,b,c,d,e);
  
return 0;
}
int get_num(void)
{
  int num;

  printf("정수 입력 : ");
  scanf("%d",&num);
  
  return num;
}