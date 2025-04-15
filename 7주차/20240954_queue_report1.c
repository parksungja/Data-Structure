#include <stdio.h>
#include <stdbool.h>

#define SIZE 30  // 큐의 크기 30

typedef struct {
    int data[SIZE];  // 고정된 크기의 배열
    int front;  // 큐의 첫 번째 요소 인덱스
    int rear;   // 큐의 마지막 요소 인덱스
} LinearQueue;

// 초기화 함수
void initQueue(LinearQueue *q) {
    q->front = 0;
    q->rear = -1;  // rear를 -1로 설정하여 첫 번째 삽입 시 0이 되도록 함
}

// 큐가 비어 있는지 확인
bool isEmpty(LinearQueue *q) {
    return q->rear < q->front;  // rear가 front보다 작으면 비어 있음
}

// 큐가 가득 찼는지 확인
bool isFull(LinearQueue *q) {
    return q->rear == SIZE - 1;  // rear가 배열 끝에 도달하면 가득 참
}

// 삽입 함수
bool enqueue(LinearQueue *q, int value) {
    if (isFull(q)) {
        printf("큐가 가득 찼습니다.\n");
        return false;
    }
    q->rear++;
    q->data[q->rear] = value;  // rear 위치에 데이터 추가
    return true;
}

// 삭제 함수
int dequeue(LinearQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        initQueue(q); // 큐를 초기화
        return false;
    }
    int value = q -> data[q -> front];
    q -> front++;
    return value;
}

// 큐 데이터 출력 함수
void printQueue(LinearQueue *q) {
    if (isEmpty(q)) {
        printf("큐가 비어있습니다.\n");
        return;
    }
    printf("큐 데이터: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    LinearQueue q;
    initQueue(&q);
    int choice, value;

    while(1) {
        printf("1. 삽입 2. 삭제 3. 출력 4. 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("삽입할 데이터 입력: ");
                scanf("%d", &value);

                if (enqueue(&q, value)) {
                    printf("삽입 성공: %d\n", value);
                } else {
                    printf("삽입 실패: 큐가 가득 찼습니다.\n");
                }
                break;
            case 2:
                if (!isEmpty(&q)) {
                    printf("제거된 데이터: %d\n", dequeue(&q));
                } else {
                    printf("큐가 비어있습니다.\n");
                }
                break;
            case 3:
                printf("큐 데이터 출력\n");
                printQueue(&q);
                break;
            case 4:
                printf("프로그램 종료.\n");
                return 0;
        }
    }

    return 0;
}
