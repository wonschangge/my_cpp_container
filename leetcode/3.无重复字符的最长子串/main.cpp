#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 法1: 哈希表(整形数组)
        int n = s.length(), ans = 0, left = 0;
        unordered_map<char, int> cnt;
        for (int right = 0; right < n; right++) {
            char c = s[right];
            cnt[c]++;
            while(cnt[c] > 1)
                cnt[s[left++]]--;
            ans = max(ans, right - left + 1);
        }
        return ans;

        // 法2: 哈希集合(布尔数组)
        // int n = s.length(), ans = 0, left = 0;
        // unordered_set<char> window;
        // for (int right = 0; right < n; right++) {
        //     char c = s[right];
        //     while (window.contains(c)) { // contains是c++20语法
        //         window.erase(s[left]);
        //         left++;
        //     }
        //     window.insert(c);
        //     ans = max(ans, right - left + 1);
        // }
        // return ans;
    }
};

int main() {
    Solution* s = new Solution();
    assert(s->lengthOfLongestSubstring("abcabcbb") == 3);
    assert(s->lengthOfLongestSubstring("bbbbb") == 1);
    assert(s->lengthOfLongestSubstring("pwwkew") == 3);
    assert(s->lengthOfLongestSubstring("qrsvbspk") == 5);
}