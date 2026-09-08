#include <stdio.h>

int main(void) 
{
 int N;//센서 개수
 int valua[1000];//센서로부터 입력되는값  
 int threshold;//비교값(0~1023)
 int i;

 printf("센서갯수 : "); scanf("%d",&N);
 printf("센서에 입력된 값 : "); 
 for(i=0;i<N;i++){
 scanf("%d",&valua[i]);
  }
 printf("Threshold : ");scanf("%d",&threshold);
 printf("\n");

 int label[N];

 for(i=0;i<N;i++)
 {
   if(valua[i] < threshold){
      label[i]=1;}
   else{
      label[i]=0;
   }
 }
 int black_count=0;
 double sum_index=0;
 for(i=0,i<N;i++;)
 {
   black_count+=label[i];
   sum_index+= i*label[i];
 }
 printf("결과\n");
 printf("블럭 갯수 : %d\n",black_count);
 if(black_count == 0){
   printf("라인없음");
 }else{
   double index_avg = sum_index / black_count;
   printf("인덱스 평균 : %.2lf\n",index_avg);
 }
 

 return 0;
}


