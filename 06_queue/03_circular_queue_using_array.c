#include <stdio.h>

#define N 5

int queue[N];
int front=-1;
int rear=-1;

void enqueue(int x)
{
    // if (rear == N-1)
    // {
    //     printf("overflow condition.");
    // }
    if ( front == -1 && rear == -1 )
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if (((rear+1)%N==front))
    {
        printf("queue is full");
    }
    else
    {
        rear=(rear+1)%N;
        queue[rear]=x;
    }
    
}

void dequeue(void)
{
    if ( front == -1 && rear == -1 )
    {
        printf("underflow condition");
    }
    else if (front == rear)
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%N;
    }
}

void display()
{
    int i=front;
    if (front < 0 && rear < 0)
    {
        printf("underflow condition");
    }
    else
    {
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i=(i+1)%N;
        }
        printf("%d", queue[rear]);
    }   

}
void peek(void)
{
    if (front < 0 && rear < 0)
    {
        printf("underflow condition");
    }
    else
    {
        printf("peek is: %d \n", queue[front]) ;
    }
}

void main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    printf("\n");
    peek();
    dequeue();
    display();
    peek();
}