#include <stdio.h>
#include<stdlib.h>

struct Node {
   int data;
   struct Node *next;
};

struct Node* start = NULL;
int new_data;
int specificNode;

void insertAtBeginning() {
   printf("\nEnter the data to be inserted: "); scanf("%d",&new_data);
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = start;
   start = new_node;
}

void insertAtEnd(){
    printf("\nEnter the data to be inserted: "); scanf("%d",&new_data);
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data =  new_data;
    new_node->next = NULL;
    if(start==NULL){
        start = new_node;
        return;
    }
    struct Node *temp = start;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new_node;
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
    temp->next = new_node;
}

void deleteAtBeginning(){
    if(start==NULL){
        printf("\nEmpty List! Deletion cannot happen!!!");
        return;
    }
      struct Node *temp = start;
      start = temp->next;
      free(temp);
}

void deleteAtEnd(){
     if(start==NULL){
        printf("\nEmpty List! Deletion cannot happen!!!");
        return;
    }
    struct Node *prev,*temp = start;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void deleteAtSpecificNode(){
    if(start==NULL){
        printf("\nList is empty! Deletion cannot happen!!!");
        return;
    }
    printf("\nEnter the node that needs to be deleted: "); scanf("%d",&specificNode);
    struct Node *prev,*temp = start;
    while(temp->data!=specificNode){
        prev = temp;
        temp = temp->next;
        if(temp==NULL){
        printf("\nInvalid node specified!");
        break;
    }    
    }
    if(temp==NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void traverseList() {
    if(start==NULL){
        printf("\nEmpty List!");
    }
   struct Node* temp;
   temp = start;
   while (temp != NULL) {
      printf("%d --> ",temp->data);
      temp = temp->next;
   }
}
int main() {
    printf("\nSingly Linked List....\n");
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