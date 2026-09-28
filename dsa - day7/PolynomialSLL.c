#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int coeff;
    int exp;
    struct poly* link;
}*head = NULL,*new = NULL,*ptr,*poly1,*poly2,*poly3,*p3;

struct poly* readpoly();
struct poly* addpoly(struct poly* p1, struct poly* p2);
void display(struct poly* p);

int main()
{
    printf("For first polynomial:\n");
    poly1 = readpoly();

    printf("For second polynomial:\n");
    poly2 = readpoly();

    poly3 = addpoly(poly1,poly2);

    printf("\nDisplaying the first polynomial:\n");
    display(poly1);
    printf("\nDisplaying the second polynomial:\n");
    display(poly2);
    printf("\nDisplaying the resultant polynomial:\n");
    display(poly3);
    
    return 0;
}

struct poly* readpoly()
{
    int n,i,c,e;

    head = NULL;

    printf("Enter the no. of terms:");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        
        new = (struct poly*) malloc(sizeof(struct poly));

        printf("Enter the coefficient of term %d:",(i+1));
        scanf("%d",&c);

        printf("Enter the exponent of term %d:",(i+1));
        scanf("%d",&e);

        new->exp = e;
        new->coeff = c;
        new->link = NULL;

        if(head==NULL)//LL is empty
        {
            head = new;
            ptr = head;
        }

        else//LL is not empty
        {
            ptr->link = new;
            ptr = new;
        }

    }

    return head;
}

struct poly* addpoly(struct poly* p1, struct poly* p2)
{
    head = NULL;
    
    while(p1!=NULL && p2!=NULL)//until both LL is empty
    {

        p3 = (struct poly*) malloc(sizeof(struct poly));
        p3->link = NULL;
        
        if(p1->exp == p2->exp)//exponents same
        {
            p3->coeff = p1->coeff + p2->coeff;
            p3->exp = p1->exp;
            p1 = p1->link;
            p2 = p2->link;
        }

        else if(p1->exp > p2->exp)//Exponent of p1 is larger
        {
            p3->coeff = p1->coeff;
            p3->exp = p1->exp;
            p1 = p1->link;
        }

        else//p2->exp > p1->exp
        {
            p3->coeff = p2->coeff;
            p3->exp = p2->exp;
            p2 = p2->link; 
        }

        if(head == NULL)//LL is empty
        {
            head = p3;
            ptr = head;
        }
        else//LL is not empty
        {
            ptr->link = p3;
            ptr = p3;
        }
    }//while

    
    while(p1!=NULL)
    {
        p3 = (struct poly*) malloc(sizeof(struct poly));
        p3->link = NULL;
        p3->coeff = p1->coeff;
        p3->exp = p1->exp;
        p1 = p1->link;
        
        if(head == NULL)//LL is empty
        {
            head = p3;
            ptr = head;
        }
        else//LL is not empty
        {
            ptr->link = p3;
            ptr = p3;
        }
    }

    while(p2!=NULL)
    {
        p3 = (struct poly*) malloc(sizeof(struct poly));
        p3->link = NULL;
        p3->coeff = p2->coeff;
        p3->exp = p2->exp;
        p2 = p2->link; 

        if(head == NULL)//LL is empty
        {
            head = p3;
            ptr = head;
        }
        else//LL is not empty
        {
            ptr->link = p3;
            ptr = p3;
        }
    }

    return head;
}

void display(struct poly* p)
{
    head = p;

    if(head == NULL)//LL is empty
    {
        printf("Empty polynomial");
    }

    else//LL is not empty
    {
        ptr = head;
        while(ptr!=NULL)
        {
            if(ptr->exp  == 0)
            {
            
                printf("%d",ptr->coeff);

            }
            else if(ptr->exp == 1)
            {
                printf("%dX",ptr->coeff);
            }
            else
            {
                printf("%dX^%d",ptr->coeff,ptr->exp);
            }

            if(ptr->link!=NULL)
            {
                printf("+");
            }

            ptr = ptr->link;

        }
    }

}