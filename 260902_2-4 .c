#include <stdio.h> // stdio : standard input
  //output(표준입출력)의 줄임말

int main(void)
{
    printf("%d\n", 10); //%d 위치에 10 출력
    printf("%lf\n", 3.4); //%lf 위치에 3.4 출력하고 소수점 6자리까지 표시
    printf("%.1lf\n", 3.45); //%.1lf 위치에 3.45 출력하고 소수점 한자리까지 표시  
    printf("%.10lf\n", 3.4);  //%.10lf 위치에 3.4 출력하고 소수점 10자리까지 표시

    printf("%d과 %d의 합은 %d입니다.\n", 10, 20, 10 + 20);
    
    printf("%.1lf-%.1lf=%.1lf\n", 3.4, 1.2, 3.4 - 1.2);    

    return 0;
}