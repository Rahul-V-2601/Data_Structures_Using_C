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
    for(i=1; i<8; i++)
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
    for(i=1; i<5; i++)
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
void intersect()
{
    struct node *temp=la,*t=lb;
    while(t->next!=NULL)
        t=t->next;
    while(temp->data!=6) {          /* nan vandhu list a la 4 ngra element oda list b ah attach panra madhiri poturuken
                                        so input la 4 nu kudukanum.*/
        temp=temp->next;
    }
    t->next=temp->next;
}

void compare()
{
    struct node *temp=la,*t=lb;
    while(temp!=NULL)
    {
        while(t!=NULL)
        {
            if(temp->next==t->next&&temp->next!=NULL)
            {
                printf("\nThe element is :%d",temp->data);
                printf("\nThe address is :%p",t->next);

                return ;
            }
            else
                t=t->next;
        }
        t=lb;
        temp=temp->next;
    }
}
void display()
{
    struct node *temp=lb;
    printf("\nList b:\t");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
void display1()
{
    struct node *temp=la;
    printf("\nList a:\t");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

void main()
{
    lista();
    listb();
    intersect();
    compare();
    display();
    display1();
}
