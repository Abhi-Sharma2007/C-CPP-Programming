#include <stdio.h>
#include<stdlib.h>
    struct node
{ int data;
struct node *next,*prev;
};
int main()
{ struct  node *temp,*head=NULL,*newnode;
int n,i=0;
    printf("enter no. o f node");
    scanf("%d",&n);
    for( i=0;i<n;i++)
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
    printf("the linked list is\n");
    while(temp!=NULL)
    {
        printf("%d <=>",temp->data);
        temp=temp->next;
    }
    printf("\n");
    for(i=0;i<n/2;i++)
    {
        if(head->data!=last->data)
        {
            printf("not palendrom\n");
            exit(0);
        }
        head=head->next;
        last=last->prev;
    }
    printf("palendrom\n");
    return 0;
}