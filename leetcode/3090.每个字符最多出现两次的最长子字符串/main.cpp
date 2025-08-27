#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length(), ans = 2, left = 0;
        unordered_map<char, int> cnt;
        for (int right = 0; right < n; right++) {
            char c = s[right];
            cnt[c]++;
            while(cnt[c] > 2)
                cnt[s[left++]]--;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main() {
    Solution* s = new Solution();
    assert(s->maximumLengthSubstring("bcbbbcba") == 4);
    assert(s->maximumLengthSubstring("aaaa") == 2);
}