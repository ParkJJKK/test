#include <stdio.h>

int main(void) 
{
 double ary[5]={1.2,3.5,7.4,0.5,10};
 double *pa = ary;
 double *pb = ary+2;

 printf("%lf",pb[-2]);

 return 0;
}


