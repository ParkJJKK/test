#include <stdio.h>

int main() {
    int N;
    int sum = 0;
    int i = 1;

    printf("N을 입력하세요: ");
    scanf("%d", &N);

    while (i <= N) {
        
        if (i % 3 == 0) {
            sum = sum + i;
        }
        i = i + 1;
    }

    
    printf("결과 (sum): %d\n", sum);

    return 0;
}