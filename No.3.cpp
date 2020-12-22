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

int mid = 0;

void printLinkedList(){
	struct node *curr = head;
	while(curr){
		printf("%d -> ", curr->score);
		curr = curr->next;
		mid++;
	}
	printf("Null\n");
}

void printMid(){
	struct node *curr = head;
	for(int i = 1; i <= mid; i++){
		if(i == mid){
			printf("Mid(value) = %d\n", curr->score);
			break;
		}
		curr = curr->next;
	}
}

int main(){
	pushTail(10);
	pushTail(20);
	pushTail(30);
	pushTail(40);
	pushTail(50);
	printLinkedList();
	if(mid % 2 == 1){
		mid++;
	}
	printf("Mid(index) = %d\n", mid/2);
	mid = mid/2;
	printMid();
}
