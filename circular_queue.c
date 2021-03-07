#include<stdio.h>
#define S 5
char queue[S];
int front=-1;
int rear=-1;
void enqueue(char );
void dequeue();
void display();
void main()
{
   int choice;
   char x=0;
   printf(" 1.Insert\n 2.Dequeue\n 3.Display\n 4.Exit");
   for(;choice!=4;)
   {
   printf("\nEnter your choice:");
   scanf("%d",&choice);
   switch(choice)
   {
   case 1:
   {
        printf("\nEnter the element:");
        scanf("%s",&x);
        enqueue(x);
        break;
        }
    case 2:
       dequeue();
       break;
    case 3:
        display();
        break;
     }
     }
     }

 void enqueue(char x)
 {
   if((rear+1)%S==front)
      printf("\nOverflow\n");
    else
        {
        rear=(rear+1)%S;
        queue[rear]=x;
        }

        if(front==-1)
          front++;

}

  void dequeue()
  {
    if(front==-1)
     printf("\nUnderflow\n");
     else if(front==rear)
     {
         printf("\n%c",queue[front]);
      front=rear=-1;
     }
      else{
            printf("\n%c",queue[front]);
        front=(front+1)%S;
      }
        }


   void display()
   {
       int i=front;
       printf("%d",i);
        printf("\n Elements in the queue:\n");
        if(front==0)
            for(;i<rear;i++)
               printf("%c\t",queue[i]);

        else
        {
      for(;(i+1)!=front;)
      {
         printf("%c\t",queue[i]);
         i=(i+1)%S;
       }
       printf("%c",queue[i]);
        }
   }
