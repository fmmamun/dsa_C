#include <stdio.h>
#include <stdlib.h>

void createList(void);
int display(void);
void insertBeginning(void);
// void insertEnd(void);
// void insetPosition(int);
// void deleteBeginning(void);
// void deleteEnd(void);
// void deletePosition(void);
// void reverseList(void);

struct node
    {
        int data;
        struct node * next;
        
    };

struct node * head, *newnode, *temp;
   

int  main()
{
    int count, choice, option = 1;

    while (option == 1)
    {
        printf("insert a number for following operation: \n");
        printf("press 1 for create list.\t\t");
        printf("press 2 for diplay list.\t\t\n");
        printf("press 3 for insert beginning list.\t\t");
        // printf("press 4 for insert end list.\t\t\n");
        // printf("press 5 for insert at position in list.\t\t");
        // printf("press 6 for delete at beginning in list.\t\t\n");
        // printf("press 7 for delete at end in list.\t\t");
        // printf("press 8 for delete at positon in list.\t\t\n");
        // printf("press 9 for reverse list.\t\t\n");

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
        // case 4:
        //     insertEnd();
        //     printf("\n");
        //     break;

        // case 5:
        //     insetPosition(count);
        //     printf("\n");
        //     break;

        // case 6:
        //     deleteBeginning();
        //     printf("\n");
        //     break; 

        // case 7:
        //     deleteEnd();
        //     printf("\n");
        //     break;

        // case 8:
        //     deletePosition();
        //     printf("\n");
        //     break;  
        
        // case 9:
        //     reverseList();
        //     printf("\n");
        //     break;
        
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
        
        printf("do you want to add more? Yes 1 or No 0: ");
        scanf("%d", &choice);
    }
    temp->next=head;
    printf("your created list is: ");
    display();
    printf("verification of circular list: ");
    printf("%d", temp->next->data);
    //end

}

int display()
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
        while (temp->next!= head)
        {
            printf("%d ", temp->data);
            temp = temp->next;
            count++;
        }
        printf("%d ", temp->data);
        printf("\n");
        return count;
    }   
    //end
}

void insertBeginning(void)
{
    
    if (head == 0)
    {
        printf("there is no list! create first.\n");
    }
    
    temp=head;
    newnode=(struct node*) malloc(sizeof(struct node));
    printf("enter the new node data: ");
    scanf("%d", &newnode->data);
    newnode->next=head;
    while (temp->next != head)
    {
        temp=temp->next;
    }
    temp->next=head=newnode;
    display();
    printf("verification of circular list: ");
    printf("%d", temp->next->data);
    
    
}