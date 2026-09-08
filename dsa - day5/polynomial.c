#include <stdio.h>

struct poly
{
    int coeff;
    int exp;
}p1[10],p2[10],p3[20];

void readpoly(struct poly p[],int t);
void display(struct poly p[],int t);

int main()
{
    int t1,t2;
    int i=0,j=0,k=0;

    printf("Enter the no. of terms of the polynomials:");
    scanf("%d%d",&t1,&t2);

    printf("Read first polynomial:\n");
    readpoly(p1,t1);

    printf("Read second polynomial:\n");
    readpoly(p2,t2);

    printf("Displaying the first polynomial:");
    display(p1,t1);

    printf("\nDisplaying the second polynomial:");
    display(p2,t2);

    while(i<t1 && j<t2)
    {
        if(p1[i].exp==p2[j].exp)
        {
            p3[k].exp = p1[i].exp;
            p3[k].coeff = p1[i].coeff+p2[j].coeff;
            i++;
            j++;
            k++;
        } 

        else if(p1[i].exp>p2[j].exp)
        {
            p3[k].exp = p1[i].exp;
            p3[k].coeff = p1[i].coeff;
            i++;
            k++;
        }

        else//p2[i].exp>p1[j].exp
        {
            p3[k].exp = p2[j].exp;
            p3[k].coeff = p2[j].coeff;
            j++;
            k++;
        }
    }

    while(i<t1)
    {
        p3[k].exp = p1[i].exp;
        p3[k].coeff = p1[i].coeff;
        i++;
        k++;
    }

    while(j<t2)
    {
        p3[k].exp = p2[j].exp;
        p3[k].coeff = p2[j].coeff;
        j++;
        k++;
    }

    printf("\nDisplaying the resultant polynomial:");
    display(p3,k);

    return 0;
}

void readpoly(struct poly p[],int t)
{
    int c,e,i;

    for(i=0;i<t;i++)
    {
        printf("Enter the coefficient of term %d:",i+1);
        scanf("%d",&c);

        printf("Enter the exponent of term %d:",i+1);
        scanf("%d",&e);

        p[i].coeff = c;
        p[i].exp = e;
    }
}

void display(struct poly p[],int t)
{
    int i;
    for(i=0;i<t;i++)
    {
        if(p[i].exp==0)
        {
            printf("%d",p[i].coeff);
        }
        else if(p[i].exp==1)
        {
            printf("%dX",p[i].coeff);
        }
        else
        {
            printf("%dX^%d",p[i].coeff,p[i].exp);
        }
        if(i<t-1)
        {
            printf("+");
        }
    }
}