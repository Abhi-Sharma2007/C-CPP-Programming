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
    struct node *last,*de;
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
    if(pos==0)
    {temp=head;
    head->prev=NULL;
    head=head->next;
    free(temp);
    printf("after deleting \n");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d <=>",temp->data);
        temp=temp->next;
    }
    }
    else
    {  temp=head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds.\n");
    } else {
        
        de=temp->next;


        temp->next = de->next;

        
        if (de->next != NULL) {
            de->next->prev = temp;
        }

        free(de);
        temp=head;
        printf("after deleting \n");
        while(temp!=NULL)
    {
        printf("%d <=>",temp->data);
        temp=temp->next;
    }
    }
    }
}