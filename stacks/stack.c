#define max 10
#include <stdio.h>
#include <stdlib.h>
int push(int [],int);
int pop(int [],int );
void display(int [],int);
void peek(int [],int);
int main()
{
    int stack[max],top=-1,choice;
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: top=push(stack,top);
                    break;
            case 2: top=pop(stack,top);
                    break;
            case 3: display(stack,top);
                    break;
            case 4: peek(stack,top);
                    break;
            case 5: exit(0);
            default: printf("\nInvalid choice");
        }
    }
}
int push(int stack[],int top)
{
    int x;
    if(top==max-1)
    {
        printf("\nStack is full");
        return top;
    }
    else
    {
        printf("\nEnter the element ");
        scanf("%d",&x);
        top++;
        stack[top]=x;
        return top;
    }
}
int pop(int stack[],int top)
{
    if(top==-1)
    {
        printf("\nStack is empty");
        return top;
    }
    else
    {
        printf("\nThe popped element is %d",stack[top]);
        top--;
        return top;
    }
}
void display(int stack[],int top)
{
    if(top==-1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nThe elements in the stack are:\n");
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
void peek(int stack[],int top)
{
    if(top==-1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nThe top element is %d",stack[top]);
    }
}
