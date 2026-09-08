#include <stdio.h>

int main(void)
{
    int ary[5]={0,1,2,3,4};
    int *p=ary;
    int i;

    printf("Array elements(배열 요소 출력):\n");

    for(i=0;i<5;i++)
    {
        printf("Element %d (요소 %d):%d\n",i,i,*p+i);
    }

    return 0;

}
