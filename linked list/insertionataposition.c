#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{ struct node *head=NULL,*temp,*newnode;
int i,pos,n;
printf("Enter the number of nodes:");
scanf("%d",&n);
 for(int i=0;i<n;i++)
{ newnode=(struct node*)malloc(sizeof(struct node));
scanf("%d",&newnode->data);
newnode->next=NULL;
if(head==NULL)
{ head=temp=newnode;
}
else
{ temp->next=newnode;
    temp=newnode;
}
}
printf("Enter the position to insert the node:");
scanf("%d",&pos);
temp=head;

for(i=0;i<pos-1 ;i++)
{ temp=temp->next;
}
if(temp==NULL)
{
    printf("Invalid position!\n");
}
else
{
    temp->next=newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be inserted at position %d:",pos);
scanf("%d",&newnode->data);
newnode->next=temp->next;
temp->next=newnode;
printf("The linked list is:\n");    
for(temp=head;temp!=NULL;temp=temp->next)
{ printf("%d ",temp->data);
}
} 
}