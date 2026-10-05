#include <stdio.h>
//#nclude <stdio_ext.h>

#define MAXSIZE 15

int a[MAXSIZE];

void buildtree(int a[] , int i , int value);
void display();

int main()
{
    int i,element;

    for(i = 1 ; i<=MAXSIZE ;i++)
    {
        a[i] = -1;
    }
    
    printf("Enter the value of the root node:");
    scanf("%d",&element);
    
    buildtree(a,1,element);
    
    printf("Displaying the binary tree:\n");
    display();
    
    return 0;
}

void buildtree(int a[15] , int i , int value)
{
    
    int lval,rtval;
    char opt;
    
    if(i == 0)//base case
    {
        return;
    }
    
    else//recursive case
    {
        a[i] = value;
        
        printf("Do you want to create a left child for %d (y/n)?:",i);
        //__fprge(stdin);
        scanf(" %c",&opt);
        
        if(opt == 'y' || opt == 'Y')
        {
            printf("Enter the value of the left child:");
            scanf("%d",&lval);
            buildtree(a,2*i,lval);
        }
        
        else//no
        {
            buildtree(a,0,0);
        }
        
        printf("Do you want to create a right child for %d (y/n)?:",i);
        //__fprge(stdin);
        scanf(" %c",&opt);
        
        if(opt == 'y' || opt == 'Y')
        {
            printf("Enter the value of the left child:");
            scanf("%d",&rtval);
            buildtree(a,2*i+1,rtval);
        }
        
        else//no
        {
            buildtree(a,0,0);
        }
    }
}

void display()
{
    int i;
    
    for(i = 1 ; i<=MAXSIZE ;i++)
    {
        if(a[i] != -1)//invalid value
        {
            printf("%d ",a[i]);
        }
        
        else//valid value
        {
            printf(" ");
        }
    }
}