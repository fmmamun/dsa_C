#include <stdio.h>
#include <stdlib.h>

void createList(void);
int display(void);
void insertBeginning(void);
void insertEnd(void);
void insetPosition(int);
void deleteBeginning(void);
void deleteEnd(void);
void deletePosition(void);
void reverseList(void);

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
            deletePosition();
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
    if (head == 0)
    {
        printf("you have not created list yet. make a list first.\n");
    }
    else
    {
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("\nenter the 1st possition data: ");
        scanf("%d", &newnode->data);
        newnode->next=head;
        head = newnode;

        //print node after insertion
        printf("data after ineserting Beginning: ");
        display();
        // temp = head;
        // while (temp != 0)
        // {
        //     printf("%d ", temp->data);
        //     temp = temp->next;
        // }
        //end
    }
    
}

void insertEnd(void)
{
    if (head == 0)
    {
        printf("you have not created list yet. make a list first.\n");
    }
    else
    {
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("\nenter the end possition data: ");
        scanf("%d", &newnode->data);
        newnode->next=0;
        temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;

        //print node after insertion
        printf("data after ineserting end: ");
        display();
        // temp = head;
        // while (temp != 0)
        // {
        //     printf("%d ", temp->data);
        //     temp = temp->next;
        // }
        //end
    }
    
}

void insetPosition(int count)
{
    if (head == 0)
    {
        printf("you have not created list yet. make a list first.\n");
    }
    else
    {
        int position, i = 1;
        printf("\ninsert number after the position: ");
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

        //print node after insertion
        printf("data after ineserting at mittle position: ");
        display();
        // temp = head;
        // while (temp != 0)
        // {
        //     printf("%d ", temp->data);
        //     temp = temp->next;
        // }
        //end
    }
    
}

void deleteBeginning(void)
{
    if (head == 0)
    {
        printf("you have not created list yet. make a list first.\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("data after deleting beginning: ");
        display();
    }
}

void deleteEnd(void)
{
    if (head == 0)
    {
        printf("you have not created list yet. make a list first.\n");
    }
    else
    {
        struct node * priviousNode;
              
        temp = head;
        while (temp->next != 0)
        {
            priviousNode = temp;
            temp = temp->next;
           
        }
        if (temp == head)
        {
            head = 0;
            free(temp);
        }
        else
        {
            priviousNode->next = 0;
            free(temp);
            printf("data after delete end position: ");
            display(); 

        }       
        
    }   
}

void deletePosition(void)
{
    if (head == 0)
    {
        printf("you have not created list yet. make a list first.\n");
    }
    else
    {
        int position, i = 1;
        struct node * priviousNode;
        printf("enter position: ");
        scanf("%d", &position);
                      
        temp = head;
        while (i < position)
        {
            priviousNode = temp;
            temp = temp->next;
            i++;
           
        }
        if (temp == head)
        {
            head = 0;
            free(temp);
        }
        else
        {
            priviousNode->next = temp->next;
            free(temp);
            display();
        }
        
    }
}

void reverseList(void)
{
    struct node *nextNode, *priNode;
    priNode=0;
    temp=nextNode=head;
    while (nextNode != 0)
    {
        nextNode = nextNode->next;
        temp->next = priNode;
        priNode = temp;
        temp = nextNode;
    }
    head = priNode;
    printf("reverse list is: ");
    display();
    
}