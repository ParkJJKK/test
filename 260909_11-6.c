#include <stdio.h>

void my_gets(char *str,int size);
void print_remaining_buffer(void);


int main(void)
{    
    char str[7];
    char strn;
    my_gets(str,sizeof(str));
    printf("입력한 문자열 : %s\n",str);
    print_remaining_buffer();

    return 0;
}
void my_gets(char *str,int size)
{
    int ch;
    int i;

    ch = getchar();
    while ((ch!='\n')&&(i<size -1))
    {
        str[i]=ch;
        i++;
        ch=getchar();
    }
    
    
}

void print_remaining_buffer(void) {
    int ch;
    printf("\n--- 남은 버퍼 내용 확인 ---\n");
    
    // 버퍼에 문자가 없거나 엔터('\n')를 만날 때까지 1글자씩 꺼내서 출력
    while ((ch = getchar()) != '\n' && ch != EOF) {
        printf("버퍼에 남아있던 문자: '%c' (ASCII: %d)\n", ch, ch);
    }
    
    printf("--- 버퍼 비우기 완료 ---\n\n");
}

