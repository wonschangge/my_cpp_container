#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 假设进来的整数数组满足: [n0, n1, ..., nn]
    // n1..(n-1) < n0 <= nn 
    int calcTrap(vector<int>& height) {
        int n = height.size();
        int sum = 0;
        for (int i = 1; i < (n - 1); i++) {
            sum += min(height[n-1],height[0]) - height[i];
        }
        return sum;
    }

    // 扫描并将子串传入
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int l = 0, r = 0, space = 0;
        for (int i = 1; i < n; i++) {
            if (height[i] >= height[l]) {
                if (space >= 1) {
                    vector<int> slice(height.begin() + l, height.begin() + r + 1);
                    ans += calcTrap(slice);
                } else {
                    l++;
                    r++;
                    continue;
                }
            }
            else {
                r++;
                space++;
            }
        }
    }
};

int main() {
    Solution* s = new Solution();
    {
        vector<int> nums = {1,0,2};
        assert(s->calcTrap(nums) == 1);
    }
    {
        vector<int> nums = {2,1,0,1,3};
        assert(s->calcTrap(nums) == 4);
    }


    // {
    //     vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    //     assert(s->trap(nums) == 6);
    // }
    // {
    //     vector<int> nums = {4,2,0,3,2,5};
    //     assert(s->trap(nums) == 9);
    // }
}