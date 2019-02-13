//C++ file
/***********************************************
#
#      Filename: main.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-11-07 11:18:28
#**********************************************/
#include <iostream>
#include"binarytree.h"
using namespace std;

int main()
{
	/* Let us create following BST 
     *         50 
     *      /     \ 
     *     30      70 
     *    /  \    /  \ 
     *  20   40  60   80 */
	binaryTreeNode *root = NULL;
	binaryTree *tree = new binaryTree();
	root = tree->insert(root, 50);
	tree->insert(root, 30);
	tree->insert(root, 20);
	tree->insert(root, 40);
	tree->insert(root, 70);
	tree->insert(root, 60);
	tree->insert(root, 80);
	tree->insert(root, 80);
	cout << "Inorder traverse tree" << endl;
	tree->inorder(root);
	cout << endl << "Breath first traversal tree" << endl;
	tree->breath_first_traversal(root);
	cout << endl << "postorder traverse tree" << endl;
	tree->postorder(root);

	findPathMatchValue(root, 300);

#if 0
	cout << endl << "After make it a mirror" << endl;
	treeMirrorRecusively(root);  // 镜像树的中序遍历变倒序了，如原本二叉搜索树的中序遍历是从小到大，变为镜像后，中序遍历就变成从大到小了。
	tree->inorder(root);

	cout << endl << "max is " << tree->maxValueNode(root)->item << endl;

	if (hasSubTree(root, root))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
#if 0
	binaryTreeNode *findResult = tree->searchNode(root, 80);
	binaryTreeNode *unfindResult = tree->searchNode(root, 90);
	printNodeInfo(findResult);
	printNodeInfo(unfindResult);
#endif

	cout << "delete 80..." << endl;
	tree->deleteNode(root, 80);
	cout << "after delete:" << endl;
	tree->inorder(root);

	cout << endl << "delete 30..." << endl;
	tree->deleteNode(root, 30);
	cout << "after delete:" << endl;
	tree->inorder(root);
#endif

	cout << endl << "second tree(create method)" << endl;
	binaryTreeNode *root1;
	vector<int> v{70,60,80};
	tree->createBST(root1, v);
	cout << "Inorder traverse tree" << endl;
	tree->inorder(root1);

	if (ifIsA_BST_efficient(root1))
		cout << endl << "It's a BST." << endl;
	else
		cout << endl << "It's not a BST." << endl;


	return 0;
}
