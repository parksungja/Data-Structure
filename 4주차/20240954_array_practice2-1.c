// 실습 2. 정해진 학생 수를 가진 학급의 성적 처리
// 코드 1. main함수에 모두 작성

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int scores[30];
    int sum = 0;
    double average = 0;
    int studentNumber;

    // 난수 생성 초기화
    srand(time(0));

    // 성적 데이터 초기화
    for (int i = 0; i < 30; i ++){
        scores[i] = rand() % 101;   // 0 ~ 100 사이의 난수 생성
        sum += scores[i];   // 성적 합계
    }

    // 평균 계산
    average = sum / 30.0;
    printf("학급 평균 점수 : %2.f\n", average);

    // 특정 학생 점수 검색
    printf("학생 번호를 입력하세요 (1 ~ 30) : ");
    scanf("%d", &studentNumber);

    if(studentNumber >= 1 && studentNumber <= 30){
        printf("%d번 학생의 점수 : %d\n", studentNumber, scores[studentNumber]);
    } else {
        printf("유효하지 않은 학생 번호 입니다.\n");
    }

    return 0;
}