#include <stdio.h> // stdio : standard input
  //output(표준입출력)의 줄임말

int main(void)
{
    printf("Be happy\n"); //문자열 "Be happy" 출력하고 줄바꿈(\n)
    printf("12345678901234567890\n"); //화면에 열 번호 출력하고 줄을 바꿈
    printf("My\t friend\n"); //"My"를 출력하고 탭 위치로 이동(\t) 후에 "friend" 출력하고 줄바꿈(\n)
    printf("Goot\bd\t chance\n"); //"Goot"출력후 한칸 왼쪽으로 이동(\b)해
    //t를 d로 바꾸고 탭위치로 이동(\t) 후에 "chance"를 출력하고 줄을 바꿈(\n)
    printf("Cow\rW\a\n");
    // 맨앞으로 이동(\r)해 C를 W로 바꾸고 벨소리(\a)를 내고 줄을 바꿈(\n)

    return 0;
}