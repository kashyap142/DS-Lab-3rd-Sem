#include <stdio.h>
#include <ctype.h>
#include <math.h>

int top = -1;
int arr[100];

void push(int k)
{
    arr[++top] = k;
}

int pop()
{
    return arr[top--];
}

void main()
{
    char exp[100];
    printf("Enter expression: ");
    scanf("%s",exp);
    int i = 0;
    char ch;
    int temp1 , temp2 , result;
    while(exp[i] != '\0') {

        ch = exp[i++];

        if(ch == ' ')
            continue;
        if(isdigit(ch))
            push(ch - 48);

        else {
            temp2 = pop();
            temp1 = pop();
            switch(ch) {
                case '+': 
                result = temp1 + temp2;
                break;
                case '-': 
                result = temp1 - temp2;
                break;
                case '*': 
                result = temp1 * temp2;
                break;
                case '/': 
                result = temp1 / temp2;
                break;
                case '^': 
                result = pow(temp1 , temp2);
                break;
            }
            push(result);
        }
    }

    int ans = pop();
    printf("%d\n", ans);

}

// 23+1-11+*