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
    for(i=1; i<=4; i++)
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
    for(i=1; i<=3; i++)
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

void display()
{
    struct node *temp=la;
    printf("\n After merging");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}



void merge()
{
    struct node *temp=la;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=lb;
}


int main()
{
    lista();
    listb();
    merge();
    display();

    return 0;
}
