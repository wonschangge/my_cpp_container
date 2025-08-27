#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int n = nums.size();
            int left = 0, right = n - 1, ans = n;
            while (left <= right) {
                int mid = ((right - left) >> 1) + left;
                if (target <= nums[mid]) {
                    ans = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return ans;
        }
    };

int main()
{
    Solution s;
    {
        vector<int> v = {1,3,5,6};
        cout << s.searchInsert(v, 5);
    }
    {
        vector<int> v = {1,3,5,6};
        cout << s.searchInsert(v, 2);
    }
    {
        vector<int> v = {1,3,5,6};
        cout << s.searchInsert(v, 7);
    }
}