#include <stdio.h> 

int main (void)
{
  float grade;
  char name[20];

  printf("학점 입력 :");
  scanf("%f", &grade); //학점 입력
  printf("이름 입력 :");
  scanf("%s", name); //이름 입력 
  printf("%s의 학점은 %.1f입니다.\n", name, grade); //입력받은 학점과 이름 출력

  return 0;
}