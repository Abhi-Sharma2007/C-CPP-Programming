#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{ struct node *head=NULL,*temp,*newnode;
     int i,n;
     printf("Enter the number of nodes:");
     scanf("%d",&n);
     printf("Enter the data of nodes:\n");
     for(i=0;i<n;i++)
     { printf("loop iteration %d\n",i);
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
     printf("The linked list is:\n");
     temp=head;
     while(temp!=NULL)
     {
         printf("%d ",temp->data);
         temp=temp->next;
     }
 
 }
