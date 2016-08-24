#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* Sorting refers to arranging data in a particular format. Sorting algorithm specifies the way to arrange data in a particular order. 
Most common orders are numerical or lexicographical order.

The importance of sorting lies in the fact that data searching can
be optimized if data is stored in a sorted manner

*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//#define MAX 10
//int list[MAX] = {1,8,4,6,0,3,5,2,7,9};
#define MAX 7
int list[MAX]={4,6,3,2,1,9,7};

void display(){
	int i;
	printf("[");

	//navigate through all items
	for (i = 0; i < MAX; ++i)
	{
		printf("%d", list[i]);
	}

	printf("]\n");
}

/* bubble-sorting: a simple sorting algorithm based on
comparison in each pair of adjacent elements 
*/
void bubbleSort(){
	int tmp;
	int i,j;

	bool swapped = false;

	//loop through all numbers
	for (i = 0; i < MAX-1; ++i)
	{
		swapped = false;

		//loop through numbers falling ahead
		for(j=0;j<MAX-1-i;++j){
			printf("items compared: [%d,%d]", list[j],list[j+1]);
		
			//check if next number is lesser than current or not
			//swap the numbers and bubble up the highest number
		
		if (list[j]>list[j+1])
		{
			tmp=list[j];
			list[j]=list[j+1];
			list[j+1]=tmp;

			swapped=true;
			printf("=> swapped [%d,%d]\n",list[j],list[j+1]);
		}else
		{
			printf("=> not swapped\n");
		}

	  }
	  //if no number was swapped that means
	  //array is sorted now and break the loop
	  if (!swapped)
		{
			break;
		}

	  printf("iteration %d\n", (i+1));
	  display();
	}

}

/* insertion sort: a in-place comparison based sorting
 a sub-list is maintained which is always sorted
*/
 void printline(int count){
 	int i;

 	for(i=0;i<count-1;i++){
 		printf("=");
 	}

 	printf("\n");
 }

 void insertionSort(){
 	int valueToSort;
 	int holePosition;
 	int i;

 	//loop through all numbers
 	for(i=1;i<MAX;i++){

 		//select a value to be inserted
 		valueToSort = list[i];
        
        //select the hole position where number is to be inserted
        holePosition=i;

        //check if previous no. is larger than value to be inserted
        while(holePosition>0&&list[holePosition-1]>valueToSort){
        	//find the last number that is larger than  
        	list[holePosition]=list[holePosition-1];
        	holePosition--;
        	printf("item moved : %d\n", list[holePosition]);
        }
		
		//through scan the maintained sorted list to decided where should the element be inserted 
        if (holePosition!=i)
        {
        	//there are part of sub-list element that is larger, insert-action needed 
        	printf("item inserted : %d, at position: %d\n", valueToSort, holePosition);
        	//insert the number at hole position
        	list[holePosition]=valueToSort;
        }

        printf("iteration %d#: \n", i);
        display();
 	}
 }

/* Select sort based algorithm in which the list is divided into two
parts, sorted part at left and unsorted part at right
The process continues moving unsorted array boundary by one element
*/
int selectionSort(){
	int indexMin, i, j;

	//loop through all numbers
	for(i=0;i<MAX-1;i++){

		//set current element as minimum
		indexMin=i;

		//check the element to be minimum
		for(j=i+1;j<MAX;j++){
			if (list[j]<list[indexMin]){
				//find the minimun element in the unsorted part
				indexMin=j;
			}
		}

		  if(indexMin!=i){
				printf("Items swapped: [%d, %d]\n",list[i],list[indexMin]);

				//swap the numbers
				int tmp=list[indexMin];
				list[indexMin]=list[i];
				list[i]=tmp;
			}

			printf("iteration: %d#:",(i+1));
			display();
		}
}

/* quick sort is a highly efficient sorting algrithm that based on
partitioning of data-array into smaller arrays
*/
int swap(int num1, int num2){
	int tmp=list[num1];
	list[num1]=list[num2];
	list[num2]=tmp;
}
int partition(int left,int right,int pivot){
	int leftPointer=left-1;
	int rightPointer=right;

	while(true){

		while(list[++leftPointer]<pivot){
			//nop
		}

		while(rightPointer>0&&list[--rightPointer]>pivot){
			//nop
		}

		if (leftPointer>=rightPointer)
		{
			break;
		}else{
			printf("item swapped: %d,%d\n",
			list[leftPointer],list[rightPointer]);
			swap(leftPointer,rightPointer);
		}
	}

	printf("pivot swapped: %d,%d\n", list[leftPointer],list[rightPointer]);
    swap(leftPointer,right);
    printf("Update Array: ");
    display();
    return leftPointer;
}
int quickSort(int left,int right){
	if(right-left<=0){
		return;
	}else{
		int pivot=list[right];
		int partitionPoint=partition(left,right,pivot);
		quickSort(left,partitionPoint-1);
		quickSort(partitionPoint+1,right);
	}
}

/*Merge sort is a sorting technique based on divide and
cinquer technique with worst-case time complexity O(n log n  
it divides the array into equal halves and combines them 
in a sorted manner  */
/*first compare each list and then combine them into another list
in sorted manner  */
void merging(int low,int mid,int high){
	int l1,l2,i;
	int b[10];

	for(l1=low,l2=mid+1,i=low;l1<=mid&&l2<=high;i++){
		if(list[l1]<=list[l2])
			b[i]=list[l1++];
		else
			b[i]=list[l2++];
	}

	while(l1<=mid)
		b[i++]=list[l1++];

	while(l2<=high)
		b[i++]=list[l2++];

	for(i=low;i<=high;i++)
		list[i]=b[i];
}

void mergesort(int low,int high){
	//take the element number of array as n
	int mid;

	if(low<high){
		//divide the list into two halve until
		mid=(low+high)/2;
		//array1 a[0]...a[n/2]
		mergesort(low,mid);
		//array2 a[n/2+1]...a[n]
		mergesort(mid+1,high);
		merging(low,mid,high);
	}else{
		//return if n==1
		return;
	}
}
/*Shell sort is a highly efficient sorting method
base on insert sort, and it avoid large shifts as
in case of insertion sort  */
void shellSort(){
	int inner,outer;
	int valueToSort;
	int interval=1;
	int elements=MAX;
	int i=0;

	while(interval<=elements/3){
		interval=interval*3+1;
	}

	while(interval>0){
		printf("iteration %d#:",i);
		display();

		for(outer=interval;outer<elements;outer++){
			valueToSort=list[outer];
			inner=outer;

			while(inner>interval-1&&list[inner-interval]>=valueToSort){
				list[inner]=list[inner-interval];
				inner-=interval;
				printf("item moved: %d\n",list[inner]);
			}

			list[inner]=valueToSort;
			printf("item inserted: %d, at position: %d\n",valueToSort,inner);
		}

		interval=(interval-1)/3;
		i++;
	}
}
int main(int argc, char *argv[]) {
	printf("input array: \n");
	display();
	printf("\n");

	/*bubbleSort();
	printf("\noutput array: \n");
	display();*/

	/*printline(50);
	insertionSort();
	printf("Output Array:");
    display();
    printline(50);*/

    /*rintf("Selection Sort:\n");
    printline(50);
    selectionSort();
    printf("Output array:");
    display();
    printline(50);*/

    /*printf("Quick Sort\n");
    printline(50);
    quickSort(0,MAX-1);
    printf("Result: ");
    display();
    printline(50);*/

    printf("Shell Sort\n");
    printf("Input Array:");
    printline(50);
    shellSort();
    printf("Output Array:");
    display();
    printline(50);
	return 0;
}
