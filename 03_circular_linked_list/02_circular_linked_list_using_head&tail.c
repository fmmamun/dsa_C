#include <stdio.h>
#include <stdlib.h>

void createList(void);
void display(void);
struct node
    {
        int data;
        struct node * next;
        
    };

struct node *head, *tail, *newNode;

int main(void)
{
    createList();
    display();
}

void createList(void)
{
    int choice=1;
    head = 0;
    //create linked node
    while (choice)
    {
        newNode=(struct node *) malloc(sizeof(struct node));
        printf("enter the data for new node: ");
        scanf("%d", &newNode->data);
        newNode->next=0;

        if (head == 0)
        {
            head = tail = newNode;
            tail->next=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
            tail->next=head;
        }
        
        printf("do you want to add more? Yes 1 or No 0: ");
        scanf("%d", &choice);
    }
    //end
   printf("circular list verification: ") ;
    printf("%d\n", tail->next->data);
   
}

void display(void)
{
    struct node *temp;
    temp=head;
    while (temp != tail)
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("%d ", temp->data);
    printf("\n");
}

