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

void printfNum(int num){
	struct node *curr = head;
	for(int i = index; i >= 1; i--){
		if(i == num){
			printf("result = %d\n", curr->score);
			break;
		}
		curr = curr->next;
	}
}

int main(){
	pushTail(12);
	pushTail(45);
	pushTail(43);
	pushTail(87);
	printLinkedList();
	printf("index = %d\n", index);
	printf("Where?(index) : ");
	int num;
	scanf("%d", &num);
	printfNum(num);
	return 0;
}

