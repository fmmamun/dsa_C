#include <stdio.h>
#include <stdlib.h>     //for exit()
#include <ctype.h>      //for isdigit(char)
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top=-1;

char pop()
{
    char item;
    if (top < 0)
    {
        printf("stack is underflow");
        getchar();
        exit(1);
    }
    else
    {
        item=stack[top];
        top--;
        return item;
    }
}

char main()
{
    char x;
    x=pop();
            
}