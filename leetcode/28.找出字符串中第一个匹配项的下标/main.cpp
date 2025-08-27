#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        for (int i = 0, j = 0; i < m ; i++) {
            // cout << i << haystack[i] << j << needle[j] << endl;
            if (haystack[i] == needle[j]) {
                if (j == n - 1) return i - j;
                else j++;
            } else {
                // i 需要回溯回去，来避免错误嵌套的子串
                if (j > 0) {
                    i = i - j;
                    j = 0;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution* s = new Solution();
    std::cout << s->strStr("test", "test") << std::endl;
    std::cout << s->strStr("abcdabce", "abce") << std::endl;
    std::cout << s->strStr("sadbutsad", "sad") << std::endl;
    std::cout << s->strStr("leetcode", "leeto") << std::endl;
    std::cout << s->strStr("mississippi", "issip") << std::endl;
    std::cout << s->strStr("mississippi", "issi") << std::endl;
    std::cout << s->strStr("mnmmnmmnmn", "mnmn") << std::endl;
}