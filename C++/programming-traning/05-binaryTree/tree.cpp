//C file
/***********************************************
#
#      Filename: tree.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-08-07 17:22:08
#**********************************************/
#include "tree.h"

template <typename T>
binaryTreeNode<T>* binaryTree<T>::Create(){
    
    binaryTreeNode<T>* current = NULL; 
    T val; 
    cin >> val;//输入键值 
    if(val == -1)//标识当前子树为空，转向下一节点
    {
        return NULL;
    }
    
    else{//递归的创建左右子树
        current = new binaryTreeNode<T>;
        current->element = val;
        current->leftChild = Create();
        current->rightChild = Create();
        return current;
    }
}

template <typename T>
binaryTreeNode<T>* binaryTree<T>::binaryTree() 
{
	mRoot = NULL;	
	return mRoot;
}

int main()
{
	binaryTree<int> tree1;
	tree1.Create();

	return 0;
}
