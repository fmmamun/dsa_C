#include <stdio.h>
#include <stdlib.h>


void createList(void);
void display(void);
void insertBeginning(void);
void insertEnd(void);
void insertAtPosition(void);
int getLength(void);
void deleteBeginning();
void deleteEnd(void);
void deleteAtPosition(void);
void reverseList(void);

struct node
{
    int data;
    struct node *next;
};

struct node *tail, *temp;

int main()
{
    int opt=1, choice;
    while (opt==1)
    {
        printf("insert a number for following operation: \n");
        printf("press 1 for create list.\t\t");
        printf("press 2 for diplay list.\t\t\n");
        printf("press 3 for insert beginning list.\t\t");
        printf("press 4 for insert end list.\t\t\n");
        printf("press 5 for insert at position in list.\t\t");
        printf("press 6 for delete at beginning in list.\t\t\n");
        printf("press 7 for delete at end in list.\t\t");
        printf("press 8 for delete at positon in list.\t\t\n");
        printf("press 9 for reverse list.\t\t\n");

        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            createList();
            printf("your created list is: ");
            display();
            break;
        
        case 2:
            display();
            // printf("size of list is: %d \n", count);
            break;
        
        case 3:
            insertBeginning();
            break;

        case 4:
            insertEnd();
            break;
        
        case 5:
            insertAtPosition();
            break;
        
        case 6:
            deleteBeginning();
            break;
        
        case 7:
            deleteEnd();
            break;

        case 8:
            deleteAtPosition();
            break;
        
        case 9:
            reverseList();
            break;

        default:
            break;
        }
        printf("Press 1 for main menu or 0 to exit: ");
        scanf("%d", &opt);
    }    
}

void createList(void)
{
    int choice;
    tail=0;
    while (choice)
    {
        struct node *newNode;
        newNode = (struct node *) malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d", &newNode->data);
        newNode->next=0;
        if (tail == 0)
        {
            tail=newNode;
            tail->next=newNode;
        }
        else
        {
            newNode->next=tail->next;
            tail->next=newNode;
            tail=newNode;
        }
        printf("do you want to add more? press 1 or 0: ");
        scanf("%d", &choice);
    }
    // printf("your created list is: ");
    // display();
}

void display(void)
{
    if (tail==0)
    {
        printf("list not created yet!");
    }
    else
    {
    temp=tail->next;
    do
    {
        printf("%d ",temp->data);
        temp = temp->next;
        // count++;
    } while (temp != tail->next);

    // while (temp->next != tail->next)
    // {
    //     printf("%d ",temp->data);
    //     temp = temp->next;
    //     count++;
    // }
    // printf("%d ",temp->data);
    printf("\n");
    // return count;
        
    }
    
}

void insertBeginning(void)
{
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newNode->data);
    newNode->next=0;    
    if (tail == 0)
    {
        printf("no list available: \n");
    }
    else
    {
        newNode->next=tail->next;
        tail->next=newNode;
    }
    printf("list after insert beginning: ");
    display();    
}

void insertEnd(void)
{
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newNode->data);
    newNode->next=0;
    if (tail == 0)
    {
        printf("no list available: \n");
    }
    else
    {
        newNode->next=tail->next;
        tail->next=newNode;
        tail=newNode;
    }
    printf("list after insert end: ");
    display(); 
}
int getLength(void)
{
    int count=0;
    if (tail==0)
    {
        printf("list not created yet!");
    }
    else
    {
        temp=tail->next;
        do
        {
            // printf("%d ",temp->data);
            temp = temp->next;
            count++;
        } while (temp != tail->next);
        
    }
    return count;
}

void insertAtPosition()
{
    
    int pos, i=1, len;
    len=getLength();
    struct node *newNode;
    printf("enter the position: ");
    scanf("%d", &pos);
    
    if (tail == 0)
    {
        printf("no list available: \n");
    }
    else if (pos < 0 || pos > len)
    {
        printf("invalid position\n");
    }
    
    else if (pos == 1)
    {
        insertBeginning();
        
    }
    else
    {
        temp=tail->next;
        newNode = (struct node *) malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d", &newNode->data);
        newNode->next=0;
        while (i < pos-1)
        {
            temp=temp->next;
            i++;
        }
        
        newNode->next=temp->next;
        temp->next=newNode;
        printf("data after insert at %d poistion: ", pos);
        display();

    }
    
}

void deleteBeginning(void)
{
    temp=tail->next;
    if (tail==0)
    {
        printf("no list available: \n");
    }
    else if (temp->next == temp)
    {
        tail=0;
        free(temp);
    }
    else
    {
        tail->next=temp->next;
        free(temp);
    }
    
}

void deleteEnd(void)
{
    struct node *privious;
    temp=tail->next;
    if (tail==0)
    {
        printf("no list available: \n");
    }
    else if (temp->next == temp)
    {
        tail=0;
        free(temp);
    }
    else
    {
        while (temp->next != tail->next)
        {
            privious=temp;
            temp=temp->next;
        }
        
        privious->next=temp->next;
        tail=privious;
        free(temp);
    }
}

void deleteAtPosition(void)
{
    struct node *nextNode;
    int i, pos, len;
    len=getLength();
    printf("enter the position: ");
    scanf("%d", &pos);
    if (tail==0)
    {
        printf("no list available: \n");
    }
    else if (pos < 0 || pos > len)
    {
        printf("invalid position!");
    }
    
    else if (pos == 1)
    {
        deleteBeginning();
    }
    else
    {
        temp=tail->next;
        while (i < pos-1)
        {
            temp=temp->next;
            i++;
        }
        nextNode=temp->next;
        temp->next=nextNode->next;
        free(nextNode);

    }
}

void reverseList(void)
{
    struct node *privious, *nextNode;
    temp=tail->next;
    nextNode=temp->next;
    if (tail==0)
    {
        printf("list not exsit");
    }
    else
    {
        while (temp != tail)
        {
            privious=temp;
            temp=nextNode;
            nextNode=temp->next;
            temp->next=privious;
        }
        nextNode->next=tail;
        tail=nextNode;
    }
    printf("data after reverse: ");
    display();
    
}