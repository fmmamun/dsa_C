#include <stdio.h>
#define N 5
int s1[N], s2[N];
int top1=-1, top2=-1, count=0;

void push1(int x)
{
    if (top1 == N-1)
    {
        printf("queue is overflow.\n");
    }
    else
    {
        top1++;
        s1[top1]=x;
    }
    
}

void push2(int x)
{
    if (top2 == N-1)
    {
        printf("queue is overflow.\n");
    }
    else
    {
        top2++;
        s2[top2]=x;
    }
    
}

void enqueue(int x)
{
    push1(x);
    count++;
}

int pop1()
{
    return s1[top1--];
}

int pop2()
{
    return s2[top2--];
}

void dequeue()
{
    int a, b, i;
    if (top1 == -1 && top2 == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        for ( i = 0; i < count; i++)
        {
            a=pop1();
            push2(a);
        }
        b=pop2();
        printf("dequeue value is: %d\n", b);
        count--;

        for ( i = 0; i < count; i++)
        {
            a=pop2();
            push1(a);
        }
        
    }
    
}

void display()
{
    int i;
    for ( i = 0; i <= top1; i++)
    {
        printf("%d ", s1[i]);
    }
    
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    display();
}