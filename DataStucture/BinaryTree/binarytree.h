#ifndef _BINARYTREE_H
#define _BINARYTREE_H
#include <iostream>
#include <set>
#include <vector>
using namespace std;


class binaryTreeNode {
	public:
		int item;
		binaryTreeNode *l_child, *r_child;

		//binaryTreeNode():l_child(NULL), r_child(NULL) { }
		binaryTreeNode(int item):item(item),l_child(NULL),r_child(NULL) { }

};


class binaryTree {
	private:
		set<int> elemSet;  // 存放树中已有元素

		bool ifExistsElement(int elem);
	public:
		binaryTree() { }
		void createBST(binaryTreeNode * &root, vector<int> &v);  // 创建一个BST
		void inorder(binaryTreeNode *root);
		binaryTreeNode *insert(binaryTreeNode *root, int item);
		binaryTreeNode *searchNode(binaryTreeNode *root, int value);
		binaryTreeNode *leftRotation(binaryTreeNode *root, binaryTreeNode *node);
		binaryTreeNode *rightRotation(binaryTreeNode *root, binaryTreeNode *node);
		binaryTreeNode *maxValueNode(binaryTreeNode *root);
		binaryTreeNode *minValueNode(binaryTreeNode *root);
		binaryTreeNode *deleteNode(binaryTreeNode *root, int delete_item);
};

// some utility functions
void printNodeInfo(binaryTreeNode *node);   // 打印一个节点内容
bool ifIsA_BST(binaryTreeNode *root);  // 判断一颗二叉树树否为BST
bool doesTree1HasTree2(binaryTreeNode *root1, binaryTreeNode *root2);  // 判断以root1为根节点的子树是否与root2有相同的结构
bool hasSubTree(binaryTreeNode *root1, binaryTreeNode *root2);  // 判断以root2为根节点的二叉树是不是以root1为根节点的二叉树的子结构
void treeMirrorRecusively(binaryTreeNode *root);  // 把root转换为其镜像树



#endif
