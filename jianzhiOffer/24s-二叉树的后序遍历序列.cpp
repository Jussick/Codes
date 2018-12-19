//C++ file
/***********************************************
#
#      Filename: 24-二叉树的后序遍历序列.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 检验一个序列是否能成为一颗二叉搜索树的后序遍历序列
#        Create: 2018-12-11 16:31:17
#**********************************************/
#include<iostream>

using namespace std;

bool verifySequenceOfBST(int *sequence, int length)
{
	if (sequence == NULL || length <= 0)
		return false;

	// root
	int root = sequence[length - 1];

	// 找到右子树的位置
	int i;
	for (i = 0; i < length - 1; ++i)
	{
		if (sequence[i] > root)
			break;
	}

	// 右子树的值都大于根节点
	int j;
	for (j = i; j < length - 1; ++j)
	{
		if (sequence[j] < root)
			return false;
	}

	// 左子树是不是BST
	bool left = true;
	if (i > 0)
		left = verifySequenceOfBST(sequence, i);

	// 右子树是不是BST
	bool right = true;
	if (i < length - 1)
		right = verifySequenceOfBST(sequence + i, length - i - 1);

	return (left && right);
}


int main()
{
	int sequence[20] = {5,7,6,9,11,10,8};	
	int length = 7;
	bool isCapability = verifySequenceOfBST(sequence, length);
	if (isCapability)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;

}

