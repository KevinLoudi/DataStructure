/*Author: Zhu Gengyu
  Date: 2016/8/12
  Propose: Test stack
A stack is an abstract data type (ADT),
commonly used in most programming languages.
It is named stack as it behaves like a real-world stack, 
for example a deck of cards or pile of plates etc.
A real-world stack allows operations at one end only
LIFO: Last-in-first-out 

A element that placed (insert-PUSH) last accessed (remove-POP) first
A stack can be implemented by means of Array, Struct, Pointer or Link-List
and can be a fixed size of dynamic resize
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int MAXSIZE = 8;
int stack[8];
int top = -1;

void printstack(){
	int tmp = top;
	if(tmp==-1){
		printf("The Stack is Empty!");
		return; 
	} 
	printf("The Stack Element is as following:\n");
	while(tmp>=0){
		printf("[%d]  %d \n",tmp,stack[tmp]);
		tmp--;
	}
	return;
}

bool isempty(){
	return top == -1;
}

bool isfull(){
	return top == MAXSIZE;
}

//get the top data element without remove it
int  peek(){
	return stack[top];
}

//put a new data element into the stack
bool push(int data){
	if(!isfull()){
	  top++; //increment top to point next empty space  
	  stack[top] = data; //add data element as pointed	
	  return 1;
	}else{
      printf("Could not insert data for the stack is full!\n");
	  return 0;		
	}
}

//access the content while removing it
int pop(){
	int data;
	
	if(!isempty()){
		data = stack[top];
		top--;
		return data;
	}else{
		printf("Could not retrieve data since stack is empty!\n");
	}
}


int main(int argc, char *argv[]) {
   //push items on to the stack
   push(3);
   push(5);
   push(9);
   push(1);
   push(12);
   push(15);
   printstack();
   int data = pop();
   printf("Following are the stack after pop\n");
   printstack();
   return 0;
}
