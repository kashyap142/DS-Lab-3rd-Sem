/*
6.  Write a program to Implement the Stack data structure using singly Linked list.  
    Search through the list. Display the elements of the stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;


void push()
{
    int value;
    struct node *ptr;
    ptr = (struct node *) malloc(sizeof(struct node));

    if(ptr == NULL) {
        printf("Overflow!!");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d",&value);
    ptr->data = value;
    if(head == NULL) {
        ptr->next = NULL;
        head = ptr;
    }
    else {
        ptr->next = head;
        head = ptr;
    }
}

void pop()
{
    struct node *ptr;

    if(head == NULL) {
        printf("Underflow!!");
        return;
    }
    ptr = head;
    printf("Deleted value %d\n",head->data);
    head = head->next;
    ptr = NULL;
    free(ptr);
}

void display()
{
    struct node *temp = head;
    if (head == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements are [ ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf(" ]\n");
}

void search()
{
    struct node *temp = head;
    int key;
    printf("Enter value to search: ");
    scanf("%d", &key);

    while(temp != NULL) {
        if(temp->data == key) {
            printf("%d found.\n" , key);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found.\n");
}

void main()
{
    display();
    push();
    push();
    push();
    display();
    pop();
    pop();
    display();
}
