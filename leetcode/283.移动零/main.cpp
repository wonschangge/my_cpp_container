#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 法1.双指针
        // int n = nums.size();
        // int l = 0, r = n - 1;

        // while (l != r) {
        //     if (nums[l] == 0) {
        //         for (int i = l; i < r; i++) {
        //             nums[i] = nums[i+1];
        //         }
        //         r--;
        //     } else {
        //         l++;
        //     }
        // }

        // for (int i = r + 1; i < n; i++) nums[i] = 0;

        // 法2.更高效的双指针
        // 0,1,0,3,12
        // 1,0,0,3,12
        // 1,3,0,0,12
        // 1,3,12,0,0
        int n = nums.size(), l = 0, r = 0;
        while (r < n) {
            if (nums[r]) {
                swap(nums[l], nums[r]);
                l++;
            }
            r++;
        }
    }
};

int main() {
    Solution* s = new Solution();
    {
        vector<int> input = {0,1,0,3,12};
        s->moveZeroes(input);
        for(auto i:input) cout<<i<<endl;

        assert(input[0] == 1);
        assert(input[1] == 3);
        assert(input[2] == 12);
        assert(input[3] == 0);
        assert(input[4] == 0);
    }
    {
        vector<int> input = {0};
        s->moveZeroes(input);
        assert(input[0] == 0);
    }
}