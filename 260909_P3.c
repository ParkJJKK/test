#include <stdio.h>

int main(void)
{  
   int i,j,k;
   char A='0';
   char B='*';

   int score[5][5];
    for(i=0;i<5;i++){
      for(j=0;j<5;j++)
      {
         if(i!=j){
           score[i][j]=A;
         }else score[i][j]=B;
         printf("%5c",score[i][j]);
      }
      printf("\n");
   }
   printf("\n");

   int score1[5][5];
   for(i=0;i<5;i++){
      for(j=0;j<5;j++)
      {
         if(i+j==4){
            score1[i][j]=B;
         }else score1[i][j]=A;
         printf("%5c",score1[i][j]);
      }
      printf("\n");
   }
   printf("\n");

   int score3[5][5];
   for(i=0;i<5;i++){
      for(j=0;j<5;j++){
         if(score[i][j]==B||score1[i][j]==B){
            score3[i][j]=B;
         }else score3[i][j]=A;
         printf("%5c",score3[i][j]);
      }
      printf("\n");
   }

   
   return 0;
}

