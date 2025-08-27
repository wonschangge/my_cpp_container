#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// 链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 找出两个无序单向链表的相同元素
vector<int> findCommonElements(ListNode* head1, ListNode* head2) {
    unordered_set<int> set;
    vector<int> result;

    // 遍历第一个链表，将元素存入哈希集合
    ListNode* cur = head1;
    while (cur != nullptr) {
        set.insert(cur->val);
        cur = cur->next;
    }

    // 遍历第二个链表，检查元素是否在哈希集合中
    cur = head2;
    while (cur != nullptr) {
        if (set.count(cur->val)) {
            result.push_back(cur->val);
            set.erase(cur->val); // 避免重复添加相同元素（若链表有重复节点）
        }
        cur = cur->next;
    }

    return result;
}

// 辅助函数：创建链表
ListNode* createList(const vector<int>& nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    for (int num : nums) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    return dummy->next;
}

// 辅助函数：打印结果
void printResult(const vector<int>& res) {
    for (size_t i = 0; i < res.size(); ++i) {
        if (i > 0) cout << " ";
        cout << res[i];
    }
    cout << endl;
}

int main() {
    // 测试案例
    vector<int> nums1 = {3, 1, 4, 2, 5};
    vector<int> nums2 = {4, 5, 6, 3, 7};
    ListNode* head1 = createList(nums1);
    ListNode* head2 = createList(nums2);

    vector<int> common = findCommonElements(head1, head2);
    printResult(common); // 输出：3 4 5

    return 0;
}