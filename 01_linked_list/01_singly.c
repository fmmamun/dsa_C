#include <stdio.h>
#include <stdlib.h>

struct node
    {
        int data;
        struct node * next;
        
    };


int  main()
{
    struct node * head, *newnode, *temp;
    head = 0;
    int choice;
    while (choice)
    {
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d", &newnode->data);
        newnode->next=0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        
        printf("do you want to continue? Press 0 or 1: ");
        scanf("%d", &choice);
    }
    
    temp = head;
    while (temp != 0)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    
   
}