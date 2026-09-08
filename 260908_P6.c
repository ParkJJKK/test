#include <stdio.h>

int count(char *pa);

int main(void)
{
    char ary[1000];
    int *pa = ary;
    int HL;

    printf("Enter a string (문자열을 입력하세요): "); 
    scanf("%s",ary);
    HL = count(ary);

    printf("Length of string (문자열 길이): %d\n",HL);
    

    return 0;
}

int count(char *pa)
{
    int count=0;
    while(*pa!='\0')
    {
        count++;
        *pa++;
    }
    return count;
}