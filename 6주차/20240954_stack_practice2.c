#include <stdio.h>
#include <ctype.h>  // isdigit(), isalpha() 사용
#include <string.h>
#include <stdlib.h> // exit() 사용

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

// 스택 초기화
void initStack(Stack* s) {
    s->top = -1;
}

// 스택이 비어있는지 확인
int isEmpty(Stack* s) {
    return s->top == -1;
}

// 스택에 요소 추가
void push(Stack *s, int value) {
    s->data[++(s->top)] = value;
}

// 스택에서 요소 제거
int pop(Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->data[(s->top)--];
}

// 스택 최상단 요소 반환
int peek(Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->data[s->top];
}

// 후위표기식을 계산하는 함수
int evaluatePostfix(char *postfix) {
    Stack s;
    initStack(&s);
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // 1. 피연산자 (숫자)
        if (isdigit(ch)) {
            // 문자열로 된 숫자를 정수로 변환하여 push
            push(&s, ch - '0');
        }
        // 2. 연산자
        else {
            int b = pop(&s);
            int a = pop(&s);
            int result;

            // 연산 수행
            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default:
                    printf("Invalid operator encountered.\n");
                    exit(1);
            }

            // 연산 결과를 스택에 push
            push(&s, result);
        }
    }

    // 스택에 남은 최종 결과를 반환
    return pop(&s);
}

int main() {
    char postfix[MAX] = "12+5*"; // 후위표기식
    printf("후위표기실 계산 결과 : %d\n", evaluatePostfix(postfix));
    return 0;
}