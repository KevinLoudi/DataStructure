#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX 20

/*
Binary search is a fast search algorithm 
with run-time complexity of Ο(log n).
works on the principle of divide and conquer 

Binary search search a particular item by comparing 
the middle most item of the collection.
If match occurs then index of item is returned. 
If middle item is greater than item then item is 
searched in sub-array to the right of the middle 
item other wise item is search in sub-array to the 
left of the middle item.

countinue on a subarray untill the size reduced to zero
*/

/*
Linear search has worst-case complexity of O(n)
Binary search O(log n)
Interpolation search O(log(log (n))
but binary search does not take advantage of the sorted data

*/
int Array[MAX] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};

void printline(int count){
	int i;
	
   for(i = 0;i <count-1;i++){
      printf("=");
   }
	
   printf("=\n");	
}

int find(int data){
	int comparison = 0;
	int index = -1;
	int i;
	
	//navigate through all items
	for(i=0;i<MAX;i++){
		//count the comparisons made
		comparison++;
		//if data found, break the loop
		if(data==Array[i]){
			index=i;
			break;
		} 
	}
	
	printf("Total comparisons made: %d",comparison);
	return index;
}

//binary search
int binaryfind(int data){
	int lowerbound = 0;
	int upperbound = MAX-1;
	int midpoint = -1;
	int comparisons = 0;
	int index = -1;
	
	while(lowerbound<=upperbound){
		printf("Comparison %d\n",(comparisons+1));
		printf("LowerBound: %d, Array[%d]=%d\n",
		         lowerbound,lowerbound,Array[lowerbound]);
		printf("UpperBound: %d, Array[%d]=%d\n",
				 upperbound,upperbound,Array[upperbound]);
		
		//compute the mid point
		//midpoint = (lowerbound+upperbound)/2
		midpoint=lowerbound+(upperbound-lowerbound)/2;
		comparisons++;
		//data found
		if(Array[midpoint]==data){
			index=midpoint;
			break;
		}else{
			if(Array[midpoint]<data){
				//data is in upper half
				lowerbound = midpoint+1;
			}else{
				//data is smaller
				upperbound = midpoint-1;
			}
		}
	}
	printf("Total comparisons made: %d",comparisons);
	return index;
}

/*
Interpolation search is an improved variant of binary search. 
This search algorithm works on the probing position of 
required value
*/
int interfind(int data){
	int lo=0;
	int hi=MAX-1;
	int mid=-1;
	int comparisons=-1;
	int index=-1;

	while(lo<=hi){
		printf("\nComparison %d \n", comparisons);
		printf("lo: %d, Array[%d]=%d\n",lo,lo,Array[lo]);
		printf("hi: %d, Array[%d]=%d\n",hi,hi,Array[hi]);

		comparisons++;

		//probe the mid point
		mid=lo+(((double)(hi-lo)/(Array[hi]-Array[lo]))*(data-Array[lo]));
		printf("mid= %d\n",mid);

		//data found
		if (Array[mid]==data){
			index=mid;
			break;
		}else{
			if (Array[mid]<data)
			{
				//if data is larger, data is in upper half
				lo=mid+1;
			}else{
				//if data is smaller, data is in lower half
				hi=mid-1;
			}
		}
	}

	//no comparison was made in the last turn
	printf("\nTotal comparisons made: %d\n", --comparisons);
	return index;
}

void display(){
	int i;
	printf("[");
	
	//navigate through all items
	for(i=0;i<MAX;i++){
		printf("%d ",Array[i]);
		//another line for every 3 elements 
		if(i%3==0){
			printf("\n");
		}
	}
	
	printf("]\n");
}

int main(int argc, char *argv[]) {
	printf("Input Array:");
	display();
	printline(50);
	
	//find location of 1; 
	int location = find(55);
	
	//if elements was found 
	if(location != -1)
		printf("\nElement found at location: %d\n",(location+1));
	else
		printf("Element not found.\n");
	
	//binary search in elements finding
	printline(50);
	location = binaryfind(55);
	
	if(location != -1)
		printf("\nElement Binary found at location: %d\n",(location+1));
	else
		printf("Element not found.");
	
    //interpolation search
    printline(50);
    location = interfind(55);
	if(location != -1)
		printf("\nElement Binary found at location: %d\n",(location+1));
	else
		printf("Element not found.");

	return 0;
}
