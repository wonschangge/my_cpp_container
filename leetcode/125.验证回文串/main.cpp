#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      if (!isalnum(s[l])) {
        l++;
      } else if (!isalnum(s[r])) {
        r--;
      } else if (tolower(s[l]) == tolower(s[r])) {
        l++;
        r--;
      } else {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution *s = new Solution();
  assert(s->isPalindrome("A man, a plan, a canal: Panama") == true);
  assert(s->isPalindrome("race a car") == false);
  assert(s->isPalindrome(" ") == true);
}