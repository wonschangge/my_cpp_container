#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1, ans = n;
        while (l <= r) {
            int mid = ((r - l) >> 1) + l;
            if (target <= nums[mid]) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution* s = new Solution();
    {
        vector<int> nums = {1,3,5,6};
        std::cout << s->searchInsert(nums,5) << std::endl;
        std::cout << s->searchInsert(nums,2) << std::endl;
        std::cout << s->searchInsert(nums,7) << std::endl;
    }
}