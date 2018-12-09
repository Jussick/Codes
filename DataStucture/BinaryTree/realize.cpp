//C++ file
/***********************************************
#
#      Filename: realize.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-11-14 16:37:53
#**********************************************/
#include <iostream>
#include <stdio.h>
#include "binarytree.h"

using namespace std;

/* 打印一个节点的信息 */
void printNodeInfo(binaryTreeNode *node)
{
	if (node != NULL)
		printf("node is %d\n", node->item);
	else
		printf("node is NULL\n");
}


/* 返回最大节点 */
binaryTreeNode *binaryTree::maxValueNode(binaryTreeNode *root)
{
	binaryTreeNode *cur = root;
	while (cur->r_child)
		cur = cur->r_child;
	return cur;
}

binaryTreeNode *binaryTree::minValueNode(binaryTreeNode *root)
{
	binaryTreeNode *cur = root;
	while (cur->l_child)
		cur = cur->l_child;
	return cur;
}

/* 判断一棵树是否为二叉搜索树（BST）*/
bool ifIsA_BST(binaryTreeNode *root)
{
	binaryTree *tree = new binaryTree();
	if (root == NULL)
		return true;
	if (root->l_child != NULL && tree->maxValueNode(root->l_child)->item > root->item)
		return false;
	if (root->r_child != NULL && tree->minValueNode(root->r_child)->item < root->item)
		return false;
	if (!ifIsA_BST(root->l_child) || !ifIsA_BST(root->r_child))
		return false;
	return true;
}

/* 中序遍历 */
void binaryTree::inorder(binaryTreeNode *root)
{
	if (root != NULL)
	{
		inorder(root->l_child);
		printf("%d \t", root->item);
		inorder(root->r_child);
	}
	else return;
}

/* 利用set的无重复元素的性质，判断一个元素是否在树中  */
bool binaryTree::ifExistsElement(int elem)
{
	for (auto pd = this->elemSet.begin(); pd != this->elemSet.end(); ++pd)
	{
		if (*pd == elem) 
			return true;
	}
	return false;
}

/* 寻找一个节点，返回该节点的指针，没找到返回NULL */
binaryTreeNode *binaryTree::searchNode(binaryTreeNode *root, int value)
{
	if (root != NULL)
	{
		if (value == root->item)
			return root;
		else if (value > root->item)
			return searchNode(root->r_child, value);
		else if (value < root->item)
			return searchNode(root->l_child, value);
	}
	else return NULL;
}


/* 插入一个节点  */
binaryTreeNode *binaryTree::insert(binaryTreeNode *root, int item)
{
	if (root == NULL)
	{
		binaryTreeNode *temp = new binaryTreeNode(item);
		this->elemSet.insert(item);  // 插入已有元素集合
		return temp;
	}
	// 检查是否元素重复
	if (ifExistsElement(item))
	{
		printf("element %d exists\n", item);
		return root;
	}

	if (item > root->item)
		root->r_child = insert(root->r_child, item);
	else
		root->l_child = insert(root->l_child, item);

	return root;
}


/* 创建一颗二叉树 */
void binaryTree::createBST(binaryTreeNode* &root, vector<int> &v)
{
	if (v.empty())
		root = NULL;
	else
	{
		for (int val : v)
			root = insert(root, val);	
	}
}

binaryTreeNode *binaryTree::leftRotation(binaryTreeNode *root, binaryTreeNode *node)
{
	return NULL;
}

binaryTreeNode *binaryTree::rightRotation(binaryTreeNode *root, binaryTreeNode *node)
{
	return NULL;
}


binaryTreeNode *binaryTree::deleteNode(binaryTreeNode *root, int value)
{
	if (root == NULL)  return NULL;

	if (value > root->item)
		root->r_child = deleteNode(root->r_child, value);
	else if (value < root->item)
		root->l_child = deleteNode(root->l_child, value);
	else
	{
		// 删除节点有一个孩子节点或无孩子节点
		if (root->l_child == NULL)
		{
			binaryTreeNode *temp = root->r_child;
			delete(root);
			return temp;
		}
		else if (root->r_child == NULL)
		{
			binaryTreeNode *temp = root->l_child;
			delete(root);
			return temp;
		}
		// 删除节点有两个孩子节点
		else
		{
			binaryTreeNode *leftChildMaxNode = maxValueNode(root->l_child);
			//cout << "leftChildMaxNode is " << leftChildMaxNode->item << endl;
			root->item = leftChildMaxNode->item;
			root->l_child = deleteNode(root->l_child, leftChildMaxNode->item);
		}
	}
	return root;
}

bool doesTree1HasTree2(binaryTreeNode *root1, binaryTreeNode *root2)
{
	if (root2 == NULL)
		return true;
	if (root1 == NULL)
		return false;
	if (root1->item != root2->item)
		return false;

	return doesTree1HasTree2(root1->l_child, root2->l_child) &&
		doesTree1HasTree2(root1->r_child, root2->r_child);
}

bool hasSubTree(binaryTreeNode *root1, binaryTreeNode *root2)
{
	bool result = false;

	if (root1 != NULL && root2 != NULL)
	{
		if (root1->item == root2->item)
			result = doesTree1HasTree2(root1, root2);
		if (!result)
			result = hasSubTree(root1->l_child, root2);
		if (!result)
			result = hasSubTree(root1->r_child, root2);
	}
	return result;
}

void treeMirrorRecusively(binaryTreeNode *root)
{
	if (root == NULL || (root->l_child == NULL && root->r_child == NULL))
		return;

	binaryTreeNode *temp = root->l_child;
	root->l_child = root->r_child;
	root->r_child = temp;

	if (root->l_child)
		treeMirrorRecusively(root->l_child);
	if (root->r_child)
		treeMirrorRecusively(root->r_child);

}
