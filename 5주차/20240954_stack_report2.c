#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} stack;

void initStack(stack* s) {
    s->top = -1;
}

int isEmpty(stack* s) {
    return (s->top == -1);
}

int isFull(stack* s) {
    return (s->top == MAX - 1);
}

void push(stack* s, char value) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push %c\n", value);
        return;
    }
    s->data[++s->top] = value;
}

char pop(stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop\n");
        return '\0';
    }
    return s->data[s->top--];
}

char peek(stack* s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->data[s->top];
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int checkBrackets(const char* str) {
    stack s;
    initStack(&s);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s) || !isMatchingPair(pop(&s), ch)) {
                return 0; // 유효하지 않은 괄호
            }
        }
    }

    return isEmpty(&s); // 스택이 비어 있으면 유효한 괄호
}

int main() {
    char text[MAX];

    printf("문자열을 입력하세요: ");
    fgets(text, MAX, stdin);

    // 문자열의 끝에 있는 개행 문자 제거
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    if (checkBrackets(text)) {
        printf("유효한 괄호\n");
    } else {
        printf("유효하지 않은 괄호\n");
    }

    return 0;
}