#include <stdio.h>
#include <stdlib.h>

struct node{
	int score;
	int flag;
	struct node *next;
}*head, *tail;

node *createNode (int score){
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
	int flag = 0;
	while(curr){
		printf("%d -> ", curr->score);
		curr->flag++;
		if(curr->flag > 1){
			flag = 1;
			break;
		}
		curr = curr->next;
	}
	if(flag == 1){
		("Ada Cycle");
	}else{
		printf("Tidak ada Cycle\n");
	}
}

int main(){
	pushTail(10);
	pushTail(20);
	pushTail(30);
	printLinkedList();
}
