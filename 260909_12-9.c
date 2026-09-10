#include <stdio.h>
#include <string.h>

int main(void)
{    
   char str [20]="mango tree";
   char str2[20]="apple world";

   strncpy(str, "apple-pie",5);
   strncpy(str2, "Hello",5);
   
   printf("%s\n",str);
   printf("%s\n",str2);
   


   return 0;
}


