#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int max_speed;
    int n;

    // 난수 생성기 초기화
    srand(time(NULL));

    // 1. 최대 속도 및 데이터 개수(N) 입력받기
    printf("최대 속도를 입력하세요: ");
    scanf("%d", &max_speed);

    printf("생성할 속도 데이터 개수(N)를 입력하세요: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("데이터 개수는 1 이상이어야 합니다.\n");
        return 0;
    }

    int speed[1000]; // 속도 데이터를 저장할 배열 (N의 최대 크기에 맞춰 조정 가능)

    // 초기 속도는 0
    speed[0] = 0;

    int current_index = 1;

    // 2 & 4. 가속/감속 상태를 랜덤으로 결정하며 N개의 데이터 채우기
    while (current_index < n) {
        // 가속(1) 또는 감속(0) 랜덤 선택
        int is_acceleration = rand() % 2;

        // 해당 가속/감속을 유지할 횟수 (10 ~ 14회)
        int duration = (rand() % 5) +10;

        for (int i = 0; i < duration && current_index < n; i++) {
            // 변화량 (1 ~ 10 범위)
            int delta = (rand() % 10) + 1;

            if (is_acceleration) {
                // 가속: 이전 속도 + delta
                speed[current_index] = speed[current_index - 1] + delta;
            } else {
                // 감속: 이전 속도 - delta
                speed[current_index] = speed[current_index - 1] - delta;
            }

            // 3. 속도 범위 제어 (0 이상, max_speed 이하)
            if (speed[current_index] > max_speed) {
                speed[current_index] = max_speed;
            }
            if (speed[current_index] < 0) {
                speed[current_index] = 0;
            }

            current_index++;
        }
    }

    // 5. 생성된 속도 데이터 및 가속/감속 과정 출력
    printf("\n=== 주행 속도 데이터 로그 ===\n");
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("[%d번째] 속도: %d (시작)\n", i + 1, speed[i]);
        } else {
            int diff = speed[i] - speed[i - 1];
            printf("[%d번째] 속도: %d (변화량: %+d)\n", i + 1, speed[i], diff);
        }
    }

    // 이미지 요구사항: 급가속(Δv >= +10), 급제동(Δv <= -10) 횟수 계산
    int hard_accel = 0;
    int hard_brake = 0;

    for (int i = 1; i < n; i++) {
        int delta = speed[i] - speed[i - 1];

        if (delta >= 7) {
            hard_accel++;
        } else if (delta <= -7) {
            hard_brake++;
        }
    }

    // 최종 결과 출력
    printf("\n=== 분석 결과 ===\n");
    printf("급가속(Δv >= +10) 횟수: %d회\n", hard_accel);
    printf("급제동(Δv <= -10) 횟수: %d회\n", hard_brake);

    return 0;
}


