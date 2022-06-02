#include <stdio.h>
#include <stdlib.h>
// #define N 5

void push(int);
void pop(void);
void peek(void);
void display(void);

struct node 
{
    int data;
    struct node *next;
};

struct node *top=0;

void main()
{
    int i=0, x, number, opt;
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
            for ( i = 0; i < 5; i++)
            {
                printf("enter the data: ");
                scanf("%d", &x);
                push(x);
            }
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

void push(int x)
{
    struct node *newNode, *temp;
    int count=1, opt=1;
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=x;
    newNode->next=top;
    top=newNode;
}

void pop(void)
{
    struct node *temp;
    temp=top;
    if (temp == 0)
    {
        printf("no stack data\n");
    }
    else
    {
        top=top->next;
        free(temp);
        
    }
}

void peek(void)
{
    if (top == 0)
    {
        printf("no stack data\n");
    }
    else
    {
        printf("%d\n", top->data);
    }
}

void display(void)
{
    struct node *temp;
    temp=top;
    if (temp == 0)
    {
        printf("no stack data\n");
    }
    else
    {
        while (temp != 0)
        {
            printf("%d\n", temp->data);
            temp=temp->next;
        }
        
    }
    
    
}