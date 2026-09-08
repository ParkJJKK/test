#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) 
{
    double reg[360];
    double dis;
    int count=360;
    int i;
    int j;
    
    srand(time(NULL));    

    for(i=0;i<count;i++)
    {
        reg[i]=rand()%500;
    }

    for(i=0;i<count;i++)
    {
        printf("  %3.1lf",reg[i]); 
        if(i%10==0)
        {
            printf("\n");
        } 
    }
    double lowD;
    int lowA;
    for(i=0;i<count;i++)
    {
        if(reg[i]<lowD){
            lowD = reg[i];
            lowA = i;
        }
    }
    printf("\n");
    printf("각도를 입력하세요. : "); scanf("%d",&i);
    printf("각도 %d도에 측정거리 : %.2lf",i,reg[i]);
    printf("\n[라이다 최소 거리 탐색 결과]\n");
    printf("가장 가까운 거리 : %.2lf\n",lowD);
    printf("최소거리 각도 : %d\n",lowA);
    
    return 0; 
  
}


