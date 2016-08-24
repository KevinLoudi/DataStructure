#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Tree represents nodes connected by edges 
there we focuse on binary search tree specially
Path refers to sequence of nodes along the edge of tree
Root refers to the top of the tree 
Parent upward edge // child
Lead refers node that does not have any child node
Subtree represents descendents of a node
visiting refers to check value of a node
traversing means passing through nodes in a specific order
levels rrepresents the generation of a node
keys represents a value of a node based on which a search operation*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* traversal is a process to visit all the nodes of a tree

*/
struct node{
	int data;

	struct node *leftchild;
	struct node *rightchild;
};

struct node *root=NULL;

void insert(int data){
	//creat a new node
	struct node *tmpnode=(struct node*)malloc(sizeof(struct node));
	struct node *current;
	struct node *parent;

	//set the new node
	tmpnode->data=data;
	tmpnode->leftchild=NULL;
	tmpnode->rightchild=NULL;

	//if tree is empty
	if (root==NULL){
		//creat root node
		root=tmpnode;
	}else{
		current=root;
		parent=NULL;

		//compare the data with node data until insertion position
		//is located
		while(true){
			parent=current;

			//go to left of the tree
			if(data<parent->data){
				//data is greater
				current=current->leftchild;

				//insert to the left
				if (current==NULL){
				parent->leftchild=tmpnode;
				return;
			    }
			}
			//go to right of the tree
			else{
				current=current->rightchild;

				//insert to the right
				if (current==NULL){
					parent->rightchild=tmpnode;
					return;
				}
			}
		}
	}
}

struct node* search(int data){
	struct node *current=root;
	printf("Visiting elements:\n");

	while(current->data!=data){
		if(current!=NULL)
			printf("%d",current->data);

		//go to left tree
		if(current->data>data){
			current=current->leftchild;
		}
		//go tp right tree
		else{
			current=current->rightchild;
		}

		//not found
		if(current==NULL){
			return NULL;
		}
	}

    //return if root.data equal to search data
	return current;
}

/*All nodes are connected via edges */
void pre_order_traversal(struct node* root){
	if(root!=NULL){
		printf("%d", root->data);
		pre_order_traversal(root->leftchild);
		pre_order_traversal(root->rightchild);
	}
}

void inorder_traversal(struct node* root){
	if(root!=NULL){
		inorder_traversal(root->leftchild);
		printf("%d",root->data);
		inorder_traversal(root->rightchild);
	}
}

void post_order_traversal(struct node* root){
	if(root!=NULL){
		post_order_traversal(root->leftchild);
		post_order_traversal(root->rightchild);
		printf("%d", root->data);
	}
}

/*Binary search tree is a tree in which all nodes follows the below
properties:
  the left sub-tree of a node has a key less than or equal its parents
  the right sub-tree of a node has a key greater than or equal its parents   
  left_subtree (keys)  ≤  node (key)  ≤  right_subtree (keys)*/

/*However if the input of BST comes in sorted manner, it is observed the worst-
case performance close to linear search.
 Then a kind of balance out existing BST is needed, Adelson, Velski&Landis, AVL trees
 
 AVL tree checks the height of left and right sub-tree and assures that the
 difference is not more than 1.*/

//AVL rotations (singal and double rotations) to make the tree itself balanced
typedef int Type;

typedef struct AVLTreeNode{
	Type key;
	int height;
	struct Avlnode *left;
	struct Avlnode *right;
}Node, *AVLTree;

static Node* creat_avl(Type key, Node *left, Node *right){
	Node* p;

	if((p=(Node*)malloc(sizeof(Node)))==NULL)
		return NULL;
	p->key=key;
	p->height=0;
	p->left=left;
	p->right=right;

	return p;
}

//get the height of the tree
#define HEIGHT(p) ((p==NULL)?-1:(((Node*)(p))->height)

int height_avl(AVLTree tree){
	return HEIGHT(tree);
}

//compare keey of two nodes
#define MAX(a,b) ((a)>(b)?(a):(b))

//left=left rotation
static Node* left_left_rotation(AVLTree k2){
	AVLTree k1;

	//take the left child as root
	k1=k2->left;left child of k2
	//make the right child of k1 become 
	k2->left=k1->right;
	//make k2 to be right child of k1
	k1->right=k2;

	//first calculate the height of sub-tree
	k2->height=MAX(HEIGHT(k2->left),HEIGHT(k1->right))+1;
	//then calculate the height of the root
	k1->height=MAX(HEIGHT(k1->left),k2->height)+1;

	//root after roation
	return k1;
}

//right=right rotation
static Node* right_right_rotation(AVLTree k3){
	AVLTree k2;

	k2=k1->right;
	k1->right=k2->left;
	k2->left=k1;

	k1->height=MAX(HEIGHT(k1->left),HEIGHT(k1->right))+1;
	k2->height=MAX(HEIGHT(k2->right),k1->height)+1;

	return k2;
}

int main(int argc, char *argv[]) {
	int i;
	int array[7]={27, 14, 35, 10, 19, 31, 42 };

	for(i=0;i<7;i++){
		insert(array[i]);
	}

	i=31;
	struct node* tmp=search(i);

	if(tmp!=NULL){
		printf("[%d] element found.\n",tmp->data);
	}else{
		printf("[x ] element not found (%d).\n",i);
	}

	i=15;
	tmp=search(i);

	if(tmp!=NULL){
		printf("[%d] element found.\n",tmp->data);
	}else{
		printf("[x ] element not found (%d).\n",i);
	}

	printf("\nperorder traversal:");
	pre_order_traversal(root);

	printf("\ninorder traversal:");
	inorder_traversal(root);

	printf("\npostorder traversal:");
	post_order_traversal(root);

	return 0;
}
