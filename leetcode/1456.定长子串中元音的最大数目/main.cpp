#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int checkIfVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int ans = 0, vowels = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            // 1.入窗口
            if (checkIfVowel(s[i])) vowels++;
            if (i < k - 1) continue; // 窗口大小不足
            // 2.更新值
            ans = max(ans, vowels);
            if (ans == k) return ans;
            // 3.出窗口
            if (checkIfVowel(s[i - k + 1])) vowels--;
        }

        return ans;
    }
};

int main() {
    Solution* s = new Solution();

    assert(s->maxVowels("abciiidef", 3) == 3);
    assert(s->maxVowels("aeiou", 2) == 2);
    assert(s->maxVowels("leetcode", 3) == 2);
    assert(s->maxVowels("rhythms", 4) == 0);
    assert(s->maxVowels("tryhard", 4) == 1);
}