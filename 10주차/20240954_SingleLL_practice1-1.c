// 실습 1-1. 초기화

#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;           // 데이터 필드
    struct Node* next;  // 다음 노드의 포인터
} Node;

int main() {
    // 연결 리스트 초기화(head를 NULL로 초기화 한다
    Node* head = NULL;

    // 초기 상태 출력
    if (head == NULL) {
        printf("리스트가 초기화되었습니다. 현재 리스트는 비어 있습니다.\n");
    }

    return 0;
}