#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev,*next;
}*head=NULL,*tail=NULL,*new,*ptr,*temp;

void insbeg(int value);
void insend(int value);
void inspos();
void delbeg();
void delend();
void delpos();
void forwarddisplay();
void backwarddisplay();

int main()
{
    int op,ele;
    
    do
    {
        printf("\n--MENU--\n1)Insertion at the beginning\n2)Insertion at the end\n3)Insertion at a particular position\n4)Deletion from the beginning\n5)Deletion from the end\n6)Deletion from a particular position\n7)forward display\n8)Backward display\n9)Exit\n");

        printf("Enter the operation do you want to perform on DLL:");
        scanf("%d",&op);

        switch(op)
        {
            case 1:
                printf("Enter the Element do you want to insert on DLL:");
                scanf("%d",&ele);
                insbeg(ele);
                break;

            case 2:
                printf("Enter the Element do you want to insert on DLL:");
                scanf("%d",&ele);
                insend(ele);
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
                forwarddisplay();
                break;

            case 8:
                backwarddisplay();
                break;

            case 9:
                printf("Program terminated");
                exit(0);

            default :
                printf("Invalid operation");
        }

    }while(1);

    return 0;
}

void insbeg(int value)
{
    new = (struct node*) malloc(sizeof(struct node));
    new->data = value;
    new->prev = NULL;
    new->next = NULL;
    
    if(head==NULL)//LL is empty
    {
        head = new;
        tail = new;
    }

    else//LL is not empty
    {
        new->next = head;
        head->prev = new;
        head = new;
    }
}

void insend(int value)
{
    new = (struct node*) malloc(sizeof(struct node));
    new->data = value;
    new->prev = NULL;
    new->next = NULL;
    
    if(head==NULL)//LL is empty
    {
        head = new;
        tail = new;
    }

    else//LL is not empty
    {
        tail->next = new;
        new->prev = tail;
        tail = new;
    }
}

void inspos()
{
    int pos,ele,count = 0,i;
    printf("Enter the position and Element do you want to insert on DLL:");
    scanf("%d%d",&pos,&ele);

    ptr = head;
    while(ptr!=NULL)
    {
        ptr = ptr->next;
        count++;
    }

    if(pos==1)
    {
        insbeg(ele);
    }
    else//pos!=1
    {
        if(pos<1 || pos>count+1)
        {
            printf("Invalid position");
        }

        else
        {
            new = (struct node*) malloc(sizeof(struct node));
            new->data = ele;
            new->prev = NULL;
            new->next = NULL;

            ptr  = head;

            for(i=1;i<pos-1;i++)
            {
                ptr = ptr->next;
            }

            new->next = ptr->next;
            ptr->next = new;

            if(new->next != NULL)
            {
                new->next->prev = new;
            }
            else
            {
                tail = new;
            }
        }
    }

}

void delbeg()
{
    if(head == NULL)//LL is empty
    {
        printf("LL is empty , Nothing to delete");
    }

    else//not empty,deletion posssible
    {
        temp = head;
        printf("Deleted value =%d",temp->data);

        if(head == tail)//single node
        {
            head = tail = NULL;
        }

        else//more than one node
        {
            head = head->next;
            head->prev = NULL;
        }
        free(temp);
    }
}

void delend()
{
    if(head == NULL)//LL is empty
    {
        printf("LL is empty , Nothing to delete");
    }

    else//not empty,deletion posssible
    {
        temp = tail;
        printf("Deleted value =%d",temp->data);

        if(head == tail)//single node
        {
            head = tail = NULL;
        }

        else//more than one node
        {
           tail = tail->prev;
           tail->next = NULL;
        }
        free(temp);
    }
}

void delpos()
{
    int pos,count = 0,i;
    
    if(head == NULL)//LL is empty
    {
        printf("LL is empty , Nothing to delete");
    }

    else//not empty,deletion posssible
    {
        printf("Enter the postion at which deletion want to perform:");
        scanf("%d",&pos);

        ptr = head;
        while(ptr!=NULL)
        {
            ptr = ptr->next;
            count++;
        }

        if(pos<1 || pos>count)
        {
            printf("Invalid position");
        }

        else
        {
            if(pos == 1)
            {
                temp = head;
                printf("Deleted value =%d",temp->data);

                if(head == tail)//single node
                {
                    head = tail = NULL;
                }

                else//more than one node
                {
                    head = head->next;
                    head->prev = NULL;
                }
                free(temp);
            }

            else//pos!=1
            {
                ptr = head;

                for(i=1;i<pos-1;i++)
                {
                    ptr = ptr->next;
                }

                temp = ptr->next;
                printf("Deleted value = %d",temp->data);
                ptr->next = temp->next;

                if(ptr->next != NULL)
                {
                    ptr->next->prev = ptr;
                }
                else
                {
                    tail = ptr;
                }
                free(temp);
            }
        }
    }
}

void forwarddisplay()
{
    if(head == NULL)//LL is empty
    {
        printf("LL is empty , Nothing to display");
    }

    else//LL is not empty
    {
        printf("Forward display:\n");
        
        ptr = head;

        while(ptr!=NULL)//until last node
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
    }
}

void backwarddisplay()
{
    if(head == NULL)//LL is empty
    {
        printf("LL is empty , Nothing to display");
    }

    else//LL is not empty
    {
        printf("Backward display:\n");
        
        ptr = tail;

        while(ptr!=NULL)//until last node
        {
            printf("%d ",ptr->data);
            ptr = ptr->prev;
        }
    }
}

/*--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:1
Enter the Element do you want to insert on DLL:1

--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:1
Enter the Element do you want to insert on DLL:2

--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:1
Enter the Element do you want to insert on DLL:3

--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:7
Forward display:
3 2 1 
--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:8
Backward display:
1 2 3 
--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:2
Enter the Element do you want to insert on DLL:6

--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:7
Forward display:
3 2 1 6 
--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:3
Enter the position and Element do you want to insert on DLL:3 5

--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:7
Forward display:
3 2 5 1 6 
--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:3
Enter the position and Element do you want to insert on DLL:8 9
Invalid position
--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:3
Enter the position and Element do you want to insert on DLL:0 5
Invalid position
--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:4
Deleted value =3
--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:5
Deleted value =6
--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:7
Forward display:
2 5 1 
--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:6
Enter the postion at which deletion want to perform:2
Deleted value = 5
--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:6
Enter the postion at which deletion want to perform:2
Deleted value = 1
--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:6
Enter the postion at which deletion want to perform:4
Invalid position
--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:5
Deleted value =2
--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:4
LL is empty , Nothing to delete
--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:7
LL is empty , Nothing to display
--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:12
Invalid operation
--MENU--
1)Insertion at the beginning
2)Insertion at the end
3)Insertion at a particular position
4)Deletion from the beginning
5)Deletion from the end
6)Deletion from a particular position
7)forward display
8)Backward display
9)Exit
Enter the operation do you want to perform on DLL:9
Program terminated*/