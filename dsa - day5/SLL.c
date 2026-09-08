#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
}*head = NULL,*new,*ptr,*temp,*ptr1;

void insbeg(int value);
void insend(int value);
void inspos(int value, int pos);
void delbeg();
void delend();
void delpos();
void display();

int main()
{
    int op,value,pos;
    char ch;
    
    do
    {
    printf("--MENU--\n1)insertion at the beginning\n2)insertion at the end\n3)insertion at a particular position\n4)deletion at the beginning\n5)deletion at the end\n6)deletion at a particular position\n7)display\n8)exit\n");

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
            printf("Enter the value and position where you want to insert:");
            scanf("%d%d",&value,&pos);
            inspos(value,pos);
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

    printf("\nDo you wan to continue?(y/n):");
    scanf(" %c",&ch);

}while(ch=='y' || ch=='Y');
   
    
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

void inspos(int value, int pos)
{
    int i,count = 0;

    new = (struct node*) malloc(sizeof(struct node));
    new->data = value;
    new->link = NULL;
    if(pos==1)
    {
        insbeg(value);
    }

    else//pos!=1
    {
        ptr = head;
        for(i=1;i<pos-1;i++)
        {
            ptr = ptr->link;
            count++;
        }
        if(pos>count+1)
        {
            printf("Invalid position");
        }
        else
        {
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
            for(i=1;i<pos-1;i++)
            {
                ptr = ptr->link;
                count++;
            }

            if(pos>count+1)
            {
                printf("Invalid position");
            }

            else
            {
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