#include <stdio.h>
#include <stdlib.h>

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

void push(stack* s, int value){
    if(isFull(s)){
        printf("Stack is full. Cannot push %d\n", value);
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
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main(){
    stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    display(&s);

    printf("Popped value: %d\n", pop(&s));
    display(&s);

    printf("Peek value: %d\n", peek(&s));

    return 0;
}