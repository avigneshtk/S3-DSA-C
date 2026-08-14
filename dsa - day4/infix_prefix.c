#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXSIZE 20

char S[MAXSIZE];
float S1[MAXSIZE];

int top = -1;
int top1 = -1;

void push(char item);
char pop();
int precedence(char item);
void push1(float item);
float pop1();

int main()
{
    char infix[20],rev[20],test[20],prefix[20];
    int i,len,j=0;
    char symbol,next;
    float x,y,result,val;
   
    printf("Enter the infix expresson:");
    scanf("%s",infix);
   
    printf("Displaying the infix expression:");
    puts(infix);
   
    len = strlen(infix);
   
    for(i=len-1;i>=0;i--)
    {
        rev[j] = infix[i];
        j++;
    }
   
    rev[j] = '\0';
   
    j = 0;
   
    for(i=0;rev[i]!='\0';i++)//conversion
    {
        symbol = rev[i];
       
        switch(symbol)
        {
            case ')':
                push(symbol);
                break;
               
            case '(':
                while(top>=0 && ((next = pop())!=')'))
                {
                    test[j] = next;
                    j++;
                }
                break;
               
            case '^':
                while(top>=0 && precedence(S[top]) >= precedence(symbol))
                {
                    test[j] = pop();
                    j++;
                }
                push(symbol);
                break;
               
            case '*':
            case '/':
            case '+':
            case '-':
                while(top>=0 && precedence(S[top]) > precedence(symbol))
                {
                    test[j] = pop();
                    j++;
                }
                push(symbol);
                break;
               
            default :
                test[j] = symbol;
                j++;
        }//switch
    }//for
   
    while(top>=0)//pop until stack empty
    {
        test[j] = pop();
        j++;
    }
   
    test[j] = '\0';
   
    len = strlen(test);
   
    j = 0;
   
    for(i=len-1;i>=0;i--)
    {
        prefix[j] = test[i];
        j++;
    }
   
    prefix[j] = '\0';
   
    printf("\nDisplaying the prefix expression:");
    puts(prefix);
   
    for(i=0;test[i]!='\0';i++)//evaluation
    {
        symbol = test[i];
        if(isalpha(symbol))
        {
            printf("Enter the value of %c:",symbol);
            scanf("%f",&val);
            push1(val);
        }
       
        else//operator
        {
            x = pop1();
            y = pop1();
           
            switch(symbol)
            {
                case '^':
                    result = pow(x,y);
                    break;
                   
                case '*':
                    result = x * y;
                    break;
                   
                case '/':
                    result = (float)x / y;
                    break;
                   
                case '+':
                    result = x + y;
                    break;
                   
                case '-':
                    result = x - y;
                    break;
            }
           
            push1(result);
        }
    }
   
    printf("The result after evaluation = %0.2f",result);
   
    return 0;
}

void push(char item)
{
    if(top>=MAXSIZE-1)
    {
        printf("Stack overflow , push not possible");
    }
   
    else//top<MAXSIZE-1 push possible
    {
        top++;
        S[top] = item;
    }
}

char pop()
{
    if(top<0)//Stack is empty
    {
        printf("Stack undeflow , nothing to pop");
        return '\0';
    }
   
    else//top>=0 stack is not empty
    {
        char del_item =  S[top];
        top--;
        return del_item;
    }
}

int precedence(char item)
{
    if(item == '^')
        return 3;
    else if(item == '*' || item == '/')
        return 2;
    else if(item == '+' || item == '-')
        return 1;
    else
        return 0;
}

void push1(float item)
{
    if(top1>=MAXSIZE-1)
    {
        printf("Stack overflow , push not possible");
    }
   
    else//top<MAXSIZE-1 push possible
    {
        top1++;
        S1[top1] = item;
    }
}

float pop1()
{
    if(top1<0)//Stack is empty
    {
        printf("Stack undeflow , nothing to pop");
        return 0;
    }
   
    else//top>=0 stack is not empty
    {
        float del_item =  S1[top1];
        top1--;
        return del_item;
    }
}