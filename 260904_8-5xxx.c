#include <stdio.h> 
#include <string.h>


int main(void)
{ 
  char str1[80]="cat";
  char str2[80];

  strcpy(str1, "tiger");
  strcpy(str1, str2);
  printf("%s,%s\n",str1,str2);

  return 0;
}
//string.h의 strcpy를 대체할수있는 함수만들기
