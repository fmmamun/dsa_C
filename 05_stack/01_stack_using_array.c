#include <stdio.h>
#define N 5

void push(void);
void pop(void);
void peek(void);
void display(void);

int stack[N];
int top=-1;

void main()
{
    int number, opt;
    while (opt)
    {
        printf("Press 1 for push operatoin.\t");
        printf("Press 2 for pop operatoin.\n");
        printf("Press 3 for peek operatoin.\t");
        printf("Press 4 for display operatoin.\n");

        printf("enter the number to stack operation: ");
        scanf("%d", &number);

        switch (number)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        
        default:
            break;
        }
        printf("press 1 for main or 0 for exit: ");
        scanf("%d", &opt);
    }
    
    
}

void push(void)
{
    int x, opt=1;
    while (opt)
    {
        printf("enter data: ");
        scanf("%d", &x);

        if (top == N-1)
        {
            printf("stack is overflow condition. Please press 0 to exit: ");
            scanf("%d", &opt);
        }
        else
        {
            top++;
            stack[top]=x;
            printf("do you want to add more? press 1 or 0: ");
            scanf("%d", &opt);
        }
        
    }
}

void pop(void)
{
    int item;
    if (top == -1)
    {
        printf("stack is underflow conditoin\n");
    }
    
    else
    {
        item=stack[top];
        top--;
        printf("%d has been removed from statck\n", item);
    }
}

void peek(void)
{
    if (top == -1)
    {
        printf("stack is underflow conditoin\n");
    }
    else
    {
        printf("top most element of stack is: %d\n", stack[top]);
    }
}

void display(void)
{
    int i;
    for ( i = top; i>=0; i--)
    {
        printf("value of %dth position is  %d\n", i, stack[i]);
    }
    
}