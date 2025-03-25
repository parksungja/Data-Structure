// 실습 2. 정해진 학생 수를 가진 학급의 성적 처리
// 코드 2. 함수로 분리

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 함수 선언
double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);

int main(){
    int scores[30];
    int studentNumber;
    double average;

    // 난수 생성 초기화
    srand(time(0));

    // 성적 데이터 ch기화
    for (int i = 0; i < 30; i++){
        scores[i] = rand() % 101;   // 0 ~ 100 사이의 ��수 생성
    }

    average = calculateAverage(scores, 30);
    printf("학급 평균 점수 : %.2f\n", average);

    // 특정 학생 점수 검색
    printf("학생 번호를 입력하세요 (1 ~ 30) : ");
    scanf("%d", &studentNumber);

    int score = getStudentScore(scores, 30, studentNumber);
    if(score!= -1){
        printf("%d번 학생의 점수 : %d\n", studentNumber, score);
    } else {
        printf("유효하지 않은 학생 번호 입니다.\n");
    }

    return 0;
}

// 평균 계산 함수
double calculateAverage(int scores[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += scores[i];
    }
    return sum / (double)size;
}

// 특정 학생 점수 검색 함수
int getStudentScore(int scores[], int size, int studentNumber){
    if(studentNumber >= 1 && studentNumber <= size){
        return scores[studentNumber - 1];
    } else {
        return -1;
    }
}