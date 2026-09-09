#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
}*head = NULL,*new,*ptr,*temp,*ptr1;

void insbeg(int value);
void insend(int value);
void inspos();
void delbeg();
void delend();
void delpos();
void display();

int main()
{
    int op,value,pos;
    
    do
    {
    printf("\n--MENU--\n1)insertion at the beginning\n2)insertion at the end\n3)insertion at a particular position\n4)deletion at the beginning\n5)deletion at the end\n6)deletion at a particular position\n7)display\n8)exit\n");

    printf("Enter the operation do you want to perform on SLL:");
    scanf("%d",&op);

    switch(op)
    {
        case 1:
            printf("Enter the element to insert:");
            scanf("%d",&value);
            insbeg(value);
            break;

        case 2:
            printf("Enter the element to insert:");
            scanf("%d",&value);
            insend(value);
            break;

        case 3:
            inspos();
            break;

        case 4:
            delbeg();
            break;

        case 5:
            delend();
            break;

        case 6:
            delpos();
            break;

        case 7:
            display();
            break;

        case 8:
            exit(0);
            break;

        default:
            printf("No such operation found");
    }

}while(1);
   
    
    return 0;
}

void insbeg(int value)
{
    new = (struct node*) malloc(sizeof(struct node));
    new->data = value;
    new->link = NULL;

    if(head==NULL)//LL is empty
    {
        head = new;
    }

    else//LL is not empty
    {
        new->link = head;
        head = new;
    }

}

void insend(int value)
{
    new = (struct node*) malloc(sizeof(struct node));
    new->data = value;
    new->link = NULL;

    if(head==NULL)//LL is empty
    {
        head = new;
    }

    else//LL is not empty
    {
        ptr = head;
        while(ptr->link!=NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = new;
    }
}

void inspos()
{
    int pos,value,count=0,i;
    
    printf("Enter the position and value to be insert:");
    scanf("%d%d",&pos,&value);

    ptr = head;
    while(ptr!=NULL)//counting the nodes
    {
        count++;
        ptr = ptr->link;
    }

    if(pos==1)
    {
        insbeg(value);
    }
    else
    {
        if(pos<1 || pos > count+1)
        {
            printf("Invalid position");
        }

        else
        {
            new = (struct node*) malloc(sizeof(struct node));
            new->data = value;
            new->link = NULL;

            ptr = head;
            for(i=1;i<pos-1;i++)
            {
                ptr = ptr->link;
            }
            new->link = ptr->link;
            ptr->link = new;
        }
    }
}


void delbeg()
{
    if(head == NULL)//LL is empty
    {
        printf("SLL is empty , nothing to delete");
    }

    else//LL is not empty
    {
        temp = head;
        printf("Deleted value = %d",temp->data);
        head = temp->link;
        free(temp);
    }
}

void delend()
{
    if(head == NULL)//LL is empty
    {
        printf("SLL is empty , nothing to delete");
    }

    else//LL is not empty
    {
        if(head->link == NULL)//single element
        {
            temp = head;
            printf("Deleted value = %d ",temp->data);
            head = NULL;
            free(temp);
        }

        else//LL is having more than one node
        {
            ptr = head;
            while(ptr->link!=NULL)
            {
                ptr1 = ptr;
                ptr = ptr->link;
            }
            temp = ptr;
            printf("Deleted value = %d ",temp->data);
            ptr1->link = NULL;
            free(temp);
        }
    }
}

void delpos()
{
    int pos,i,count = 0;
    
    if(head == NULL)//LL is empty
    {
        printf("SLL is empty , nothing to delete");
    }

    else//LL is not empty
    {
        printf("Enter the position where the deletion want to perform:");
        scanf("%d",&pos);

        if(pos==1)
        {
            delbeg();
        }

        else//pos!=1
        {
            ptr = head;
            while(ptr!=NULL)
            {
                count++;
                ptr = ptr->link;
            }
            ptr = NULL;
            
            if(pos<=0 || pos>count)
            {
                printf("Invalid position");
            }

            else
            {
                ptr = head;
                for(i=1;i<pos-1;i++)
                {
                    ptr = ptr->link;
                }
                temp = ptr->link;
                printf("Deleted value = %d",temp->data);
                ptr->link = temp->link;
                free(temp);
            }
        }
    }
}

void display()
{
    if(head==NULL)
    {
        printf("SLL is empty, nothing to display");
    }

    else
    {
        ptr = head;
        printf("Displaying the SLL:\n");
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->link;
        }
    }
}