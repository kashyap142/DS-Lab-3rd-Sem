#include <stdio.h>
#include <stdlib.h>

int top = -1;
#define size 1000
int arr[size];

void push()
{
    int id;
    printf("Enter book id: ");
    scanf("%d",&id);

    if(top == size - 1)
        printf("List is full\n");
    else {
        arr[++top] = id;
        printf("Book added to list\n");
    }
    printf("\n");
}

void pop()
{
    if(top == -1)
        printf("List is empty\n");
    else
        printf("Book %d is removed\n",arr[top--]);
    
    printf("\n");
}

void main()
{
    int choice = 1;

    while(choice) {
        printf("Choose an option\n1.Add a book\n2.Remove a book\n3.Exit\n");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1 : push();
                    break;
            case 2 : pop();
                    break;
            case 3 : choice = 0;
                    break;
            default:
                printf("Invalid input\n\n");
        }
    }
}
