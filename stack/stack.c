
#include <stdio.h>
#define SIZE 5

int stack[SIZE], top=SIZE-1;
void push(int st[], int val);
void pop(int st[]);
void peek(int st[]);
void display(int st[]);

int main() {

int val, choice;
printf("Enter the elements for the array:\n");
for(int i=0;i<SIZE;i++)
{
    scanf("%d",&stack[i]);
}
printf("\n 1. PUSH");
printf("\n 2. POP");
printf("\n 3. PEEK");
printf("\n 4. DISPLAY");
printf("\n 5. EXIT");

for(;choice!=5;)
{


printf("\n Enter your option: ");
scanf("%d", &choice);
switch(choice)
{
case 1:
{
printf("\n Enter the number to be pushed on stack: \n");
scanf("%d", &val);
push(stack, val);
break;
}
case 2:
{
 pop(stack);
break;
    }
case 3:
{
peek(stack);
break;
}
case 4:
{
display(stack);
break;

}
}
}
return 0;
}





void push(int st[], int val)            //push
{
if(top == SIZE-1)
printf("\n STACK OVERFLOW\n\n");

else
stack[++top] = val;
}


void pop(int stack[])          //pop
{

if(top == -1)
printf("\n STACK UNDERFLOW\n\n");
else
{
printf("The poped element is:%d\n\n",stack[top]);
top--;
}
}


void display(int stack[])          //display
{
int i;
if(top == -1)
printf("\n STACK IS EMPTY\n\n");
else
{
for(i=top;i>=0;i--)
printf("\t %d",stack[i]);
}
}


void peek(int stack[])       //peek
{
if(top == -1)
printf("\n STACK IS EMPTY");

else
printf("The top element is :%d\n\n",stack[top]);
}

