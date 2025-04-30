#include <stdio.h>
#include <stdbool.h>

#define SIZE 30  // 큐의 크기

typedef struct {
    int data[SIZE];  // 고정된 크기의 배열
    int front;  // 큐의 첫 번째 요소 인덱스
    int rear;   // 큐의 마지막 요소 인덱스
} CircularQueue;

// 초기화 함수
void initQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = 0;  // 원형 큐는 rear와 front를 0으로 초기화
}

// 큐가 비어 있는지 확인
bool isEmpty(CircularQueue *q) {
    return q->front == q->rear;  // front와 rear가 같으면 비어 있음
}

// 큐가 가득 찼는지 확인
bool isFull(CircularQueue *q) {
    return (q->rear + 1) % SIZE == q->front;  // 다음 위치가 front이면 가득 참
}

// 삽입 함수
bool enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("큐가 가득 찼습니다.\n");
        return false;
    }
    q->data[q->rear] = value;  // rear 위치에 데이터 추가
    q->rear = (q->rear + 1) % SIZE;  // rear를 다음 위치로 이동
    return true;
}

// 삭제 함수
int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("큐가 비어 있습니다.\n");
        return -1;  // 큐가 비어 있을 때 -1 반환
    }
    int value = q->data[q->front];  // front 위치의 데이터를 반환
    q->front = (q->front + 1) % SIZE;  // front를 다음 위치로 이동
    return value;
}

// 큐의 현재 상태 출력 함수
void printQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("큐가 비어 있습니다.\n");
        return;
    }
    printf("큐의 데이터: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);
    int choice, value;

    while (true) {
        printf("\n1. 삽입\n2. 삭제\n3. 큐 데이터 출력\n4. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // 삽입
                printf("삽입할 값: ");
                scanf("%d", &value);
                if (enqueue(&q, value)) {
                    printf("%d가 큐에 삽입되었습니다.\n", value);
                }
                break;
            case 2:  // 삭제
                value = dequeue(&q);
                if (value != -1) {
                    printf("삭제된 값: %d\n", value);
                }
                break;
            case 3:  // 큐 데이터 출력
                printQueue(&q);
                break;
            case 4:  // 종료
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 입력입니다. 다시 시도해주세요.\n");
                break;
        }
    }
    return 0;
}