#include<iostream>
#include<string>
using namespace std;

template <typename T>
class binaryTreeNode {
public:
    T element;
    binaryTreeNode<T>* leftChild;
    binaryTreeNode<T>* rightChild;
    
    binaryTreeNode(){leftChild = NULL;rightChild = NULL;}
};

template <typename T>
class binaryTree {
private:
    binaryTreeNode<T>* mRoot;//树根
    
    
    int getSize(binaryTreeNode<T>*);
    int getHeight(binaryTreeNode<T>*);
    
    void preOrder(binaryTreeNode<T>*);
    void inOrder(binaryTreeNode<T>*);
    void postOrder(binaryTreeNode<T>*);
    void distroy(binaryTreeNode<T>*&);
    binaryTreeNode<T>* AddNode(const T& key,int direction,binaryTreeNode<T>*& root);
    
public:
    binaryTree();
    virtual ~binaryTree();
    binaryTreeNode<T>* Create();//递归的创建二叉树的节点
    void AddNode(const T& key,int direction);
    
    int getSize();//递归得到树的节点数目
    int getHeight();//递归得到树的高度
    
    //递归遍历
    void preOrder();//前序遍历
    void inOrder();//中序遍历
    void postOrder();//后序遍历
    
    //删除二叉树
    void distroy();
    
};
