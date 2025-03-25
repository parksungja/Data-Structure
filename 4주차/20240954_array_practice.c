// 실습 1. 정적 데이터 값의 처리

#include <stdio.h>

int main() {
    int sales[12] = {200, 300, 250, 400, 320, 600, 500, 700, 450, 350, 400, 300};
    int total = 0, maxSales = sales[0], maxMonth = 0;

    // 합계 및 최대 매출 계산
    for (int i = 0; i < 12; i++) {
        total += sales[i];
        if (sales[i] > maxSales) {
            maxSales = sales[i];
            maxMonth = i;
        }
    }

    // 결과 출력
    printf("총 매출: %d\n", total);
    printf("최대 매출: %d (월: %d)\n", maxSales, maxMonth + 1); // 월은 1부터 시작

    return 0;
}