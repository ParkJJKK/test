#include <stdio.h>


int main(void) 

{
    int a = 10;
    int *p = &a;
    printf("Before change(변경 전): a=%d\n",a);
    printf("Address of a(a의 주소):%p\n",&a);
    printf("Pointer p Address(p가 저장한 주소):%p\n",p);

    *p=20;
    printf("after change (변경 후):a=%d\n",a);
    printf("Value through pointer (포인터로 읽은 값):%d\n",*p);
    
    return 0; 
}  


