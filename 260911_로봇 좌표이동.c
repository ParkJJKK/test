#include <stdio.h> 

// 1. Position 구조체 정의
typedef struct {
    int x;
    int y;
} Position;


void move(Position *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

int main(void) {
    //현재 위치 (0, 0)에서 시작하는 로봇 선언
    Position robot = {0, 0};

    //main 함수에서 이동 수행
    // 첫 번째 이동: (+5, +3)
    move(&robot, 5, 3);
    
    // 두 번째 이동: (-2, +4)
    move(&robot, -2, 4);

    // 최종 좌표 출력
    printf("로봇 최종 위치: (%d, %d)\n", robot.x, robot.y);

    return 0;
}