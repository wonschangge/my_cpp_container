#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') ans++;
            else if ((i + 1 < n) && s[i+1] != ' ') ans = 0; 
        }
        return ans;
    }
};

int main() {
    Solution* s = new Solution();
    assert(s->lengthOfLastWord("Hello World") == 5);
    assert(s->lengthOfLastWord("   fly me   to   the moon  ") == 4);
    assert(s->lengthOfLastWord("luffy is still joyboy") == 6);
    cout << "perfect" << endl;
}