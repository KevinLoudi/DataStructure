#ifndef _AVL_TREE_H_ //条件编译 if not defined 
#define _AVL_TREE_H_
//三种预处理功能（宏定义，文件包含和条件编译）中的一种 
//对同一个变量或者函数进行多次声明不会报错
//但如果h文件中定义了全局变量，不加条件编译会出现重复定义的错误
 
typedef int Type;

typedef struct AVLTreeNode{
    Type key;                    // 关键字(键值)
    int height;
    struct AVLTreeNode *left;    // 左孩子
    struct AVLTreeNode *right;    // 右孩子
}Node, *AVLTree;
//相当于定义了一个新结构体并为它起了一个名字
//Node 是结构体的别名，AVLTree 是指向结构体的指针 

// 获取AVL树的高度
int avltree_height(AVLTree tree);

//创建节点
static Node* avltree_create_node(Type key,Node *left,Node *right);

// 前序遍历"AVL树"
void preorder_avltree(AVLTree tree);
// 中序遍历"AVL树"
void inorder_avltree(AVLTree tree);
// 后序遍历"AVL树"
void postorder_avltree(AVLTree tree);

void print_avltree(AVLTree tree, Type key, int direction);

// (递归实现)查找"AVL树x"中键值为key的节点
Node* avltree_search(AVLTree x, Type key);
// (非递归实现)查找"AVL树x"中键值为key的节点
Node* iterative_avltree_search(AVLTree x, Type key);

// 查找最小结点：返回tree为根结点的AVL树的最小结点。
Node* avltree_minimum(AVLTree tree);
// 查找最大结点：返回tree为根结点的AVL树的最大结点。
Node* avltree_maximum(AVLTree tree);

// 将结点插入到AVL树中，返回根节点
Node* avltree_insert(AVLTree tree, Type key);

// 删除结点(key是节点值)，返回根节点
Node* avltree_delete(AVLTree tree, Type key);

// 销毁AVL树
void destroy_avltree(AVLTree tree);


#endif
