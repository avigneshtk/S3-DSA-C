#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

int queue[MAXSIZE];

int front = -1;

int rear = -1;

void enqueuefront(int item);
void enqueuerear(int item);
void dequeuefront();
void dequeuerear();
void display();

int main()
{
    
    int op,ele;
    char c;
    do
    {
        printf("--MENU--\n");
        printf("1. enqueuefront\n");
        printf("2. enqueuerear\n");
        printf("3. dequeuefront\n");
        printf("4. dequeuerear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter which operation do you want to perform on Double ended queue:");
        scanf("%d",&op);

        switch(op)
        {
            case 1:
                printf("Insertion via front\n");
                printf("Enter the element to insert:");
                scanf("%d",&ele);
                enqueuefront(ele);
                break;

            case 2:
                printf("Insertion via rear\n");
                printf("Enter the element to insert:");
                scanf("%d",&ele);
                enqueuerear(ele);
                break;

            case 3:
                dequeuefront();
                break;

            case 4:
                dequeuerear();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("program terminated\n");
                exit(0);

            default:
                printf("No such opertion found\n");
        }//switch

        printf("\nDo you want to continue?(y/n)");
        scanf(" %c",&c);
    }while(op!=4 && (c=='Y' || c =='y'));

    return 0;
}

void enqueuefront(int item)
{
    int temp;

    if(front==-1)//Deque is empty
    {
        front=rear=0;
        queue[front] = item;
    }

    else//Deque is not empty
    {
        if(front==0)
        {
            temp = MAXSIZE-1;

            if(temp==rear)
            {
                printf("Deque is full\n");
            }

            else//temp!=rear
            {
                front = temp;
                queue[front] = item;
            }
        }

        else//front!=0
        {
            temp = front-1;

            if(temp==rear)
            {
                printf("Deque is full\n");
            }

            else//temp!=rear
            {
                front = temp;
                queue[front] = item;
            }
        }
    }
}

void enqueuerear(int item)
{
    if((rear+1)%MAXSIZE == front)
    {
        printf("Deque is full , insertion not possible");
    }

    else//insertion possible
    {
        if(front==-1)//Deque is empty
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

void dequeuefront()
{
    int del_item;
    if(front==-1)
    {
        printf("Deque is empty , nothing to delete");
    }

    else//Deque is not empty
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

void dequeuerear()
{
    int del_item;
    
    if(front==-1)
    {
        printf("Deque is empty , dequeuerear not possible\n");
    }

    else//Deque is not empty
    {
        if(front==rear)//single eleent
        {
            del_item = queue[rear];
            printf("Deleted item = %d",del_item);
            front=rear=-1;
        }

        else//more than one element
        {
            if(rear==0)
            {
                del_item = queue[rear];
                printf("Deleted item = %d",del_item);
                rear = MAXSIZE-1;
            }

            else
            {
                del_item = queue[rear];
                printf("Deleted item = %d",del_item);
                rear--;
            }
        }
    }
}

void display()
{
    int i;
    if(front == -1)
    {
        printf("Deque is empty , nothing to display");
    }

    else//Deque is not empty
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