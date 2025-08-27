#include <bits/stdc++.h>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode * reverseList(ListNode * head)
    {
        if (head == NULL) // 空表
            return head;
        
        ListNode* cur = head;
        ListNode* pre = NULL;
        while (cur != NULL) {
            // 断开链表前，先记录后续一个
            ListNode* tmp = cur->next;
            // 当前的next指向前一个
            cur->next = pre;
            // 前一个更新为当前
            pre = cur;
            // 当前一个更新为先前记录的后续一个
            cur = tmp;
        }
        return pre;
    }
};

