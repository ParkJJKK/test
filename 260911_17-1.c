#include <stdio.h> 

struct student
{
    int num;
    double grade;
};
struct size
{
    char ch1;
    char ch2;
    char ch3;
    short num;
    int score;
    int grade;

};

int main(void) {
    
    struct student s1;
    struct size ss;
    int a;
    a=sizeof(ss);


    s1.num = 2;
    s1.grade = 2.7;
    printf("학번 :%d\n",s1.num);
    printf("학점 :%.1lf\n",s1.grade); 
    printf("ss size :%d\n",a);


    return 0;
    
}