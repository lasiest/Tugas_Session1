#include <stdio.h>
#include <stdlib.h>

struct node{
	int score;
	struct node *next;
}*head, *tail;

node *createNode(int score){
	struct node *newNode = (node*)malloc(sizeof(node));
	newNode->score = score;
	newNode->next = NULL;
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

void remove(){
	struct node *curr = head;
	struct node *next1 = head->next;
	while(next1 != NULL){
		if(curr->score == next1->score){
			curr->next = next1->next;
			printf("%d ", curr->score);
			free(next1);
			next1 = curr->next;
		}else{
			curr = curr->next;
			next1 = next1->next;
		}

	}
}

int main(){
	pushTail(10);
	pushTail(20);
	pushTail(20);
	pushTail(30);
	pushTail(30);
	pushTail(40);
	pushTail(50);
	printLinkedList();
	remove();
	printf("\n");
	printLinkedList();
}
