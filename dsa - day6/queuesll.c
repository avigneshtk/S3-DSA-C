#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
}*front = NULL,*rear = NULL,*new,*ptr,*temp;

void enqueue(int value);
void dequeue();
void display();

int main()
{
    int op,ele;
    
    do
    {
        printf("\n--MENU--\n1)Insertion - enqueue()\n2)Deletion - dequeue()\n3)Display\n4)Exit\n");

        printf("Enter the operation do you want to perform on Queue:");
        scanf("%d",&op);

        switch(op)
        {
            case 1:
                printf("Enter the element do you want to insert:");
                scanf("%d",&ele);
                enqueue(ele);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program terminated");
                exit(0);

            default:
                    printf("Invalid operation");

        }

    }while(1);
    
    return 0;
}

void enqueue(int value)
{
    new = (struct node*) malloc(sizeof(struct node));
    new->data = value;
    new->link = NULL;

    if(front == NULL)//Queue is empty(SLL)
    {
        front = new;
        rear = new;
    }

    else//Queue is not empty
    {
        rear->link = new;
        rear = new;
    }
}

void dequeue()
{
    if(front == NULL)
    {
        printf("Queue is empty , nothing to delete");
    }

    else//Queue is  not empty(SLL)
    {
        temp = front;
        printf("Deleted item =%d",temp->data);

        if(front == rear)//single node
        {
            front = rear = NULL;
        }

        else//more than one node
        {
            front = front->link;
        }
        free(temp);
    }
}

void display()
{
    if(front == NULL)
    {
        printf("Queue is empty , nothing to display");
    }

    else//Queue is not empty
    {
        printf("Displaying the Queue:\n");
        
        ptr = front;

        while(ptr!=NULL)//until last node
        {
            printf("%d ",ptr->data);
            ptr = ptr->link;
        }
    }
}

/*--MENU--
1)Insertion - enqueue()
2)Deletion - dequeue()
3)Display
4)Exit
Enter the operation do you want to perform on Queue:3
Queue is empty , nothing to display
--MENU--
1)Insertion - enqueue()
2)Deletion - dequeue()
3)Display
4)Exit
Enter the operation do you want to perform on Queue:2
Queue is empty , nothing to delete
--MENU--
1)Insertion - enqueue()
2)Deletion - dequeue()
3)Display
4)Exit
Enter the operation do you want to perform on Queue:1
Enter the element do you want to insert:2

--MENU--
1)Insertion - enqueue()
2)Deletion - dequeue()
3)Display
4)Exit
Enter the operation do you want to perform on Queue:1
Enter the element do you want to insert:3

--MENU--
1)Insertion - enqueue()
2)Deletion - dequeue()
3)Display
4)Exit
Enter the operation do you want to perform on Queue:1
Enter the element do you want to insert:4

--MENU--
1)Insertion - enqueue()
2)Deletion - dequeue()
3)Display
4)Exit
Enter the operation do you want to perform on Queue:1
Enter the element do you want to insert:5

--MENU--
1)Insertion - enqueue()
2)Deletion - dequeue()
3)Display
4)Exit
Enter the operation do you want to perform on Queue:3
Displaying the Queue:
2 3 4 5 
--MENU--
1)Insertion - enqueue()
2)Deletion - dequeue()
3)Display
4)Exit
Enter the operation do you want to perform on Queue:2
Deleted item =2
--MENU--
1)Insertion - enqueue()
2)Deletion - dequeue()
3)Display
4)Exit
Enter the operation do you want to perform on Queue:2
Deleted item =3
--MENU--
1)Insertion - enqueue()
2)Deletion - dequeue()
3)Display
4)Exit
Enter the operation do you want to perform on Queue:2
Deleted item =4
--MENU--
1)Insertion - enqueue()
2)Deletion - dequeue()
3)Display
4)Exit
Enter the operation do you want to perform on Queue:2
Deleted item =5
--MENU--
1)Insertion - enqueue()
2)Deletion - dequeue()
3)Display
4)Exit
Enter the operation do you want to perform on Queue:2
Queue is empty , nothing to delete
--MENU--
1)Insertion - enqueue()
2)Deletion - dequeue()
3)Display
4)Exit
Enter the operation do you want to perform on Queue:8
Invalid operation
--MENU--
1)Insertion - enqueue()
2)Deletion - dequeue()
3)Display
4)Exit
Enter the operation do you want to perform on Queue:4
Program terminated*/