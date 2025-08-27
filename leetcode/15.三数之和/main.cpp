#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    // 1.哈希表+辅助集合,超时
    // vector<vector<int>> ans = {};
    // set<vector<int>> tmpset;

    // int n = nums.size();
    // for (int i = 0; i < (n - 2); i++) {
    //   int sub = 0 - nums[i];
    //   unordered_map<int, int> idx;
    //   for (int j = i + 1; j < n; j++) {
    //     int target = sub - nums[j];
    //     auto it = idx.find(target);
    //     if (it != idx.end()) {
    //       vector<int> tmp = {nums[i], target, nums[j]};
    //       sort(tmp.begin(), tmp.end());
    //       tmpset.insert(tmp);
    //     }
    //     idx[nums[j]] = j;
    //   }
    // }
    // for (auto v : tmpset)
    //   ans.push_back(v);
    // return ans;
  }
};

int main() {
  Solution *s = new Solution();
  {
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> output = s->threeSum(input);
    vector<vector<int>> answer = {{-1, -1, 2}, {-1, 0, 1}};
    assert(output == answer);
  }
  {
    vector<int> input = {0, 1, 1};
    vector<vector<int>> output = s->threeSum(input);
    vector<vector<int>> answer = {};
    assert(output == answer);
  }
  {
    vector<int> input = {0, 0, 0};
    vector<vector<int>> output = s->threeSum(input);
    vector<vector<int>> answer = {{0, 0, 0}};
    assert(output == answer);
  }
  {
    vector<int> input = {-1, 0, 1};
    vector<vector<int>> output = s->threeSum(input);
    vector<vector<int>> answer = {{-1, 0, 1}};
    assert(output == answer);
  }
  {
    vector<int> input = {1, -1, -1, 0};
    vector<vector<int>> output = s->threeSum(input);
    vector<vector<int>> answer = {{-1, 0, 1}};
    assert(output == answer);
  }
}