#include <bits/stdc++.h>
#include <cassert>
#include <iterator>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    // 法1.暴力
    // for (int i = 0;; i++)
    //   for (int j = i + 1; j < nums.size(); j++)
    //     if (nums[i] + nums[j] == target)
    //       return {i, j};
    // return {};
    // 法2.哈希
    unordered_map<int, int> idx;
    for (int j = 0; j < nums.size(); j++) {
      auto it = idx.find(target - nums[j]);
      if (it != idx.end())
        return {it->second, j};
      idx[nums[j]] = j;
    }
    return {};
  }
};

int main() {
  Solution *s = new Solution();
  {
    vector<int> input = {2, 7, 11, 15};
    vector<int> output = s->twoSum(input, 9);
    vector<int> answer = {0, 1};
    assert(output == answer);
  }
  {
    vector<int> input = {3, 2, 4};
    vector<int> output = s->twoSum(input, 6);
    vector<int> answer = {1, 2};
    assert(output == answer);
  }
  {
    vector<int> input = {3, 3};
    vector<int> output = s->twoSum(input, 6);
    vector<int> answer = {0, 1};
    assert(output == answer);
  }
}