#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*la,*lb;

void lista()
{
    int a,i;
    struct node *temp,*newnode;
    la=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value for a:\n");
    scanf("%d",&a);
    la->data=a;
    la->next=NULL;
    temp=la;
    for(i=1; i<3; i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the value for a:\n");
        scanf("%d",&a);
        newnode->data=a;
        newnode->next=NULL;
        temp->next=newnode;
        temp=newnode;
    }
}

void listb()
{
    int b,i;
    struct node *temp,*newnode;
    lb=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value for b:\n");
    scanf("%d",&b);
    lb->data=b;
    lb->next=NULL;
    temp=lb;
    for(i=1; i<3; i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the value for b:\n");
        scanf("%d",&b);
        newnode->data=b;
        newnode->next=NULL;
        temp->next=newnode;
        temp=newnode;
    }
}

void compare()
{
    struct node *temp=la,*t=lb;
    while(temp!=NULL)
    {
        while(t!=NULL)
        {
            if(temp->data==t->data)
            {
                printf("The element is :%d",t->data);
                return ;
            }
            else
                t=t->next;
        }
        t=lb;
        temp=temp->next;
    }
}

void main()
{
    lista();
    listb();
    compare();
}
