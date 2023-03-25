/*
    Write a C program to with respect to Binary Search Trees
    Creation and insertion into a Binary Search Tree
    Display the contents of the tree in inorder, postorder and preorder manner.
    Search for a given element in the BST.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *rlink;
    struct node *llink;
};

struct node *createNewNode(int value)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->llink = temp->rlink = NULL;
    return temp;
}

struct node *insert(struct node *root , int value)
{
    if(root == NULL)
        return createNewNode(value);

    if(value < root->data)
        root->llink = insert(root->llink , value);
    else if(value > root->data)
        root->rlink = insert(root->rlink , value);
    
    return root;
}

struct node *search(struct node *root , int key)
{
    if(root == NULL || root->data == key)
        return root;
    
    if (root->data < key)
        return search(root->rlink , key);

    return search(root->llink , key);
}

void preorder(struct node *root)
{
    if(root == NULL)
        return;
    
    printf("%d ",root->data);
    preorder(root->llink);
    preorder(root->rlink);
}

void inorder(struct node *root)
{
    if(root == NULL)
        return;
    
    inorder(root->llink);
    printf("%d ", root->data);
    inorder(root->rlink);
}

void postorder(struct node *root)
{
    if(root == NULL)
        return;
    
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d ", root->data);
}

void main()
{
    struct node *root = NULL;
    int choice , data;

    while(1) {
        printf("Choose an option\n1.Insertion\n2.Search\n3.Preorder Traversal\n4.Inorder traversal\n5.Postorder traversal\n6.Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("Enter value to insert: ");
                    scanf("%d",&data);
                    root = insert(root , data);
                    break;
            case 2: printf("Enter value to search: ");
                    scanf("%d", &data);
                    if(search(root , data) == NULL)
                        printf("%d not found.\n" , data);
                    else
                        printf("Found\n");
                    break;
            case 3: printf("Preorder traversal of BST is\n[ ");
                    preorder(root);
                    printf(" ]\n");
                    break;
            case 4: printf("Inorder traversal of BST is\n[ ");
                    inorder(root);
                    printf(" ]\n");
                    break;
            case 5: printf("Postorder traversal of BST is\n[ ");
                    postorder(root);
                    printf(" ]\n");
                    break;
            case 6: exit(0);
            default: printf("Invalid input\n");
        }
        printf("\n");
    }
}