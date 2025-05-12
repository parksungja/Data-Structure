#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 리스트 출력 함수
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 첫 번째 노드 삽입 함수
Node* insertFirst(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// 마지막에 노드 추가 함수
Node* insertLast(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;

    return head;
}

// 특정 값을 가진 노드 뒤에 삽입
void insertAfterValue(Node* head, int targetValue, int newData) {
    Node* current = head;

    while (current != NULL) {
        if (current->data == targetValue) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = newData;
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }

    printf("값 %d를 가진 노드를 찾을 수 없습니다. 삽입하지 않습니다.\n", targetValue);
}

int main() {
    Node* head = NULL;

    // 노드 삽입
    head = insertFirst(head, 30);
    head = insertFirst(head, 20);
    head = insertFirst(head, 10);
    head = insertLast(head, 70);
    head = insertLast(head, 80);
    head = insertLast(head, 90);
    insertAfterValue(head, 30, 40);
    insertAfterValue(head, 40, 50);
    insertAfterValue(head, 50, 60);

    // 리스트 출력
    printList(head);

    return 0;
}