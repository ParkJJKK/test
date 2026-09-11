#include <stdio.h> 

typedef struct{
    int num;
    char name[20];
    int kor;
    int eng;
    int math;
    double grade;
    char ABCF;
    
}Student;



int main(void) 
{
    
    Student list [5]={        
        {315,"홍길동",80,75,90},
        {316,"이순신",88,92,100},
        {317,"서하윤",95,99,98},
        {318,"유관순",84,70,72},
        {319,"박신혜",60,65,40}
    };
    

    int i;
    char pa1='A';
    char pa2='B';
    char pa3='C';
    char pa4='F';
    
        
    for(i=0;i<5;i++)
    {
        list[i].grade = (list[i].kor+list[i].eng+list[i].math)/3.0;
        if(list[i].grade>=90){
            list[i].ABCF=pa1;}
        
            else if(list[i].grade>=80){
             list[i].ABCF=pa2;}
            
             else if(list[i].grade>=70){
                list[i].ABCF=pa3;}
             
        else {list[i].ABCF=pa4;}
    }
    int j;
  Student temp;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4 - i; j++) {
        // 앞 학생의 학점이 뒤 학생 학점보다 크면 위치 교환 (A < B < C < F)
        if (list[j].ABCF > list[j + 1].ABCF) {
            temp = list[j];
            list[j] = list[j + 1];
            list[j + 1] = temp;
        }
    }
  }

 // --- 기존 출력 코드 ---
 for (i = 0; i < 5; i++) {
    printf("%5d%15s%5d%5d%5d%10.1lf%5c\n",
        list[i].num, list[i].name, list[i].kor, list[i].eng, list[i].math, list[i].grade, list[i].ABCF);}

    
 return 0;
}


