#include <stdio.h> 

union student{
    int num;
    double grade;
};

int main(void) {
    int a;
    union student A;
    a=sizeof(A);

    printf("size : %d\n",a);

    
    return 0;
}