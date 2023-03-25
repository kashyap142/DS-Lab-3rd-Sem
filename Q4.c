#include <stdio.h>
typedef long int ll;

int rear = -1;
int front = 0;
ll arr[100];

void enqueue()
{
    if(rear == -1)
        rear = 0;
    ll num;
    printf("Enter phone number: ");
    scanf("%ld",&num);
    arr[front++] = num;
    printf("Added\n");
}

void dequeue()
{
    if(rear == -1)
        printf("No customers currently\n");
    else {
        printf("Next Customer : %ld\n" , arr[rear--]);
    }
}

void main()
{
    int choice = 1;
    while(choice) {
        printf("Choose a option\n1.Add a number\n2.Next Customer\n3.Exit\n");
        scanf("%d",&choice);

        switch(choice) {
            case 1: 
                enqueue();
                break;
            case 2: 
                dequeue();
                break;
            case 3: 
                choice = 0;
                break;
            default: printf("Invalid input\n");
        }
    }
}