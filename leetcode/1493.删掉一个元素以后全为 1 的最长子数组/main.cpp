#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // 法1.滑动窗口
        // int n = nums.size(), ans = 0, left = 0, haszero = 0;
        // unordered_map<int, int> cnt;
        // for (int right = 0; right < n; right++) {
        //     cnt[nums[right]]++;
        //     while (cnt[0] >= 2) {
        //         cnt[nums[left++]]--;
        //     }
        //     if (cnt[0] > 0) haszero = 1;
        //     ans = max(ans, right - left + 1 - haszero);
        // }
        // if (ans == n) ans--;
        // return ans;

        // 法2.更优的滑动窗口
        int ans = 0, left = 0, cnt0 = 0;
        for (int right = 0; right < nums.size(); right++) {
            // 1.入窗口
            cnt0 += 1 - nums[right]; // 单一个变量即可维护0的数量
            // 2.出窗口
            while (cnt0 > 1)
                cnt0 -= 1 - nums[left++];
            // 3.更新值
            ans = max(ans, right - left); // 无论如何都是要减1的
        }
        return ans;
    }
};


int main() {
    Solution* s = new Solution();
    {
        vector<int> input = {1,1,0,1};
        assert(s->longestSubarray(input) == 3);
    }
    {
        vector<int> input = {0,1,1,1,0,1,1,0,1};
        assert(s->longestSubarray(input) == 5);
    }
    {
        // 易错,必须删除一个元素
        vector<int> input = {1,1,1};
        assert(s->longestSubarray(input) == 2);
    }
}