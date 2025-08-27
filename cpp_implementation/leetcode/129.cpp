#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 法1.暴力枚举
        int ans = 0, n = prices.size();
        if (n == 1) return ans;
        for (int i = 0; i < n - 1; i++) {
            if (prices[i] > prices[i+1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (prices[i] < prices[j]) {
                    ans = max(ans, prices[j] - prices[i]);
                }
            }
        }
        return ans;
        // 
    }
};

int main()
{
    Solution s;
    vector<int> test = {7,1,5,3,6,4};

    cout << s.maxProfit(test);
}
