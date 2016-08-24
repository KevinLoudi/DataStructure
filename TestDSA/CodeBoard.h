#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node{
	int data;
	int key;
	struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;
//dispaly the list
void printList(){
	//start from the beginning 
	struct node *ptr = head;
	printf("\n[");
	
	while(ptr!= NULL){
		printf("(%d,%d)",ptr->key,ptr->data);
		ptr = ptr->next;
	}
	printf(" ]");	
}

//insert link at the first location
void insertFirst(int key,int data){
	//creat a new link
	struct node *link = (struct node*)malloc(sizeof(struct node);
	
	link->key = key;
	link->data = data;
	
	//point to the old first node and act as a new fisrt node
	link->next = head;
	head = link;
}


int main(int argc, char *argv[]) {
	
	printf("Original List:");
	printList();
	return 0;
}