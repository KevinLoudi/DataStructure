/*Queue is an abstract data structure, somewhat similar to Stack.
 In contrast to Queue, queue is opened at both end.
 
 One end is always used to insert data (enqueue) and the other 
 is used to remove data (dequeue). 
 
 FIFO:First-In-First-Out
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 6

int Queue[MAX];
int front = 0; //head start from [-1,0] to rear < MAX
int rear = -1; //tail 
int itemCount = 0;

int peek(){
	return Queue[front];
}

int isEmpty(){
	return itemCount == 0;
}

int isFull(){
	return itemCount == MAX;
}

int size(){
	return itemCount;
}

void insert(int data){
	if(!isFull()){
		if(rear == MAX-1){
			//the queue is full, reset 
			rear = -1;
		}
		//add an element at the end (pointer rear) 
		Queue[++rear] = data;
		itemCount++;
	}
}

int removeData(){
	//read the front of the queue
	//then adjust the front point 
	int data = Queue[front++];
	//if the front reached MAX, reset 
	if(front==MAX){
		front=0;
	}
	//decrease the itemcount 
	itemCount--;
	return data;
}

void printQueue(){
  printf("The elements of the queue is as:\n");
  int i = 0;
  for(i=0;i<=itemCount;i++){
  	printf("[%d] %d\n",i,Queue[i]);
  }	
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
   /* insert 5 items */
   insert(3);
   insert(5);
   insert(9);
   insert(1);
   insert(12);
   printQueue();
   return 0;
}
