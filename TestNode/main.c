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
//is list empty
bool isEmpty(){
	return head == NULL;
 } 
//find the length of the list
int length(){
	int length = 0;
	struct node *current;
	
	for(current=head;current!=NULL;current=current->next){
		length++; 
	}
	
	return length;
 } 
//dispaly the list
void printList(){
	//start from the beginning 
	struct node *ptr = head;
	printf("\n[");
	
	while(ptr!= NULL){
		printf("(%d,%d)",ptr->key,ptr->data);
		ptr = ptr->next;
	}
	printf("]\n");	
}

//insert link at the first location
void insertFirst(int key,int data){
	//creat a new link
	struct node *link = (struct node*)malloc(sizeof(struct node));
	
	link->key = key;
	link->data = data;
	
	//point to the old first node and act as a new fisrt node
	link->next = head;
	head = link;
}

//delete first item
struct node* deleteFirst(){
    struct node *tmpLink = head;
    
    //mark next to first link as the new first link 
    head = head->next;
    //save reference to first link 
    return tmpLink;
}
//delete item according to a given key
struct node* delete(int key){
	//start from the first link 
	struct node* current = head;
	struct node* previous = NULL;
	
	//return if the list is empty 
	if(isEmpty()){
		return NULL;
	} 
	
	//navigate through list
	while(current->key!=key){
		if(current->next==NULL){
			return NULL;
		}else{
			//store reference to current link 
			previous = current;
			//move to the next link 
			current = current->next;
		}
	} 
	
	//found a match then update the link
	if(current==head){
		//change first if it is the current link 
		head = head->next;
	}else{
		//bypass the current link 
		previous->next = current->next;
	}
	
	return current;
} 
 
//find a link according to a key
struct node* find(int key){
	//start from the head;
	struct node* current = head;
	
	//if the list is empty
	if (isEmpty()){
		return NULL;
	} 
	
	//navigate through list
	while(current->key!=key){
		if(current->next==NULL){
			return NULL;
		}else{
			current=current->next;
		}
	} 
	//data found, return the current link 
	return current;
} 

//sort list link 
void sort(){
	int i,j,k,tempKey,tempData;
	struct node *current;
	struct node *next;
	
	int size=length();
	k = size;
	
	for(i=0;i<size-1;i++,k--){
		//point to the head of the list 
		current = head;
		next = head->next;
		
		//navigate all link 
		for(j=1;j<k;j++){
			//exchange if next has a larger data 
			if(current->data>next->data){
				tempData = current->data;
				current->data = next->data;
				next->data = tempData ;

                tempKey = current->key;
                current->key = next->key;
                next->key = tempKey;
			}
			//give a next at the end 
			current = current->next;
			next = next->next;
		}
	}
}

//reverse list, make the last node point to the head node
void reverse(struct node** head_ref){
	struct node* prev = NULL;
	struct node* current = *head_ref;
	struct node* next;
	
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	*head_ref = prev;
}
 
int main(int argc, char *argv[]) {
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56);
   printf("Original List:");
   printList();
   
   struct node* foundLink = find(4);
   if(foundLink!=NULL){
   	printf("Element found:");
   	printf("(%d,%d)",foundLink->key,foundLink->data);
	printf("\n");    
   }else{
   	printf("Element not found");
   }
   
   struct node *tmp = deleteFirst();
   printf("\nDeleted first value:");
   printList();
   struct node *tmpe = delete(4);
   printf("\nDeleted according to key %d:",4);
   printList();
   
   sort();
   printf("\n");
   printf("List after sorting the data: ");  
   printList();
   
   reverse(&head);
   printf("\nList after reversing the data: ");  
   printList();
   
   return 0;
}
