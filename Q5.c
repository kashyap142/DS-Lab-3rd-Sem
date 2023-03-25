/*
5.Write a program to demonstrate round robin processor scheduling using circular queue (array implementation) with 
suitable inputs. Program should have options to add, remove and display elements of the queue. 
*/

#include <stdio.h>
#include <stdlib.h>

#define size 10
int queue[size];
int rear = -1;
int front = -1;

void enqueue()
{
    int value;
    if((front + 1) % size == rear) {
        printf("Queue is full\n");
    }
    else {
        if(front == -1)
            front = 0;
        printf("Enter value to insert: ");
        scanf("%d",&value);
        rear = (rear + 1) % size;
        queue[rear] = value;
    }
} 

void dequeue()
{
    if(front == rear && rear == -1) {
        printf("Queue is empty\n");
    }
    else {
        printf("Deleted value : %d\n", queue[front]);
        if(rear == front)
            rear = front = -1;
        else
            front = (front + 1) % size;
    }
}

void display()
{
    int i = front;
    if(rear == -1 && rear == front)
        printf("Queue is empty.\n");
    else {
        printf("Queue elements are [ ");
        while(i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % size;
        }
        printf("%d ]\n", queue[i]);
    }
}

void main()
{
    // Menu driven program
}