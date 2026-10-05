#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data[50];
    struct node *prev;
    struct node *next;
}*head = NULL,*tail = NULL , *new = NULL , *current = NULL;

void insend(char site[]);

int main()
{
    int op;
    char site[50];

    do
    {

        printf("\n====MENU====\n1)Go to a site\n2)Go backward\n3)Go forward\n4)Exit\n");

        printf("What are you looking for:");
        scanf("%d",&op);

        switch(op)
        {
            case 1:
            
                printf("Enter your site address:");
                scanf("%s",site);
                insend(site);
                break;
                
            case 2:
            
                if(current == NULL)//Empty DLL
                {
                    printf("You didn't opened any sites");
                }
                
                else
                {
                    if(current->prev != NULL)
                    {
                        current = current->prev;
                        printf("You are currently at %s",current->data);
                    }
                    
                    else//current->prev == NULL
                    {
                        printf("No previous sites found");
                    }
                }
                
                break;
                
            case 3:
            
                if(current == NULL)//Empty DLL
                {
                    printf("You didn't opened any sites");
                }
                
                else
                {
                    if(current->next != NULL)
                    {
                        current = current->next;
                        printf("You are currently at %s",current->data);
                    }
                    
                    else//current->next == NULL
                    {
                        printf("No sites found after this site");
                    }
                }
                
                break;
                
            case 4:
                
                exit(0);
                
            default:
            
                printf("No such action permitted");
                
        }

    }while(1);


    return 0;
}

void insend(char site[50])
{
    new = (struct node*) malloc(sizeof(struct node));
    strcpy(new->data,site);
    new->prev = NULL;
    new->next = NULL;
    
    if(head == NULL)//empty DLL
    {
        head = new;
        tail = new;
    }
    
    else//DLL is not empty
    {
        tail->next = new;
        new->prev = tail;
        tail = new;
    }
    
    current = new;
    
    printf("You are currently at the site %s",site);
}

/*
====MENU====
1)Go to a site
2)Go backward
3)Go forward
4)Exit
What are you looking for:2
You didn't opened any sites
====MENU====
1)Go to a site
2)Go backward
3)Go forward
4)Exit
What are you looking for:3
You didn't opened any sites
====MENU====
1)Go to a site
2)Go backward
3)Go forward
4)Exit
What are you looking for:1
Enter your site address:www.youtube.com
You are currently at the site www.youtube.com
====MENU====
1)Go to a site
2)Go backward
3)Go forward
4)Exit
What are you looking for:2
No previous sites found
====MENU====
1)Go to a site
2)Go backward
3)Go forward
4)Exit
What are you looking for:3
No sites found after this site
====MENU====
1)Go to a site
2)Go backward
3)Go forward
4)Exit
What are you looking for:1
Enter your site address:www.instagram.com
You are currently at the site www.instagram.com
====MENU====
1)Go to a site
2)Go backward
3)Go forward
4)Exit
What are you looking for:2
You are currently at www.youtube.com
====MENU====
1)Go to a site
2)Go backward
3)Go forward
4)Exit
What are you looking for:2
No previous sites found
====MENU====
1)Go to a site
2)Go backward
3)Go forward
4)Exit
What are you looking for:3
You are currently at www.instagram.com
====MENU====
1)Go to a site
2)Go backward
3)Go forward
4)Exit
What are you looking for:3
No sites found after this site
====MENU====
1)Go to a site
2)Go backward
3)Go forward
4)Exit
What are you looking for:4
*/