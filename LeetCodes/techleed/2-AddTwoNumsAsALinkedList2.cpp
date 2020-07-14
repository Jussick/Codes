//C++ file
/***********************************************
#
#      Filename: 1-AddTwoNumsAsALinkedList.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: You are given two linked-lists representing two non-negative integers. Each of their nodes contain 
                  a single digit. Add the two numbers and return it as a linked list.
                 * Upgrade: Do not use linklist reverse to achive algorithm.
                 Example:
                 Input: (2 -> 4 -> 3) + (1 -> 6 -> 4)
                 Output: 4 -> 0 -> 7
                 Explanation: 243 + 164 = 407.
#        Create: 2020-07-08 17:35:16
#**********************************************/
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode():val(-1),next(NULL) {}
    ListNode(int num):val(num),next(NULL) {}
};

class Solution {
public:
    Solution& AddNode(ListNode **head, int val);
    void PrintList(ListNode *head);
    ListNode* reverseList(ListNode *head);  // 反转链表
    ListNode* AddTwoLinklist(ListNode *head1, ListNode *head2);
};

Solution& Solution::AddNode(ListNode **head, int val)
{
    ListNode *node = new ListNode(val);
    if (*head == NULL)
    {
        *head = node;
    }
    else
    {
        ListNode *p = *head;
        for (; p->next != NULL; p = p->next);
        p->next = node;
    }
    return *this;
}

void Solution::PrintList(ListNode *head)
{
    ListNode *p = head;
    while (p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

ListNode* Solution::reverseList(ListNode *head)  // 反转链表
{
    // first input check
    if (head == NULL)
        return NULL;

    ListNode *cur = head;  // 当前节点指针
    ListNode *next;        // 下一个节点指针
    ListNode *pre = NULL;  // 前一个节点指针

    while (cur != NULL)
    {
        if (cur->next == NULL)  // 到了尾节点
        {
            cur->next = pre;
            break;
        }
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return cur;
}

ListNode* Solution::AddTwoLinklist(ListNode *head1, ListNode *head2)
{
    ListNode *p1 = head1;
    ListNode *p2 = head2;

    /* calculate two linklists' length */
    int head1_len, head2_len;
    for (head1_len = 1; p1->next != NULL; p1 = p1->next, head1_len++) {}
    for (head2_len = 1; p2->next != NULL; p2 = p2->next, head2_len++) {}
    cout << "head1_len: " << head1_len << ", head2_len: " << head2_len << endl;
    
    ListNode *head1_r = reverseList(head1);
    ListNode *head2_r = reverseList(head2);
    p1 = head1_r;
    p2 = head2_r;
    ListNode *res_head = NULL;

    int carryFlag = 0;  // 进位标志
    if (head1_len == head2_len)
    {
        for (;p1; p1 = p1->next, p2 = p2->next)
        {
            int sum = p1->val + p2->val; 
            if (carryFlag)
            {
                sum += 1;
                carryFlag = 0;
            }
            if (sum >= 10)
            {
                sum -= 10;
                carryFlag = 1;
            }
            AddNode(&res_head, sum);
        }
    }
    else if (head1_len > head2_len)
    {
        for (; p2; p1 = p1->next, p2 = p2->next)  // p2较短
        {
            int sum = p1->val + p2->val;
            if (carryFlag)
            {
                sum += 1;
                carryFlag = 0;
            }
            if (sum >= 10)
            {
                sum -= 10;
                carryFlag = 1;
            }
            AddNode(&res_head, sum);
        }
        for (; p1; p1 = p1->next)  // p1剩余部分
        {
            int nextNum = p1->val;
            if (carryFlag)
            {
                if (p1->val + 1 == 10)
                {
                    nextNum = 0;
                }
                else
                {
                    nextNum = p1->val + 1;
                    carryFlag = 0;
                }
                AddNode(&res_head, nextNum);
            }
            else
            {
                AddNode(&res_head, p1->val);
            }
        }
    }
    else if (head2_len > head1_len)
    {
        for (; p1; p1 = p1->next, p2 = p2->next)  // p1较短
        {
            // p_res->val = p1->val + p2->val;
            int sum = p1->val + p2->val;
            if (carryFlag)
            {
                // p_res->val += 1;
                sum += 1;
                carryFlag = 0;
            }
            if (sum >= 10)
            {
                sum -= 10;
                carryFlag = 1;
            }
            AddNode(&res_head, sum);
        }
        for (; p2; p2 = p2->next)   // p2剩余部分
        {
            int nextNum = p2->val;
            if (carryFlag)
            {
                if (p2->val + 1 == 10)
                {
                    nextNum = 0;
                }
                else
                {
                    nextNum = p2->val + 1;
                    carryFlag = 0;
                }
                AddNode(&res_head, nextNum);
            }
            else
            {
                AddNode(&res_head, p2->val);
            }
        }

    }
    if (carryFlag)
        AddNode(&res_head, 1);

    return reverseList(res_head);
}

int main()
{
    Solution ss;
    /* create two linklist */
    ListNode *head1 = NULL;
    ss.AddNode(&head1, 1).AddNode(&head1, 2).AddNode(&head1, 3);
    ListNode *head2 = NULL;
    ss.AddNode(&head2, 5).AddNode(&head2, 6).AddNode(&head2, 7);

    cout << "linklist1: "; 
    ss.PrintList(head1);
    cout << "linklist2: "; 
    ss.PrintList(head2);

    ListNode *res_head = ss.AddTwoLinklist(head1, head2);
    cout << "sum linklist is: ";
    ss.PrintList(res_head);
}
