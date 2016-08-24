/*Author: Zhu Gengyu 
  Date: 2016/8/10
  Propose: Test various DSA with C
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int TestArray();
int InsertAfterIndex(int* Array, int ArrayLen,int InsertItem,int InsertIndex);
int InsertBeforeIndex(int* Array, int ArrayLen,int InsertItem,int InsertIndex);
int DeleteAfterIndex(int* Array, int ArrayLen,int InsertIndex);
int SearchItemIndex(int* Array, int ArrayLen, int SearchObj);
int UpdateItem(int* Array, int ArrayLen, int Obj, int ObjIndex);
// a sequence of data connected via links
// chain of nodes 
// simple linked list, doubly linked list and circular linked list

int TestList(); 
//Definition and Methods used in double-Link-List 
/********************************/
struct node{
	int data;
	int key;
	
	struct node *next;
	struct node *prev;
};
struct node *head = NULL;
struct node *last = NULL;
struct node *current = NULL;
bool ListisEmpty(){
	return head == NULL;
}
int length(){
	int length = 0;
	struct node *current;
	
	for(current=head; current != NULL;current = current->next){
		length++;
	}
	return length;
} 
/********************************/
int InsertFirst(int key,int data){
	//creat a link
	struct node *link = (struct node*) malloc (sizeof(struct node)); 
	link->key = key;
	link->data = data;
	
	if(ListisEmpty()){
		//make "link" the last link 
		last = link;
	}else{
		//update first prev link 
		head->prev = link;
	}
	//point "link" to old first link 
	link->next = head;
	//point first to new first link 
	head = link;
	return 0;
}

int InsertLast(int key,int data){
  	//creat a link
	struct node *link = (struct node*) malloc (sizeof(struct node)); 
	link->key = key;
	link->data = data;
	
	if(ListisEmpty()){
		//make "link" the last link 
		last = link;
	}else{
		//make "link" the last link  
		last->next = link;
		//make old last node as prev of new link 
		link->prev = last;
	}
	//point "link" to new last link 
    last = link;
	return 0;
}
int TestList(){
	
	return 0;
}

int main(int argc, char *argv[]) {

	TestArray();
	return 0;
}

int TestArray(){
	int LAA[] = {1,3,5,7,8};
	int LA[] = {1,3,5,7,8};
	//Insert item, Insert Position, Array length 
	int item = 10, k=3,n=5; 
	int i = 0, j = n; 
	printf("The original array elements are :\n");;
	for(i=0;i<n;i++)
	{
		printf("LA[%d] = %d \n",i,LA[i]); 
	}
    n = InsertAfterIndex(&LA[0],n,item,k);
	printf("The elements after insertion :\n");
	
    for(i = 0; i<n; i++) {
      printf("LA[%d] = %d \n", i, LA[i]);
    }
    
    n = DeleteAfterIndex(&LA[0],n,k);
    printf("Delet the array elements after index :\n");
    for(i = 0; i<n; i++){
    	printf("LA[%d] = %d \n", i, LA[i]);
	}
    
    
    n = 5;
    n = InsertBeforeIndex(&LAA[0],n,item,k);
    printf("The array elements before insertion :\n");
	for(i = 0; i<n; i++) {
      printf("LA[%d] = %d \n", i, LAA[i]);
    }
    
    int f = 20;
    printf("Find the index of element--%d :\n",f);
    int sa = SearchItemIndex(&LAA[0],n,f);
    printf("the index of the element is %d",sa);
    
    int tmp = LAA[3];
    UpdateItem(&LAA[0],n,LAA[3]*10,3);
    printf("Update the 3th element from %d to %d:\n",tmp,LAA[3]);
    
	return 0;
}
//Insertion after given index of an array
int InsertAfterIndex(int* Array, int ArrayLen,int InsertItem,int InsertIndex){
	int AIndex = InsertIndex;
	int i = 0;
	//Shift the rest elements downwards 
	for(i = ArrayLen;i >= AIndex;i--)
	{
	  Array[i+1] = Array[i];
	}
	//add new element at the first position 
	Array[InsertIndex] = InsertItem;
	ArrayLen++;
	return ArrayLen;
}

int InsertBeforeIndex(int* Array, int ArrayLen,int InsertItem,int InsertIndex){
 	int AIndex = InsertIndex;
	int i = 0;
	//Shift the rest elements downwards 
	for(i = ArrayLen;i >= AIndex+1;i--)
	{
	  Array[i+1] = Array[i];
	}
	//add new element at the first position 
	Array[InsertIndex+1] = InsertItem;
	ArrayLen++;
	return ArrayLen;
 }

int DeleteAfterIndex(int* Array, int ArrayLen,int InsertIndex) {
  int i, j;
  j = InsertIndex;
  while(j<ArrayLen){
  	Array[j-1] = Array[j];
  	j = j + 1;
  }
  ArrayLen --;
  return ArrayLen;
}

//Find a return the index of SearchObj
//if there is no SearchObj, return -1; 
int SearchItemIndex(int* Array, int ArrayLen, int SearchObj){
	int j = 0;
	int FindRes = -1;
	/*for(j=0;j<ArrayLen;j++)
	{
	  if(Array[j] == SearchObj){
	  	FindRes = j;
	  	break;
	  }
	}*/
	while(j < ArrayLen) 
	{
	  if(Array[j] == SearchObj){
	  	FindRes = j;
	  	break;
	  }
	  j = j + 1;
	}
	return FindRes;
}

int UpdateItem(int* Array, int ArrayLen, int Obj, int ObjIndex){
  Array[ObjIndex] = Obj;
  return 0;	
}
 
 
 
 
 
