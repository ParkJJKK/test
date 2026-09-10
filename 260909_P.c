#include <stdio.h>

void my_string_cat (char *pa,char *pb)   
{
   int i;
   int j;
   int count1=sizeof(*pa);
   int count2=sizeof(*pb);
   int count=count1+count2;

   for(i=count1;i<count;i++){
      if(pa[i]!='\0') continue;
      *pa[i]=*pb
      
      
      
   }
 
} 

int main(void){
   char str1[20] = "apple";
   char str2[20]= "banana";

   my_string_cat(str1,str2);
   printf("%s\n",str1);

   return 0;

}

