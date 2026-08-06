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
    struct node *dup;
    printf("enter position");
    int pos;
    scanf("%d",&pos);
    printf("enter data");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
 if(pos==0)
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    else
    { pos=pos-1;
    temp=head;
    for(int i=0;i<pos && temp!=NULL;i++)
    temp=temp->next;
    newnode->next=temp->next;
    newnode->prev=temp;
    if(temp->next!=NULL)
    temp->next->prev=newnode;
    temp->next=newnode;
 temp=head;
 if(newnode->next==NULL)
 last=newnode;
    while(temp!=NULL)
    {
        printf("%d <=>",temp->data);
        temp=temp->next;
    }
    printf("\n");
    temp=last;
    while(temp!=NULL)
    {
        printf("%d <=>",temp->data);
        temp=temp->prev;
    }
    
}
}