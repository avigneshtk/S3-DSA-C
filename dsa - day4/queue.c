#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

int queue[MAXSIZE];

int front = -1;
int rear = -1;

void enqueue(int item);
void dequeue();
void display();

int main()
{
    int op,ele;
    char c;
    
    do
    {
        printf("--MENU--\n");
        printf("1. Enqueue - Insertion\n");
        printf("2. Dequeue - Deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter the operation do you want to perform on queue:");
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
        }//switch

        printf("\nDo you want to continue?(y/n)");
        scanf(" %c",&c);

    }while(op!=4 && (c == 'y' || c=='Y'));
    
    return 0;
}

void enqueue(int item)
{
    if(rear>=MAXSIZE-1)
    {
        printf("Queue overflow , insertion not possible\n");
    }

    else//insertion possible
    {
        if(front==-1)//queue is empty
        {
            front = 0;
            rear = 0;
            queue[rear] = item;
        }

        else//normal insertion
        {
            rear++;
            queue[rear] = item;
        }
    }
}

void dequeue()
{
    int del_item;
    
    if(front==-1)
    {
        printf("Queue is empty , nothing to delete\n");
    }
    
    else//queue is not empty
    {
        if(front==rear)//only one element
        {
            del_item = queue[front];
            front = rear = -1;
        }

        else//normal deletion
        {
            del_item = queue[front];
            front++;
        }

        printf("Deleted item = %d",del_item);
    }
}

void display()
{
    int i;
    if(front==-1)//queue is empty
    {
        printf("Queue is empty , nothing to dispay\n");
    }

    else//queue is not empty
    {
        printf("Displaying the queue:");
        for(i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
    }
}