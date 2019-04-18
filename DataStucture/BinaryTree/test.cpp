//C file
/***********************************************
#
#      Filename: test.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 二叉树（非BST）的前、中、后序遍历的非递归实现
#        Create: 2019-04-09 14:10:26
#**********************************************/

#include<iostream>
#include<string>
#include<memory>
#include <queue>
#include<stack>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
#if 0
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {

    }
};
#endif

bool isASpace(int ch) {
	return !isspace(ch);
}

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), isASpace));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), isASpace).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

void preOrderIter(TreeNode *root)
{
    if (root == NULL) return;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty()) {
        TreeNode *nd = s.top();
        cout << nd->val<< " ";
        s.pop();
        if (nd->right != NULL)
            s.push(nd->right);
        if (nd->left != NULL)
            s.push(nd->left);
    }
    cout << endl;
}

void inOrderIter(TreeNode *root)
{
    stack<TreeNode *> s;
    while (root != NULL || !s.empty()) {
        if (root != NULL) {
            s.push(root);
            root = root->left;
        }
        else {
            root = s.top();
			cout << root->val << " ";  //访问完左子树后才访问根结点
            s.pop();
			root = root->right;  // 访问右子树
        }
    }
    cout << endl;
}



void postOrderIter(TreeNode *root)
{
    if (!root) return;
    stack<TreeNode *> s, output;
    s.push(root);
    while (!s.empty()) {
        TreeNode *curr = s.top();
        output.push(curr);
        s.pop();
        if (curr->left)
            s.push(curr->left);
        if (curr->right)
            s.push(curr->right);
    }

    while (!output.empty()) {
        cout << output.top()->val << " ";
        output.pop();
    }
    cout << endl;
}



void levelOrderIter2(TreeNode *root)
{
    if (!root) return;
    queue<TreeNode *> nodesQueue;
    int nodesInCurrentLevel = 1;
    int nodesInNextLevel = 0;
    nodesQueue.push(root);
    while (!nodesQueue.empty()) {
        TreeNode *currNode = nodesQueue.front();
        nodesQueue.pop();
        nodesInCurrentLevel--;
        if (currNode) {
            cout << currNode->val << " ";
            nodesQueue.push(currNode->left);
            nodesQueue.push(currNode->right);
            nodesInNextLevel += 2;
        }
        if (nodesInCurrentLevel == 0) {
            cout << endl;
            nodesInCurrentLevel = nodesInNextLevel;
            nodesInNextLevel = 0;
        }
    }
}

#if 0
int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* t1 = stringToTreeNode(line);
        getline(cin, line);
        TreeNode* t2 = stringToTreeNode(line);

        TreeNode* ret = Solution().mergeTrees(t1, t2);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
#endif

int main() {
	string s = "   [2,1,3,null,4,null,7]    ";
	TreeNode *node = stringToTreeNode(s);
	preOrderIter(node);
	inOrderIter(node);
	levelOrderIter2(node);

	return 0;
}
