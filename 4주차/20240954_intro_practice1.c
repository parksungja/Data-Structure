// 실습 1.1 학생 성적 관리 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int scores[10];  // 10명의 학생 성적 저장
    int sum = 0;
    double average = 0;

    // 난수 생성 초기화
    srand(time(0));

    // 성적 데이터 초기화
    for (int i = 0; i < 10; i++) {
        scores[i] = rand() % 101;   // 0 ~ 100 사이의 난수 생성
        sum += scores[i];   // 성적 합계
    }

    // 평균 계산
    average = sum / 30.0;
    printf("학급 평균 점수: %.2f\n", average);

    return 0;
}