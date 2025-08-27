#include <bits/stdc++.h>

using namespace std;

// 大O为n, 故不能用快排/二分进行排序

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 法1.哈希表
        // Step1. 丢入set中去重
        unordered_set<int> num_set;
        for (const int& num: nums)
            num_set.insert(num);
        
        // Step2.
        int longestStreak = 0;

        for (const int& num: num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};

int main() {
    Solution* s = new Solution();
    {
        vector<int> input = {100,4,200,1,3,2};
        assert(s->longestConsecutive(input) == 4);
    }
    {
        vector<int> input = {0,3,7,2,5,8,4,6,0,1};
        assert(s->longestConsecutive(input) == 9);
    }
    {
        vector<int> input = {1,0,1,2};
        assert(s->longestConsecutive(input) == 3);
    }
}