#include <stdio.h>


int main(void)
{    
    char ch;
    int res;

    while(1)
    {
        res=scanf("%c",&ch);
        if(res==EOF) break; //EOF = -1
        printf("%d",ch);
    }
    

    return 0;

}
