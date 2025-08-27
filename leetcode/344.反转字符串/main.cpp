#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  void reverseString(vector<char> &s) {
    // 法1.单指针/双指针
    // int n = s.size();
    // for (int i = 0; i < (n / 2); i++) {
    //   swap(s[i], s[n - i - 1]);
    // }
    // 法2.库函数
    ranges::reverse(s); // -std=c++20
  }
};

int main() {
  Solution *s = new Solution();
  {
    vector<char> input = {'h', 'e', 'l', 'l', 'o'};
    vector<char> answer = {'o', 'l', 'l', 'e', 'h'};
    s->reverseString(input);
    assert(input == answer);
  }
  {
    vector<char> input = {'H', 'a', 'n', 'n', 'a', 'h'};
    vector<char> answer = {'h', 'a', 'n', 'n', 'a', 'H'};
    s->reverseString(input);
    assert(input == answer);
  }
}