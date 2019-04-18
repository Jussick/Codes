#ifndef _BINARYTREE_H
#define _BINARYTREE_H
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#define MAX_VAL 2147483647
#define MIN_VAL -2147483648
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
		void createBST(binaryTreeNode * &root, vector<int> &v);  // 插入方法创建一个BST
		void inorder(binaryTreeNode *root);  // 中序遍历
		void inorder_nonRecur(binaryTreeNode *root);  // 中序遍历的非递归写法
		void postorder(binaryTreeNode *root);  // 后序遍历
		void breath_first_traversal(binaryTreeNode *root);  // 层序遍历
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
bool ifIsA_BST_efficient(binaryTreeNode *root);  // 判断一棵树是否为BST的高效方法
bool doesTree1HasTree2(binaryTreeNode *root1, binaryTreeNode *root2);  // 判断以root1为根节点的子树是否与root2有相同的结构
bool hasSubTree(binaryTreeNode *root1, binaryTreeNode *root2);  // 判断以root2为根节点的二叉树是不是以root1为根节点的二叉树的子结构
void treeMirrorRecusively(binaryTreeNode *root);  // 把root转换为其镜像树
void findPathMatchValue(binaryTreeNode *root, int expectedSum);  // 打印和为value的路径
void findPathMatchValue(binaryTreeNode *root, int expectedSum, vector<int> &path, int &currentSum, bool &isFound);  // 重载上面的函数以递归解决问题
binaryTreeNode *mergeTrees(binaryTreeNode *t1, binaryTreeNode *t2);  // 合并两个二叉树（leetcode-617）
void createBinarytree(binaryTreeNode * &root, vector<const char *> &v);  // 层序遍历方法创建一个BST



#endif
