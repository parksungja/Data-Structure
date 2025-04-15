#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

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
        return false;
    }
    int value = q -> data[q -> front];
    q -> front++;
    return value;
}

int main() {
    LinearQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Dequeue: %d\n", dequeue(&q));   // 10제거
    printf("Dequeue: %d\n", dequeue(&q));   // 20제거

    enqueue(&q, 60); // 큐에 60 삽입
    enqueue(&q, 70); // 큐에 70 삽입

    while (!isEmpty(&q)) {
        printf("Dequeue: %d\n", dequeue(&q)); // 큐가 비어질때까지 데이터 출력
    }

    return 0;
}
