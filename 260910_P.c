#include <stdio.h>

int main(void)
{    
   int ary[5][6];
   int i,j;
   int num=0;
   int sum1=0;
   int sum2=0;
  
   for(i=0;i<4;i++)
   {
      for(j=0;j<5;j++)
      {
         num+=1;
         ary[i][j]=num;
                      
      } 

    
   }
   
   for(i=0;i<4;i++){
      sum1=0;
      for(j=0;j<5;j++){
        
       sum1+=ary[i][j];
      }
      ary[i][5] = sum1;
     
   }   

   for(j=0;j<6;j++){
      sum2=0;
      for(i=0;i<4;i++){
         sum2 += ary[i][j];
      }
      ary[4][j]=sum2;
   }

   for(i=0;i<5;i++)
   {
      for(j=0;j<6;j++){
         printf("%5d",ary[i][j]);
      }
      printf("\n");
   }
       
   
   
  
 return 0;
}

