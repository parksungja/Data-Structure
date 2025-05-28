#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 노드를 생성하고 초기화하는 함수
TreeNode* createNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        printf("메모리 할당 오류\n");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 간단한 순환 큐 구현
typedef struct {
    TreeNode* items[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;   //front, rear가 같으면 비어있음.
}

int isFull(Queue* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front; // rear의 다음방이 front와 같으면
}

void enqueue(Queue* q, TreeNode* node) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        exit(1);
    }
    q->items[q->rear] = node;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;    
}

TreeNode* dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        exit(1);
    }
    TreeNode* node = q->items[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return node;
}

// 레벨 순회 함수(BFS)
void levelOrder(TreeNode* root) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        TreeNode* current = dequeue(&q);
        printf("%d ", current->data);  // 현재 노드 방문

        if (current->left != NULL)
            enqueue(&q, current->left);
        if (current->right != NULL)
            enqueue(&q, current->right);
    }
}

int main() {
    // 트리 구성
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(25);

    // 순회 출력
    printf("레벨 순회: ");
    levelOrder(root); // BFS 탐색
		
		freeTree(root);
    return 0;
}