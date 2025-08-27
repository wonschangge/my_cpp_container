#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int ans = INT_MAX, s = 0;
        for (int i = 0; i < n; i++) {
            // 1.入窗口
            if (i < k - 1) {
                if (blocks[i] == 'B') s++;
                continue;
            }
            if (blocks[i] == 'B') s++;
            // 2.更新值
            ans = min(ans, (k - s));
            // 3.出窗口
            if (blocks[i - k + 1] == 'B') s--;
        }
        return ans;
    }
};

int main() {
    Solution* s = new Solution();
    assert(s->minimumRecolors("WBBWWBBWBW", 7) == 3);
    assert(s->minimumRecolors("WBWBBBW", 2) == 0);
}