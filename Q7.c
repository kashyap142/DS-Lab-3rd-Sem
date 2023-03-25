/*
    Write a program to Implement the Queue data structure using Singly Linked list.
    Search through the list. Display the elements of the stack.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front , *rear;

void enQueue()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    int value;
    printf("Enter value to insert: ");
    scanf("%d",&value);
    temp->data = value;
    if(rear == NULL) {
        front = rear = temp;
        rear->next = NULL;
    }
    else {
        rear->next = temp;
        temp->next = NULL;
        rear = temp;
    }
}

void deQueue()
{
    struct node *temp = front;
    if(front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Deleted value: %d\n", front->data);
    front = temp->next;
    temp = NULL;
    free(temp);
}

void display()
{
    struct node *temp = front;
    if(front == NULL) {
        printf("Queue is empty,\n");
        return;
    }
    printf("Queue eleemnts are [ ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf(" ]\n");
}

void main()
{
    enQueue();
    enQueue();
    enQueue();
    display();
    deQueue();
    deQueue();
    display();
}