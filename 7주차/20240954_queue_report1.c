#include <stdio.h>
#include <stdbool.h>

#define SIZE 30 // 큐의 크기 30으로 설정

typedef struct {
    int data[SIZE];
    int front;
    int rear;
} LinearQueue;

// 초기화 함수
void initQueue(LinearQueue *q) {
    q -> front = 0;
    q -> rear = -1;
}

// 큐가 비어있는지 확인
bool isEmpty(LinearQueue *q) {
    return (q -> rear < q -> front);
}

// 큐가 가득 찼는지 확인
bool isFull(LinearQueue *q) {
    return (q -> rear == SIZE - 1);
}

// 삽입 함수
bool enqueue(LinearQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return false;
    }
    q -> rear++;
    q -> data[(q -> rear)] = value;
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

int main() {
    LinearQueue q;
    initQueue(&q);

    while(1) {
        int select;
        printf("1. 삽입 2. 삭제 3. 출력 4. 종료\n");
        scanf("%d", &select);

        int data;

        switch (select){
            case 1:
                printf("삽입할 데이터 입력: ");
                scanf("%d", &data);

                if (enqueue(&q, data)) {
                    printf("삽입 성공: %d\n", data);
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
                if (isEmpty(&q)) {
                    printf("큐가 비어있습니다.\n");
                } else {
                    while (!isEmpty(&q)) {
                        printf("Dequeue : %d\n", dequeue(&q));
                    }
                }
                break;
            case 4:
                printf("프로그램 종료.\n");
                return 0;
        }
    }

    return 0;
}