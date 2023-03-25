#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int top = -1;
char stack[100];

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int priority(char ch)
{
    switch(ch) {
        case '+':
        case '-': return 1;

        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return 0;
}


void main()
{
    char exp[100];
    printf("Enter expression: ");
    scanf("%s", exp);
    char ch , temp;
    int i = 0;
    while(exp[i] != '\0') {
        ch = exp[i++];

        if(ch == ' ') {
            continue;
        }
        if(isalnum(ch))
            printf("%c",ch);
        else if(ch == '(')
            push(ch);
        else if (ch == ')' ) {
            while((temp = pop()) != '(' )
                printf("%c", temp);
        }
        else {
            while(priority(stack[top]) >= priority(ch)) 
                printf("%c",pop());

            push(ch);
        }
    }

    while(top != -1)
        printf("%c",pop());

}