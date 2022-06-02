#include <stdio.h>

#define N 5

int queue[N];
int front=-1;
int rear=-1;

void enqueue(int x)
{
    if (rear == N-1)
    {
        printf("overflow condition.");
    }
    else if ( front < 0 && rear < 0 )
    {
        front=rear=0;
        queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
    
}

void dequeue(void)
{
    if (front < 0 && rear < 0)
    {
        printf("underflow condition");
    }
    else if (front == rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
}

void display()
{
    int i;
    if (front < 0 && rear < 0)
    {
        printf("underflow condition");
    }
    else
    {
        for ( i = front; i < rear+1; i++)
        {
            printf("%d ", queue[i]) ;
        }
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
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    display();
    peek();
    dequeue();
    display();
    peek();
}