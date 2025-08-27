#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0, s = 0;
        unordered_map<int, int> uniq;
        for (int i = 0; i < n; i++) {
            //1.入
            s += nums[i];
            uniq[nums[i]]++;
            if (i < k - 1) continue;
            //2.更
            if (uniq.size() == k) ans = max(ans, s);
            //3.出
            int out = nums[i - k + 1];
            s -= out;
            if (--uniq[out] == 0) uniq.erase(out);
        }
        return ans;
    }
};

int main() {
    Solution* s = new Solution();
    {
        vector<int> input = {1,5,4,2,9,9,9};
        assert(s->maximumSubarraySum(input, 3) == 15);
    }
    {
        vector<int> input = {4,4,4};
        assert(s->maximumSubarraySum(input, 3) == 0);
    }
}