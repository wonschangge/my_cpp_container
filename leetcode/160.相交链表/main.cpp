#include <bits/stdc++.h>
#include <cassert>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p = headA;
    ListNode *q = headB;
    while (p != q) {
      p = p != nullptr ? p->next : headB;
      q = q != nullptr ? q->next : headA;
    }
    return p;
  }
};

int main() {
  Solution *s = new Solution();
  {
    ListNode *headA;
    ListNode *headB;
    ListNode *a1;
    ListNode *b1;
    ListNode *b2;
    ListNode *c1;
    ListNode *c2;
    ListNode *c3;

    // b1->val = 6;
    // b1->next = b2;
    // b2->val = 1;
    // b2->next = c1;
    // c1->val = 8;
    // c1->next = c2;
    // c2->val = 4;
    // c2->next = c3;
    // c3->val = 5;
    // c3->next = nullptr;
    headA->val = 4;
    headA->next = a1;
    a1->val = 1;
    a1->next = c1;
    // headB->val = 5;
    // headB->next = b1;
    // assert(s->getIntersectionNode(headA, headB) == headA->next->next);
  }
}