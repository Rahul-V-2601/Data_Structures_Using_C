#include <stdio.h> 
#include <stdlib.h> 


//Sorting a Linked List using Merge Sort Algorithm

struct Node { 
	int data; 
	struct Node* next; 
}; 

typedef struct Node Node;

Node* start = NULL;

Node* sortList(Node* a, Node* b); 
void listSplit(Node* src, Node** front, Node** back); 

void mergeSort(Node** startPointer)       //Recursive Function
{ 
	Node* head = *startPointer; 
	Node* a; 
	Node* b; 

    //Base case
	if (head == NULL || head->next == NULL){ 
		return; 
	} 

	//List is divided
	listSplit(head, &a, &b); 

	//Sorting the divided lists
	mergeSort(&a); 
	mergeSort(&b); 

	*startPointer = sortList(a, b); 
} 

//Splitting the list using fast-slow strategy
void listSplit(Node* src,Node** front, Node** back) 
{ 
	Node* fast; 
	Node* slow; 
	slow = src; 
	fast = src->next; 

	//The fast node is moved two places at a time, while the slow node is moved one place at a time
	while (fast != NULL) { 
		fast = fast->next; 
		if (fast != NULL) { 
			slow = slow->next; 
			fast = fast->next; 
		} 
	} 

	//When fast node is at the end of the list, the slow node will be at the middle
	*front = src; 
	*back = slow->next; 
	slow->next = NULL; 
} 

Node* sortList(Node* a, Node* b)    //Recursive function
{ 
	Node* result = NULL; 

	//Base case
	if (a == NULL) 
		return b; 
	else if (b == NULL) 
		return a; 

    //Recursive case
	if (a->data <= b->data) { 
		result = a; 
		result->next = sortList(a->next, b); 
	} 
	else { 
		result = b; 
		result->next = sortList(a, b->next); 
	} 
	return result; 
}

void insertAtEnd(){
    int new_data;
    printf("\nEnter the data to be inserted: "); scanf("%d",&new_data);
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data =  new_data;
    new_node->next = NULL;
    if(start==NULL){
        start = new_node;
        return;
    }
    Node *temp = start;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

void traverseList() {
    if(start==NULL){
        printf("\nEmpty List!");
    }
   Node* temp;
   temp = start;
   while (temp != NULL) {
      printf("%d --> ",temp->data);
      temp = temp->next;
   }
}

int main() 
{ 
    int n,input;
    printf("Enter the no of Nodes:  "); scanf("%d",&n);
    for(int i = 0;i<n;i++){
        insertAtEnd();
    }

    printf("\nBefore Sorting: \n");
    traverseList();
    printf("\n\n");

	mergeSort(&start); 

	printf("After Sorting: \n"); 
	traverseList();
    printf("\n\n");

	return 0; 
} 
