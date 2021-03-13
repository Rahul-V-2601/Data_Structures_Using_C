#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*top=NULL;

void push(int n)
{
    struct node *temp;
    int val;
    for(int i=1;i<=n;i++)
    {
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value:\n");
    scanf("%d",&val);
    temp->data=val;
    temp->next=top;
    top=temp;
    }
}

void display()
{
    struct node *temp=top;
    printf("\nThe values are:\n");
    while(temp!=NULL)
    {

        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    push(n);
    display();
    return 0;
}
