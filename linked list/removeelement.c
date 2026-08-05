#include <stdio.h>
#include<stdlib.h>
struct node
{ int data;
struct node *next;
};
int main()
{ struct node *head=NULL,*temp,*newnode,*ptr2,*dup;
int n;
    printf("enter n");
    scanf(" %d",&n);
    printf("enter element");
    for(int i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        
    }
    int val;
    printf("enter value ");
    scanf("%d",&val);
    while(head!=NULL && head->data==val)
    { dup=head;
        head=head->next;
        free(dup);
    }
    temp=head;
    while(temp!=NULL && temp->next!=NULL)
    { 
        if(temp->next->data==val)
        {
            dup=temp->next;
            temp->next=dup->next;
            free(dup);
        }
        else
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}
