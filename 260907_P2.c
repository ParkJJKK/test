#include <stdio.h>

int main(void) {
    int N, i;
    double battery[100];
    int warning = 0; // 0: OFF, 1: ON

    // 데이터 개수 N 입력 (예시: 10)
    printf("데이터 개수 N을 입력하세요: ");
    if (scanf("%d", &N) != 1) return 0;

    // 배터리 잔량 데이터 입력
    printf("%d개의 배터리 잔량(%%)을 입력하세요:\n", N);
    for (i = 0; i < N; i++) {
        scanf("%lf", &battery[i]);
    }

    printf("\n--- 처리 결과 ---\n");
    // 각 시점별 히스테리시스 경고 상태 업데이트 및 출력
    for (i = 0; i < N; i++) {
        double level = battery[i];

        // 조건 처리
        if (warning == 0 && level <= 30.0) {
            warning = 1; // 경고 켜짐 (ON)
        } else if (warning == 1 && level >= 35.0) {
            warning = 0; // 경고 꺼짐 (OFF)
        }

        // 결과 출력
        printf("시점 %2d | 배터리: %5.1f%% | 경고 상태: %s\n", 
               i + 1, level, warning ? "ON" : "OFF");
    }

    return 0;
}


