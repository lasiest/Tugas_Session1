#include <stdio.h>
#include <stdlib.h>

int index = 0;

struct node{
	int score;
	struct node *next;
}*head, *tail;

node *createNode(int score){
	struct node *newNode = (node*)malloc(sizeof(node));
	newNode->score = score;
	newNode->next = NULL;
	index++;
	return newNode;
}

void pushTail(int score){
	struct node *temp = createNode(score);
	if(!head){
		head = tail = temp;
	}else{
		tail->next = temp;
		tail = temp;
	}
}

void printLinkedList(){
	struct node *curr = head;
	while(curr){
		printf("%d -> ", curr->score);
		curr = curr->next;
	}
	printf("Null\n");
}

void swap(struct node *a, struct node *b){
	int temp = a->score;
	a->score = b->score;
	b->score = temp;
}

void bubbleSort(struct node *head){

    int swapped, i; 
    struct node *ptr1; 
    struct node *lptr = NULL; 
  
    if (head == NULL){
    	return;    	
	}
	
    do{ 
        swapped = 0;
        ptr1 = head;
        while(ptr1->next != lptr) 
        { 
            if(ptr1->score < ptr1->next->score) 
            { 
            	swap(ptr1, ptr1->next); 
        		swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    }while (swapped); 
 
}

int main(){
	pushTail(10);
	pushTail(20);
	pushTail(30);
	pushTail(40);
	pushTail(50);
	printLinkedList();
	bubbleSort(head);
	printLinkedList();
	return 0;
}
