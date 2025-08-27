#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minimumLength(string s) {
    int n = s.length();
    int l = 0, r = n - 1;
    while (l < r && s[l] == s[r]) {
      if (l + 1 < r) {
        if (s[l + 1] == s[r])
          l++;
        else if (s[l] == s[r - 1])
          r--;
        else {
          break;
        }
      } else {
        l++;
        r--;
      }
    }
    return r - l + 1;
  }
};

int main() {
  Solution *s = new Solution();
  assert(s->minimumLength("ca") == 2);
  assert(s->minimumLength("cabaabac") == 0);
  assert(s->minimumLength("aabccabba") == 3);
}