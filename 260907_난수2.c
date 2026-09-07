#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N;

    printf("배열의 크기 N을 입력하세요: ");
    scanf("%d", &N);

    // N을 입력받은 후 배열 선언
    int arr[N];

    // 난수 초기화
    srand(time(NULL));

    // 배열에 랜덤 숫자 대입 (0 ~ 99)
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }

    // 결과 출력
    printf("\n생성된 %d개의 랜덤 요소:\n", N);
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
