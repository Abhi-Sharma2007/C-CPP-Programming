#include <stdio.h>
#include<stdlib.h>
struct node
{ int data;
struct node *next,*prev;
};
int main()
{ struct  node *temp,*head=NULL,*newnode;
int n;
    printf("enter no. o f node");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter data");
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
            newnode->prev=NULL;
        }
        else
        
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
    struct node *last;
    last=temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d <=>",temp->data);
        temp=temp->next;
    }
    printf("\n");
    printf("enter data for first node");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
     temp=head;
    while(temp!=NULL)
    {
        printf("%d <=>",temp->data);
        temp=temp->next;
    }
    printf("\n");
    printf(" enter to insert at last");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    temp=last;
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;
     temp=head;
    while(temp!=NULL)
    {
        printf("%d <=>",temp->data);
        temp=temp->next;
    }
    return 0;
}
