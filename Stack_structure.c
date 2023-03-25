#include <stdio.h>

#define size 5

struct stack {
    int top;
    int arr[size];
};

void initialize(struct stack *s)
{
    s->top = -1;
}

void  push(struct stack *s)
{
    int value;
    if(s->top == size - 1) {
        printf("Overflow!!");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &value);
    s->top++;
    s->arr[s->top] = value;
}

void pop(struct stack *s)
{
    if(s->top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Deleted value: %d\n", s->arr[s->top] );
    s->top--;
}

void main()
{
    struct stack s;
    initialize(&s);
    push(&s);

}