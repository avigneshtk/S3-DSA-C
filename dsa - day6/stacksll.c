#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
}*top = NULL,*new,*temp,*ptr;

void push(int value);
void pop();
void display();

int main()
{
    do
    {
        int op,value;
        
        printf("\n--MENU--\n1)Insertion- push() \n2)Deletion - pop()\n3)Display\n4)Exit\n");

        printf("Enter the operation do you want to perform:");
        scanf("%d",&op);

        switch(op)
        {
            case 1:
                printf("Enter the element to insert:");
                scanf("%d",&value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program terminated");
                exit(0);

            default:
                printf("No such operation");
        }

    }while(1);

    return 0;
}

void push(int value)
{
    new = (struct node*) malloc(sizeof(struct node));
    new->data = value;
    new->link = NULL;

    if(top == NULL)//Stack is empty(LL)
    {
        top = new;
    }

    else//Stack is not empty
    {
        new->link = top;
        top = new;
    }
}

void pop()
{
    if(top == NULL)
    {
        printf("Stack is empty , nothing to delete");
    }

    else//Stack not empty(SLL)
    {
        temp = top;
        printf("Deleted value = %d",temp->data);
        top = top->link;
        free(temp);
    }
}

void display()
{
    if(top == NULL)
    {
        printf("Stack is empty , nothing to display");
    }

    else//Stack not empty(SLL)
    {
        printf("Displaying the stack:\n");
        
        ptr = top;
        while(ptr!=NULL)//uti last node
        {
            printf("%d ",ptr->data);
            ptr = ptr->link;
        }
    }
}

/*--MENU--
1)Insertion- push() 
2)Deletion - pop()
3)Display
4)Exit
Enter the operation do you want to perform:3
Stack is empty , nothing to display
--MENU--
1)Insertion- push() 
2)Deletion - pop()
3)Display
4)Exit
Enter the operation do you want to perform:2
Stack is empty , nothing to delete
--MENU--
1)Insertion- push() 
2)Deletion - pop()
3)Display
4)Exit
Enter the operation do you want to perform:1
Enter the element to insert:2

--MENU--
1)Insertion- push() 
2)Deletion - pop()
3)Display
4)Exit
Enter the operation do you want to perform:1
Enter the element to insert:3

--MENU--
1)Insertion- push() 
2)Deletion - pop()
3)Display
4)Exit
Enter the operation do you want to perform:1
Enter the element to insert:4

--MENU--
1)Insertion- push() 
2)Deletion - pop()
3)Display
4)Exit
Enter the operation do you want to perform:3
Displaying the stack:
4 3 2 
--MENU--
1)Insertion- push() 
2)Deletion - pop()
3)Display
4)Exit
Enter the operation do you want to perform:2
Deleted value = 4
--MENU--
1)Insertion- push() 
2)Deletion - pop()
3)Display
4)Exit
Enter the operation do you want to perform:2
Deleted value = 3
--MENU--
1)Insertion- push() 
2)Deletion - pop()
3)Display
4)Exit
Enter the operation do you want to perform:2
Deleted value = 2
--MENU--
1)Insertion- push() 
2)Deletion - pop()
3)Display
4)Exit
Enter the operation do you want to perform:2
Stack is empty , nothing to delete
--MENU--
1)Insertion- push() 
2)Deletion - pop()
3)Display
4)Exit
Enter the operation do you want to perform:8
No such operation
--MENU--
1)Insertion- push() 
2)Deletion - pop()
3)Display
4)Exit
Enter the operation do you want to perform:4
Program terminated*/