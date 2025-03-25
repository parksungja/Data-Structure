// 실습 2. 정해진 학생 수를 가진 학급의 성적 처리
// 코드 2. 추가 - 평균점수 이상 학생정보 출력[실습 과제]

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 함수 선언
double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);
void printScore(int scores[], int size, double average, int options);

int main(){
    int scores[30];
    int studentNumber;
    double average;
    int options;

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

    // 평균 점수 이상 학생 정보 출력
    printf("options를 입력해주세요(0 : 모든 학생, 1 : 평균점수 이상, 2 : 평균점수 미만) : ");
    scanf("%d", &options);
    printScore(scores, 30, average, options);

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

// 폋균 점수 이상 학생 정보 출력
void printScore(int scores[], int size, double average, int options){
    if (options == 0){
        for (int i = 0; i < size; i++){
            if(scores[i] >= average){
                printf("%d번 학생 : %d\n", i + 1, scores[i]);
            }
        }
    } else if (options == 1) {
        for (int i = 0; i < size; i++){
            if (scores[i] >= average) {
                printf("%d번 학생 : %d\n", i + 1, scores[i]);
            }
        }
    } else if (options == 2) {
        for (int i = 0; i < size; i++) {
            if (scores[i] < average) {
                printf("%d번 학생 : %d\n", i + 1, scores[i]);
            }
        }
    } else {
        printf("잘못된 값을 입력하셨습니다.(0, 1, 2)\n");
    }
}