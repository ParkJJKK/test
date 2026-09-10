#include <stdio.h>
#include <string.h>

void swap(const char *type, void *pa, void *pb) {
    if (strcmp(type, "int") == 0) {
        int temp = *(int *)pa;
        *(int *)pa = *(int *)pb;
        *(int *)pb = temp;
    } 
    else if (strcmp(type, "double") == 0) {
        double temp = *(double *)pa;
        *(double *)pa = *(double *)pb;
        *(double *)pb = temp;
    }
}

int main(void) {
    int age1, age2;
    double height1, height2;

    // 입력 받기
    printf("첫 번째 사람의 나이와 키 입력 : ");
    scanf("%d %lf", &age1, &height1);

    printf("두 번째 사람의 나이와 키 입력 : ");
    scanf("%d %lf", &age2, &height2);

    // swap 함수 호출
    swap("int", &age1, &age2);
    swap("double", &height1, &height2);

    // 결과 출력
    printf("첫 번째 사람의 나이와 키 : %d, %.1f\n", age1, height1);
    printf("두 번째 사람의 나이와 키 : %d, %.1f\n", age2, height2);

    return 0;
}
