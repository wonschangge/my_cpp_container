#include <bits/stdc++.h>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    // 只要开辟一个长度等同于两个数组长度之和的新数组，并使用两个指针来遍历原有的两个数组，
    // 不断将较小的数字添加到新数组中，并移动对应的指针即可

    // 将两个有序数组合并为一个有序数组
    vector<int> merge(vector<int> arr1, vector<int> arr2) {
        vector<int> result(arr1.size() + arr2.size());
        int index1 = 0, index2 = 0;
        while (index1 < arr1.size() && index2 < arr2.size()) {
            if (arr1[index1] <= arr2[index2]) {
                result[index1 + index2] = arr1[index1];
                index1++;
            }
            else {
                result[index1 + index2] = arr2[index2];
                index2++;
            }
        }
        //将剩余数字补到结果数组之后
        while(index1 < arr1.size()) {
            result[index1 + index2] = arr1[index1];
            index1++;
        }
        while(index2 < arr2.size()) {
            result[index1 + index2] = arr2[index2];
            index2++;
        }
        return result;
    }

    void mergeSort(vector<int>&nums, int start, int end) {
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
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