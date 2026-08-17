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
        printf("--MENEU--\n");
        printf("1. Enqueue - Insertion\n");
        printf("2. Dequeue - Deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Which action do you want to perform on circular queue?:");
        scanf("%d",&op);

        switch(op)
        {
            case 1:
                printf("Enter the element that do you want to insert on circular queue:");
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
            
            default :
                printf("No such operation found");

        }//switch

        printf("\nDo you want to continue?(y/n):");
        scanf(" %c",&c);
        
    }while(c=='Y' || c=='y');

    return 0;
}

void enqueue(int item)
{
    if((rear+1)%MAXSIZE == front)//Circular queue is full
    {
        printf("Circular queue is full , insertion not possible");
    }

    else//insertion possible
    {
        if(front==-1)//Circular queue is empty
        {
            front = 0;
            rear = 0;
            queue[rear] = item;

        }

        else//normal insertion
        {
            rear = (rear+1)%MAXSIZE;
            queue[rear] = item;
        }
    }
}

void dequeue()
{
    int del_item;
    if(front==-1)
    {
        printf("Circular queue is empty , nothing to delete");
    }

    else//Circular queue is not empty
    {
        if(front==rear)//Only one element
        {
            del_item = queue[front];
            front = -1;
            rear = -1;
        } 

        else//normal deleton
        {
            del_item = queue[front];
            front = (front+1)%MAXSIZE;
        }

        printf("Deleted item = %d",del_item);
    }
}

void display()
{
    int i;
    if(front == -1)
    {
        printf("Circular queue is empty , nothing to display");
    }

    else//Circular queue is not empty
    {
        i = front;

        while(i!=rear)
        {
            printf("%d ",queue[i]);

            i = (i+1)%MAXSIZE;
        }
        printf("%d ",queue[rear]);
    }
}