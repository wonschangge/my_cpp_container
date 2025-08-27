#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

class Solution {
public:
    void quickSort(vector<int>&nums, int start, int end) {
        if (start >= end) return;

        // 确保是一个随机选取的数
        int x = rand() % (end - start + 1) + start; // start为校准的偏移量(offset)
        int pivot = nums[x];
        swap(nums[start], nums[x]); // 将基准值放到最前面去，利于左右区间的缩窄

        int l = start, r = end;
        while (l < r) {
            while (l < r && nums[l] <= pivot) l++; //l<r且nums[l]值小于等于基准值,左区间+1
            if (l < r) { //相当于 l<r且nums[l]>pivot, 即nums[l]值大于基准值
                swap(nums[l], nums[r]); // 把大于基准值的数对调到右区间去
                r--; // 右区间可以确保是大于基准值的了,右区间-1
            }
        }
        if (l == r && nums[r] > pivot) r--; // l和r交汇了,且nums[r]大于基准值,右区间再-1
        if (r != start) swap(nums[start], nums[r]); //只要r没和start交汇,就交换他们的值
        // r所在的位置确保就是开头设定的基准值,后续也就不用再处理了

        quickSort(nums, start, r - 1);
        quickSort(nums, r + 1, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quickSort(nums, 0, n - 1);
        return nums;
    }
};

int main() {
    Solution* s = new Solution();
    {
        vector<int> input = {3,4,1,5,9,2,6};
        s->sortArray(input);
        for(auto i:input) cout << i << " ";
    }
}