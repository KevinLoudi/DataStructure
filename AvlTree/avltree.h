#ifndef _AVL_TREE_H_ //�������� if not defined 
#define _AVL_TREE_H_
//����Ԥ�����ܣ��궨�壬�ļ��������������룩�е�һ�� 
//��ͬһ���������ߺ������ж���������ᱨ��
//�����h�ļ��ж�����ȫ�ֱ����������������������ظ�����Ĵ���
 
typedef int Type;

typedef struct AVLTreeNode{
    Type key;                    // �ؼ���(��ֵ)
    int height;
    struct AVLTreeNode *left;    // ����
    struct AVLTreeNode *right;    // �Һ���
}Node, *AVLTree;
//�൱�ڶ�����һ���½ṹ�岢Ϊ������һ������
//Node �ǽṹ��ı�����AVLTree ��ָ��ṹ���ָ�� 

// ��ȡAVL���ĸ߶�
int avltree_height(AVLTree tree);

//�����ڵ�
static Node* avltree_create_node(Type key,Node *left,Node *right);

// ǰ�����"AVL��"
void preorder_avltree(AVLTree tree);
// �������"AVL��"
void inorder_avltree(AVLTree tree);
// �������"AVL��"
void postorder_avltree(AVLTree tree);

void print_avltree(AVLTree tree, Type key, int direction);

// (�ݹ�ʵ��)����"AVL��x"�м�ֵΪkey�Ľڵ�
Node* avltree_search(AVLTree x, Type key);
// (�ǵݹ�ʵ��)����"AVL��x"�м�ֵΪkey�Ľڵ�
Node* iterative_avltree_search(AVLTree x, Type key);

// ������С��㣺����treeΪ������AVL������С��㡣
Node* avltree_minimum(AVLTree tree);
// ��������㣺����treeΪ������AVL��������㡣
Node* avltree_maximum(AVLTree tree);

// �������뵽AVL���У����ظ��ڵ�
Node* avltree_insert(AVLTree tree, Type key);

// ɾ�����(key�ǽڵ�ֵ)�����ظ��ڵ�
Node* avltree_delete(AVLTree tree, Type key);

// ����AVL��
void destroy_avltree(AVLTree tree);


#endif
