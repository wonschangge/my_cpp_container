#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        long long ans = 0, sum = 0;
        unordered_map<int, int> unique;
        for (int i = 0; i < n; i++) {
            // 1.入窗口
            sum += nums[i];
            unique[nums[i]]++;
            if (i < k - 1) continue;
            // 2.更新值
            if (unique.size() >= m) 
                ans = max(ans, sum);
            // 3.出窗口
            int out = nums[i - k + 1];
            sum -= out;
            if (--unique[out] == 0) unique.erase(out);
        }
        return ans;
    }
};

int main() {
    Solution* s = new Solution();
    {
        vector<int> input = {2,6,7,3,1,7};
        assert(s->maxSum(input, 3, 4) == 18);
    }
    {
        vector<int> input = {5,9,9,2,4,5,4};
        assert(s->maxSum(input, 1, 3) == 23);
    }
    {
        vector<int> input = {1,2,1,2,1,2,1};
        assert(s->maxSum(input, 3, 3) == 0);
    }
    {
        // 错误输出值为 0
        vector<int> input = {1,1,1,3};
        assert(s->maxSum(input, 2, 2) == 4);
    }
}