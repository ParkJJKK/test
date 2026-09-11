#include <stdio.h> 

typedef struct
{
    int num;
    double grade;
}Student;

void print_data(Student *ps);

int main(void) {
    
   Student s1 = {315,4.2};

   print_data(&s1);

   return 0;
        
}

void print_data(Student *ps)
{
   printf("학번 : %d\n",ps->num);
   printf("학점 : %.1lf\n",ps->grade);
}