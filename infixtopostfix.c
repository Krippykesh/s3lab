#include <stdio.h>
#include <ctype.h>
int stack[100],expr[100],top=-1;
int priority(char x)
{
    if(x=='^' || x=='!')
        return 4;
    else if(x=='*' || x=='/' || x=='%')
        return 3;
    else if(x=='+' || x=='-')
        return 2;
    else
        return 1;
}
void push(char item)
{
    stack[++top]=item;
}
char pop()
{
    return stack[top--];
}
void main()
{
    char temp,*i;
    printf("Enter the expression\n");
    scanf("%s",expr);
    i=expr;
    while(*i!='\0')
    {
        if(isalnum(*i))
            printf("%c",*i);
        else if(*i=='(')
            push(*i);
        else if(*i==')')
        {
            while((temp=pop())!='(')
                printf("%c",temp);
        }
        else
        {
            while(priority(stack[top])>=priority(*i))
                printf("%c",pop());
            push(*i);
        }
        ++i;
    }
    while(top!=-1)
        printf("%c",pop());
}
a
