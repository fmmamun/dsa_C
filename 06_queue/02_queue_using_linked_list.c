#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front=0, *rear=0;

void enqueue(int x)
{
    
    struct node *newNode;
    newNode=(struct node *) malloc(sizeof(struct node));
    newNode->data=x;
    newNode->next=0;

    if (front == 0 && rear == 0)
    {
        front=rear=newNode;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
    }
    
}

void display()
{
    struct node *temp;
    if (front==0 && rear ==0)
    {
        printf("queue is empty");
    }
    else
    {
        temp=front;
        while (temp != 0)
        {
            printf("%d ", temp->data);
            temp=temp->next;
        }
        
    }
    
}

void dequeue()
{
    struct node *temp;
    temp=front;
    if (front == 0 && rear == 0)
    {
        printf("queue is empty\n");
    }
    else
    {
        front=front->next;
        free(temp);
    }
}

void peek()
{
    if (front == 0 && rear == 0)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("peek is: %d\n", front->data);
    }
}

void main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    display();
    peek();
}