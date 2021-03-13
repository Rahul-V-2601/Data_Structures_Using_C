#include <stdio.h>
#include<stdlib.h>

struct Node {
   int data;
   struct Node *prev,*next;
};

struct Node* start = NULL;
int new_data;
int specificNode;

void insertAtBeginning() {
   printf("\nEnter the data to be inserted: "); scanf("%d",&new_data);
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->prev = NULL;
   new_node->next = start;
   if(start!=NULL){
       start->prev = new_node;
       }
   start = new_node;
   printf("\nInsertion Successful..!");
}

void insertAtEnd(){
    printf("\nEnter the data to be inserted: "); scanf("%d",&new_data);
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data =  new_data;
    new_node->next = NULL;
    if(start==NULL){
        new_node->prev = NULL;
        start = new_node;
        printf("\nInsertion Successful..!");
        return;
    }
    struct Node *temp = start;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    new_node->prev = temp;
    temp->next = new_node;
    printf("\nInsertion Successful..!");
}

void insertAfter(){

    if(start==NULL){
        printf("\nList is empty!!!");
        return;
    }
    printf("\nEnter the data to be inserted: "); scanf("%d",&new_data);
    printf("\nEnter the node after which to be inserted: "); scanf("%d",&specificNode);
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data =  new_data;
    
    struct Node *temp = start;
    while(temp->data!=specificNode){
        temp = temp->next;
         if(temp==NULL){
        printf("\nInvalid node specified!");
        break;
    }    
    }
     if(temp==NULL){
        return;
    }
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next->prev = new_node;
    temp->next = new_node;
    printf("\nInsertion Successful..!");
}

void deleteAtBeginning(){
    if(start==NULL){
        printf("\nEmpty List! Deletion cannot happen!!!");
        return;
    }
      struct Node *temp = start;
      if(temp->prev==temp->next){     //Only one node in the list
        start = NULL;
        free(temp);
        printf("\nDeletion Successful..!");
        return;
      }
      temp->next->prev = NULL;
      start = temp->next;
      free(temp);
      printf("\nDeletion Successful..!");
}

void deleteAtEnd(){
     if(start==NULL){
        printf("\nEmpty List! Deletion cannot happen!!!");
        return;
    }
    struct Node *temp = start;
    if(temp->prev==temp->next){     //Only one node in the list
        start = NULL;
        free(temp);
        printf("\nDeletion Successful..!");
        return;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    printf("\nDeletion Successful..!");
}

void deleteAtSpecificNode(){
    if(start==NULL){
        printf("\nList is empty! Deletion cannot happen!!!");
        return;
    }
    printf("\nEnter the node that needs to be deleted: "); scanf("%d",&specificNode);
    struct Node *temp = start;
    while(temp->data!=specificNode){
        temp = temp->next;
        if(temp==NULL){
        printf("\nInvalid node specified!");
        break;
    }    
    }
    if(temp==NULL){
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    printf("\nDeletion Successful..!");
}

void traverseList() {
    if(start==NULL){
        printf("\nEmpty List!");
    }
   struct Node* temp;
   temp = start;
   printf("\nCurrent Linked list :  ");
   while (temp != NULL) {
      printf("%d --> ",temp->data);
      temp = temp->next;
   }
}
int main() {
    printf("\nDoubly Linked List....\n");
    int selectedOption;

     do
    {
       printf("\n\nMenu : \n1. Insert at beginning\t2. Insert at End\n3. Insert after a node\t4. Delete at beginning\n5. Delete at end\t6. Delete a specific node\n7. Traverse the list\t8. Terminate\n");
       printf("\nWhat are you gonna choose?: ");
       scanf("%d",&selectedOption);
       switch(selectedOption){
           case 1: insertAtBeginning(); break;
           case 2: insertAtEnd(); break;
           case 3: insertAfter(); break;
           case 4: deleteAtBeginning(); break;
           case 5: deleteAtEnd(); break;
           case 6: deleteAtSpecificNode(); break;
           case 7: traverseList(); break;
           case 8: break;
           default: printf("\nSelected option is invalid!");
       }
    } while (selectedOption!=8);

   return 0;
}