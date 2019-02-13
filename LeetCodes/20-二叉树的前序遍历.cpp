//C++ file
/***********************************************
#
#      Filename: 20-二叉树的前序遍历.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2019-01-14 14:18:27
#**********************************************/
#include<iostream>
#include<vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	public:
		vector<int> preorderTraversal(TreeNode* root) {
			vector<int> seq;
			if (root != NULL)
			{
				seq.push_back(root->val);
				preorderTraversal(root->left);
				preorderTraversal(root->right);
			}
			return seq;
		}
};
