#include <stdio.h>
#include <stdlib.h>

struct node{
	int score;
	struct node *next;
}*head_a, *tail_a, *head_b, *tail_b, *head_sort;

node *createNode(int score){
	struct node *newNode = (node*)malloc(sizeof(node));
	newNode->score = score;
	newNode->next = NULL;
	return newNode;
}

void pushHead(int score, int flag){
	if(flag == 1){
		struct node *temp = createNode(score);
		if(!head_a){
			head_a = tail_a = temp;
		}else{
			temp->next = head_a;
			head_a = temp;
		}
	}else if(flag == 2){
		struct node *temp = createNode(score);
		if(!head_b){
			head_b = tail_b = temp;
		}else{
			temp->next = head_b;
			head_b = temp;
		}
	}
}

void pushTail(int score, int flag){
	if(flag == 1){
		struct node *temp = createNode(score);
		if(!head_a){
			head_a = tail_a = temp;
		}else{
			tail_a->next = temp;
			tail_a = temp;
		}
	}else if(flag == 2){
		struct node *temp = createNode(score);
		if(!head_b){
			head_b = tail_b = temp;
		}else{
			tail_b->next = temp;
			tail_b = temp;
		}
	}
}

node *merge(node *head_a, node *head_b, node *sortedNode){
//	node *head_sort = NULL;
	if(head_a == NULL) return head_b;
	if(head_b == NULL) return head_a;
	
	if(head_a && head_b){
		if(head_a->score <= head_b->score){
			
			sortedNode = head_a;
			head_a = head_a->next;
//			printf("head_a(1)\n");
		}else{
			sortedNode = head_b;
			head_b = sortedNode->next;
//			printf("head_b(1)\n");
		}
	}
	head_sort = sortedNode;
	
	while(head_a && head_b){
		if(head_a->score <= head_b->score){
			sortedNode->next = head_a;
			sortedNode = head_a;
			head_a = head_a->next;
//			printf("head_a\n");
		}else{
			sortedNode->next = head_b;
			sortedNode = head_b;
			head_b = head_b->next;
//			printf("head_b\n");
		}
//		sortedNode = sortedNode->next;
//		printf("here");
	}
//	if(head_a == NULL) sortedNode->next = head_b; printf("head_a(last)\n");
//	if(head_b == NULL) sortedNode->next = head_a; printf("head_b(last)\n");
	
	return head_sort;
}

struct node *mergee = merge(head_a, head_b, mergee);

void printLinkedlist(int flag){
	if(flag == 1){
		struct node *curr = head_a;
		while(curr){
			printf("%d -> ", curr->score);
			curr = curr->next;
		}
	}
	else if(flag == 2){
		struct node *curr = head_b;
		while(curr){
			printf("%d -> ", curr->score);
			curr = curr->next;
		}	
	}else if(flag == 3){
		struct node *curr = head_sort;
		while(curr){
			printf("%d -> ", curr->score);
			curr = curr->next;
		}
	}
	printf("Null\n");
}



int main(){
	pushTail(10, 1);
	pushTail(30, 1);
	pushTail(50, 1);
	printLinkedlist(1);
	pushTail(20,2);
	pushTail(40,2);
	pushTail(60,2);
	printLinkedlist(2);
//	struct node 
	struct node *mergee = merge(head_a, head_b, mergee);
	printLinkedlist(3);
	return 0;
}
