//C++ file
/***********************************************
#
#      Filename: 03-两两交换链表中的节点.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
                你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
                示例:
                给定 1->2->3->4, 你应该返回 2->1->4->3.
#        Create: 2020-09-07 17:41:21
#**********************************************/
#include <iostream>

using namespace std;



/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* 在链表结尾添加一个节点 */
bool addOneNodeToTail(int item, ListNode **head)  // **是为了要改变head指向的地址
{
    ListNode *cur = *head;
    ListNode *pnew = new ListNode(item);
    if (pnew == NULL)  // 内存申请失败
        return false;

    if (cur == NULL)  // 链表为空时
        *head = pnew;
    else
    {
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = pnew;
    }
    return true;
}

void TraverseList(ListNode *head)
{
    /* 递归法遍历 */
    if (head == NULL)
    {
        cout << endl;
        return;
    }
    cout << head->val << " ";
    TraverseList(head->next);

    /* 迭代法遍历 */
    // ListNode *temp = head;
    // while (temp != NULL)
    // {
        // cout << temp->val << " ";
        // temp = temp->next;
    // }
    // cout << endl;
}

/* 递归解法 */
// 思路：(递归三部曲)
//  1、返回值：交换完成的子链表
//  2、调用单元做了什么：若两个结点为head和next，那么head->next指向交换好的子链表，next->next=head
//  3、终止条件：head或next为null
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};

int main()
{
    ListNode *head = NULL;
    addOneNodeToTail(1, &head);
    addOneNodeToTail(2, &head);
    addOneNodeToTail(3, &head);
    addOneNodeToTail(4, &head);
    TraverseList(head);

    Solution s;
    ListNode *newHead = s.swapPairs(head);
    TraverseList(newHead);
}
