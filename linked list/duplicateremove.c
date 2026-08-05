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
    printf("with duplicate \n");
    temp=head;
    for(int i=0;i<n;i++)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp->next!=NULL)
    {
        ptr2=temp;
        while(ptr2->next != NULL)
        {
            if(temp->data==ptr2->next->data)
            {dup=ptr2->next;
                ptr2->next=ptr2->next->next;
                free(dup);
            }
            else {ptr2=ptr2->next;
        }}
        temp=temp->next;
    }
temp=head;
printf("after - \n");
while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }

    return 0;
}
