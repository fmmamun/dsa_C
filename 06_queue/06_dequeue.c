#include <stdio.h>
#define N 5

int dequeue[N];
int front=-1, rear=-1;

void enqueueFront(int x)
{
    if ((front == 0 && rear == N-1) || (front == rear+1))
    {
        printf("queue is full");
    }
    else if (front == -1 && rear == -1)
    {
        front=rear=0;
        dequeue[front]=x;
    }
    else if (front == 0)
    {
        front=N-1;
        dequeue[front]=x;
    }
    else
    {
        front--;
        dequeue[front]=x;
    }
        
    
}

void enqueueRear(int x)
{
    if ((front == 0 && rear == N-1) || (front == rear+1))
    {
        printf("queue is full");
    }
    else if (front == -1 && rear == -1)
    {
        front=rear=0;
        dequeue[rear]=x;
    }
    else if (rear == N-1)
    {
        rear==0;
        dequeue[rear]=x;
    }
    else
    {
        rear++;
        dequeue[rear]=x;
    }
    
}

void display()
{
    int i=front;
    while (i != rear)
    {
        printf("%d ", dequeue[i]);
        i = (i+1)%N;
    }
    printf("%d ", dequeue[rear]);
}

void dequeueFront()
{
    if ( front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else if (front == rear)
    {
        front=rear=-1;
    }
    else if (front == N-1)
    {
        front=0;
    }
    else
    {
        front++;
    }  
    
}

void dequeueRear()
{
    if ( front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else if (front == rear)
    {
        front=rear=-1;
    }
    else if (rear == 0)
    {
        rear = N-1;
    }
    else
    {
        rear--;
    }
    
}

void main()
{
    enqueueFront(2);
    enqueueFront(5);
    enqueueRear(-1);
    enqueueRear(0);
    enqueueFront(7);
    enqueueFront(4);
    dequeueFront();
    dequeueRear();
    display();
}