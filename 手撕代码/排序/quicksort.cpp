#include <bits/stdc++.h>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    void quicksort(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
    }

    void quicksort(vector<int>& nums, int start, int end) {
        // 可将下面四个判断简化为(不懂)
        // if (start >= end) return;
        
        // 将数组分区，并获得中间值的下标
        int middle = partition(nums, start, end);
        // // 对左边区域快速排序
        // quicksort(nums, start, middle - 1);
        // // 对右边区域快速排序
        // quicksort(nums, middle + 1, end);
        // 当左边区域中至少有2个数字时，对左边区域快速排序
        
        if (start != middle && start != middle - 1)
            quicksort(nums, start, middle - 1);
        // 当右边区域中至少有2个数字时，对右边区域快速排序
        if (middle != end && middle != end - 1)
            quicksort(nums, middle + 1, end);

        // if (start != middle && start != middle - 1)
        // if (middle != end && middle != end - 1)
        // 效果等同于
        // if (start == end || start == end + 1) return;
        // 进一步等同于
        // if (start >= end) return;
    }

    // 分区算法
    // 注意各种边界条件，需要实际动手实践才能加深体会
    int partition(vector<int>& nums, int start, int end) {
        // TODO: 将 nums 从 start 到 end 分区，左边区域比基数小，右边区域比基数大
        //       最后返回中间值的下标
        // 取第一个数作为基数
        int pivot = nums[start];
        // 取第二个数开始分区
        int left = start + 1;
        // 右边界
        int right = end;

        // left right 相遇时退出循环
        while (left < right) {
            // 找到第一个大于基数的位置
            while (left < right && nums[left] <= pivot) left++;
            // 如果左边不等于右边，等同于 left < right && nums[left] > pivot
            // 交换这两个数，使得左边分区都小于或等于基数，右边分区大于或等于基数
            if (left < right && nums[left] > pivot) {
            // if (left != right) { // 可简化为
                swap(nums[left], nums[right]);
                right--;
            }
        }
        // 如果 left 和 right 相等，单独比较 nums[right] 和 pivot，以缩小基数值左侧的规模
        if (left == right && nums[right] > pivot) right--;
        // 将基数和中间数交换
        if (right != start) swap(nums[start], nums[right]);
        // 返回(可能已经缩小范围的)右值(此时它这个位置的值代表是一定小于等于pivot的值)
        return right;
    }

};

int main() {
    Solution* s = new Solution();
    // {
    //     vector<int> input = {3,4,1,5,9,2,6};
    //     s->quicksort(input);
    //     for(auto i:input) cout << i << " ";
    // }
    {
        vector<int> input = {110, 100, 0};
        s->quicksort(input);
        for(auto i:input) cout << i << " ";
    }
}