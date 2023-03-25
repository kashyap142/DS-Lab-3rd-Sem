/*
    Write C program to perform the following operations with respect to Doubly Linked List

    a. Insertion at the front
    b. Delete based on position
    c. Print the contents in the order of insertion
    d. Print the content in the reverse order of insertion
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
} *head;

void insertAtFront()
{
    struct node *ptr;
    int value;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter value to insert at beginnning: ");
    scanf("%d", &value);
    ptr->data = value;
    if(head == NULL) {
        ptr->next = ptr->prev = NULL;
        head = ptr;
        return;
    }
    ptr->next = head;
    head->prev = ptr;
    ptr->prev = NULL;
    head = ptr;
}

void deleteAtPosition()
{
    int pos;
    printf("Enter position to delete: ");
    scanf("%d",&pos);

    struct node *temp , *ptr;
    temp = ptr = head;
    for (int i=1; i<pos; i++) {
        ptr = temp;
        temp = temp->next;
        if(ptr == NULL) {
            printf("Position %d doesn't exist.\n" , pos);
            return;
        }
    }
    printf("Deleted %d at position %d.\n", temp->data , pos);
    ptr->next = temp->next;
    temp->next->prev = ptr;
    temp = NULL;
    free(temp);
}

void printInOrder()
{
    struct node *temp = head;
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements are [ ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf(" ]\n");
}

void printInReverse(struct node *temp)
{
    if(temp == NULL)
        return;
    
    printInReverse(temp->next);
    printf("%d " , temp->data);
}

void main()
{
    // Menu driven program
    insertAtFront();
    insertAtFront();
    insertAtFront();

    deleteAtPosition();
    deleteAtPosition();

    insertAtFront();
    insertAtFront();
    insertAtFront();

    printInOrder();

    printf("\n \n");

    printInReverse(head);
}
