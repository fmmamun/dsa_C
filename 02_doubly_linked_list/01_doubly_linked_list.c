#include <stdio.h>
#include <stdlib.h>

void createList(void);
int display(void);
void insertBeginning(void);
void insertEnd(void);
void insetPosition(int);
void deleteBeginning(void);
void deleteEnd(void);
void deletePosition(int);
void reverseList(void);
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head, *newNode, *priviousNode, *temp, *nextNode, *tail;

void main()
{
    int count, choice, option = 1;

    while (option == 1)
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

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createList();
            printf("\n");
            break;
        
        case 2:
            printf("your created list is: ");
            count = display();
            printf("\n");
            break;
        
        case 3:
            insertBeginning();
            printf("\n");
            break;

        case 4:
            insertEnd();
            printf("\n");
            break;

        case 5:
            insetPosition(count);
            printf("\n");
            break;

        case 6:
            deleteBeginning();
            printf("\n");
            break; 

        case 7:
            deleteEnd();
            printf("\n");
            break;

        case 8:
            deletePosition(count);
            printf("\n");
            break;  
        
        case 9:
            reverseList();
            printf("\n");
            break;
        
        default:
            break;
        }

        printf("Press 1 for main menu or 0 to exit: ");
        scanf("%d", &option);

    }
}
void createList(void)
{
    int choice;
    head = 0;

    while (choice)
    {
        newNode = (struct node *) malloc(sizeof(struct node));
        printf("enter the the data: ");
        scanf("%d", &newNode->data);
        newNode->prev=0;
        newNode->next=0;

        if (head == 0)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next=newNode;
            newNode->prev=tail;
            tail = newNode;

        }
        printf("do you want add more? press 1 to add or 0 for exit: ");
        scanf("%d", &choice);
    }
    printf("your created list is: ");
    display();
        
}
int display(void)
{
    //print linked node
    int count = 1;
    if (head == 0)
    {
        printf("you have not created list yet. make a list first.\n");
    }
    else
    {
        temp = head;
        while (temp != 0)
        {
            printf("%d ", temp->data);
            temp = temp->next;
            count++;
        }
        printf("\n");
        return count;
    }   
    //end
}

void insertBeginning(void)
{
    newNode = (struct node *) malloc(sizeof(struct node));
    printf("enter the the data: ");
    scanf("%d", &newNode->data);
    newNode->prev=0;
    // newNode->next=0;

    if (head == 0)
    {
        printf("no list! create list first\n");
    }
    else
    {
        head->prev=newNode;
        newNode->next=head;
        head = newNode;

    }
    printf("data after insert beginning: ");
    display();
}

void insertEnd(void)
{
    newNode = (struct node *) malloc(sizeof(struct node));
    printf("enter the the data: ");
    scanf("%d", &newNode->data);
    // newNode->prev=0;
    newNode->next=0;

    if (head == 0)
    {
        printf("no list! create list first\n");
    }
    else
    {
        tail->next=newNode;
        newNode->prev=tail;
        tail = newNode;

    }
    printf("data after insert end: ");
    display();
}

void insetPosition(int count)
{
    int position, i=1;
    printf("enter the position: ");
    scanf("%d", &position);
    if (position <= 0 || position > count)
    {
        printf("invalid position!");
    }
    else if (position == 1)
    {
        insertBeginning();
    }
    // else if (position == count)
    // {
    //     insertEnd();
    // }
    else
    {
        temp = head;
        newNode = (struct node *) malloc(sizeof(struct node));
        printf("enter the the data: ");
        scanf("%d", &newNode->data);
        // newNode->prev=0;
        // newNode->next=0;
        while (i < position-1)
        {
            temp = temp->next;
            i++;
        }
        newNode->prev=temp;
        newNode->next=temp->next;
        temp->next=newNode;
        newNode->next->prev=newNode;   
    }
   
}

void deleteBeginning(void)
{
    if (head == 0)
    {
        printf("no list! create list first\n");
    }
    else
    {
        temp=head;
        head=head->next;
        head->prev=0;
        free(temp);
        printf("data after delete beginning\n");
        display();
    }
}

void deleteEnd(void)
{
    if (head == 0)
    {
        printf("no list! create list first\n");
    }
    else
    {
        temp=tail;
        tail=tail->prev;
        tail->next=0;
        free(temp);
        printf("data after delete end\n");
        display();
    }
}

void deletePosition(int len)
{
    int position, i=1;
    printf("enter the position: ");
    scanf("%d", &position);
    temp = head;
    if (head == 0)
    {
        printf("no list! create list first\n");
    }
    else if (position == 1)
    {
        deleteBeginning();
    }
    else if (position == len)
    {
       deleteEnd();
    }
    
    else
    {
    while (i < position)
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    printf("data after %d position data\n", position);
    display();
    }
    
}

void reverseList(void)
{
    int i;
    temp = head;

    if (head == 0)
    {
        printf("no list! create list first\n");
    }
    else
    {
        while (temp != 0)
        {
            newNode = temp->next;
            temp->next=temp->prev;
            temp->prev=newNode;
            temp=newNode;
        }
    }
    temp=head;
    head=tail;
    tail=temp;
    printf("data after reverse: ");
    display();
}