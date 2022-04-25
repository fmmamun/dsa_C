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
    int choice, count=1;
    
    //create linked node
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
    //end
    
    //print linked node
    temp = head;
    while (temp != 0)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
        count++;
    }
    //end
    
    //insert node at given possition
    int position, i = 1;
    printf("insert number after the position: ");
    scanf("%d", &position);
    if (position > count)
    {
        printf("Invalid! Position not exist\n");
    }
    else
    {
        temp = head;
        while (i < position)
        {
            temp = temp->next;
            i++;
        }
        
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("enter the data after %d postion data: ", position);
        scanf("%d", &newnode->data);
        newnode->next = temp->next;
        temp->next = newnode;
    }
    
    //end

    //print node after insertion
    printf("data after ineserting\n");
    temp = head;
    while (temp != 0)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    //end
   
}