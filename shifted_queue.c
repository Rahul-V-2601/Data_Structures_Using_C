#include <stdio.h>
#define SIZE 5
char queue[SIZE];
int front=-1,rear=-1;
void enqueue(char);
void dequeue();
void display();


int main()
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

    return 0;
}

void enqueue(char x)
 {
   if(rear==SIZE-1)
       printf("\nOverflow\n");
    else
        {
            rear++;
        queue[rear]=x;
        }

        if(front==-1)
         front++;
}

  void dequeue()
  {
    if(front==rear)
     printf("\nUnderflow\n");
    else
    {
        for(int i=front;i<rear;i++)
            queue[i]=queue[i+1];

    }
    rear--;

}


   void display()
   {
       int i;
        printf("\n Elements in the queue:\n");
            for(i=front;i<=rear;i++)
               printf("%c\t",queue[i]);
   }
