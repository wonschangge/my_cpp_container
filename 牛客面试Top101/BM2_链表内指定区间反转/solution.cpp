#include <bits/stdc++.h>
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) return head;
        ListNode* cur = head;
        ListNode* pre = head;
        ListNode* begin = NULL;
        ListNode* end = NULL;
        for (int i = 0; i < m - 1; i++) {
            begin = cur;
            cur = cur->next;
        }
        for (int i = 0; i < n - 1; i++) {
            pre = pre->next;
        }
        end = pre->next;
        for (int i = 0; i < (n - m + 1); i++) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        begin->next = pre;
        cur->next = end;
        return head;
    }
};