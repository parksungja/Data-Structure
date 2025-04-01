#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct{
    int data[MAX];
    int top;
} stack;

void initStack(stack* s){
    s->top = -1;
}

int isEmpty(stack* s){
    return (s->top == -1);
}

int isFull(stack* s){
    return (s->top == MAX - 1);
}

void push(stack* s, char value){
    if(isFull(s)){
        printf("Stack is full. Cannot push %s\n", value);
        return;
    }
    s->data[++s->top] = value;
}

int pop(stack* s){
    if(isEmpty(s)){
        printf("Stack is empty. Cannot pop\n");
        return -1;
    }
    return s->data[s->top--];
}

int peek(stack* s){
    if(isEmpty(s)){
        printf("Stack is empty. Cannot peek\n");
        return -1;
    }
    return s->data[s->top];
}

void display(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return;
    }

    printf("Stack Contents: ");
    for(int i = s->top; i >= 0; i--){
        printf("%s ", s->data[i]);
    }
    printf("\n");
}

int main(){
    stack s;
    char text[MAX];
    initStack(&s);

    printf("문자열을 입력하시오: ");
    fgets(text, MAX, stdin);

    // 문자열의 끝에 있는 개행 문자 제거
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    // 문자열을 스택에 저장
    for (int i = 0; text[i] != '\0'; i++) {
        push(&s, text[i]);
    }

    printf("거꾸로 출력된 문자열: ");
    // 스택에서 문자열을 꺼내어 출력
    while (!isEmpty(&s)) {
        printf("%c", pop(&s));
    }
    printf("\n");

    return 0;
}