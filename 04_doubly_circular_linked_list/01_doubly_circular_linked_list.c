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
// void reverseList(void);

struct node
{
    int data;
    struct node *priv;
    struct node *next;
};

struct node *head, *tail;

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
        // printf("press 9 for reverse list.\t\t\n");

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
        
        // case 9:
        //     reverseList();
        //     break;

        default:
            break;
        }
        printf("Press 1 for main menu or 0 to exit: ");
        scanf("%d", &opt);
    }    
}

void createList(void)
{
    int opt;
    head=0;
    struct node *newNode;
    while (opt)
    {
        newNode=(struct node *) malloc(sizeof(struct node));
        printf("enter the data: ");
        scanf("%d", &newNode->data);
        newNode->priv=0;
        newNode->next=0;
        if (head == 0)
        {
            head=tail=newNode;
            newNode->priv=newNode;
            newNode->next=newNode;
        }
        else
        {
            tail->next=newNode;
            newNode->priv=tail;
            newNode->next=head;
            head->priv=newNode;
            tail=newNode;
        }
        printf("do you want to add more? press 1 or 0: ");
        scanf("%d", &opt);
    }
    
}

void display(void)
{
    struct node *temp;
    temp=head;
    if (head ==0)
    {
        printf("no list available!");
    }
    else
    {
        while (temp != tail)
        {
            printf("%d ", temp->data);
            temp=temp->next;
        }
        printf("%d ", temp->data);
    }
    printf("\n");
    
}

void insertBeginning(void)
{
    struct node *newNode;
    newNode=(struct node *) malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &newNode->data);
    newNode->priv=0;
    newNode->next=0;
    if (head == 0)
    {
        printf("no list available!");
    }
    else
    {
        newNode->next=head;
        newNode->priv=head->priv;
        head->priv=newNode;
        tail->next=newNode;
        head=newNode;        
    }
    printf("data after insert at beginning: ");
    display();
}

void insertEnd(void)
{
    struct node *newNode;
    newNode=(struct node *) malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &newNode->data);
    newNode->priv=0;
    newNode->next=0;
    if (head == 0)
    {
        printf("no list available!");
    }
    else
    {
        newNode->priv=tail;
        newNode->next=tail->next;
        tail->next=newNode;
        head->priv=newNode;
        tail=newNode;        
    }
    printf("data after insert at end: ");
    display();
}

int getLength(void)
{
    int count=0;
    struct node *temp;
    temp=head;
    if (head ==0)
    {
        printf("no list available!");
    }
    else
    {
        while (temp != tail)
        {
            // printf("%d ", temp->data);
            temp=temp->next;
            count++;
        }
        // printf("%d ", temp->data);
    }
    return count+1;
}

void insertAtPosition(void)
{
    int i, len, pos;
    // printf("%d", len=getLength());
    printf("enter the position: ");
    scanf("%d", &pos);
    if (head == 0)
    {
        printf("no list available!");
    }
    else if (pos < 0 || pos > len)
    {
        printf("invalid position");
    }
    else if (pos == 1)
    {
        insertBeginning();
    }
    else
    {
        struct node *newNode, *temp;
        temp=head;
        while (i < pos-1)
        {
            temp=temp->next;
            i++;
        }
        newNode=(struct node *) malloc(sizeof(struct node));
        printf("enter the data: ");
        scanf("%d", &newNode->data);
        newNode->priv=temp;
        newNode->next=temp->next;
        temp->next->priv=newNode;
        temp->next=newNode;
    }
    printf("data after inser at position: ");
    display();
    
}

void deleteBeginning(void)
{   struct node *temp;
    temp=head;
    if (head == 0)
    {
        printf("no list available!");
    }
    else if (head->next == head)
    {
        head=tail=0;
        free(temp);
    }
    
    else
    {
        head=head->next;
        head->priv=tail;
        tail->next=head;
        free(temp);
    }
    printf("data after delete at beginning: ");
    display();
}

void deleteEnd(void)
{
    struct node *temp;
    temp=tail;
    if (head == 0)
    {
        printf("no list available!");
    }
    else if (head->next == head)
    {
        head=tail=0;
        free(temp);
    }
    
    else
    {
        tail=tail->priv;
        tail->next=head;
        head->priv=tail;
        free(temp);
    }
    printf("data after delete at end: ");
    display();
}

void deleteAtPosition(void)
{
    int i, len, pos;
    // printf("%d", len=getLength());
    printf("enter the position: ");
    scanf("%d", &pos);
    if (head == 0)
    {
        printf("no list available!");
    }
    else if (pos < 0 || pos > len)
    {
        printf("invalid position");
    }
    else if (pos == 1)
    {
        deleteBeginning();
    }
    else
    {
        struct node *newNode, *temp;
        temp=head;
        while (i < pos-1)
        {
            temp=temp->next;
            i++;
        }
        temp->priv->next=temp->next;
        temp->next->priv=temp->priv;
        if (temp->next == head)
        {
            tail=temp->priv;
            free(temp);
        }
        else
        {
            free(temp);
        }
    }
    printf("data after delete at position: ");
    display();
}