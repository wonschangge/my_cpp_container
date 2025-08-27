#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX, left = 0, sum = 0;

        for(int right = 0; right < n; right++) {
            if (nums[right] >= target) return 1;
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left++];
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

int main() {
    Solution* s = new Solution();
    {
        vector<int> input = {2,3,1,2,4,3};
        assert(s->minSubArrayLen(7,input) == 2);
    }
    {
        vector<int> input = {1,4,4};
        assert(s->minSubArrayLen(4,input) == 1);
    }
    {
        vector<int> input = {1,1,1,1,1,1,1,1};
        assert(s->minSubArrayLen(11,input) == 0);
    }
}