#include <stdio.h>
#include <stdlib.h>

/*
  Hash table is a data structure which store data in associative
  manner.
  data is stored in array format where each data values has its
  own unique index value
  then we can access data fast when we know the index of desired data
  search,insert and delete
*/
/*步骤：1.根据Hash函数构造哈希表 2.解决地址冲突 3.进行Hash查找*/
/*
 method1: compute the hash code of the key of data item
 mehtod2: 
*/  
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define SIZE 20 

struct DataItem
{
	int data;
	int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key){
	return key%SIZE;
}
/*search an element, compute the hash code of the key passed
 and locate the element using that hashcode as index
 Use liner probing to get element ahead if not found at hash
 code
 */
struct DataItem* search(int key){
	//get the hash
	int hashIndex=hashCode(key);

	//move in array until an empty
	while(hashArray[hashIndex]!=NULL){
		if (hashArray[hashIndex]->key==key)
			return hashArray[hashIndex];

		//go to the next cell
		++hashIndex;

		//warp around the table
		hashIndex %= SIZE;
	}
	return NULL;
}
/*insert element: compute the hash code of the key passed
and locate the index using hashcode */
void insert(int key,int data){
	struct DataItem *item=(struct DataItem*)malloc(sizeof(struct DataItem));
    item->data=data;
    item->key=key;

    //get the hash
    int hashIndex=hashCode(key);

    //move in array until an empty or deleted cell
    //冲突处理方法
    while(hashArray[hashIndex]!=NULL&&hashArray[hashIndex]->key!=-1){
    	//go to next cell
    	++hashIndex;

    	//warp around the table
    	hashIndex %= SIZE;
    }

    hashArray[hashIndex]=item;
}

struct DataItem* delete(struct DataItem* item){
	int key=item->key;

	//get the hash
	int hashIndex=hashCode(key);

	//move in array until an empty
	while(hashArray[hashIndex]!=NULL){
		if (hashArray[hashIndex]->key==key)
		{
			struct DataItem* tmp=hashArray[hashIndex];

			//assign a dummy item at deleted position
			hashArray[hashIndex]=dummyItem;
			return tmp;
		}

		//go to next cell
		++hashIndex;

		//warp around the table
		hashIndex %= SIZE;
	}

	return NULL;
}

void display(){
	int i=0;

	for (i = 0; i < SIZE; i++)
	{
		if (hashArray[i]!=NULL)
			printf("(%d,%d)", hashArray[i]->key,hashArray[i]->data);
		else
			printf(" ~~ ");
	}

	printf("\n");
}

int main(int argc, char *argv[]) {
	dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
	dummyItem->data=-1;
	dummyItem->key=-1;

   insert(1, 20);
   insert(2, 70);
   insert(42, 80);
   insert(4, 25);
   insert(12, 44);
   insert(14, 32);
   insert(17, 11);
   insert(13, 78);
   insert(37, 97);

   display();

   item=search(37);
   if (item!=NULL)
   {
   	printf("Element found: %d\n", item->data);
   }else{
   	printf("Element not found\n");
   }

   delete(item);

   item=search(37);

   if (item!=NULL)
   {
   	printf("Element found: %d\n", item->data);
   }else{
   	printf("Element not found\n");
   }
   return 0;
}
