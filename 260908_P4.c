#include <stdio.h>

void swap(int *pa,int *pb);

int main(void) 
{
    int a,b;
        
    printf("Enter two integers(두 정수를 입력하세요):");scanf("%d %d",&a,&b);
    printf("\nBefore swap (교환 전): a=%d,b=%d",a,b);
    swap(&a,&b);
    printf("\nAfter swap (교환 후): a=%d,b=%d",a,b);
  
    return 0;
}  

void swap(int *pa,int *pb)
{
    int temp;

    temp = *pa;
    *pa=*pb;
    *pb=temp;
}
