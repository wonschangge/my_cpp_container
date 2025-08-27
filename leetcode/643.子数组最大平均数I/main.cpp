#include <bits/stdc++.h>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int ans = INT_MIN, sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // 1.入窗口
            sum += nums[i];
            if (i < k - 1) continue;
            // 2.更新值
            ans = max(ans, sum);
            // 3.出窗口
            sum -= nums[i - k + 1];
        }
        return double(ans) / k;
    }
};

int main() {
    Solution* s = new Solution();
    {
        vector<int> input = {1,12,-5,-6,50,3};
        assert(s->findMaxAverage(input, 4) == 12.75);
    }
    {
        vector<int> input = {5};
        assert(s->findMaxAverage(input, 1) == 5.00000);
    }
    {
        // 未考虑负数情况就会失败
        // ans 初始值应设为无穷小
        vector<int> input = {-1};
        assert(s->findMaxAverage(input, 1) == -1.0);
    }
}