#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int minIncrementForUnique(vector<int> &nums) {
    // 法1.排序 - O(nlogn)
    // int ans = 0;
    // sort(nums.begin(), nums.end());
    // for (int i = 1; i < nums.size(); i++) {
    //     if (nums[i] <= nums[i-1]) {
    //         ans += nums[i-1] - nums[i] + 1;
    //         nums[i] = nums[i-1] + 1;
    //     }
    // }
    // return ans;
    // 法2.计数排序 - O(n)
    int ans = 0, biggest = 0;
    int cnt[200000] = {0};
    for(int x: nums) cnt[x]++;
    for(int i = 0; i <= biggest; i++) {
        if (cnt[i] > 1) {
            cnt[i+1]++;
            ans++;
        }
    }
    return ans;
  }
};

int main() {
  Solution *s = new Solution();
//   {
//     vector<int> input = {1, 2, 2};
//     assert(s->minIncrementForUnique(input) == 1);
//   }
  {
    vector<int> input = {3, 2, 1, 2, 1, 7};
    assert(s->minIncrementForUnique(input) == 6);
  }
}