#define max 10
#include <stdio.h>
#include <stdlib.h>
int enq(int [],int,int);
int deq(int [],int,int);
void display(int [],int,int);
void peek(int [],int,int);
int main()
{
    int queue[max],front=-1,rear=-1,ch,item;
    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                rear=enq(queue,front,rear);
                if(front==-1)
                    front=0;
                break;
            case 2:
                front=deq(queue,front,rear);
                if(front>rear)
                    front=rear=-1;
                break;
            case 3:
                display(queue,front,rear);
                break;
            case 4:
                peek(queue,front,rear);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }while(1);
    return 0;
}
int enq(int queue[],int front,int rear)
{ 
    int item;
     printf("\nEnter the item to be inserted:");
                scanf("%d",&item);
    if(rear==max-1)
    {
        printf("\nQueue is full");
        return rear;
    }
    else
    {
        rear++;
        queue[rear]=item;
        return rear;
    }
}
int deq(int queue[],int front,int rear)
{
    if(front==-1 || front>rear)
    {
        printf("\nQueue is empty");
        return front;
    }
    else
    {
        printf("\nThe dequeued element is %d",queue[front]);
        front++;
        return front;
    }
}
void display(int queue[],int front,int rear)
{
    if(front==-1 || front>rear)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nThe elements in the queue are:\n");
        for(int i=front;i<=rear;i++)
            printf("%d ",queue[i]);
    }
}
void peek(int queue[],int front,int rear)
{
    if(front==-1 || front>rear)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nThe front element is %d",queue[front]);
    }
}