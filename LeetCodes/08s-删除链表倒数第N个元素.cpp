//C file
/***********************************************
#
#      Filename: 08-删除链表倒数第N个元素.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

		* 示例：
			给定一个链表: 1->2->3->4->5, 和 n = 2.
			当删除了倒数第二个节点后，链表变为 1->2->3->5.
		
		[示例输入]: [1,2,3,4,5] 2
		[输出]: [1,2,3,5]
		
		* 说明：
			给定的 n 保证是有效的。
		
		* 进阶：
			你能尝试使用一趟扫描实现吗？
#        Create: 2018-08-20 17:29:08
#**********************************************/
#include<algorithm>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		
		// 链表只有一个节点的情况,由于输入保证了给定的n有效，就无须再判断
		if (head->next == NULL) {
			delete head;
			return NULL;
		}
		ListNode *first = head;
		ListNode *second = head;

		/*  找到倒数第n个节点 */

			// 把first指向第n-1个节点
		for (int i = 0; i < n - 1; ++i) {
			first = first->next;	
		}
			// 把second指向倒数第n个节点
		while (first->next != NULL) {
			second = second->next;
			first = first->next;
		}
		// 如果删除的是尾节点，则按照常规方式删除
		if (second->next == NULL) {
			// 	把cur指向链表倒数第二个节点
			ListNode *cur;
			for ( cur = head; cur->next->next != NULL; cur = cur->next);
			ListNode *deleteNode = cur->next;
			cur->next = cur->next->next;
			delete deleteNode;
		}
		else {
			second->val = second->next->val;
			ListNode *deleteNode = second->next;
			second->next = second->next->next;
			delete deleteNode;
		}
			
		return head;
    }
};
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

int stringToInteger(string input) {
    return stoi(input);
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        ListNode* ret = Solution().removeNthFromEnd(head, n);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
