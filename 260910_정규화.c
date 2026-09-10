#include <stdio.h>

double map (double vale, double in_min,double in_max,double out_min,double out_max)
{
    double ratio = (vale - in_min)/(in_max-in_min);
    double result = out_min + ratio * (out_max - out_min);
    return result; 
}
void senavg (double sensor[],double avg[],int count,double in_min,double in_max,double out_min,double out_max)
{
    int i;
    for(i=0;i<count;i++)
    {
        avg[i]=map(sensor[i],in_min,in_max,out_min,out_max);
    }
}

int main(void)
{    
    //센서값 입력
    printf("센서인력값");
    double sensor[5];
    double avg[5];
    int i;
    for(i=0;i<5;i++)
    {
        scanf("%lf",&sensor[i]);
    } printf("\n");
    
    //입력 볌위  
    printf("입력 범위 :");
    double in_min , in_max;
    {
        scanf("%lf %lf",&in_min,&in_max);
    }
    
    //출력 볌위
    printf("출력 범위 :");
    double out_min ,out_max;
    {
        scanf("%lf %lf",&out_min,&out_max);
    }

    senavg(sensor,avg,5,in_min,in_max,out_min,out_max);

    printf("\n결과\n");
    for(i=0;i<5;i++)
    {
        printf("%d번째 센서값 %.1lf -> 정규화 %.1lf\n",i+1,sensor[i],avg[i]);
    } 
   
  
 return 0;
}

